// Timber.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Animation");
    //Set target Frames per second
    window.setFramerateLimit(60);

    sf::RectangleShape rect(sf::Vector2f(50, 100));
    sf::RectangleShape rect2(sf::Vector2f(50, 100));
    sf::RectangleShape rect3(sf::Vector2f(50, 100));
    sf::RectangleShape rect4(sf::Vector2f(50, 100));

    rect.setFillColor(sf::Color::Cyan);

    rect2.setFillColor(sf::Color::Red);
    rect3.setFillColor(sf::Color::White);
    rect4.setFillColor(sf::Color::Blue);

    rect.setOrigin(sf::Vector2f(-70, 25));

    rect2.setOrigin(sf::Vector2f(200, 25));
    rect3.setOrigin(sf::Vector2f(780, 25));
    rect4.setOrigin(sf::Vector2f(1500, 25));

    rect.setPosition(sf::Vector2f(50, 50));
    
    rect2.setPosition(sf::Vector2f(2000, 500));
    rect3.setPosition(sf::Vector2f(2000, 500));
    rect4.setPosition(sf::Vector2f(2000, 500));

    while (window.isOpen()) 
    {
        /*Handle events here*/

        //SQUARE 1
        //Update frame
        rect.rotate(1.5f);
        rect.move(sf::Vector2f(1, 0));

        //Render frame
        window.clear(sf::Color::Black);
        window.draw(rect);

        //SQUARE 2
        //Update frame
        rect2.rotate(181.5f);
        rect2.move(sf::Vector2f(1, 0));

        //Render frame
        window.draw(rect2);

        //SQUARE 3
        //Update frame
        rect3.rotate(-1344.5f);
        rect3.move(sf::Vector2f(1, 0));

        //Render frame
        window.draw(rect3);

        //SQUARE 4
        //Update frame
        rect4.rotate(-871.5f);
        rect4.move(sf::Vector2f(1, 0));

        //Render frame
        window.draw(rect4);
        window.display();
    }

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
