#include <iostream>
#include <ctime> // Biblioteca per reiniciar el valor aleatori
using namespace std;
void main() {
    srand(time(0)); // Serveix per canviar el valor de random quan es tanca el programa
    int numusuari; bool continuar = true; int numvegades = 0; int num1; int num2;
    cout << "\t\tAdivina el numero entre 0 i 100\n"; cout << "Introdueix el num1 de l'interval: "; cin >> num1; cout << "\nIntrodueix el num2 de l'interval: "; cin >> num2;
    int randomnum = num1+rand() % (num2 -  num1); //Fa un valor aleatori en el rang de numero1 i numero2 que ha escollit l'usuari
    while (continuar == true) {
        ++numvegades; //Suma 1 el valor de numvegades
        cout << "\nIntrodueix un numero entre " << num1 << " i " << num2 <<endl; /*Demana un numero a l'usuari*/ 
        cin >> numusuari; //Declara el valor de numusuari
        if (numusuari == randomnum){  //Compara el valor de l'usuari amb el valor aleatori
        cout << "Enhorabona!. Has aconseguit el numero en " << numvegades << " vegades." << endl;  
        continuar = false; 
        } //Mostra que has aconseguit el numero aleatori i en cuantes vegades
        else if (numusuari > randomnum) { cout << "El teu numero es massa gran!"; } //Si el valor de l'usuari és mes gran que el valor aleatori doncs que mostri que el valor de l'usuari es massa gran
        else if (numusuari < randomnum) { cout << "El teu numero es massa petit!"; } //Si el valor de l'usuari és mes petit que el valor aleatori doncs que mostri que el valor de l'usuari es massa petit
    }
}