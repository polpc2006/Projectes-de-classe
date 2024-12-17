#pragma once
#include <iostream>
#include <string>

using namespace std;

void IntroduirJugadors(string nomjugador[], int numerojugador[]); // Sense retorn
int SaberQuiComenca(const int numerojugador[]);
int FuncTorn(const string& nomJugador, int torn, int numerojoc);
void JugarNim();