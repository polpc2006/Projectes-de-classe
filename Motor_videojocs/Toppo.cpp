#include "Toppo.h"



using namespace sf;

Toppo::Toppo() {
    // Inicialitza les variables
    m_speed = 0.0f;
    m_position = Vector2f(0.0f, 0.0f);
}

Toppo::~Toppo() {}

void Toppo::init(string textureName, Vector2f position, float speed) {
    m_position = position;
    m_speed = speed;

    // Carrega la textura
    m_texture.loadFromFile(textureName);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);
}

void Toppo::update(float dt) {
    m_sprite.move(0, m_speed * dt); // Mou cap amunt (Y negativa)
}

Sprite Toppo::getSprite() {
    return m_sprite;
}
