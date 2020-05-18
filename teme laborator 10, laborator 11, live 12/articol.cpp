#include "articol.h"
#include <ostream>
#include <string>

Articol::Articol()
{
	this->id = "";
	this->name = "";
	this->date = "";
	this->price = 0;
	this->number_of_pieces = 0;
}

Articol::Articol(const Articol& a) {

	this->id = a.id;
	this->name = a.name;
	this->date = a.date;
	this->price = a.price;
	this->number_of_pieces = a.number_of_pieces;
}

Articol::Articol(std::string id, std::string name, std::string date, int price, int number_of_pieces) {

	this->id = id;
	this->name = name;
	this->date = date;
	this->price = price;
	this->number_of_pieces = number_of_pieces;
}

Articol::~Articol()
{
	this->id = "";
	this->name = "";
	this->date = "";
	this->price = 0;
	this->number_of_pieces = 0;
}

//Setters
void Articol::set_id(std::string new_id) {

	this->id = new_id;
}

void Articol::set_name(std::string new_name) {

	this->name = new_name;
}

void Articol::set_date(std::string new_date) {

	this->date = new_date;
}

void Articol::set_price(int new_price) {

	this->price = new_price;
}


void Articol::set_number_of_pieces(int number_of_pieces) {

	this->number_of_pieces = number_of_pieces;

}

//Getters
std::string Articol::get_id() {

	return this->id;
}

std::string Articol::get_name() {

	return this->name;
}

std::string Articol::get_date() {

	return this->date;
}

int Articol::get_price() {

	return this->price;
}


int Articol::get_number_of_pieces() {

	return this->number_of_pieces;

}

Articol& Articol::operator =(const Articol& a) {

	this->set_id(a.id);
	this->set_name(a.name);
	this->set_date(a.date);
	this->set_price(a.price);
	this->set_number_of_pieces(a.number_of_pieces);

	return *this;
}

Articol* Articol::clone()
{
	return new Articol(*this);
}

bool Articol:: operator == (const Articol& a) {

	return a.id == id and a.name == name and a.price == price and a.date == date and a.number_of_pieces == number_of_pieces;
}

std::string Articol::toStringDelimiter(std::string delim)
{
	return id + delim + name + delim + date + delim + std::to_string(price) + delim + std::to_string(number_of_pieces);
}
