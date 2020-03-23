#include "magazin.h"
#include <string.h>
#include <iostream>
#include <istream>
#include <cstddef>
#include <ostream>

using namespace std;

//constructor default(fara param)
Magazin::Magazin() {
	this->nume = NULL;
	this->data = NULL;
	this->pret = 0;
}

//constructor cu param
Magazin::Magazin(const char* nume, const char* data, int pret) {
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->data = new char[strlen(data) + 1];
	strcpy_s(this->data, strlen(data) + 1, data);
	this->pret = pret;
}

//constructor de copiere
Magazin::Magazin(const Magazin& m) {
	this->nume = new char[strlen(m.nume) + 1];
	strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);
	this->data = new char[strlen(m.data) + 1];
	strcpy_s(this->data, strlen(m.data) + 1, m.data);
	this->pret = m.pret;
}

//getter pentru nume
char* Magazin::getNume() {
	return this->nume;
}

//setter pentru nume
void Magazin::setNume(char* n) {
	if (nume) delete[]nume;
	nume = new char[strlen(n) + 1];
	strcpy_s(nume, strlen(n) + 1, n);
}

//getter pentru data
char* Magazin::getData() {
	return this->data;
}

//setter pentru data
void Magazin::setData(char* d) {
	if (data) delete[]data;
	data = new char[strlen(d) + 1];
	strcpy_s(data, strlen(d) + 1, d);
}

//getter pentru pret
int Magazin::getPret() {
	return this->pret;
}

//setter pentru pret
void Magazin::setPret(int p) {
	this->pret = p;
}

//destructor
Magazin::~Magazin() {
	if (nume) delete[]nume;
	nume = NULL;
	if (data) delete[]data;
	data = NULL;
	pret = -1;
}

//suprascrie operatorul "=" pentru un element de tip entitate
Magazin& Magazin::operator=(const Magazin& m) {
	this->setNume(m.nume);
	this->setData(m.data);
	this->setPret(m.pret);
	return *this;
}

//operatorul de egalitate
bool Magazin::operator==(const Magazin& m) {
	return (strcmp(nume, m.nume) == 0) and (strcmp(data, m.data) == 0) and (pret == m.pret);
}

//afisarea1
ostream& operator<<(ostream& os, const Magazin& m)
{
	os << "Nume: " << m.nume << ", data: " << m.data << ", pret: " << m.pret << endl;
	return os;
}

//afisare2
void Magazin::afisare() {
	cout << "Nume: " << this->nume << ", data: " << this->data << ", pret: " << this->pret;

}