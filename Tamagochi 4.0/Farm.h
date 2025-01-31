#pragma once
#include  <vector>

using namespace std;

class Farm {
public:
	void AddPet(); //Afegeix nova mascota
	void ListPets(); //Llistar totes les mascotes
	vector<Pet>& GetPets(); //Agafar el valor del vector de les mascotes
private:
	vector<Pet> pets; //Vector mascotes
};