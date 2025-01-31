#include "Pet.h"
#include "Farm.h"
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>


using namespace std;
using namespace sf;

Pet::Pet(int gana, int aborriment, int neteja, int son, int sed)
{
	// Assignació dels paràmetres als atributs de la classe
	hunger = gana;
	thirsty = sed;
	boredom = aborriment;
	sleepiness = son;
	cleanliness = neteja;
}

// Funció per establir el nom de la mascota
void Pet::setPetName(string newName) {
	petname = newName;
}

// Funció retornar el nom
string Pet::getpetName() const {
	return petname;
}

void Pet::maincode() {
	
	Farm myFarm; // Creem un objecte de la classe Farm, que representarà la granja
	
	cout << "Welcome to your virtual pet, the Tamagochi!!!\n"; // Mostra un missatge de benvinguda al jugador

	//Demana el nom de les mascotes predeterminades i les afegeix
	cout << "Set the name for your Hen\n";
	myFarm.AddPet();
	cout << "Set the name for your Pig\n";
	myFarm.AddPet();
	cout << "Set the name for your Cow\n";
	myFarm.AddPet();

	vector<Pet>& pets = myFarm.GetPets(); //Agafem la referència 

	int petnumber; //Guardar el número de la mascota seleccionada

	//Demana a l'usuari el que vol seleccionar
	cout << "Now, which pet do you want to pick.\n";
	cout << "If you want a Hen. Write 0\n";
	cout << "If you want a Pig. Write 1\n";
	cout << "If you want a Cow. Write 2\n";
	cin >> petnumber;
	
	pets[petnumber].getpetName(); // Obtenció del nom de la mascota seleccionada

	//Variables menu i bucles
	int choice;
	bool menu = true;
	bool opmascotes = true;

	// Mostrar la mascota segons la que l'usuari ha seleccionat
	switch (petnumber) {
	case 0:
		pets[petnumber].showHen();
		break;
	case 1:
		pets[petnumber].showPig();
		break;
	case 2:
		pets[petnumber].showCow();
		break;
	}
	//La mascota saluda i agafa el nom introduit anteriorment
	String name;
	name = pets[petnumber].getpetName();
	pets[petnumber].Greet(name);

	// Bucle principal per al menú d'interacció amb la mascota
	while (menu)
	{
		int hours;

		cout << "Now what do you want to do?\n\n";
		cout << "Do you want to play with " << pets[petnumber].getpetName() << endl;
		cout << "Write 1\n";
		cout << "Do you want to feed " << pets[petnumber].getpetName() << endl;
		cout << "Write 2\n";
		cout << "Do you want to give " << pets[petnumber].getpetName() << " water\n";
		cout << "Write 3\n";
		cout << "Do you want to listen " << pets[petnumber].getpetName() << "\n";
		cout << "Write 4\n";
		cout << "Do you want to take " << pets[petnumber].getpetName() << " a shower\n";
		cout << "Write 5\n";
		cout << "Do you want " << pets[petnumber].getpetName() << " to sleep\n";
		cout << "Write 6\n";
		cout << "Do you want to see " << pets[petnumber].getpetName() << " stats\n";
		cout << "Write 7\n";
		cout << "Do you want to listen to music\n";
		cout << "Write 8\n";
		cout << "Do you want to Modify your creature\n";
		cout << "Write 9\n";
		cout << "Do you want to leave\n";
		cout << "Write 10\n";
		cin >> choice;
		cout << "\n\n";

		// Comprovació si l'elecció és vàlida (1 a 10)
		if (choice < 11 && choice>0)
		{
			switch (choice)
			{
			case 1:
				pets[petnumber].Play(); //Jugar amb mascota
				break;
			case 2:
				pets[petnumber].Eat(); //Alimentar mascota
				break;
			case 3:
				pets[petnumber].Drink(); //Donar aigua a la mascota
				break;
			case 4:
				pets[petnumber].Talk(); //Parlar amb la mascota
				break;
			case 5:
				pets[petnumber].takeShower(); //Dutxar a la mascota
				break;
			case 6:
				pets[petnumber].Sleep(); //Dormir a la mascota
				break;
			case 7:
				pets[petnumber].Stats(); //Mostrar Estadístiques
				break;
			case 8:
				pets[petnumber].ListenMusic(); //Escoltar música
				break;
			case 9:
				// Gestió de les mascotes (afegir, llistar o seleccionar)
				opmascotes = true;
				while (opmascotes) {
					cout << "Do you want to add a creature\n Write 1\n";
					cout << "Do you want to list your creatures\n Write 2\n";
					cout << "Do you want to select your creatures\n Write 3\n";
					int petchoice;
					cin >> petchoice;

					switch (petchoice) {
						case 1:
							// Afegir una nova mascota cridant a la funció AddPets de la granja
							myFarm.AddPet();

							// Mostrar totes les mascotes afegides
							for (int i = 0; i < pets.size(); i++) {
								cout << i << ": " <<pets[i].getpetName() << "\n";
							}

							cout << "Now, which pet do you want to pick.\n";
							opmascotes = false;
							// Validar que el número de mascota sigui correcte
							cin >> petnumber;
							
							break;
						case 2:
							// Mostrar totes les mascotes afegides
							myFarm.ListPets();
							opmascotes = false;
							break;
						case 3:
							//Select mascotes
							myFarm.ListPets();
							cout << "Now, which pet do you want to pick.\n";
							cin >> petnumber;
							opmascotes = false;
							break;
						default:
							cout << "Invalid choice. Please choose a valid option.\n";
							break;
					}
				}
				break;
			case 10:
				cout << "Bye, see you another time\n";
				menu = false;
			}
		}
	}
}

// Funció Saludar
void Pet::Greet(string name)
{
	cout << "Hi, I am " << name <<endl;
	Pet::Stats();
}

//Jugar amb l'usuari cridant als jocs i canviar les estadístiques
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
			hunger += 2;
			thirsty += 0;
			boredom -= 3;
			sleepiness += 2;
			cleanliness += 2;
			timeh += 2;
			break;
		case 2:
			Riddles();
			hunger += 2;
			thirsty += 0;
			boredom -= 3;
			sleepiness += 2;
			cleanliness += 2;
			timeh += 2;
			break;
		case 3:
			TestQ();
			hunger += 2;
			thirsty += 0;
			boredom -= 3;
			sleepiness += 2;
			cleanliness += 2;
			timeh += 2;
			break;
		case 4:
			RPS();
			hunger += 2;
			thirsty += 0;
			boredom -= 3;
			sleepiness += 2;
			cleanliness += 2;
			timeh += 2;
			break;
		case 5:
			continuegam = false;
			break;
		default:
			cout << "Incorrect number";
		}
		
		Pet::CheckStats();
		cout << "2 hours have passed\n";
		Pet::Time(timeh);
	}
}

//Jocs
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

// Parlar amb mascota
void Pet::Talk()
{
	srand(time(0)); //Reset random number
	
	valrand = rand() % 10; //Agafar un valor aleatori del 0 al 9

	//Menú segons el valor aleatori
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
	timem += 15;
	cout << "15 minutes have passed\n";
	cout << "Thank your for the nice talk we had\n";
	cout << "\n\n";
	boredom = boredom - 2;
	sleepiness += 3;
	thirsty += 2;
	Pet::CheckStats();
}

// Mostrar estadístiques
void Pet::Stats() 
{
	Pet::ConvertTime(); //Convertir el temps
	Pet::CheckStats(); //Comprovar estadístiques per mantenir-les entre 0 i 10
	cout << "My stats are:\n";
	cout << "Hunger level: " << hunger << endl;
	cout << "Thirsty level: " << thirsty << endl;
	cout << "Boredom level: " << boredom << endl;
	cout << "Sleepiness level: " << sleepiness << endl;
	cout << "Cleaninless level: " << cleanliness << endl;
	cout << "Han passat: " << timed << " dies " << timeh << " hores i " << timem << " minuts" << endl;
	cout << "##########################\n\n";
}

//Funció menjar
void Pet::Eat()
{
	cout << "Um, the food was delicious.\n";
	hunger = hunger - 5;
	sleepiness += 2;
	boredom += 2;
	thirsty += 1;
	Pet::CheckStats();
	timem += 30;
	cout << "30 minutes have passed\n";
	cout << "Now my hunger value is " << hunger<<endl<<endl;
	
}

//Funció dormir
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
	timeh += 8;
	cout << "8 hours have passed\n";
	cout << "Now my sleepiness value is " << sleepiness << endl << endl;
}

//Funció dutxar-se
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
	timem += 30;
	cout << "30 minutes have passed\n";
	cout << "Now my cleanliness value is " << cleanliness << endl << endl;
}

//Funció beure
void Pet::Drink()
{
	cout << "Ohh, I was so thirsty.\n";
	thirsty = thirsty - 3;
	hunger += 1;
	boredom += 1;
	sleepiness += 1;
	Pet::CheckStats();
	timem += 6;
	cout << "6 minutes have passed\n";
	cout << "Now my thirsty value is " << thirsty << endl<<endl;
}

//Funció escoltar música
void Pet::ListenMusic()
{
	//POP
	SoundBuffer musicpopAdele; // Crear un objecte SoundBuffer
	musicpopAdele.loadFromFile("./MUSIC/Adele_RollingintheDeep.wav"); // Carregar el fitxer de so
	Sound popAdele; // Crear un objecte Sound
	popAdele.setBuffer(musicpopAdele); // Assignar el SoundBuffer a l'objecte Sound


	SoundBuffer musicpopWeekend;
	musicpopWeekend.loadFromFile("./MUSIC/TheWeeknd_BlindingLights.wav");
	Sound popWeekend;
	popWeekend.setBuffer(musicpopWeekend);


	SoundBuffer musicpopBruno;
	musicpopBruno.loadFromFile("./MUSIC/BrunoMars_Uptown Funk.wav");
	Sound popBruno;
	popBruno.setBuffer(musicpopBruno);

	//ROCK
	SoundBuffer musicrockQueen;
	musicrockQueen.loadFromFile("./MUSIC/Queen_BohemianRhapsody.wav");
	Sound rockQueen;
	rockQueen.setBuffer(musicrockQueen);

	SoundBuffer musicrockACDC;
	musicrockACDC.loadFromFile("./MUSIC/ACDC_HighwaytoHell.wav");
	Sound rockACDC;
	rockACDC.setBuffer(musicrockACDC);

	SoundBuffer musicrockLP;
	musicrockLP.loadFromFile("./MUSIC/LinkinPark_IntheEnd.wav");
	Sound rockLP;
	rockLP.setBuffer(musicrockLP);

	//METAL
	SoundBuffer musicmetalAV;
	musicmetalAV.loadFromFile("./MUSIC/avenged.wav");
	Sound metalAV;
	metalAV.setBuffer(musicmetalAV);

	SoundBuffer musicmetalAC;
	musicmetalAC.loadFromFile("./MUSIC/accept.wav");
	Sound metalAC;
	metalAC.setBuffer(musicmetalAC);

	SoundBuffer musicmetalNP;
	musicmetalNP.loadFromFile("./MUSIC/napalm.wav");
	Sound metalNP;
	metalNP.setBuffer(musicmetalNP);

	//JAZZ
	SoundBuffer musicjazzDB;
	musicjazzDB.loadFromFile("./MUSIC/TakeFive_DaveBrubeck.wav");
	Sound jazzDB;
	jazzDB.setBuffer(musicjazzDB);

	SoundBuffer musicjazzBB;
	musicjazzBB.loadFromFile("./MUSIC/TheBluesBrothers.wav");
	Sound jazzBB;
	jazzBB.setBuffer(musicjazzBB);

	SoundBuffer musicjazzCh;
	musicjazzCh.loadFromFile("./MUSIC/AllThatJazz.wav");
	Sound jazzCh;
	jazzCh.setBuffer(musicjazzCh);

	//CLASSIC MUSIC
	SoundBuffer musicclassicB;
	musicclassicB.loadFromFile("./MUSIC/5taSinfonía_Beethoven.wav");
	Sound classicB;
	classicB.setBuffer(musicclassicB);

	SoundBuffer musicclassicMoz;
	musicclassicMoz.loadFromFile("./MUSIC/Mozart_SerenadeN13.wav");
	Sound classicMoz;
	classicMoz.setBuffer(musicclassicMoz);

	SoundBuffer musicclassicLC;
	musicclassicLC.loadFromFile("./MUSIC/El_LagoCisnes.wav");
	Sound classicLC;
	classicLC.setBuffer(musicclassicLC);

	//REGGAETON
	SoundBuffer musicgasolina;
	musicgasolina.loadFromFile("./MUSIC/Gasolina.wav");
	Sound RGgasolina;
	RGgasolina.setBuffer(musicgasolina);

	SoundBuffer musicrgDK;
	musicrgDK.loadFromFile("./MUSIC/BadBunny_DAKITI.wav");
	Sound rgDK;
	rgDK.setBuffer(musicrgDK);

	SoundBuffer musicrgM4;
	musicrgM4.loadFromFile("./MUSIC/Maluma_Feliceslos4.wav");
	Sound rgM4;
	rgM4.setBuffer(musicrgM4);

	int musicchoice;
	int songchoice;
	bool musictype = true;
	bool musicsong = true;

	//Menú per seleccionar genere musical
	while (musictype) {
		cout << "What type of music what do you want to listen\n";
		cout << "POP. Write 1\n";
		cout << "ROCK. Write 2\n";
		cout << "METAL. Write 3\n";
		cout << "JAZZ. Write 4\n";
		cout << "Classic Music. Write 5\n";
		cout << "Reggaeton. Write 6\n";
		cout << "Return to menu. Write 7\n";
		cin >> musicchoice;

		//Menú POP
		switch (musicchoice) {
		case 1:
			musicsong = true;
			while (musicsong) {

				cout << "Which song do you want to listen?\n";
				cout << "Rolling in the Deep - Adele. Write 1\n";
				cout << "Uptown Funk - Bruno Mars. Write 2\n";
				cout << "Blinding Lights - The Weekend. Write 3\n";
				cout << "To return to menu type. Write 4\n";
				cin >> songchoice;

				switch (songchoice) {
				case 1:
					//POP
					/*Rolling in the Deep, Blinding Lights, Uptown Funk*/
					popAdele.play(); //Iniciar música

					while (popAdele.getStatus() == Sound::Playing && songchoice == 1) {  //Comprovar si songchoice no és 1
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 1) {
							popAdele.stop(); //Parar música
						}
					}
					break;
				case 2:
					popBruno.play(); 

					while (popBruno.getStatus() == Sound::Playing && songchoice == 2) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 2) {
							popBruno.stop(); 
						}
					}
					break;
				case 3:
					popWeekend.play(); 

					while (popWeekend.getStatus() == Sound::Playing && songchoice == 3) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 3) {
							popWeekend.stop();
						}
					}
				case 4:
					cout << "Return to menu type\n\n";
					musicsong = false;
					break;
				default:
					cout << "Write 1, 2, 3 or 4\n\n";
					break;
				}
			}
			break;
		case 2:
			//ROCK
				/*Bohemian Rhapsody, Highway to Hell,In the End*/
			musicsong = true;

			//Menú ROCK
			while (musicsong) {

				cout << "\nWhich song do you want to listen?\n";
				cout << "Bohemian Rhapsody - Queen. Write 1\n";
				cout << "Highway to Hell - AC DC. Write 2\n";
				cout << "In the End - Linkin Park. Write 3\n";
				cout << "To return to menu type. Write 4\n";
				cin >> songchoice;

				switch (songchoice) {
				case 1:

					rockQueen.play(); //Iniciar música

					while (rockQueen.getStatus() == Sound::Playing && songchoice == 1) { //Comprovar songchoice no es 1
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 1) {
							rockQueen.stop(); //Parar música
						}
					}
					break;
				case 2:
					rockACDC.play();

					while (rockACDC.getStatus() == Sound::Playing && songchoice == 2) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 2) {
							rockACDC.stop();
						}
					}
					break;
				case 3:
					rockLP.play();

					while (rockLP.getStatus() == Sound::Playing && songchoice == 3) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 3) {
							rockLP.stop();
						}
					}
				case 4:
					cout << "Return to menu type\n\n";
					musicsong = false;
					break;
				default:
					cout << "Write 1, 2 or 3\n\n";
					break;
				}
			}
			break;
		case 3:
			//METAL
			/*Avenged, Accept, Napalm*/
			musicsong = true;
			while (musicsong) {
				cout << "\nWhich song do you want to listen?\n";
				cout << "Avenged - Mitj. Write 1\n";
				cout << "Accept - Tranquil. Write 2\n";
				cout << "Napalm - Fort. Write 3\n";
				cout << "To return to menu type. Write 4\n";
				cin >> songchoice;

				switch (songchoice) {
				case 1:
					metalAV.play(); //Iniciar música

					while (metalAV.getStatus() == Sound::Playing && songchoice == 1) { //Comprovar si songchoice no és 1
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 1) { //Parar música
							metalAV.stop();
						}
					}
					break;
				case 2:
					metalAC.play();

					while (metalAC.getStatus() == Sound::Playing && songchoice == 2) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 2) {
							metalAC.stop();
						}
					}
					break;
				case 3:
					metalNP.play();

					while (metalNP.getStatus() == Sound::Playing && songchoice == 3) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 3) {
							metalNP.stop();
						}
					}
					break;
				case 4:
					cout << "Return to menu type\n\n";
					musicsong = false;
					break;
				}
			}
			break;
		case 4:
			//JAZZ
			/*Take Five, Everybody needs Somebody, What a Wonderful Things*/
			musicsong = true;
			while (musicsong) {
				cout << "\nWhich song do you want to listen?\n";
				cout << "Take Five - Dave Brubeck. Write 1\n";
				cout << "Everybody needs Somebody - Blues Brothers. Write 2\n";
				cout << "All that Jazz - Chicago. Write 3\n";
				cout << "To return to menu type. Write 4\n";
				cin >> songchoice;

				switch (songchoice) {
				case 1:
					jazzDB.play(); //Iniciar música

					while (jazzDB.getStatus() == Sound::Playing && songchoice == 1) { //Comprovar si songchoice no és 1
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 1) {
							jazzDB.stop(); //Parar música
						}
					}
					break;
				case 2:
					jazzBB.play();

					while (jazzBB.getStatus() == Sound::Playing && songchoice == 2) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 2) {
							jazzBB.stop();
						}
					}
					break;
				case 3:
					jazzCh.play();

					while (jazzCh.getStatus() == Sound::Playing && songchoice == 3) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 3) {
							jazzCh.stop();
						}
					}
					break;
				case 4:
					cout << "Return to menu type\n\n";
					musicsong = false;
					break;
				}
			}
			break;
		case 5:
			//Música classica
			/*Simfonia núm 5, El llac dels Cignes, Mozart Serenade13*/
			musicsong = true;
			while (musicsong) {
				cout << "\nWhich song do you want to listen?\n";
				cout << "Simfonia num5. Write 1\n";
				cout << "El llac dels Cignes. Write 2\n";
				cout << "Mozart Serenade 13. Write 3\n";
				cout << "To return to menu type. Write 4\n";
				cin >> songchoice;

				switch (songchoice) {
				case 1:
					classicB.play(); //Iniciar música

					while (classicB.getStatus() == Sound::Playing && songchoice == 1) {  //Comprovar si songchoice no és 1
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 1) {
							classicB.stop(); //Parar música
						}
					}
					break;
				case 2:
					classicLC.play();

					while (classicLC.getStatus() == Sound::Playing && songchoice == 2) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 2) {
							classicLC.stop();
						}
					}
					break;
				case 3:
					classicMoz.play();

					while (classicMoz.getStatus() == Sound::Playing && songchoice == 3) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 3) {
							classicMoz.stop();
						}
					}
					break;
				case 4:
					cout << "Return to menu type\n\n";
					musicsong = false;
					break;
				}
			}
			break;
		case 6:
			//Reggaeton
			/*Gasolina, Dákiti, Felices los 4*/
			musicsong = true;
			while (musicsong) {
				cout << "\nWhich song do you want to listen?\n";
				cout << "Gasolina - Daddy Yankee. Write 1\n";
				cout << "Dakiti - Bad Bunny. Write 2\n";
				cout << "Felices los 4 - Maluma. Write 3\n";
				cout << "To return to menu type. Write 4\n";
				cin >> songchoice;

				switch (songchoice) {
				case 1:
					RGgasolina.play(); //Iniciar música

					while (RGgasolina.getStatus() == Sound::Playing && songchoice == 1) { //Comprovar si songchoice no és 1
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 1) {
							RGgasolina.stop(); //Parar música
						}
					}
					break;
				case 2:
					rgDK.play();

					while (rgDK.getStatus() == Sound::Playing && songchoice == 2) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 2) {
							rgDK.stop();
						}
					}
					break;
				case 3:
					rgM4.play();

					while (rgM4.getStatus() == Sound::Playing && songchoice == 3) {
						cout << "Do you want to finish the song. Write 4\n";
						cin >> songchoice;
						if (songchoice != 3) {
							rgM4.stop();
						}
					}
					break;
				case 4:
					cout << "Return to menu type\n\n";
					musicsong = false;
					break;
				}
			}
			break;
		
			//Final menú
		case 7:
			musictype = false;
			break;
			//Opció default
		default:
			cout << "Type 1 to 8\n";
			break;

			}
		}
		timem += 30;
		cout << "30 minutes have passed\n";
	}

// Funció Comprovar estats i mantenir-los entre 0 i 9
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

//Funció temps
void Pet::Time(int timeh)
{
	cout << petname << " has " << timeh << " hores de vida\n";
	
};

//Funció convertir temps
void Pet::ConvertTime() 
{
	while (timem > 60) {
		if (timem >= 60) {
			timem -= 60;
			timeh += 1;
		}
	}

	while (timeh > 24) {
		if (timeh >= 24) {
			timeh -= 24;
			timed += 1;
		}
	}
}

	//Funció mostrar mascotes predeterminades
	void Pet::showHen() {
		cout << R"(
  
                ,-'__ `-,
               {,-'  `. }              ,')
              ,( a )   `-.__         ,',')~,
             <=.) (         `-.__,==' ' ' '}
               (   )                      /
                `-'\   ,                  )
                    |  \        `~.      /
                    \   `._        \    /
                     \     `._____,'   /
                      `-.            ,'
                         `-.      ,-'
                            `~~~~'
                            //_||
                         __//--'/`          
                       ,--'/    //'--,
    )" << endl;
	};
	void Pet::showPig() {
		cout << R"(
     ,--.  ,--.
     `  /-~-` /
      )' a a '(
     (  ,---.  )
      `(_o_o_)'
        )`-'(
    )" << endl;
	};
	void Pet::showCow() {
		cout << R"(
   ^__^
  (oo)\_______
 (__)\
      ||----w |
      ||     ||
    )" << endl;
	};

	//Funció Afegir mascotes
	void Pet::AddPets(vector<Pet> pets)
	{
		// Crear una nova mascota
		Pet newPet;

		// Sol·licitar el nom per a la nova mascota
		string petName;
		cout << "Enter a name for your new pet: ";
		cin >> petName;
		newPet.setPetName(petName);  // Assignar nom

		// Afegir la nova mascota al vector
		pets.push_back(newPet);

		cout << "New pet added: " << newPet.getpetName() << endl;

		//Afegir mascotes
	}