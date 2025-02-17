#include "Hero.h"

Hero::Hero() {
	// Inicializa las variables del héroe, si es necesario
	m_position = Vector2f(0.0f, 0.0f); // Posiciò per defecte
	m_mass = 1.0f; // Massa predeterminada
	m_velocity = 0.0f; // Velocitat inicial
	m_grounded = false; // Inicialment no està en el terra
	m_force = 0; // Força inicial
	jumpCount = 0; // Sense salts al inici
}

Hero::~Hero() {
}

void Hero::init(std::string textureName, sf::Vector2f position, float mass) {
	m_position = position;
	m_mass = mass;
	m_grounded = false;
	m_velocity = 0;
	// Carrega la font per al text del nom
	m_font.loadFromFile("FONTS/fonttext_motor_en_Black.ttf");
	m_nameText.setFont(m_font);
	m_nameText.setString("Liam");
	m_nameText.setCharacterSize(30);
	m_nameText.setFillColor(Color(0, 128, 0));
	// Posicionar el texto encima del personaje
	m_nameText.setPosition(m_position.x - m_nameText.getLocalBounds().width / 2, m_position.y - m_texture.getSize().y / 2 );
	// Carrega la textura i crea el sprite
	m_texture.loadFromFile(textureName.c_str());
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_texture.getSize().x / 2,
	m_texture.getSize().y / 2);
}

void Hero::update(float dt) {
	m_velocity -= m_mass * m_gravity * dt;
	m_position.y -= m_velocity * dt;
	m_sprite.setPosition(m_position);
	if (m_position.y >= 768 * 0.75f) {
		m_position.y = 768 * 0.75f;
		m_velocity = 0;
		m_grounded = true;
		jumpCount = 0;
	}
	// Actualitza la posició del text per mantenir-lo sobre l'heroi
	m_nameText.setPosition(m_position.x - m_nameText.getLocalBounds().width / 2, m_position.y - m_texture.getSize().y / 2 - 20);}

void Hero::jump(float velocity)
{
	if (jumpCount < 2) {
		jumpCount++;
		m_velocity = velocity;
		m_grounded = false;

	}
}

void Hero::moveLeft(float dt) {
	m_position.x -= 250 * dt; // Mou cap a l'esquerra
}
void Hero::moveRight(float dt) {

	m_position.x += 250 * dt; // Mou cap a la dreta
}

Sprite Hero::getSprite() { return m_sprite; } // Retorna el sprite de l'heroi