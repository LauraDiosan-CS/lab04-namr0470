#include "animal.h"
#include <iostream>
#include <string>
animal::animal() :Articol() {

	this->age = 0;
}

animal::~animal() {

	this->age = 0;
}
animal::animal(const animal& pet) :Articol(pet) {

	this->age = pet.age;
}


animal::animal(std::string id, std::string name, std::string date, int price, int number_of_pieces, int age) :
	Articol(id, name, date, price, number_of_pieces) {

	this->age = age;
}

//Setter
void animal::set_age(int new_age) {

	this->age = new_age;
}

//Getter
int animal::get_age() {

	return this->age;
}

//Overloading operators

animal& animal::operator = (const animal& pet) {

	Articol::operator = (pet);
	this->set_age(pet.age);

	return *this;
}

Articol* animal::clone()
{
	return new animal(*this);
}

std::string animal::toStringDelimiter(std::string delim)
{
	return "AA" + delim + Articol::toStringDelimiter(delim) + delim + std::to_string(age);
}

bool animal:: operator == (const animal& pet) {

	return Articol::operator==(pet) and pet.age == age;
}
