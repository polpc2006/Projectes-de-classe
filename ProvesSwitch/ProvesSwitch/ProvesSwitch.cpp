// ProvesSwitch.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

/*int main()
{
	int nota;

   cout << "Calificació:" << endl;

   cin >> nota;

   switch (nota) {

   case 0:

   }
   case 1:

	   return 0;
}*/
/*
int main() 
{
	int listSize = 4;
	int numberProcessed = 0;
	double sum = 0;
	cout << "Introdueix el nombre de valors que vulguis operar:\n";
	cin >> listSize;
	cout << "\nIntrodueix els " << listSize << " valors que vulguis operar\n";
	while (numberProcessed < listSize) {
		double value;
		cin >> value;
		sum += value;
		++numberProcessed;
	}
	double average = sum / numberProcessed;
	cout << "Average: " << average << endl;

	return 0;
}*/

int main() {
	
	int TableSize;
	int base;
	long Entry = 1;
	int fase = 0;
	cout << "Introdueix fins a quin valor vols elevar:\n";
	cin >> TableSize;
	cout << "\nIntrodueix el valor que vols elevar a " << TableSize << ".\n";
	cin >> base;
	
	

	//cout << base << "\t\t" << " ** valor " << endl;

	while (fase < TableSize) {
		cout << base <<"^"<<fase << "\t\t" << Entry << endl;
		Entry = base * Entry;
		++fase;
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
