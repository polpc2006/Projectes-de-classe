#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Modificar funció per demanar els 4 noms
void nombre(string& Bus1, string& Bus2, string& Bus3, string& Bus4) {
    gotoxy(15, 3); cout << "INGRESAR NOMBRES" << endl;
    gotoxy(10, 4); cout << "Nombre Bus 1: ";
    getline(cin, Bus1);
    gotoxy(10, 5); cout << "Nombre Bus 2: ";
    getline(cin, Bus2);
    gotoxy(10, 6); cout << "Nombre Bus 3: ";
    getline(cin, Bus3);
    gotoxy(10, 7); cout << "Nombre Bus 4: ";
    getline(cin, Bus4);

    gotoxy(25, 9); cout << "INICIAMOS LA CARRERA: " << endl;
    gotoxy(28, 10); cout << Bus1 << ", " << Bus2 << ", " << Bus3 << " y " << Bus4 << endl;
}

void pista(int inx, int iny) {
    gotoxy(inx, iny);      cout << "|----------------------------------------------------------------------------||";
    gotoxy(inx, iny + 1); cout << "|                                                                            ||";
    gotoxy(inx, iny + 2); cout << "|                                                                            ||";
    gotoxy(inx, iny + 3); cout << "|                                                                            |M";
    gotoxy(inx, iny + 4); cout << "|                                                                            |E";
    gotoxy(inx, iny + 5); cout << "|----------------------------------------------------------------------------|T";
    gotoxy(inx, iny + 6); cout << "|                                                                            |A";
    gotoxy(inx, iny + 7); cout << "|                                                                            |A";
    gotoxy(inx, iny + 8); cout << "|                                                                            ||";
    gotoxy(inx, iny + 9); cout << "|                                                                            ||";
    gotoxy(inx, iny + 10); cout << "|----------------------------------------------------------------------------||";
}

void bus(int position, int line, int color) {
    setColor(color);
    gotoxy(position, line);     cout << "_______________ ";
    gotoxy(position, line + 1); cout << "|__|__|__|__|__|___ ";
    gotoxy(position, line + 2); cout << "|                 |)";
    gotoxy(position, line + 3); cout << "|~~~@~~~~~~~~~@~~~|)";
    setColor(7);
}

void imprimirNombre(int position, int line, const string& name) {
    gotoxy(position + 4, line + 2); // Ajusta la posición para centrar el nombre
    cout << name;
}

void carrera(string Bus1, string Bus2, string Bus3, string Bus4) {
    int bus1Pos = 1;
    int bus2Pos = 1;
    int bus3Pos = 1;
    int bus4Pos = 1;

    srand(static_cast<unsigned int>(time(0)));

    while (bus1Pos < 100 && bus2Pos < 100 && bus3Pos < 100 && bus4Pos < 100) {  // Meta a la posició 100
        Sleep(100);

        // Actualitzar posicions de forma aleatòria
        bus1Pos += rand() % 3;
        bus2Pos += rand() % 3;
        bus3Pos += rand() % 3;
        bus4Pos += rand() % 3;

        // Esborrar línies anteriors completament
        for (int i = 11; i <= 28; i++) {
            gotoxy(2, i); cout << string(80, ' ');  // Utilitzar espais per esborrar tota la línia
        }

        // Dibuixar els busos amb diferents colors
        bus(bus1Pos, 11, 9); imprimirNombre(bus1Pos, 11, Bus1);   // Bus 1 (color 9)
        bus(bus2Pos, 16, 10); imprimirNombre(bus2Pos, 16, Bus2);  // Bus 2 (color 10)
        bus(bus3Pos, 21, 11); imprimirNombre(bus3Pos, 21, Bus3);  // Bus 3 (color 11)
        bus(bus4Pos, 26, 12); imprimirNombre(bus4Pos, 26, Bus4);  // Bus 4 (color 12)

        // Comprovar si algun bus ha arribat a la meta
        if (bus1Pos >= 100) {
            gotoxy(60, 30); cout << Bus1 << " es el ganador!" << endl;
            break;
        }
        else if (bus2Pos >= 100) {
            gotoxy(60, 30); cout << Bus2 << " es el ganador!" << endl;
            break;
        }
        else if (bus3Pos >= 100) {
            gotoxy(60, 30); cout << Bus3 << " es el ganador!" << endl;
            break;
        }
        else if (bus4Pos >= 100) {
            gotoxy(60, 30); cout << Bus4 << " es el ganador!" << endl;
            break;
        }
    }
}


int main() {
    string Bus1, Bus2, Bus3, Bus4;
    // Demanar els noms dels quatre busos
    nombre(Bus1, Bus2, Bus3, Bus4);

    int inx = 1;
    int iny = 10;
    pista(inx, iny);

    // Iniciar la carrera amb quatre busos
    carrera(Bus1, Bus2, Bus3, Bus4);

    cout << "\n\n\n\n\n\n\n";
    system("pause");

    return 0;
}
