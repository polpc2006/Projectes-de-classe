// Variables globals.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int glob = 10; //global variable

void access_global();
void hide_global();
void change_global();

int main()
{
    cout << "In main() glob is: " << glob << "\n\n";
    access_global();

    cout << "In main() glob is: " << glob << "\n\n";
    hide_global();

    cout << "In main() glob is: " << glob << "\n\n";
    change_global();

    return 0;
}

void access_global() 
{
    cout << "In access global() is: " << glob << "\n\n";
}

void hide_global() 
{
    int glob = 0; //hide global variable glob
    cout << "In hide global() is: " << glob << "\n\n";
}

void change_global() 
{
    glob = -10;
    cout << "In change global() is: " << glob << "\n\n";
}

