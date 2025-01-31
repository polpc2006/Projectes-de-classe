#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Pet
{
public:
	void maincode(); //Funci� main

	//Funcions nom
	string getpetName() const;
	void setPetName(string newName);

	//Mostrar mascotes predeterminades
	void showHen();
	void showPig();
	void showCow();

	Pet(int gana = 5, int aborriment = 5, int neteja = 5,int son= 5, int sed = 5); //Constructor Pet
	
	void Stats(); //Funci� estad�stiques

	void Greet(string name); //Funci� Saludar
	void Play();// Funci� jugar
		//Jocs
		void Timber();
		void Riddles();
		void TestQ();
		void RPS();

	void Talk(); //Funci� parlar amb la mascota que mostra 1 frase per cop i hi ha 10 frases de manera ale�toria
	void Drink(); //Funci� de beure
	void Eat(); //Funci� de menjar
	void Sleep(); //Funci� dormir
	void takeShower(); //Funci� dutxa

	void ListenMusic(); //Funci� escoltar m�sica

	void CheckStats(); // Funci� ComprovarStats per que no sigui valor negatiu ni superior a 10
	void ConvertTime(); // Funci� convertir temps de minuts a hores i hores a dies

private:
	string petname = "a"; // Nom de la mascota
	int hunger = 0;		  // Gana
	int thirsty = 0;	  // Set
	int boredom = 0;	  // Avorriment
	int sleepiness = 0;   // Son
	int cleanliness = 0;  // Neteja

	int valrand = 0; //Valor random per parlar amb el Tamagochi

	int timed = 0; //Temps en dies
	int timeh = 0; //Temps en hores
	int timem = 0; //Temps en minuts

	void Time(int timeh); //Mostrar el temps de vida

	void AddPets(vector<Pet> pets);
	
};