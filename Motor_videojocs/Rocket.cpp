#include "Rocket.h"

using namespace sf;

Rocket::Rocket() {
    // Inicialitza les variables predeterminades
    m_speed = 0.0f;
    m_position = Vector2f(0.0f, 0.0f);
}

Rocket::~Rocket() {
   
}

void Rocket::init(std::string textureName, Vector2f position, float _speed) {
    m_position = position;
    m_speed = _speed;
    // Carrega la textura del coet
    if (!m_texture.loadFromFile(textureName)) {
        // Gestiona l'error si la textura no es pot carregar
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);
}

void Rocket::update(float dt) {
    // Mou el coet cap a la dreta segons la seva velocitat
    m_sprite.move(m_speed * dt, 0); 
}

Sprite Rocket::getSprite() {
    return m_sprite; // Retorna el sprite del coet
}
