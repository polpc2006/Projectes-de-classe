// Programa variable.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int main()
{
	/*
	//Exercici 1
		//Alternitava1
	int peus, polzades;
	peus = 0;
	polzades = 0;

	cout << "peus: " << peus ;
	cout << " polzades: " << polzades ;
	*/
		//Alternativa 2
	/*
	int peus;
	int polzades;

	peus = 0;
	polzades = 0;

	cout << "peus: " << peus << " polzades: " << polzades;
	*/
	/*
	//Exercici2

	int v1, v2, v3, v4, v5, v6;

	cout << v1;
	cout << v2;
	cout << v3;
	cout << v4;
	cout << v5;
	cout << v6;
	*/
	
	//Exercici3

	double Valor_Farenheit;
	double Valor_Celsius;

	cout << "Introdueix el valor en Farenheit\n";
	cin >> Valor_Farenheit;
	Valor_Celsius = (Valor_Farenheit - 32) / (1.8);
	cout << "Valor Celsius: ";
	cout << Valor_Celsius;

}
