// Escriu i depura codiPPC RA3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;


void Exercici1() 
{
    bool majoredat;
    //Exercici 1
    int edat; //Variable de l'edat de l'usuari

    cout << "Quants anys tens?\n";
    cin >> edat;

    majoredat = edat >= 18;

    cout << "El resultat de l\'operacio: " << majoredat << endl;

    if (majoredat) {
        cout << "Ets major d'edat.\n";
    }
    else {
        cout << "No ets major d'edat.\n";
    }
}
void Exercici2() 
{
    //Exercici 2

    int numpar; //Variable numero introduit
    int residu; //Variable residu de l'operació

    cout << "Introdueix un numero\n"; //Demana un numero
    cin >> numpar;

    residu = numpar % 2; //Troba el residu de l'operació

    if (residu != 0) //Si el residu és més gran que 0 doncs és parell si no no.
    {
        cout << "El teu valor es imparell\n";
    }
    else {
        cout << "El teu valor es parell";
    }
}

void Exercici3() 
{
    //Exercici 3

    int valor;
    int valorresidu;
    int valorrestant;


    cout << "Introdueix un valor ";
    cin >> valor;

    valorresidu = valor % 7 == 0;

    valorrestant = 7 - valorresidu;


    if (valor % 7 == 0) {
        cout << "El numero es multiple de 7";
    }
    else {
        valorresidu = valor % 7;
        valorrestant = 7 - valorresidu;
        cout << "El valor " << valor << " li falten " << valorrestant << " per ser multiple de 7";
    }
}

void Exercici4() 
{
    //Exercici 4
    int valorsegons;
    int tempssegons;
    int tempsminuts;
    int tempshores;

    cout << "Introdueix el temps que has tardat en segons.\n";
    cin >> valorsegons;

    tempshores = valorsegons / 3600;
    valorsegons = valorsegons % 3600;
    tempsminuts = valorsegons / 60;
    tempssegons = valorsegons % 60;
    cout << "Hores: " << tempshores << endl;
    cout << "Minuts: " << tempsminuts << endl;
    cout << "Segons: " << tempssegons << endl;
    
}

void Exercici5() 
{
    int puntuacio1;
    int puntuacio2;

    cout << "Introdueix la puntuacio1"<< endl;
    cin >> puntuacio1;
    cout << "\nIntrodueix la puntuacio2" << endl;
    cin >> puntuacio2;

    if (puntuacio1 > puntuacio2) {
        cout << "\nPuntuacio 1 es superior a Puntuacio 2" << endl;
    }
    else if(puntuacio1 < puntuacio2)  {
        cout << "\nPuntuacio 2 es superior a Puntuacio 1" << endl;
    }
    else if (puntuacio1 == puntuacio2) {
        cout << "\nPuntuacio 1 es igual a Puntuacio 2" << endl;
    }
}

void Exercici6() 
{
    int posicio;

    cout << "Introdueix la posicio que has entrat.\n";
    cin >> posicio;

    if (posicio <= 10) {
        cout << "Has quedat entre els 10 primers";
    }
    else if (posicio <= 100) {
        cout << "Has quedat entre els 100 primers";
    }
    else if (posicio <= 1000) {
        cout << "Has quedat entre els 1000 primers";
    }
    else if (posicio > 1000) {
        cout << "No has classificat";
    }
}

void Exercici7()
{
    int DNI;
    int resultat;
    char lletra;



    cout << "Introdueix els numeros del teu DNI\n";
    cin >> DNI;

    cout << "Introdueix la lletra del teu DNI en majuscula\n";
    cin >> lletra;




    resultat = DNI % 23;

    char lletradni[] = { 'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E' };

   // cout << "La Teva lletra es " << resultat[lletradni] << endl;

    char lletracomp = resultat[lletradni];

    if (lletracomp == lletra) {
        cout << "La teva lletra es correcte";
    }
    else {
        cout << "La teva lletra es incorrecte, la lletra real es: " << lletracomp;
    }

}


/*void Exercici9()
{
    string inputDni;
    string numDni;
    int resultatDivisio;
    //int resultatDni = dni % 23;
    string lletraDni = "TRWAGMYFPDXBNJZSQVHLCKE";
    string lletraDnimin = "trwagmyfpdxbnjzsqvhlcke";

    cout << "Introdueix un DNI de 8 digits per validar si es correcte ";
    cin >> inputDni;
    for (int i=0; i<8; i++) 
    {
        //dni[i];
        
        numDni += inputDni[i];
    }
    cout << numDni;
    
    resultatDivisio = (stoi(numDni) % 23);
    cout << inputDni[8];
    if (inputDni[8] == (lletraDni[resultatDivisio]) || lletraDnimin[resultatDivisio])
    {
        cout << "\nDNI correcte";
    
    }
    else 
    {
        cout << "\nDNI erroni";
    }
}*/

void Exercici8() 
{
    cout << "hola";
}

int main()
{
    int codi;
    cout << "Escull un programa del 1 al 8\n";
    cin >> codi;

    switch (codi) {

    case 1:
        Exercici1();
        break;

    case 2:
        Exercici2();
        break;

    case 3:
        Exercici3();
        break;

    case 4:
        Exercici4();
        break;

    case 5:
        Exercici5();
        break;
    case 6:
        Exercici6();
        break;
    case 7:
        Exercici7();
        break;

    case 8:
        Exercici8();
        break;
    }
}