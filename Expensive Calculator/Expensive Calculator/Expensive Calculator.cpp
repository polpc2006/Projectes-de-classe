// Expensive Calculator.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int main()  //Expensive calculator
{
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
   

    num1 = 7;
    num2 = 3;
    num3 = 5;
    num4 = 7.0;
    num5 = 3.0;


    /*
    cout << "7+3=" << num1 + num2 << endl;
    cout << "7-3=" << num1 - num2 << endl;
    cout << "7*3=" << num1 * num2 << endl;
    cout << "7/3=" << num1 / num2 << endl;
    cout << "7.0/3.0=" << num4 / num5 << endl;
    cout << "7 % 3=" << num1 % num2 << endl;
    cout << "7 + 3 * 5=" << num1 + num2 * num3 << endl;
    cout << "(7 + 3) * 5=" << (num1 + num2) * num3 << endl;
    cout << "(num1 * num3 + (num2 + num4)) / num5=" << (num1 * num3 + (num2 + num4)) / num5 << endl;
    */
    cout << "(Introdueix el numero1)";
    cin >> num1;
    cout << "(Introdueix el numero2)";
    cin >> num2;
    cout << "num1 + num2\n=" << (num1 + num2); 
    cout << "num1 - num2\n=" << (num1 - num2);
    cout << "num1 * num2\n=" << (num1 * num2);
    cout << "num1 / num2\n=" << (num1 / num2);
    cout << "(Introdueix el numero3)";
    cin >> num3;
    cout << "num1 * num2 + num3\n=" << (num1 * num2 + num3);
    cout << "(Descobreix el num4)";
    num4 = num1 + 3;
    cout << "(num1 + num2+ num3 + num4)\n" << (num1 + num2 + num3 + num4);
    return 0;
}
/*
int main() 
{
    int length; //this declares a variable 

    length = 7; //this assigns 7 to length

    cout << "The length is ";
    cout << length; //This displays 7

    return 0;
}*/
/*
int main() 
{
    int score;
    double distance;
    char PlayAgain;
    int lives;
    int aliensKilled;
    double engineTemp;
    int fuel;
    int bonus;

    score = 0;
    distance = 1200.76;
    PlayAgain = 'y';
    lives = 3;
    aliensKilled = 10;
    engineTemp = 6572.89;
    bonus = 10;

    cout << "score: " << score <<endl;
    cout << "distance: " << distance << endl;
    cout << "PlayAgain: " << PlayAgain << endl;
    cout << "lives: " << lives << endl;
    cout << "aliensKilled: " << aliensKilled << endl;
    cout << "engineTemp: " << engineTemp << endl;
    cout << "How much fuel?" << endl;
    cin >> fuel;
    cout << "fuel: " <<fuel << endl;
    cout << "bonus: " << bonus << endl;
}*/


