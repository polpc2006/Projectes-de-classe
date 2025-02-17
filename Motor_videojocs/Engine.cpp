#include "Engine.h"
#include <iostream>

// Constructor de la classe Engine, inicialitza la finestra de joc
Engine::Engine() {
	// Establim la mida de la finestra de joc
	viewSize.x = 1024;
	viewSize.y = 768;
	// Creem la finestra amb SFML
	window.create(sf::VideoMode(viewSize.x, viewSize.y), "Joc liam - gats", Style::Default);
}
// Destructor de la classe Engine, allibera la memòria dinàmica
Engine::~Engine() {
	for (Enemy* enemy : enemies) {
		delete enemy;
	}
	for (Rocket* rocket : rockets) {
		delete rocket;
	}
	enemies.clear();
	rockets.clear();
}
// Mètode principal que executa el bucle del joc
int Engine::run() {
		Clock clock;
	init(); // Inicialitza els recursos del joc
	while (window.isOpen()) {
		Time dt = clock.restart();
		updateInput(dt.asSeconds()); // Processa l'entrada de l'usuari
		if (!gameover) {
			update(dt.asSeconds()); // Actualitza l'estat del joc si no ha acabat
		}
		draw(); // Dibuixar els elements a la pantalla
	}
	return 0;
}
// Inicialitza elements del joc com imatges, textos i so
void Engine::init() {
	// Carrega i configura el fons del joc
	 bgTexture.loadFromFile("GRAPHICS/background.png");
	 bgSprite.setTexture(bgTexture);
	 
	 // Carreguem les fonts i configurem els textos
	 float scaleX = viewSize.x / bgTexture.getSize().x;
	 float scaleY = viewSize.y / bgTexture.getSize().y;
	 bgSprite.setScale(scaleX, scaleY);
	 
	 headingFont.loadFromFile("FONTS/fonttext_motor_en.ttf");
	 scoreFont.loadFromFile("FONTS/fonttext_motor_en_Black.ttf");
	 MaxscoreFont.loadFromFile("FONTS/fonttext_motor_en_Black.ttf");
	 
	 headingText.setFont(headingFont);
	 headingText.setString("Liam's game");
	 headingText.setCharacterSize(84);
	 headingText.setFillColor(Color(0, 128, 128));
	 FloatRect headingbounds = headingText.getLocalBounds();
	 headingText.setOrigin(headingbounds.width / 2, headingbounds.height / 2);
	 headingText.setPosition(Vector2f(viewSize.x * 0.5f, viewSize.y * 0.10f));
	
	  tutorialText.setFont(scoreFont);
	  tutorialText.setString("Press Down Arrow to Fire and Start Game, Up Arrow to Jump");
	  tutorialText.setCharacterSize(35);
	  tutorialText.setFillColor(Color(0, 128, 128));
	  FloatRect tutorialbounds = tutorialText.getLocalBounds();
	  tutorialText.setOrigin(tutorialbounds.width / 2, tutorialbounds.height / 2);
	  tutorialText.setPosition(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.20f));

	  
	  scoreText.setFont(scoreFont);  // Establecemos la fuente
	  scoreText.setCharacterSize(30); // Tamaño del texto
	  scoreText.setFillColor(Color(0, 128, 0)); // Color del texto
	  scoreText.setPosition(10, 10);  // Posición del texto en la pantalla

	  MaxscoreText.setFont(MaxscoreFont);  // Establecemos la fuente
	  MaxscoreText.setCharacterSize(30); // Tamaño del texto
	  MaxscoreText.setFillColor(Color(0, 128, 0)); // Color del texto
	  MaxscoreText.setPosition(10, 50);  // Posición del texto en la pantalla
	  // Carreguem i reproduïm la música de fons
	  bgMusic.openFromFile("FONTS/LEVEL-UP.ogg");

	  bgMusic.setLoop(true); // Activar bucle para la música
	  bgMusic.play(); // Iniciar la música
	  
	  //inicialitzem el jugador
	  Liam.init("GRAPHICS/PLAYER.png", Vector2f(viewSize.x * 0.05f, viewSize.y * 0.5f), 200);
	  //inicialitzem els valors aleatoris.
	  srand((int)time(0));
}
// Processa l'entrada de l'usuari
void Engine::updateInput(float dt) {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::KeyPressed) { // Revisem les tecles premudes
			if (event.key.code == Keyboard::Up) { // Personatge salta
				Liam.jump(750.0f);
			}

			if (event.key.code == Keyboard::Down) {
				if (gameover) { // Si no juguem, llavors engeguem el joc
					gameover = false;
					reset();
				}
			}

			// Cooldown per disparar
			const float maxCooldown = 0.5f; // Temps mínim entre trets (0.5 segons)
			if (Cooldown >= maxCooldown) {
				if (event.key.code == Keyboard::Space) { // Només dispara si ha passat el temps necessari
					shoot();
					Cooldown = 0; // Reinicia el cooldown després de disparar
				}
			}
		}

		// Condicions per tancar el programa
		if (event.key.code == Keyboard::Escape || event.type == Event::Closed)
			window.close();
	}

	// Incrementem el cooldown fora del bucle d'events
	Cooldown += dt;
}


void Engine::update(float dt) {
	//actualitzem la posició del personatge
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		Liam.moveLeft(dt);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		Liam.moveRight(dt);
	}

	if (score < 0) {
		gameover = true;
	}

	// Actualizamos al personaje
	Liam.update(dt);

	// Actualizar el texto del score con el valor actual
	scoreText.setString("Score: " + to_string(score));
	// Actualizar el texto del Maxscore si és más alto
	MaxscoreText.setString("Max Score: " + to_string(Maxscore));
	//modifiquem el temps per sabre el que ha passat
	currentTime += dt;
	// Aparèixer Enemics
	if (currentTime >= prevTime + 1.125f) {
		spawnEnemy();
		prevTime = currentTime;
	}
	// Crea un nou Toppo cada 3 segons
	static float spawnTimer = 0;
	spawnTimer += dt;
	// Aparèixer Talps
	if (spawnTimer >= 3.0f) {
		spawnToppo();
		spawnTimer = 0;
	}
	for (int i = 0; i < enemies.size(); i++) {
		Enemy* enemy = enemies[i];
		enemy->update(dt);
		if(enemy->getSprite().getPosition().x
			< 0) {
			delete enemy;
			enemies.erase(enemies.begin() + i);
			score -= 20;
			i--;
		}
	}
	// Vector per emmagatzemar els enemics Toppo
	for (int i = 0; i < toppos.size(); i++) {
		Toppo* toppo = toppos[i];
		toppo->update(dt);

		if (toppo->getSprite().getPosition().y < 0) {
			delete toppo;  // Esborra la memòria abans d’eliminar-lo del vector
			toppos.erase(toppos.begin() + i);
			score -= 30;
			i--; // Esborra la memòria abans d’eliminar-lo del vector
		}
	}

	// Actualitzar rockets
	for (Rocket* rocket : rockets) {
		rocket->update(dt);  // Llamar al método update() de cada bala
	}

	// Comprovar col·isió entre Rockets i Enemics
	// Actualitzem els coets i verifiquem les col·lisions amb els enemics
	for (int i = 0; i < rockets.size(); i++) {
		Rocket* rocket = rockets[i];
		rocket->update(dt);

		// Verifiquem la col·lisió entre cada coet i els enemics
		for (int j = 0; j < enemies.size(); j++) {
			if (checkCollision(rocket->getSprite(), enemies[j]->getSprite())) {
				// Eliminar coet i enemic en cas de col·lisió
				delete enemies[j];
				delete rockets[i];
				enemies.erase(enemies.begin() + j);
				rockets.erase(rockets.begin() + i);

				// Incrementar puntuació per destruir un enemic
				score += 10;
				if (score > Maxscore) {
					Maxscore = score;
				}
				break; // Sortir del bucle de coets quan es detecta una col·lisió
			}
		}
		for (int j = 0; j < toppos.size(); j++) {
			if (checkCollision(rocket->getSprite(), toppos[j]->getSprite())) {
				// Eliminar coet i enemic en cas de col·lisió
				delete toppos[j];
				delete rockets[i];
				toppos.erase(toppos.begin() + j);
				rockets.erase(rockets.begin() + i);

				// Incrementar puntuació per destruir un enemic
				score += 20;
				if (score > Maxscore) {
					Maxscore = score;
				}
				break; // Sortir del bucle de coets quan es detecta una col·lisió
			}
		}
	}
}

void Engine::draw() {
	// netejem la pantalla
	window.clear(Color::Red);
	//dibuixem elements
	window.draw(bgSprite);
	window.draw(Liam.getSprite());
	// Dibuixa el nom del personatje
	window.draw(Liam.getNameText());
	//Dibuixa els enemics bàsics
	for (Enemy* enemy : enemies) {
		window.draw(enemy->getSprite());
	}
	//Dibuixa els talps
	for (Toppo* toppo : toppos) {
		window.draw(toppo->getSprite());
	}
	//Mostrem text depenent si estem jugant o no
	if (gameover) {
		window.draw(headingText);
		window.draw(tutorialText);
		
	}
	else {
		window.draw(scoreText);
		window.draw(MaxscoreText);
		window.draw(Liam.getNameText()); // Aquí dibuixem el text del nom
	}
	for (Rocket* rockets : rockets) {
		window.draw(rockets->getSprite());
	}
		window.draw(Liam.getNameText()); // Aquí dibuixem el text del nom
	//enviem a la pantalla.

	// Si el joc no ha acabat, dibuixem el score
	if (!gameover) {
		window.draw(scoreText);  // Dibuixa el text del score en la pantalla
		window.draw(MaxscoreText);
	}
	else {
		window.draw(headingText);
		window.draw(tutorialText);
	}
	window.display();
}
// Reinicialitza l'estat del joc
void Engine::reset() {
	score = 0;
	currentTime = 0.0f;
	prevTime = 0.0;
	for (Enemy* enemy : enemies) {
		delete(enemy);
	}
	for (Rocket* rocket : rockets) {
		delete(rocket);
	}
	enemies.clear();
	rockets.clear();
}
// Crea nous enemics
void Engine::spawnEnemy() {
	int randLoc = rand() % 3;
	Vector2f enemyPos;
	float speed = 50;
	switch (randLoc) {
	case 0: enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.75f);
		speed = -400; break;
	case 1: enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.60f);
		speed = -550; break;
	case 2: enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.40f);
		speed = -650; break;
	default: printf("incorrect y value \n"); break;
	}
	Enemy* enemy = new Enemy();
	enemy->init("GRAPHICS/enemic.png", enemyPos, speed);
	enemies.push_back(enemy);
}
// Crea nous talps
void Engine::spawnToppo() {
	Vector2f toppoPos;
	float speed = -300; // Velocitat cap amunt

	// Generar Toppo a la part inferior de la pantalla
	toppoPos = Vector2f(400, 600); // Ajusta X segons vulguis
	
	Toppo* toppo = new Toppo();
	toppo->init("GRAPHICS/talp.png", toppoPos, speed);
	toppos.push_back(toppo); // Guardem com a punter genèric
}
// Dispara un nou projectil
void Engine::shoot() {
	Rocket* rocket = new Rocket();
	rocket->init("GRAPHICS/bala.png", Liam.getSprite().getPosition(), velocitat+450);
	rockets.push_back(rocket);
}
// Comprova col·lisions entre elements del joc
bool Engine::checkCollision(Sprite sprite1, Sprite sprite2) {
	if (sprite1.getTexture() == nullptr || sprite2.getTexture() == nullptr) {
		return false;
	}
	return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
}