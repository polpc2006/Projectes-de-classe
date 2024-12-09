// RepasExamen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "fuRepas.h" //Inclou el fitxen on es declaren les funcions

using namespace std;

int main()
{
    const int numjugadors = 3; //Definim el nombre de jugadors a 3
    string jugador[numjugadors]; //Declarem un array tipus string per guardar el jugador segons la posicio
    int puntuacio[numjugadors]; //Declarem un array tipus int per guardar la puntuacio segons la posicio

    //Cridar a la funcio per demanar els noms dels jugadors i la puntuacio
    demanar_NomPunct(jugador, puntuacio, numjugadors);
    //Cridar a la funcio per agafar el jugador amb la puntuacio maxima
    max_NomPunct(jugador, puntuacio, numjugadors);

    return 0;
}


