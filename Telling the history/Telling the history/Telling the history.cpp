#include <iostream> 
#include <cstdlib> // Biblioteca random
#include <ctime>   // Biblioteca per reiniciar el valor aleatori
using namespace std;
void main()
{
    srand(time(0)); // Serveix per canviar el valor de random quan es tanca el programa
    int randomnum = rand() % 101; int numusuari; bool continuar = true; int numvegades = 0;
    cout << "\t\tAdivina el numero entre 0 i 100\n";
    while (continuar == true)
    {
        ++numvegades; //Suma 1 el valor de numvegades
        cout << "\nIntrodueix un numero\n"; //Demana un numero a l'usuari
        cin >> numusuari; //Declara el valor de numusuari
        if (numusuari == randomnum)  //Compara el valor de l'usuari amb el valor aleatori
        {cout << "Enhorabona!. Has aconseguit el numero en " << numvegades << " vegades." << endl;  continuar = false;} //Mostra que has aconseguit el numero aleatori i en cuantes vegades
        else if (numusuari > randomnum) { cout << "El teu numero es massa gran!";} //Si el valor de l'usuari és mes gran que el valor aleatori doncs que mostri que el valor de l'usuari es massa gran
        else if (numusuari < randomnum) { cout << "El teu numero es massa petit!";} //Si el valor de l'usuari és mes petit que el valor aleatori doncs que mostri que el valor de l'usuari es massa petit
    }
}