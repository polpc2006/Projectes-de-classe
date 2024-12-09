// Timber videogame.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>


// Control the player input
bool acceptInput = false;


// Make code easier to type with "using namespace"
using namespace sf;
//constant 
const int Xmax = 1920;
const int Ymax = 1080;

const int NUM_BRANCHES = 6;
// Where is the player/branch?
// Left or Right
enum class side { LEFT, RIGHT, NONE };

void updateBranches(int seed, side branca[]);


// programa principal
int main()
{
	
	Sprite branches[NUM_BRANCHES];
	side branchPositions[NUM_BRANCHES];

	// Prepare 6 branches
	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");
	// Set the texture for each branch sprite
	for (int i = 0; i < NUM_BRANCHES; i++) {
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000);
		// Set the sprite's origin to dead centre
		// We can then spin it round without changing its position
		branches[i].setOrigin(220, 20);
	}
	

	// Time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Yellow);
	timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);
	Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

	// Track whether the game is running
	bool paused = true;


	// Draw some text
	int score = 0;
	Text messageText;
	Text scoreText;

	// We need to choose a font
	Font font;
	font.loadFromFile("fonts/TextFont2.otf");
	// Set the font to our message
	messageText.setFont(font);
	scoreText.setFont(font);

	//Set the fon of the FPS

	float fps = 0.0f; // Velocidad del fotograma

	sf::Text fpsText;
	fpsText.setFont(font); // Usa la misma fuente que la puntuación
	fpsText.setCharacterSize(50);
	fpsText.setFillColor(sf::Color::White);
	fpsText.setPosition(1600, 50); // Coloca el texto debajo de la puntuación

	// Assign the actual message
		messageText.setString("Press Enter to start!");
		scoreText.setString("Score = 0");
	// Make it really big
		messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);
	// Choose a color
		messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);

	// Position the text
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	messageText.setPosition(Xmax / 2.0f, Ymax / 2.0f);
	scoreText.setPosition(20, 20);


	// Create a video mode object
	VideoMode vm(Xmax, Ymax);

	// Create and open a window for the game  
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);
	window.setFramerateLimit(60); // Limitar a 60 FPS

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background2.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);
	//Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	// Prepare the bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/lenyador.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	// Is the bee currently moving?
	bool beeActive = false;
	// How fast can the bee fly
	float beeSpeed = 2.0f;


	// make 3 cloud sprites from 1 texture
	Texture textureCloud;
	// Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");
		// 3 New sprites with the same texture
	const int NumMaxClouds = 3;
	Sprite spriteCloud[NumMaxClouds];
	spriteCloud[0].setTexture(textureCloud);
	spriteCloud[1].setTexture(textureCloud);
	spriteCloud[2].setTexture(textureCloud);
	// Position the clouds on the left of the screen
	for (int i = 0; i < NumMaxClouds; i++)
	{
		spriteCloud[i].setTexture(textureCloud);
		spriteCloud[i].setPosition(0, i * 250);
	}
	// at different heights
	
	// Are the clouds currently on screen?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	// How fast is each cloud?
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;
	
	//Measure time
	Clock clock;

	int frameCounter = 0; // Contador de fotogramas

	// Prepare the Player
	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/palyer.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(580, 720);
	// The player starts on the left
		side playerSide = side::LEFT;
	// Prepare the gravestone
		Texture textureGravestone;
		textureGravestone.loadFromFile("graphics/gravestone2.png");
		Sprite spriteGravestone;
		spriteGravestone.setTexture(textureGravestone);
		spriteGravestone.setPosition(2000, 675);

	// Prepare the axe
		Texture textureaxe;
		textureaxe.loadFromFile("graphics/motoserra.png");
		Sprite spriteAxe;
		spriteAxe.setTexture(textureaxe);
		spriteAxe.setPosition(740, 780);

		// Prepare the axe2
		Texture textureaxe2;
		textureaxe2.loadFromFile("graphics/motoserra2.png");
		Sprite spriteAxe2;
		spriteAxe2.setTexture(textureaxe2);
		spriteAxe2.setPosition(740, 780);

	// Prepare the flying log
		Texture textureLog;
		textureLog.loadFromFile("graphics/log.png");
		Sprite spriteLog;
		spriteLog.setTexture(textureLog);
		spriteLog.setPosition(2000, 830);

	// Line the axe up with the tree – Cal posar-ho fora de la funció main
		const float AXE_POSITION_LEFT = 700;
		const float AXE_POSITION_RIGHT = 1075;
	// Prepare the flying log

	// Some other useful log related variables
		bool logActive = false;
		float logSpeedX = 1000;
		float logSpeedY = -1500;

		// The player chopping sound
		SoundBuffer chopBuffer;
		chopBuffer.loadFromFile("sound/chop.wav");
		Sound chop;
		// Prepare the sounds

		// The player death sound
		SoundBuffer deathBuffer;
		deathBuffer.loadFromFile("sound/death.wav");
		Sound death;
		bool boldeath = true;

		// The player out of time sound
		SoundBuffer timeBuffer;
		timeBuffer.loadFromFile("sound/time.wav");
		Sound timeof;
		// Prepare the sounds
		death.setBuffer(deathBuffer);

		timeof.setBuffer(timeBuffer);
		chop.setBuffer(chopBuffer);

		// The player out of time sound 2
		SoundBuffer feinaBuffer;
		feinaBuffer.loadFromFile("sound/feina.wav");
		Sound feina;
		feina.setBuffer(feinaBuffer);
		
		

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/

		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;
			// Reset the time and the score
			score = 0;
			timeRemaining = 6;
			// Make all the branches disappear
			for (int i = 1; i < NUM_BRANCHES; i++)
			{
				branchPositions[i] = side::NONE;
			}
			// Make sure the gravestone is hidden
			spriteGravestone.setPosition(675, 2000);
			// Move the player into position
			spritePlayer.setPosition(580, 720);
			acceptInput = true;
		}

		if (acceptInput) 
		{
			// First handle pressing the right cursor key
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				// Make sure the player is on the right
				playerSide = side::RIGHT;
					score++;
				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;
				
				spriteAxe2.setPosition(AXE_POSITION_RIGHT,
					spriteAxe2.getPosition().y);
				spritePlayer.setPosition(1200, 720);
				// update the branches
				updateBranches(score, branchPositions);
				// Set the log flying to the left
				spriteLog.setPosition(810, 720);
				logSpeedX = -5000;
				logActive = true;
				acceptInput = false;
				chop.setVolume(50);
				chop.play();

			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				// Make sure the player is on the right
				playerSide = side::LEFT;
				score++;
				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;
				spriteAxe.setPosition(AXE_POSITION_LEFT,
					spriteAxe.getPosition().y);
				spritePlayer.setPosition(580, 720);
				// update the branches
				updateBranches(score, branchPositions);
				// Set the log flying to the left
				spriteLog.setPosition(810, 720);
				logSpeedX = +5000;
				logActive = true;
				acceptInput = false;
				chop.setVolume(50);
				chop.play();

			}

		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased && !paused)
			{
				// Listen for key presses again
				acceptInput = true;
				// hide the axe
				spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
				spriteAxe2.setPosition(2000, spriteAxe2.getPosition().y);
			}
		}
		// Dentro del bucle del juego
		frameCounter++;

		if (frameCounter >= 60) {
			float elapsedTime = clock.restart().asSeconds(); // Tiempo transcurrido
			fps = 1.0f / elapsedTime; // Calculamos FPS
			frameCounter = 0; // Reiniciamos el contador
		}

		fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//Initialize the previous variables, one way or another

		/*
		****************************************
		Update the scene
		****************************************
		*/
		//Set up the bee
		Time dt = clock.restart();

		fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));

		if (!paused) 
		{


			// update the branch sprites
			for (int i = 0; i < NUM_BRANCHES;
				i++)
			{
				float height = i * 150;
				if (branchPositions[i] == side::LEFT)
				{
					// Move the sprite to the left side
					branches[i].setPosition(610, height);
					// Flip the sprite round the other way
					branches[i].setRotation(180);
				}
				else if (branchPositions[i] == side::RIGHT)
				{
					// Move the sprite to the right side
					branches[i].setPosition(1330, height);
					// Set the sprite rotation to normal
					branches[i].setRotation(0);
				}
				else
				{
					// Hide the branch
					branches[i].setPosition(3000, height);
				}
			}

			

			

		

			// Subtract from the amount of time remaining
			timeRemaining -= dt.asSeconds();
			// size up the time bar
			timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

			if (timeRemaining <= 0.0f) {
				// Pause the game
				paused = true;
				// Change the message shown to the player
				messageText.setString("Out of time!!");
				//Reposition the text based on its new size
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
				timeof.setVolume(100);
				timeof.play();
				feina.setVolume(100);
				feina.play();
			}
			
			if (!beeActive)
			{
				//How fast is the bee
				srand((int)time(0));
				beeSpeed = (rand() % 200) + 200;

				//How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;
			}
			else
				//Move the bee
			{
				spriteBee.setPosition(
					spriteBee.getPosition().x -
					(beeSpeed * dt.asSeconds()),
					spriteBee.getPosition().y);

				//Has the bee reached the left-hand edge of the screen?
				if (spriteBee.getPosition().x < -100)
				{
					// Set it up ready to be a whole new bee next frame
					beeActive = false;
				}
			}

			if (!cloud1Active)
			{
				// How fast is the cloud
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200) + 1000;

				// How high is the cloud
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud[0].setPosition(-200, height);
				cloud1Active = true;
			}
			else
			{
				spriteCloud[0].setPosition(
					spriteCloud[0].getPosition().x +
					(cloud1Speed * dt.asSeconds()),
					spriteCloud[0].getPosition().y);
				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud[0].getPosition().x > Xmax)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud1Active = false;
				}
			}

			if (!cloud2Active)
			{
				// How fast is the cloud
				srand((int)time(0) * 10);
				cloud2Speed = (rand() % 200) + 1000;

				// How high is the cloud
				srand((int)time(0) * 10);
				float height = (rand() % 100);
				spriteCloud[1].setPosition(-100, height);
				cloud2Active = true;
			}
			else
			{
				spriteCloud[1].setPosition(
					spriteCloud[1].getPosition().x +
					(cloud2Speed * dt.asSeconds()),
					spriteCloud[1].getPosition().y);
				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud[1].getPosition().x > Xmax)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud2Active = false;
				}
			}

			if (!cloud3Active)
			{
				// How fast is the cloud
				srand((int)time(0) * 10);
				cloud3Speed = (rand() % 200) + 1000;

				// How high is the cloud
				srand((int)time(0) * 10);
				float height = (rand() % 50);
				spriteCloud[2].setPosition(-50, height);
				cloud3Active = true;
			}
			else
			{
				spriteCloud[2].setPosition(
					spriteCloud[2].getPosition().x +
					(cloud3Speed * dt.asSeconds()),
					spriteCloud[2].getPosition().y);
				// Has the cloud reached the right hand edge of the screen?
				if (spriteCloud[2].getPosition().x > Xmax)
				{
					// Set it up ready to be a whole new cloud next frame
					cloud3Active = false;
				}
			}
		}
		
		// Handle a flying log               
		if (logActive)
		{

			spriteLog.setPosition(
				spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
				spriteLog.getPosition().y + (logSpeedY * dt.asSeconds())
			);

			// Has the insect reached the right hand edge of the screen?
			if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000)
			{
				// Set it up ready to be a whole new cloud next frame
				logActive = false;
				spriteLog.setPosition(810, 720);
			}
		}



		// has the player been squished by a branch?
		if (branchPositions[5] == playerSide)
		{
			// death
			paused = true;
			acceptInput = false;
			// Draw the gravestone
			
			spriteGravestone.setPosition(525, 760);
			// hide the player
			spritePlayer.setPosition(2000, 660);
			// Change the text of the message
			messageText.setString("RESTART!!");
			// Center it on the screen
			FloatRect textRect = messageText.getLocalBounds();
			messageText.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
			
			if (boldeath) {
				death.setVolume(20);
				death.play();
				boldeath = false;
			}
			
		}
		
		// End if(!paused)

		/*
		****************************************
		Draw the scene
		****************************************
		*/

		// Clear everything from the last frame
		window.clear();


		// Draw our game scene here
		window.draw(spriteBackground);
		// Draw the clouds
		for (int i = 0; i < NumMaxClouds; i++)
		{
			window.draw(spriteCloud[i]);
		}

		// Draw the branches
		for (int i = 0; i < NUM_BRANCHES; i++) {
			window.draw(branches[i]);
		}

		// Draw the tree
		window.draw(spriteTree);
		// Draw the insect
		window.draw(spriteBee);

		// Draw the player
		window.draw(spritePlayer);

		// Draw the axe
		window.draw(spriteAxe);
		// Draw the axe
		window.draw(spriteAxe2);
		// Draraw the flying log
		window.draw(spriteLog);

		// Draw the gravestone
		window.draw(spriteGravestone);

		// Update the score text
		std::stringstream ss;
		ss << "Score = " << score;
		scoreText.setString(ss.str());

		// Draw the score
		window.draw(scoreText);
		if (paused)
		{
			// Draw our message
			window.draw(messageText);
		}
		// Draw the timebar
		window.draw(timeBar);

		// Draw the FPS text
		window.draw(fpsText);
		// Show everything we just drew
		window.display();

	}
	return 0;
}

void updateBranches(int seed, side branca[])
{
	// Move all the branches down one place
	for (int j = NUM_BRANCHES - 1; j > 0; j--) {
		branca[j] = branca[j - 1];
	}
	// Spawn a new branch at position 0
		// LEFT, RIGHT or NONE
	srand((int)time(0) + seed);
	int r = (rand() % 5);
	switch (r) {
	case 0:
		branca[0] = side::LEFT;
		break;
	case 1:
		branca[0] = side::RIGHT;
		break;
	default:
		branca[0] = side::NONE;
		break;
	}
}
