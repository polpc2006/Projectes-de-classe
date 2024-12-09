// Pensament Computacional PPC.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

int main()
{
    int puntuacio;
    int vides;
    int videsCopies;
    unsigned int variableExtra;

    cout << "Introdueix una puntuacio\n";
    cin >> puntuacio;
    puntuacio = puntuacio + 100;
    cout << "La puntuacio es: " << puntuacio;
    puntuacio = puntuacio + 100;
    cout << "\nLa puntuacio es: " << puntuacio;
    cout << "\nIntrodueix el numero de vides\n";
    cin >> vides;
    
    cout << "\nEl numero de vides es: " << ++vides;
    videsCopies = vides;
    cout << "\nEl numero de videsCopies es: " << videsCopies;
    vides = vides * 10;
    cout << "\nEl numero de vides es: " << vides;
    videsCopies = videsCopies * 10;
    cout << "\nEl numero de videsCopies es: " << videsCopies;
    variableExtra = 4294967295;
    cout << "\nLa variable extra te el valor de:" << variableExtra;
    cout << "\nLa variable extra te el valor de:" << ++variableExtra;
    return 0;


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
