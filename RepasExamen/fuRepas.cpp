#include <iostream>
#include "fuRepas.h" //Inclou el fitxen on es declaren les funcions

using namespace std;

// Definició de la funció demanar_NomPunct per demanar noms i puntuacions als jugadors
void demanar_NomPunct(string jugador[], int puntuacio[], int numjugadors) {

    // Bucle per demanar els noms i les puntuacions dels jugadors
    for (int i = 0; i < numjugadors; i++) {
        cout << "Escriu un nom del jugador" << i + 1 << ":\n";
        cin >> jugador[i]; // Guardem el nom a la llista jugador
        // Demanem la puntuació del jugador
        cout << "Escriu una puntuacio per " << jugador[i] << endl;
        cin >> puntuacio[i];
        // Mostrem el nom i la puntuació per confirmar
        cout << "Jugador: " << jugador[i] << ", Puntuacio " << puntuacio[i] << endl << endl;
    }
}

// Definició de la funció max_NomPunct per trobar el guanyador
void max_NomPunct(const string jugador[], const int puntuacio[], int numjugadors) {

    int maxPuntuacio = puntuacio[0]; // Assignem la màxima puntuació a la primera puntuació
    int indexGuanyador = 0; // Assignem l'índex del guanyador amb 0 (que és el primer jugador)
    // Bucle per recórrer totes les puntuacions i trobar la màxima
    for (int i = 1; i < numjugadors; i++) {
        if (puntuacio[i] > maxPuntuacio) { // Si la puntuació actual és més alta que la màxima, actualitzem
            maxPuntuacio = puntuacio[i]; //Actualitzar la màxima puntuació
            indexGuanyador = i; //Actualitza l'índex del guanyador
        }
    }
    // Mostrem el nom del guanyador i la seva puntuació
    cout << "El guanyador es " << jugador[indexGuanyador] << " amb " << maxPuntuacio << " punts.\n";
}
