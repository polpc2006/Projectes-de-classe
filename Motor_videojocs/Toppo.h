#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Toppo {
public:
    Toppo(); //Constructor de la classe Toppo
    ~Toppo(); //Destructor de la classe Toppo
    void init(string textureName, Vector2f position, float _speed); // Inicialitza la textura, posici� i velocitat
    void update(float dt); // Actualitza la posici� en funci� del temps
    Sprite getSprite(); // Retorna el sprite per a la representaci� gr�fica
private:
    Texture m_texture; // Textura del personatge
    Sprite m_sprite;   // Sprite associat a la textura
    Vector2f m_position; // Posici� del personatge
    float m_speed; // Velocitat de moviment
};
