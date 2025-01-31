#include "Pet.h"
#include "Farm.h"
#include <cstdlib>
#include <ctime>
#include <vector>


// Funció per llistar totes les mascotes que hi ha a la granja
void Farm::ListPets() {
    // Recorrem el vector "pets" per mostrar totes les mascotes
	for (size_t i = 0; i < pets.size(); ++i) {
		cout << "Pet " << i << ": " << pets[i].getpetName() << endl;
	}
}
// Funció que retorna una referència al vector de mascotes de la granja
vector<Pet>& Farm::GetPets() {
	return pets;
}

// Funció per afegir nova mascota a la granja
void Farm::AddPet() {
    Pet newPet; //Crear nou objecte Pet
    string petName; //Nom nova mascota
    
    //Assignar el nou nom a la mascota
    cout << "Enter a name for your new pet: "; 
    cin >> petName;
    newPet.setPetName(petName);

    pets.push_back(newPet);  // Afegim la mascota al vector de Farm

    cout << "New pet added: " << newPet.getpetName() << endl; //Mostrar a l'usuari que s'ha afegit la mascota
}