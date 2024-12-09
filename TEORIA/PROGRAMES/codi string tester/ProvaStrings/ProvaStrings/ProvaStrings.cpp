// ProvaStrings.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
/*
void main(void)
{
	char line[4000];
	int count = 0;
	cout << "Enter a sentence of no more than 79 characters:\n";
	cin.getline(line, 4000);
	cout << "The sentence you entered is:\n";
	while (line[count] != '\0')
	{
		cout << line[count];
		count++;
	}
}*/

void main() 
{
	string paraula1; 
	string paraula2; 
	string paraula3; 
	string paraula4;
	string frase;
	char car1 = frase[0]; //Variable caràcter 1 de la frase
	int llista;

	cout << "Escriu 3 paraules:\n";
	cin >> paraula1;
	cin >> paraula2;
	cin >> paraula3;

	frase = paraula1 + " " + paraula2 + " " + paraula3;
	cout << "Les teves paraules son:\n";
	cout << frase << endl;
	cout << "La teva frase te " << frase.length() << " caracters en ella.\n";
	cout << "\nEl teu caracter a la posicio 0 es: " << frase[0]<<endl;
	cout << "Canvia la primera lletra de la frase:";
	cin >> car1;
	frase[0] = car1;
	cout << "La frase ara es: " << frase <<endl;

	for (llista = 0; llista < frase.length(); ++llista) {
		cout << "El caracter a la posicio " << llista << " es: " << frase[llista] <<endl;
	}

	cout << "La paraula " << paraula2 << " esta a la localitzacio " << frase.find(paraula2)<<endl;

	cout << "Introdueix la paraula 4\n";
	cin >> paraula4;

	if (paraula4 == paraula1 || paraula4 ==  paraula2 || paraula4 == paraula3) {
		cout << "La paraula que has escrit esta en la frase\n";
	}
	else {
		cout << "La paraula que has escrit no esta en la frase\n";
	}
	llista = frase.length();
	while (llista != 0) {
		cout << frase;
		--llista;
	}
}