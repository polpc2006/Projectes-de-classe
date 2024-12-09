// Exemple modular.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include "fuPol.h"


int main()
{
	int exercici =0;

	cout << "Inici funcions escull exercici1 o exercici 2\n\n";

	

	while (exercici != 3) {
		cout << "Escriu 1 per anar a l'exercici1 i escriu 2 per anar a l'exercici2\n";
		cin >> exercici;
			switch (exercici)
			{
			case 1:
				exercici1();
				break;
			case 2:
				exercici2();
				break;
			default:
				exercici = 0;
				break;
			}
		}
		return 0;
}