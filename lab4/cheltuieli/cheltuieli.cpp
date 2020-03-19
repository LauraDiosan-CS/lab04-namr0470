#include "cheltuieli.h"
#include <string.h>

Cheltuieli::Cheltuieli() {
	zi = 0;
	pret = 0;
	tip = NULL;
}

Cheltuieli::Cheltuieli(int zi, int pret, const char* tip) {
	this->zi = zi;
	this->pret = pret;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

Cheltuieli::Cheltuieli(const Cheltuieli& c) {
	this->zi = c.zi;
	this->pret = c.pret;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
}

int Cheltuieli::getZi() {
	return zi;
}

void Cheltuieli::setZi(int z) {
	zi = z;
}

int Cheltuieli::getPret() {
	return pret;
}

void Cheltuieli::setPret(int p) {
	pret = p;
}

char* Cheltuieli::getTip() {
	return tip;
}

void Cheltuieli::setTip(char* t){
	if (tip) delete[]tip;
	tip = new char[strlen(t) + 1];
	strcpy_s(tip, strlen(t) + 1, t);
}

Cheltuieli::~Cheltuieli() {
	if (tip) delete[]tip;
	tip = NULL;
	zi = -1;
	pret = -1;
}

Cheltuieli& Cheltuieli::operator=(const Cheltuieli& c) {
	if (this == &c) return *this;
	if (tip) delete[] tip;
	tip = new char[strlen(c.tip) + 1];
	strcpy_s(tip, strlen(c.tip) + 1, c.tip);
	zi = c.zi;
	pret = c.pret;
	return *this;
}

bool Cheltuieli::operator==(const Cheltuieli& c) {
	return (strcmp(tip, c.tip) == 0) and (zi == c.zi) and (pret == c.pret);
}