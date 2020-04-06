#include "entitate.h"
#include <string.h>
#include <iostream>
#include <istream>
#include <cstddef>
#include <ostream>

using namespace std;

//constructor default(fara param)
Entitate::Entitate() {
	this->titlu = NULL;
	this->autor = NULL;
	this->status = NULL;
}

//constructor cu param
Entitate::Entitate(const char* titlu, const char* autor, const char* status) {
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, strlen(autor) + 1, autor);
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
	
}

//constructor de copiere
Entitate::Entitate(const Entitate& s) {
	this->titlu = new char[strlen(s.titlu) + 1];
	strcpy_s(this->titlu, strlen(s.titlu) + 1, s.titlu);
	this->autor = new char[strlen(s.autor) + 1];
	strcpy_s(this->autor, strlen(s.autor) + 1, s.autor);
	this->status = new char[strlen(s.status) + 1];
	strcpy_s(this->status, strlen(s.status) + 1, s.status);
}

//getter pentru titlu
char* Entitate::getTitlu() {
	return this->titlu;
}

//setter pentru titlu
void Entitate::setTitlu(char* t) {
	if (titlu) delete[]titlu;
	titlu = new char[strlen(t) + 1];
	strcpy_s(titlu, strlen(t) + 1, t);
}

//getter pentru autor
char* Entitate::getAutor() {
	return this->autor;
}

//setter pentru autor
void Entitate::setAutor(char* d) {
	if (autor) delete[]autor;
	autor = new char[strlen(d) + 1];
	strcpy_s(autor, strlen(d) + 1, d);
}

//getter pentru status
char* Entitate::getStatus() {
	return this->status;
}

//setter pentru status
void Entitate::setStatus(char* d) {
	if (status) delete[]status;
	status = new char[strlen(d) + 1];
	strcpy_s(status, strlen(d) + 1, d);
}

//destructor
Entitate::~Entitate() {
	if (titlu) delete[]titlu;
	titlu = NULL;
	if (autor) delete[]autor;
	autor = NULL;
	if (status) delete[]status;
	status = NULL;
}

//suprascrie operatorul "=" pentru un element de tip entitate
Entitate& Entitate::operator=(const Entitate& s) {
	this->setTitlu(s.titlu);
	this->setAutor(s.autor);
	this->setStatus(s.status);
	return *this;
}

//operatorul de egalitate
bool Entitate::operator==(const Entitate& s) {
	return  (strcmp(titlu, s.titlu) == 0) && (strcmp(autor, s.autor) == 0) && (strcmp(status, s.status) == 0);
}

//afisarea1
ostream& operator<<(ostream& os, const Entitate& s)
{
	os << "Titlu: " << s.titlu << ", autor: " << s.autor << ", status: " << s.status << endl;
	return os;
}

//afisare2
void Entitate::afisare() {
	cout << "Titlu: " << this->titlu << ", autor: " << this->autor << ", status: " << this->status;

}
