#include "validProdus.h"
#include <iostream>
using namespace std;

ValidatorProdus::ValidatorProdus()
{
	err = 0;
	mesaj = "";
}


int ValidatorProdus::validate(produs e, int contor)
{
	err = 0;
	mesaj = "";
	if (e.get_name() == "-") {
		err++; mesaj += "Numele nu trebuie sa fie vid! ";
	}
	if (e.get_number_of_pieces() <= 0 ) {
		err++; mesaj += "Numarul de bucati nenule! ";
	}
	if (e.get_price() <=0) {
		err++; mesaj += "Pret nenul! ";
	}
	if (contor != 0) {
		err++; mesaj += "ID-ul trebuie sa fie unic! ";
	}
	return err;
}


string ValidatorProdus::toString() {
	return mesaj;
}

ValidatorProdus::~ValidatorProdus() {
}