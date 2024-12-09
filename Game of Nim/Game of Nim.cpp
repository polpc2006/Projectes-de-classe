// Game of Nim.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int main()
{
    bool inicijugar = false;
    bool fijoc = false;


    string nomjugador1;
    string nomjugador2;

    int numerojugador1;
    int numerojugador2;
    int numerojoc = 50;
    int torn;

    char sn = 'a';
    int puntjug1;
    int puntjug2;

    cout << "Benvinguts al videojoc de Nim\n";
    cout << "Vols comencar el videojoc?\n\n";

    while (!inicijugar)

    {

        cout << "S per comencar a jugar\n";
        cout << "N per sortir del joc\n\n";
        cin >> sn;
        inicijugar = true;

        if (sn == 's' || sn == 'S')
        {
            inicijugar = true;
        }
        else if (sn == 'n' || sn == 'N') {
            cout << "\nNo has volgut jugar.\n";
            cout << "Fins una altra.";
            inicijugar = true;
            fijoc = true;
        }
        else {
            cout << "Escull S o N\n";
            inicijugar = false;
        }

        if (inicijugar && fijoc == false)
        {
            cout << "\nJugador 1 escriu un nom\n\n";
            cin >> nomjugador1;
            cout << "\nJugador 2 escriu un nom\n\n";
            cin >> nomjugador2;

            cout << endl << nomjugador1 << ": Escriu un numero\n";
            cin >> numerojugador1;
            cout << endl << nomjugador2 << ": Escriu un numero\n";
            cin >> numerojugador2;

            if (numerojugador1 >= numerojugador2)
            {
                numerojoc = numerojugador1;
                cout << "\nLa puntuacio del jugador 1 que es " << numerojoc << " es el guanyador";
            }
            else if (numerojugador2 >= numerojugador1)
            {
                numerojoc = numerojugador2;
                cout << "\nLa puntuacio del jugador 2 que es " << numerojoc << " es el guanyador";
            }

            while (numerojoc != 0) 
            {
                cout << endl << nomjugador1 << " es el teu torn, vols restar 1 o 2?";
                cin >> puntjug1;
                if (puntjug1 == 1 && numerojoc > 0) {
                    numerojoc = numerojoc - puntjug1;
                    torn = 1;
                }
                else if (puntjug1 == 2 && numerojoc > 0) {
                    numerojoc = numerojoc - puntjug1;
                    torn = 1;
                }
                if (numerojoc > 0) {
                    cout << "Ara la puntuacio es " << numerojoc;
                    cout << endl << nomjugador2 << " es el teu torn, vols restar 1 o 2?";
                    cin >> puntjug2;
                }

                if (puntjug2 == 1 && numerojoc > 0) {
                    
                    numerojoc = numerojoc - puntjug2;
                    torn = 2;
                }
                else if (puntjug2 == 2 && numerojoc > 0) {
                    numerojoc = numerojoc - puntjug2;
                    torn = 2;
                }
                cout << "Ara la puntuacio es " << numerojoc;    
            }
            if (torn == 1 && numerojoc == 0) {
                cout << endl << endl << nomjugador1 << " ha guanyat";
            }
            else if (torn == 2 && numerojoc == 0) {
                cout << endl << endl << nomjugador2 << " ha guanyat";
            }
           
            if (numerojoc == 0) 
            {
                fijoc = true;
                cout << "\n\nAcaba el joc";
            } 
        }
    }
}