// Demostració Condicionals.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

/*int main()
{
    if (true)
    {
        cout << "This is always displayed.\n\n";
    }

    if (false)
    {
        cout << "This is never displayed.\n\n";
    }
    int score = 1000;
    cout << "What is your score?\n";
    cin >> score;
    if (score)
    {
        cout << "\nAt least you didn't score zero.\n\n";
    }
    if (score>=250)
    {
        cout << "You scored 250 or more. Decent.\n\n";
    }
    if (score >= 500)
    {
        cout << "You scored 500 or more. Nice.\n\n";
    }
    if (score >= 1000)
    {
        cout << "You scored 1000 or more. Impressive!.\n\n";
    }
    else 
    {
        cout << "You scored less than 1000\n\n";
    }
    
    return 0;
}*/

void main() 
{
    float nota;
    cout << "Dona una nota: " << endl;

    cin >> nota;
    if (nota >= 9) {
        cout << "Excelent" << endl;
    }
    else if (nota >= 7) {
        cout << "Notable" << endl;
    }
    else if (nota >= 5) {
        cout << "Aprovat" << endl;
    }
    else {
        cout << "Suspes" << endl;
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
