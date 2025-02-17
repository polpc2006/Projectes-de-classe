#pragma once
#include "SFML/Graphics.hpp" 

using namespace std; 
using namespace sf;  

// Definici� de la classe Hero (Heroi)
class Hero {
public:
    // Constructor de la classe Hero
    Hero();
    // Destructor de la classe Hero
    ~Hero();
    // M�tode per inicialitzar l'heroi amb textura, posici� i massa
    void init(string textureName, Vector2f position, float mass);
    // M�tode per actualitzar l'heroi
    void update(float dt);
    // M�tode per fer que l'heroi salti amb una velocitat determinada
    void jump(float velocity);
    // M�tode per moure l'heroi cap a l'esquerra
    void moveLeft(float dt);
    // M�tode per moure l'heroi cap a la dreta
    void moveRight(float dt);
    // M�tode per obtenir el sprite de l'heroi
    Sprite getSprite();
    // Getter per obtenir el text del nom de l'heroi
    Text getNameText() const { return m_nameText; }
private:
    Texture m_texture; // Variable per emmagatzemar la textura de l'heroi
    Sprite m_sprite;   // Sprite que representa l'heroi a la pantalla
    Vector2f m_position; // Posici� de l'heroi a la pantalla
    int jumpCount = 0;    // Comptador per controlar el nombre de salts
    float m_mass;         // Massa de l'heroi
    float m_velocity;     // Velocitat de l'heroi
    const float m_gravity = 9.80f; // Constanta de gravetat
    bool m_grounded;      // Variable per saber si l'heroi est� a terra
    int m_force;          // For�a per calcular el salt i el moviment

    // Text de l'heroi
    Font m_font;          // Per carregar la font
    Text m_nameText;      // El text que es mostrar� sobre el personatge (nom de l'heroi)
};
