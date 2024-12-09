// SnakeProva.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>  // Per utilitzar _kbhit() i _getch()
#include <windows.h>  // Per utilitzar Sleep()

using namespace std;

bool gameOver;
const int width = 20;  // Amplada de la finestra
const int height = 20; // Altura de la finestra
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];  // Coordenades de la cua de la serp
int nTail;  // Longitud de la cua
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };  // Direccions possibles
eDirection dir;  // Direcció actual de la serp

// Funció per inicialitzar els valors
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;  // Posició inicial de la serp al centre de la pantalla
    y = height / 2;
    fruitX = rand() % width;  // Posiciona la fruita de forma aleatòria
    fruitY = rand() % height;
    score = 0;  // Inicialitza la puntuació a zero
}

// Funció per dibuixar el mapa
void Draw() {
    system("cls");  // Esborra la pantalla

    // Dibuixa el límit superior
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Dibuixa les files interiors
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)  // Límits laterals esquerres
                cout << "#";
            if (i == y && j == x)  // Dibuixa el cap de la serp
                cout << "O";
            else if (i == fruitY && j == fruitX)  // Dibuixa la fruita
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {  // Dibuixa la cua de la serp
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == width - 1)  // Límits laterals drets
                cout << "#";
        }
        cout << endl;
    }

    // Dibuixa el límit inferior
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    // Mostra la puntuació
    cout << "Score: " << score << endl;
}

// Funció per gestionar la entrada de l'usuari
void Input() {
    if (_kbhit()) {  // Si una tecla ha estat premuda
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;  // Finalitza el joc si es prem 'x'
            break;
        }
    }
}

// Funció per actualitzar la lògica del joc
void Logic() {
    // Guarda la posició anterior de la cua
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Canvia la posició segons la direcció
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Si la serp surt de la pantalla, el joc s'acaba
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    // Comprova si la serp es mossega a si mateixa
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    // Si la serp menja la fruita
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;  // Nova posició de la fruita
        fruitY = rand() % height;
        nTail++;  // Allarga la cua
    }
}

int main() {
    Setup();  // Inicialitza el joc
    while (!gameOver) {  // Bucle principal del joc
        Draw();  // Dibuixa la pantalla
        Input();  // Gestiona les entrades
        Logic();  // Actualitza la lògica del joc
        Sleep(100);  // Fes una pausa per reduir la velocitat del joc
    }
    return 0;
}