#include "validAnimal.h"
using namespace std;
#include <iostream>
#include <string.h>
#include <string>


ValidatorAnimal::ValidatorAnimal()
{
	err = 0;
	mesaj = "";
}


int ValidatorAnimal::validate(animal e, int contor)
{
	err = 0;
	mesaj = "";
	if (e.get_name() == "-") {
		err++; mesaj += "Numele nu trebuie sa fie vid! ";
	}
	if (e.get_age() <=0) {
		err++; mesaj += "Varsta diferita de zero! ";
	}
	if (e.get_price() < 1) {
		err++; mesaj += "Pret nenul! ";
	}
	if (contor != 0) {
		err++; mesaj += "ID-ul trebuie sa fie unic! ";
	}
	return err;
}

void ValidatorAnimal::showMesaj()
{
	if (mesaj != "")
	{
		cout << endl;
		cout << "--- ERORI ---: " << endl;
		cout << mesaj << endl;
		cout << endl;
	}
}

string ValidatorAnimal::toString() {
	return mesaj;
}


ValidatorAnimal::~ValidatorAnimal()
{
}