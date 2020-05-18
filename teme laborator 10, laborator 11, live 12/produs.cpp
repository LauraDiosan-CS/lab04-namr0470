#include "produs.h"


produs::produs() :Articol() {

	this->end_date = "";
}

produs::~produs() {
	this->end_date = "";
}

produs::produs(const produs& pet_stuff) :Articol(pet_stuff) {

	this->end_date = pet_stuff.end_date;
}


produs::produs(std::string id, std::string name, std::string date, int price, int number_of_pieces, std::string end_date) :
	Articol(id, name, date, price, number_of_pieces) {

	this->end_date = end_date;
	//Pet_stuff::Produce(id, name, date, price, number_of_pieces);
}

//Setter
void produs::set_end_date(std::string new_end_date) {

	this->end_date = new_end_date;
}

//Getter
std::string produs::get_end_date() {

	return this->end_date;
}

//Overloading operators

produs& produs::operator=(const produs& pet_stuff) {

	this->end_date = pet_stuff.end_date;
	Articol::operator=(pet_stuff);

	return *this;
}

Articol* produs::clone()
{
	return new produs(*this);
}

std::string produs::toStringDelimiter(std::string delim)
{
	return "AP" + delim + Articol::toStringDelimiter(delim) + delim + end_date;
}

bool produs:: operator == (const produs& petStuff) {

	return Articol::operator==(petStuff) and petStuff.end_date == end_date;
}

