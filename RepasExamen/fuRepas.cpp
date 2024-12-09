#include <iostream>
#include "fuRepas.h" //Inclou el fitxen on es declaren les funcions

using namespace std;

// Definici� de la funci� demanar_NomPunct per demanar noms i puntuacions als jugadors
void demanar_NomPunct(string jugador[], int puntuacio[], int numjugadors) {

    // Bucle per demanar els noms i les puntuacions dels jugadors
    for (int i = 0; i < numjugadors; i++) {
        cout << "Escriu un nom del jugador" << i + 1 << ":\n";
        cin >> jugador[i]; // Guardem el nom a la llista jugador
        // Demanem la puntuaci� del jugador
        cout << "Escriu una puntuacio per " << jugador[i] << endl;
        cin >> puntuacio[i];
        // Mostrem el nom i la puntuaci� per confirmar
        cout << "Jugador: " << jugador[i] << ", Puntuacio " << puntuacio[i] << endl << endl;
    }
}

// Definici� de la funci� max_NomPunct per trobar el guanyador
void max_NomPunct(const string jugador[], const int puntuacio[], int numjugadors) {

    int maxPuntuacio = puntuacio[0]; // Assignem la m�xima puntuaci� a la primera puntuaci�
    int indexGuanyador = 0; // Assignem l'�ndex del guanyador amb 0 (que �s el primer jugador)
    // Bucle per rec�rrer totes les puntuacions i trobar la m�xima
    for (int i = 1; i < numjugadors; i++) {
        if (puntuacio[i] > maxPuntuacio) { // Si la puntuaci� actual �s m�s alta que la m�xima, actualitzem
            maxPuntuacio = puntuacio[i]; //Actualitzar la m�xima puntuaci�
            indexGuanyador = i; //Actualitza l'�ndex del guanyador
        }
    }
    // Mostrem el nom del guanyador i la seva puntuaci�
    cout << "El guanyador es " << jugador[indexGuanyador] << " amb " << maxPuntuacio << " punts.\n";
}
