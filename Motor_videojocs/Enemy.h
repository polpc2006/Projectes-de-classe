#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
// Definici� de la classe Enemy (Enemic)
class Enemy
{
public:
	// Constructor de la classe Enemy
	Enemy();
	// Destructor de la classe Enemy
	~Enemy();
	// M�tode per inicialitzar l'enemic amb textura, posici� i velocitat
	void init(string textureName, Vector2f position, float _speed);
	// M�tode per actualitzar la posici� de l'enemic
	void update(float dt);
	// M�tode per obtenir el sprite de l'enemic
	Sprite getSprite();
private:
	Texture m_texture; // Variable per emmagatzemar la textura de l'enemic
	Sprite m_sprite;   // Sprite que representa l'enemic a la pantalla
	Vector2f m_position; // Posici� de l'enemic a la pantalla
	float m_speed;      // Velocitat de l'enemic
};