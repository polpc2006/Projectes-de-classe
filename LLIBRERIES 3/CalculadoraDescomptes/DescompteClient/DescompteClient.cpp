// DescompteClient.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "CalculadoraDescomptes.h"

using namespace std;


int main()
{
    double preu; //Variable double preu
    double descompte; //Variable double descompte
    double descompteimport=0; //Variable double descompteimport 
    double resultat; //Variable 

    cout << "Programa Calcular el preu amb descompte\n\n";

    //Demanar preu i descompte a l'usuari
    cout << "Introdueix un preu (pot ser amb decimals)\n";
    cin >> preu;
    cout << "Introdueix un descompte (pot ser amb decimals)\n";
    cin >> descompte;

    //Mostrar el preu amb descompte i el descompte que s'ha fet
    cout << "El preu amb descompte es " << CalcDescompt::Operacio::OperDescompt(preu, descompte) << " euros" << endl;
    resultat = CalcDescompt::Operacio::OperDescompt(preu, descompte);
    cout << "El descompte es de: " << CalcDescompt::Operacio::NumDescompte(preu, descompteimport, resultat) << " euros" << endl;
}