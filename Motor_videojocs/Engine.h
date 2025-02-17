#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Hero.h"
#include "Enemy.h"
#include "Rocket.h"
#include "Toppo.h"

using namespace sf;
using namespace std;

class Engine
{

private:
	//Velocitat enemic
	float velocitat;
	//creem la variables per crear la finestra de joc
	Vector2f viewSize;
	VideoMode vm;
	RenderWindow window;
	//variable per emmagatzemar el fons
	//paisatge
	Texture bgTexture;
	Sprite bgSprite;
	// Text
	Font headingFont;
	Text headingText;
	Text tutorialText;
	//Scores
	Font scoreFont;
	Text scoreText;
	Font MaxscoreFont;
	Text MaxscoreText;
	// Audio
	Music bgMusic;
	//variable del personatge
	Hero Liam;
	//variable enemic
	vector <Enemy*> enemies; // Vector per emmagatzemar els enemics 
	vector <Toppo*> toppos;  // Vector per emmagatzemar els enemics Toppo
	//variable Rocket
	vector <Rocket*> rockets;
	//temps entre frame
	float currentTime;
	float prevTime = 0.0f;
	float Cooldown = 0.0f; // Cooldown global per a trets
	//variables del joc.
	int score = 0;
	int Maxscore = 0;
	bool gameover = true;

	void reset();
	void init();
	void updateInput(float dt);
	void update(float dt);
	void draw();

	void spawnEnemy();
	void spawnToppo();

public: 
	// Constructor de la classe Engine, s'executa quan es crea un objecte Engine
	Engine();
	// Destructor de la classe Engine, s'executa quan l'objecte es destrueix
	~Engine();
	// Mètode principal que executa el joc
	int run();
	// Funció per disparar coets
	void shoot();
	// Funció per comprovar si dos elements han col·lisionat
	bool checkCollision(Sprite sprite1, Sprite sprite2);
};

