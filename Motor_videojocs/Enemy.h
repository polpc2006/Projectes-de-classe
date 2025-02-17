#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
// Definició de la classe Enemy (Enemic)
class Enemy
{
public:
	// Constructor de la classe Enemy
	Enemy();
	// Destructor de la classe Enemy
	~Enemy();
	// Mètode per inicialitzar l'enemic amb textura, posició i velocitat
	void init(string textureName, Vector2f position, float _speed);
	// Mètode per actualitzar la posició de l'enemic
	void update(float dt);
	// Mètode per obtenir el sprite de l'enemic
	Sprite getSprite();
private:
	Texture m_texture; // Variable per emmagatzemar la textura de l'enemic
	Sprite m_sprite;   // Sprite que representa l'enemic a la pantalla
	Vector2f m_position; // Posició de l'enemic a la pantalla
	float m_speed;      // Velocitat de l'enemic
};