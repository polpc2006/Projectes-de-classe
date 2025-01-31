#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Pet
{
public:
	void maincode(); //Funció main

	//Funcions nom
	string getpetName() const;
	void setPetName(string newName);

	//Mostrar mascotes predeterminades
	void showHen();
	void showPig();
	void showCow();

	Pet(int gana = 5, int aborriment = 5, int neteja = 5,int son= 5, int sed = 5); //Constructor Pet
	
	void Stats(); //Funció estadístiques

	void Greet(string name); //Funció Saludar
	void Play();// Funció jugar
		//Jocs
		void Timber();
		void Riddles();
		void TestQ();
		void RPS();

	void Talk(); //Funció parlar amb la mascota que mostra 1 frase per cop i hi ha 10 frases de manera aleàtoria
	void Drink(); //Funció de beure
	void Eat(); //Funció de menjar
	void Sleep(); //Funció dormir
	void takeShower(); //Funció dutxa

	void ListenMusic(); //Funció escoltar música

	void CheckStats(); // Funció ComprovarStats per que no sigui valor negatiu ni superior a 10
	void ConvertTime(); // Funció convertir temps de minuts a hores i hores a dies

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