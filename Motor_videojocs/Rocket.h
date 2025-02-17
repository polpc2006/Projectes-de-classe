#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Rocket
{
public:
	Rocket(); //Constructor coet
	~Rocket(); //Destructor coet
	void init(std::string textureName, Vector2f position, float _speed); // Inicialitza el coet
	void update(float dt); // Actualitza la posició del coet en funció del temps
	Sprite getSprite(); // Retorna el sprite del coet
private:
	Texture m_texture; // Textura del coet
	Sprite m_sprite;   // Sprite associat a la textura
	Vector2f m_position; // Posició del coet
	float m_speed; // Velocitat del coet
};