#pragma once
#include <iostream>
using namespace std;

class Pet
{
public:
	void getPetName();
	string setPetName();
	
	void Stats();

	void Greet();
	void Play();

		void Timber();
		void Riddles();
		void TestQ();
		void RPS();

	void Talk();
	void Drink();
	void Eat();
	void Sleep();
	void takeShower();

	void ListenMusic();

	void CheckStats();
private:
	string petname = "a";
	
	int hunger = 5;
	int thirsty = 5;
	int boredom = 5;
	int sleepiness = 5;
	int cleanliness = 5;

	int valrand;
};