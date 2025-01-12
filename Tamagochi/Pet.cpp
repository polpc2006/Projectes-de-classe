#include "Pet.h"
#include <cstdlib>


using namespace std;

void Pet::getPetName()
{
	cout << "Welcome to your virtual pet, the Tamagochi!!!\n";
	cout << "Now, you have to set the name for your pet.\n";
	cin >> petname;
	cout << "\nYour pet name is " << petname << endl;
}

string Pet::setPetName()
{
	return petname;
}

void Pet::Greet()
{
	cout << "Hi, I am " << petname<<endl;
	Pet::Stats();
	
}

void Pet::Play()
{
	

	int choicegames;
	bool continuegam = true;



	while (continuegam) {
		cout << "We have different games like timber, riddles, test questions, rock paper scissors\n";
		cout << "To play Timber Write 1.\n";
		cout << "To play Riddles Write 2.\n";
		cout << "To play test questions Write 3.\n";
		cout << "To play rock, paper, scissors Write 4.\n";
		cout << "To return to menu. Write 5.\n";
		cin >> choicegames;

		switch (choicegames)
		{
		case 1:
			Timber();
			break;
		case 2:
			Riddles();
			break;
		case 3:
			TestQ();
			break;
		case 4:
			RPS();
			break;
		case 5:
			continuegam = false;
			break;
		default:
			cout << "Incorrect number";
		}
		hunger += 2;
		thirsty += 0;
		boredom -= 3;
		sleepiness += 2;
		cleanliness += 2;
	}
}

void Pet::Timber() {

	srand(time(0)); //Reset random number

	int playerpoints;
	int petpoints = rand() % 501;

	cout << "Lets play timber\n";
	cout << "You first\n";
	cout << "What was your punctuation\n";
	cin >> playerpoints;

	if (playerpoints > petpoints)
	{
		cout << "You win I lose\n";
		boredom = boredom - 3;
		hunger += 2;
		sleepiness += 2;
		cleanliness += 2;
		cout << "\n\n";
		Pet::CheckStats();
	}
	else {
		cout << "I win you lose\n";
		boredom = boredom - 4;
		hunger += 3;
		sleepiness += 1;
		cleanliness += 3;
		cout << "\n\n";
		Pet::CheckStats();
	}
}

void Pet::Riddles() 
{
	string wordplayer = "a";

	cout << "Adivinanza 1:\n";

	cout << "\tCuanto mas quitas, mas grande se vuelve. ¿Que es?\n";
	cin >> wordplayer;
	if (wordplayer == "agujero" || wordplayer == "Agujero") {
		cout << "Correcto\n\n";
	}
	else {
		cout << "Erronio\n\n";
	}
		//Respuesta : Un agujero.
	cout << "Adivinanza 2 :\n";

	cout << "\tTengo ciudades, pero no casas; montanas, pero no arboles; rios, pero no agua. ¿Que soy?\n";
	cin >> wordplayer;
	if (wordplayer == "mapa" || wordplayer == "Mapa") {
		cout << "Correcto\n\n";
	}
	else {
		cout << "Erronio\n\n";
	}
	//Respuesta : Un mapa.
	cout << "Adivinanza 3 :\n";

	cout << "\tVuelo sin alas, lloro sin ojos. Siempre que voy, la oscuridad se alza. ¿Que soy?\n";
	cin >> wordplayer;
	if (wordplayer == "nube" || wordplayer == "Nube") {
		cout << "Correcto\n\n";
	}
	else {
		cout << "Erronio\n\n";
	}
	//Respuesta : Una nube.
	cout << "Adivinanza 4 :\n";

	cout << "\tMientras mas seco, mas mojado. ¿Que es?\n";
	cin >> wordplayer;
	if (wordplayer == "toalla" || wordplayer == "Toalla") {
		cout << "Correcto\n\n";
	}
	else {
		cout << "Erronio\n\n";
	}
	//Respuesta : Una toalla.
	cout << "Adivinanza 5 :\n";

	cout << "\tSi me nombras, desaparezco. ¿Que soy?\n";
	cin >> wordplayer;
	if (wordplayer == "silencio" || wordplayer == "Silencio") {
		cout << "Correcto\n\n";
	}
	else {
		cout << "Erronio\n\n";
	}
	//Respuesta : El silencio.
}

void Pet::TestQ() 
{
	int typetest;
	char letterplayer = 'a';
	bool resetgame = true;

	cout << "What test do you want to do\n";
	cout << "Videogames type Write 1\n";
	cout << "Music type Write 2\n";
	cout << "Language type Write 3\n";
	cin >> typetest;

	while (resetgame) {


		switch (typetest) {
		case 1:
			//VIDEOJUEGOS
			cout << "Videojuegos\n";
			cout << "\t¿Cual es el nombre del personaje principal en The Legend of Zelda ?\n";

			cout << "\t\tA) Link\n";
			cout << "\t\tB) Zelda\n";
			cout << "\t\tC) Ganondorf\n";
			cout << "\t\tD) Navi\n";
			cin >> letterplayer;

			if (letterplayer == 'A' || letterplayer == 'a') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}

			//	Respuesta : A) Link
			cout << "\t¿En que ano se lanzo el primer videojuego de Super Mario Bros ?\n";

			cout << "\t\tA) 1983\n";
			cout << "\t\tB) 1985\n";
			cout << "\t\tC) 1987\n";
			cout << "\t\tD) 1990\n";
			cin >> letterplayer;

			if (letterplayer == 'B' || letterplayer == 'b') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}

			//Respuesta: B) 1985
			cout << "\t¿Cual es el nombre de la consola portatil de Nintendo lanzada en 1989 ?\n";

			cout << "\t\tA) Game Boy\n";
			cout << "\t\tB) PSP\n";
			cout << "\t\tC) Nintendo DS\n";
			cout << "\t\tD) Game Gear\n";
			cin >> letterplayer;

			if (letterplayer == 'A' || letterplayer == 'a') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}

			//Respuesta : A) Game Boy
			cout << "\t¿Que tipo de juego es Fortnite ?\n";

			cout << "\t\tA) RPG\n";
			cout << "\t\tB) Battle Royale\n";
			cout << "\t\tC) MOBA\n";
			cout << "\t\tD) RTS\n";
			cin >> letterplayer;

			if (letterplayer == 'B' || letterplayer == 'b') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}
			//Respuesta : B) Battle Royale
			cout << "\t¿Cual es el nombre del estudio que desarrollo The Witcher 3 ?\n";

			cout << "\t\tA) Bethesda\n";
			cout << "\t\tB) CD Projekt Red\n";
			cout << "\t\tC) BioWare\n";
			cout << "\t\tD) Ubisoft\n";
			cin >> letterplayer;

			if (letterplayer == 'B' || letterplayer == 'b') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}
			//Respuesta : B) CD Projekt Red
			resetgame = false;
			break;
		case 2:
			//MUSICA
			cout << "Musica\n";
			cout << "\t¿Quien es conocido como el Rey del Pop?\n";

			cout << "\t\tA) Elvis Presley\n";
			cout << "\t\tB) Michael Jackson\n";
			cout << "\t\tC) Prince\n";
			cout << "\t\tD) Freddie Mercury\n";
			cin >> letterplayer;

			if (letterplayer == 'B' || letterplayer == 'b') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}

			//	Respuesta : B) Michael Jackson
			cout << "\t¿Cual es el instrumento principal de un pianista?\n";

			cout << "\t\tA) Violin\n";
			cout << "\t\tB) Guitarra\n";
			cout << "\t\tC) Piano\n";
			cout << "\t\tD) Flauta\n";
			cin >> letterplayer;

			if (letterplayer == 'C' || letterplayer == 'c') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}

			//Respuesta: C) Piano
			cout << "\t¿Cual de las siguientes bandas es britanica?\n";

			cout << "\t\tA) Metallica\n";
			cout << "\t\tB) U2\n";
			cout << "\t\tC) The Beatles\n";
			cout << "\t\tD) Nirvana\n";
			cin >> letterplayer;

			if (letterplayer == 'C' || letterplayer == 'c') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}

			//Respuesta : C) The Beatles
			cout << "\t¿Que artista lanzó el album Thriller en 1982?\n";

			cout << "\t\tA) Madonna\n";
			cout << "\t\tB) Michael Jackson\n";
			cout << "\t\tC) Whitney Houston\n";
			cout << "\t\tD) Prince\n";
			cin >> letterplayer;

			if (letterplayer == 'B' || letterplayer == 'b') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}
			//Respuesta : B) Michael Jackson
			cout << "\t¿Que genero musical es conocido por el uso de improvisacion?\n";

			cout << "\t\tA) Rock\n";
			cout << "\t\tB) Jazz\n";
			cout << "\t\tC) Pop\n";
			cout << "\t\tD) Clasica\n";
			cin >> letterplayer;

			if (letterplayer == 'B' || letterplayer == 'b') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}
			//Respuesta : B) Jazz
			resetgame = false;
			break;
		case 3:
			//LENGUA
			cout << "Lengua\n";
			cout << "\t¿Que es un sustantivo?\n";

			cout << "\t\tA) Una accion\n";
			cout << "\t\tB) Un lugar\n";
			cout << "\t\tC) Un nombre\n";
			cout << "\t\tD) Un adjetivo\n";
			cin >> letterplayer;

			if (letterplayer == 'C' || letterplayer == 'c') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}

			//	Respuesta : C) Un nombre
			cout << "\t¿Cual es el sinonimo de rapido?\n";

			cout << "\t\tA) Lento\n";
			cout << "\t\tB) Veloz\n";
			cout << "\t\tC) Fuerte\n";
			cout << "\t\tD) Alto\n";
			cin >> letterplayer;

			if (letterplayer == 'B' || letterplayer == 'b') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}

			//Respuesta: B) Veloz
			cout << "\t¿Que tipo de palabra es bellamente?\n";

			cout << "\t\tA) Adjetivo\n";
			cout << "\t\tB) Sustantivo\n";
			cout << "\t\tC) Verbo\n";
			cout << "\t\tD) Adverbio\n";
			cin >> letterplayer;

			if (letterplayer == 'D' || letterplayer == 'd') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}

			//Respuesta : D) Adverbio
			cout << "\t¿Cual es el antonimo de feliz?\n";

			cout << "\t\tA) Triste\n";
			cout << "\t\tB) Alegre\n";
			cout << "\t\tC) Contento\n";
			cout << "\t\tD) Satisfecho\n";
			cin >> letterplayer;

			if (letterplayer == 'A' || letterplayer == 'a') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}
			//Respuesta : A) Triste
			cout << "\t¿Que signo de puntuacion se usa al final de una pregunta?\n";

			cout << "\t\tA) Punto\n";
			cout << "\t\tB) Coma\n";
			cout << "\t\tC) Signo de interrogacion\n";
			cout << "\t\tD) Signo de exclamacion\n";
			cin >> letterplayer;

			if (letterplayer == 'C' || letterplayer == 'c') {
				cout << "Correcte\n\n";
			}
			else {
				cout << "Erroni\n\n";
			}
			//Respuesta : C) Signo de interrogación
			resetgame = false;
			break;
		default:
			cout << "Type 1, 2 or 3";
			resetgame = true;
			break;
		}
	}
}

void Pet::RPS() {

	for (int i = 0; i < 3; ++i) {

		string playerChoice;

		cout << "Welcome to rock, paper, scissors\n";

		cout << "No you have to take 1 of those rock paper or scissors\n";
		cout << "To take rock. Type ROCK\n";
		cout << "To take paper. Type PAPER\n";
		cout << "To take scissors. Type SCISSORS\n";
		cin >> playerChoice;

		srand(time(0));

		string options[] = { "PAPER", "ROCK", "SCISSORS" };
		int randomIndex = rand() % 3;
		string machineChoice = options[randomIndex];

		while (playerChoice != "PAPER" && playerChoice != "ROCK" && playerChoice != "SCISSORS") {
			cout << "Invalid choice. Please enter PAPER, ROCK, or SCISSORS: ";
			cin >> playerChoice;
		}

		if (playerChoice == machineChoice) {
			cout << "It's a tie!" << endl;
		}
		else if ((playerChoice == "PAPER" && machineChoice == "ROCK") ||
			(playerChoice == "ROCK" && machineChoice == "SCISSORS") ||
			(playerChoice == "SCISSORS" && machineChoice == "PAPER")) {
			cout << "You win!" << endl;
		}
		else {
			cout << "The machine wins!" << endl;
		}
	}

}

void Pet::Talk()
{
	srand(time(0)); //Reset random number
	
	valrand = rand() % 10;

	switch (valrand) {
	case 0:
		cout << "Do you know that dogs can smell diseases in humans.\n";
		break;
	case 1:
		cout << "Do you know that fleas can jump up to 350 times the length of their body.\n";
		break;
	case 2:
		cout << "Do you know that a hummingbird's heart beats up to 1,200 times per minute.\n";
		break;
	case 3:
		cout << "Do you know that octopuses have three hearts. Two pump blood to the gills, and the third to the rest of the body.\n";
		break;
	case 4:
		cout << "Do you know that Giraffes only sleep about 30 minutes a day. They do it in small intervals of 5 minutes.\n";
		break;
	case 5:
		cout << "Do you know that The heart of a blue whale is as large as a small car. Its beats can be heard more than 3 kilometers away.\n";
		break;
	case 6:
		cout << "Do you know that Crocodiles can't stick out their tongues. Their tongues are attached to the bottom of their mouths to prevent them from sticking out when hunting.\n";
		break;
	case 7:
		cout << "Do you know that Butterflies have taste sensors on their feet. This allows them to taste the leaves they land on to decide if they are suitable for laying eggs.\n";
		break;
	case 8:
		cout << "Do you know that Koalas have fingerprints almost identical to humans. So similar that they can even confuse crime scene experts.\n";
		break;
	case 9:
		cout << "Do you know that Starfish have neither brains nor blood. Instead, they pump seawater through their bodies to move nutrients.\n";
		break;
	default:
		cout << "Invalid number.\n";
		break;
	}

	cout << "Thank your for the nice talk we had\n";
	cout << "\n\n";
	boredom = boredom - 2;
	sleepiness += 3;
	thirsty += 2;
	Pet::CheckStats();
}

void Pet::Stats() 
{
	cout << "My stats are:\n";
	cout << "Hunger level: " << hunger << endl;
	cout << "Thirsty level: " << thirsty << endl;
	cout << "Boredom level: " << boredom << endl;
	cout << "Sleepiness level: " << sleepiness << endl;
	cout << "Cleaninless level: " << cleanliness << endl;
	cout << "##########################\n\n";
	Pet::CheckStats();
}

void Pet::Eat()
{
	cout << "Um, the food was delicious.\n";
	hunger = hunger - 5;
	sleepiness += 2;
	boredom += 2;
	thirsty += 1;
	Pet::CheckStats();
	cout << "Now my hunger value is " << hunger<<endl<<endl;
	
}

void Pet::Sleep()
{
	cout << "I am so tired\n";
	cout << "zzzz\nzzzz\nzzzz\nzzzz\nzzzz\nzzzz\nzzzz\nzzzz\nzzzz\nzzzz\nzzzz\nzzzz\nzzzz\n";
	cout << "8 hours later..........\n";
	sleepiness = sleepiness - 5;
	boredom += 2;
	hunger += 2;
	cleanliness += 1;
	Pet::CheckStats();
	cout << "Nom my sleepiness value is " << sleepiness << endl << endl;
	
}

void Pet::takeShower()
{
	cout << "I am so dirty\n";
	cout << "I go to take a shower\n";
	cout << "10 minutes later...\n";
	cout << "Now I am cleaner\n";
	cleanliness = cleanliness - 3;
	hunger += 1;
	thirsty += 1;
	boredom += 2;
	sleepiness += 2;
	Pet::CheckStats();
	cout << "Nom my cleanliness value is " << cleanliness << endl << endl;
}

void Pet::Drink()
{
	cout << "Ohh, I was so thirsty.\n";
	thirsty = thirsty - 3;
	hunger += 1;
	boredom += 1;
	sleepiness += 1;
	Pet::CheckStats();
	cout << "Nom my thirsty value is " << thirsty << endl<<endl;
	
}

void Pet::ListenMusic() 
{

}

void Pet::CheckStats() 
{
	//HUNGER
	if (hunger < 0) {hunger = 0;}
	else if (hunger > 10) {hunger = 10;}
	//THIRSTY
	if (thirsty < 0) {thirsty = 0;}
	else if (thirsty > 10) {thirsty = 10;}
	//BOREDOM
	if (boredom < 0) {boredom = 0;}
	else if (boredom > 10) {boredom = 10;}
	//SLEEPINESS
	if (sleepiness < 0) {sleepiness = 0;}
	else if (sleepiness > 10) {sleepiness = 10;}
	//CLEANINLESS
	if (cleanliness < 0) {cleanliness = 0;}
	else if (cleanliness > 10) {cleanliness = 10;}
}