#include "Enemy.h"

// Constructor de la classe Enemy
Enemy::Enemy() {
    // Aqu� pots inicialitzar les variables de la classe si cal
    m_speed = 0.0f;
    m_position = Vector2f(0.0f, 0.0f);
}
// Destructor de la classe Enemy
Enemy::~Enemy() {
}

// M�tode per inicialitzar l'enemic amb textura, posici� i velocitat
void Enemy::init(string textureName, Vector2f position, float _speed) {
    m_position = position;
    m_speed = _speed;
    // Carregar textura
    if (!m_texture.loadFromFile(textureName)) {
        // Gesti� d'errors si la textura no es carrega
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);
}
// M�tode per actualitzar la posici� de l'enemic
void Enemy::update(float dt) {
    m_position.x += m_speed * dt;
    m_sprite.setPosition(m_position);
}
// M�tode per obtenir el sprite de l'enemic
Sprite Enemy::getSprite() {
    return m_sprite;
}
