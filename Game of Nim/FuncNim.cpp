#include "FuncNim.h"
#include <iostream>


using namespace std;

// Funció per introduir les dades dels jugadors
void IntroduirJugadors(string nomJugador[], int numerojugador[]) {
    for (int i = 0; i < 2; i++) {
        cout << "\nJugador " << i + 1 << " escriu un nom\n";
        cin >> nomJugador[i];
        cout << "\nJugador " << nomJugador[i] << " escriu una puntuacio\n\n";
        cin >> numerojugador[i];
    }
}

// Funció per saber qui comença
int SaberQuiComenca(const int numerojugador[]) {
    if (numerojugador[0] >= numerojugador[1]) {
        return 0; // Comença jugador 1
    }
    else {
        return 1; // Comença jugador 2
    }
}

// Funció per fer un torn
int FuncTorn(const string& nomJugador, int numerojoc) {
    int moviment;
    do {
        cout << nomJugador << ", vols restar 1 o 2 del total? ";
        cin >> moviment;
        if (moviment != 1 && moviment != 2) {
            cout << "Error! Nomes pots entrar 1 o 2.\n";
        }
    } while (moviment != 1 && moviment != 2);
    return numerojoc - moviment; // Retornem el nou valor del total
}

// Funció principal del joc
void JugarNim() {
    string nomJugador[2] = { "a", "b" };
    int numerojugador[2] = { 0, 0 }; // Inicialitzem els valors
    int numerojoc;
    int torn = 0;

    // Introduir dades dels jugadors i determinar el valor inicial del joc
    IntroduirJugadors(nomJugador, numerojugador);

    // Calcular el valor més gran com a numerojoc
    numerojoc = max(numerojugador[0], numerojugador[1]);
    
    // Determinar qui comença
    torn = SaberQuiComenca(numerojugador);

    // Bucle principal del joc
    while (numerojoc > 0) {
        // Mostrem el total actual
        cout << "\nEl total actual es: " << numerojoc << "\n";

        // Torn del jugador actual
        numerojoc = FuncTorn(nomJugador[torn], numerojoc);

        // Comprovem si el joc ha acabat
        if (numerojoc <= 0) {
            cout << "\nEl total es " << numerojoc << ". " << nomJugador[torn] << " ha guanyat!\n";
            break;
        }

        // Canvi de torn
        torn = 1 - torn; // Alternem entre 0 i 1
    }

    cout << "\nEl joc ha acabat. Gracies per jugar!\n";
}
