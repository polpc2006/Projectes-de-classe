#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(1000, 1000), "Cíclope");
	window.setFramerateLimit(60);

	//Figura1
	ConvexShape figura1; //Crear variable figura1
	figura1.setPointCount(3); //Fa servir 3 vertexs per la figura
	figura1.setOrigin(25, 25); //Agafa el punt d'origen a les coordenades desitjades
	figura1.setPosition(Vector2f(0, 0)); //Posar la posició a les coordenades desitjades
	figura1.setPoint(0, sf::Vector2f(0, -150)); //Posar la posició del vèrtex1
	figura1.setPoint(1, sf::Vector2f(250, 150));//Posar la posició del vèrtex2
	figura1.setPoint(2, sf::Vector2f(0, 150)); //Posar la posició del vèrtex3
	figura1.rotate(90); //Cambiar la rotació de la figura
	figura1.setFillColor(Color::Blue); //Posar el color Blau
	
	//Figura2
	ConvexShape figura2; //Crear variable figura2
	figura2.setPointCount(3);
	figura2.setOrigin(25, 25);
	figura2.setPosition(Vector2f(1000, 1000));
	figura2.setPoint(0, Vector2f(0, -150));
	figura2.setPoint(1, Vector2f(250, 150));
	figura2.setPoint(2, Vector2f(0, 150));
	figura2.rotate(270);
	figura2.setFillColor(Color::Blue);

	//Figura3
	ConvexShape figura3; //Crear variable figura3
	figura3.setPointCount(3);
	figura3.setOrigin(25, 25);
	figura3.setPosition(Vector2f(0, 1000));
	figura3.setPoint(0, Vector2f(0, -150));
	figura3.setPoint(1, Vector2f(250, 150));
	figura3.setPoint(2, Vector2f(0, 150));
	figura3.setFillColor(Color::Blue);

	//Figura4
	ConvexShape figura4; //Crear variable figura4
	figura4.setPointCount(3);
	figura4.setOrigin(25, 25);
	figura4.setPosition(Vector2f(1000, 0));
	figura4.setPoint(0, Vector2f(0, -150));
	figura4.setPoint(1, Vector2f(250, 150));
	figura4.setPoint(2, Vector2f(0, 150));
	figura4.rotate(180);
	figura4.setFillColor(Color::Blue);

	//Figura 5
	RectangleShape figura5(Vector2f(500, 500)); //Crear variable figura5
	figura5.setOrigin(25, 25);
	figura5.setPosition(Vector2f(550, 200));
	figura5.rotate(45);

	//Figura 6
	RectangleShape figura6(Vector2f(500, 500)); //Crear variable figura6
	figura6.setOrigin(25, 25);
	figura6.setPosition(Vector2f(550, 200));
	figura6.rotate(45);

	//Figura 7
	RectangleShape figura7(Vector2f(150, 150)); //Crear variable figura7
	figura7.setPosition(Vector2f(550, 165));
	
	figura7.setFillColor(Color::Red);

	//Figura 8
	RectangleShape figura8(Vector2f(150, 150)); //Crear variable figura8
	figura8.setPosition(Vector2f(200, 518));
	
	figura8.setFillColor(Color::Cyan);

	//Figura 9
	RectangleShape figura9(Vector2f(150, 150)); //Crear variable figura9
	figura9.setPosition(Vector2f(550, 870));

	figura9.setFillColor(Color::Yellow);

	//Figura 10
	RectangleShape figura10(Vector2f(150, 150)); //Crear variable figura10
	figura10.setPosition(Vector2f(900, 520));

	figura10.setFillColor(Color::Blue);

	//Figura 11
	CircleShape figura11(10); //Crear variable figura11
	figura11.setPosition(Vector2f(500, 400));
	figura11.setRadius(50);
	figura11.setFillColor(Color::Black);

	//Figura 12
	CircleShape figura12(8); //Crear variable figura12
	figura12.setPosition(Vector2f(520, 420));
	figura12.setRadius(30);
	figura12.setFillColor(Color::White);

	//Figura 13
	CircleShape figura13(5); //Crear variable figura13
	figura13.setPosition(Vector2f(540, 440));
	figura13.setRadius(10);
	figura13.setFillColor(Color::Magenta);

	//Figura 14
	RectangleShape figura14(Vector2f(90,5)); //Crear variable figura14
	figura14.setPosition(Vector2f(570, 360));
	figura14.setFillColor(Color::Black);
	figura14.setRotation(45);

	//Figura 15
	RectangleShape figura15(Vector2f(90, 5)); //Crear variable figura15
	figura15.setPosition(Vector2f(480, 420));
	figura15.setFillColor(Color::Black);
	figura15.setRotation(-45);



	while (window.isOpen()) {

		//Mostrar figures
		window.clear(Color::Black);
		window.draw(figura1);
		window.draw(figura2);
		window.draw(figura3);
		window.draw(figura4);
		window.draw(figura5);
		window.draw(figura6);
		window.draw(figura7);
		figura7.rotate(-5); //Rota la figura7 en bucle
		
		window.draw(figura8);
		figura8.rotate(10);

		window.draw(figura9);
		figura9.rotate(-5);

		window.draw(figura10);
		figura10.rotate(10);

		window.draw(figura11);

		window.draw(figura12);

		window.draw(figura13);

		window.draw(figura14);

		window.draw(figura15);
		
		window.display(); //Mostrar la pantalla
	}
	return 0;
}
