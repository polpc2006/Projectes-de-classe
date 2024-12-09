// Telling History.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    string job; //Variable treball tipus text
    int ageplayer; //Variable edat jugador
    string ObjectTransport; //Variable objecte transport tipus text
    string adjective; //Variable adjectiu tipus text
    string place; //Variable lloc tipus text
    string verb; //Variable verb tipus text
    string Object; //Variable objecte tipus text
    string SmallObject; //Variable objectepetit tipus text
    float price; //Variable preu tipus numerica
    string Object2; //Variable objecte2 tipus text
    string verbinf; //Variable verbinfinitu tipus text
    char sn = 'a'; //Variable sn tipus caracter
    char snjugar = 'a'; //Variable snjugar tipus caracter
    bool jugar = true; //Variable jugar tipus booleana
    
    while (jugar) 
    {
        cout << "Hola usuari ara llegiras una historia en Angles.\n\n"; 
        Sleep(4000);
        system("cls");
        //Demana a l'usuari el valor de les variables
        cout << "Write a job\n";
        cin >> job;
        system("cls"); //Esborra el text en pantalla
        cout << "How old is the main character?\n";
        cin >> ageplayer;
        system("cls");
        cout << "Tell me a vehicle of transportation\n";
        cin >> ObjectTransport;
        system("cls");
        cout << "Introduce an adjective\n";
        cin >> adjective;
        system("cls");
        cout << "Tell me a place\n";
        cin >> place;
        system("cls");
        cout << "Tell me verb\n";
        cin >> verb;
        system("cls");
        cout << "Tell me an object\n";
        cin >> Object;
        system("cls");
        cout << "Tell me a small object\n";
        cin >> SmallObject;
        system("cls");
        cout << "Tell me a decimal number.\n";
        cin >> price;
        system("cls");
        cout << "Tell me a verb in infinitive\n";
        cin >> verbinf;
        system("cls");

        //Comença la història

        //Mostra el text i les diferents variables i després espera 4 segons a mostrar la següent frase
        cout << "In the middle of nowhere, there was a " << job << " that was "<<ageplayer<<" years old. This "<<job<<" was conquering other " << job << " " << ObjectTransport <<"s" << endl; Sleep(4000);
        cout << "One day, this "<<job <<" saw a foreign city with his spyglass, and it seems to be desinhabitated. After seeing the city, the "<< job <<" was tented to go there and explore the city.\n"; Sleep(4000);
        cout << "The "<< job <<" went to the city with the other "<< job <<"s and explored the city.\n\n"; Sleep(4000);
        cout << "After exploring the city for so many hours, they gave up because they saw that there were some " << adjective << " buildings and broken houses and, it seemed to be, that there weren\'t important.\n"; Sleep(4000);
        cout << "When they were returning to the "<< ObjectTransport <<", they saw a beautiful " << place << " that looked very modern and rich.\n"; Sleep(4000);
        cout << "They went there to " << verb << " and they saw a golden " << Object << " exposing in the middle of the king's room in the castle.\n"; Sleep(4000);
        cout << "They were very glad to see a " << SmallObject << ", that has been valued at " << price << " euros.\n\n"; Sleep(4000);

        cout << "Do you take the golden " << SmallObject << "?\n";
        cout << "Y for yes N for no\n\n";
        cin >> sn;

        if (sn == 'y' || sn == 'Y') //Condició si sn es igual a y o a Y
        {
            //Mostrar text
            cout << "After that they tried to take the gold " << SmallObject << ", all the castle started to overthrow in pieces.\n"; Sleep(4000);
            cout << "Then the "<<job<<" and his team tried to " << verbinf << ", but it was not possible because all the exits were covered.\n"; Sleep(4000);
            cout << "Consequently, one wall that was near the "<<job<<" team fell down and trapped the pirates.\n"; Sleep(4000);
            cout << "Following the other walls of the castle fall the down and there was another wall that attacked all the "<<job<<" team.\n\n"; Sleep(4000);
            cout << "End.\n\n";

            cout << "Do you want to play again?\n";
            cout << "Y for yes N for no\n\n";
            cin >> snjugar;

            if (snjugar == 'y' || snjugar == 'Y') //Condició si snjugar es igual a y o a Y
            {
                system("cls");
                jugar = true;
            }
            else
            {
                jugar = false;
            }
        }
        else if (sn == 'n' || sn == 'N') //Condició si sn es igual a n o a N
        {
            //Mostrar text
            cout << "As they exited the castle, a strange calm enveloped the group.As they walked away, they began to notice changes around them.\nThe air became cooler, and the sky, which had been sunny, started to darken.A fog spread quickly, covering the path they had taken.\n"; Sleep(4000);
            cout << "Upon returning to the village, the atmosphere had changed. The people seemed happier, and the market was bustling with activity.\nWhen they spoke with the locals, they realized that their choice not to take the golden "<<Object<<" had revitalized the spirit of the kingdom.\n\n"; Sleep(4000);
            cout << "End.\n\n"; Sleep(4000);

            cout << "Do you want to play again?\n";
            cout << "Y for yes N for no\n\n";
            cin >> snjugar;

            if (snjugar == 'y' || snjugar == 'Y') //Condició si snjugar es igual a y o a Y
            {
                system("cls");
                jugar = true;
            }
            else
            {
                jugar = false;
            }
        }
    }
    return 0; //Final programa
}