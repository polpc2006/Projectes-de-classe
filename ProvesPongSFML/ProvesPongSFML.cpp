#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
    window.setFramerateLimit(60);

    // Pales
    sf::RectangleShape paddle1(sf::Vector2f(10, 100));
    sf::RectangleShape paddle2(sf::Vector2f(10, 100));

    paddle1.setFillColor(sf::Color::Cyan);
    paddle2.setFillColor(sf::Color::Cyan);

    paddle1.setPosition(30, 250); // Pala esquerra
    paddle2.setPosition(760, 250); // Pala dreta

    // Pilota
    sf::CircleShape ball(10);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(395, 295);

    // Velocitat de la pilota
    float ballVelocityX = 0.3f;
    float ballVelocityY = 0.3f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Moviment de les pales
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paddle1.getPosition().y > 0)
            paddle1.move(0, -0.5f); // Moure pala esquerra amunt
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && paddle1.getPosition().y < 600 - paddle1.getSize().y)
            paddle1.move(0, 0.5f); // Moure pala esquerra avall

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle2.getPosition().y > 0)
            paddle2.move(0, -0.5f); // Moure pala dreta amunt
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && paddle2.getPosition().y < 600 - paddle2.getSize().y)
            paddle2.move(0, 0.5f); // Moure pala dreta avall

        // Moviment de la pilota
        ball.move(ballVelocityX, ballVelocityY);

        // Rebote de la pilota
        if (ball.getPosition().y <= 0 || ball.getPosition().y >= 600 - ball.getRadius() * 2)
            ballVelocityY = -ballVelocityY; // Rebota amb la part superior/inferior

        if (ball.getGlobalBounds().intersects(paddle1.getGlobalBounds()) || ball.getGlobalBounds().intersects(paddle2.getGlobalBounds()))
            ballVelocityX = -ballVelocityX; // Rebota amb les pales

        // Renderitzar
        window.clear(sf::Color::Black);
        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(ball);
        window.display();
    }

    return 0;
}
