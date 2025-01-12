// Tamagochi.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "Pet.h"
#include <iostream>

using namespace std;

int main()
{
    Pet pet1;

    pet1.getPetName();

    string name = pet1.setPetName();
    int choice;
    bool menu = true;

    pet1.Greet();
    
    while (menu)
    {
        cout << "Now what do you want to do?\n\n";
        cout << "Do you want to play with " << name << endl;
        cout << "Write 1\n";
        cout << "Do you want to feed " << name << endl;
        cout << "Write 2\n";
        cout << "Do you want to give " << name << " water\n";
        cout << "Write 3\n";
        cout << "Do you want to listen " << name << "\n";
        cout << "Write 4\n";
        cout << "Do you want to take " << name << " a shower\n";
        cout << "Write 5\n";
        cout << "Do you want " << name << " to sleep\n";
        cout << "Write 6\n";
        cout << "Do you want to see " << name << " stats\n";
        cout << "Write 7\n";
        cout << "Do you want to leave\n";
        cout << "Write 8\n";
        cin >> choice;
        cout << "\n\n";

        if (choice < 9 && choice>0)
        {
            switch (choice)
            {
            case 1:
                pet1.Play();
                break;
            case 2:
                pet1.Eat();
                break;
            case 3:
                pet1.Drink();
                break;
            case 4:
                pet1.Talk();
                break;
            case 5:
                pet1.takeShower();
                break;
            case 6:
                pet1.Sleep();
                break;
            case 7:
                pet1.Stats();
                break;
            case 8:
                cout << "Bye, see you another time\n";
                menu = false;
            }
            
        }
       
    }
}
