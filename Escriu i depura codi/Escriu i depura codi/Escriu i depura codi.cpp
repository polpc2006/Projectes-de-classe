// Escriu i depura codi.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
    int anyactual;
    int edat;

    cout << "Quin any es?\n";
    cin >> anyactual;
    cout << "Quina edat tens?\n";
    cin >> edat;

    if (edat >= 16) {
        cout << "Pots entrar a instagram\n";
    }
    else {
        cout << "Pots entrar a instagrama l'any " << anyactual + (16 - edat);
    }
    return 0;
    // Programa demanar edat per instagram
}

int main() 
{
    int  anyactual;
    int anynaixement;
    int edat;

    cout << "Quina any es?\n";
    cin >> anyactual;
    cout << "Quin any vas neixer?\n";
    cin >> anynaixement;

    edat = anyactual - anynaixement;

    cout << "Tens " << edat << " anys";

    return 0;
    //Programa càlcul edat segons l’any actual.
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
