#include "comanda.h"
#include "utils.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

Comanda::Comanda() {
	this->articol = "";
	this->pret = 0;
}

Comanda::Comanda(string articol, int pret)
{
	this->articol = articol;
	this->pret = pret;
}

Comanda::Comanda(const Comanda& a) {
	this->articol = a.articol;
	this->pret = a.pret;
}


string Comanda::getArticol() {
	return this->articol;
}


int Comanda::getPret() {
	return this->pret;
}


void Comanda::setArticol(string articol)
{
	this->articol = articol;
}


void Comanda::setPret(int pret)
{
	this->pret = pret;
}

string Comanda::toStringCSV()
{
	string array = this->articol;
	float pret = this->pret;
	std::string articol(array); // CONVERT CHAR* TO STRING
	std::string pretS = std::to_string(pret);
	vector<string> atr;
	atr.push_back(articol);
	atr.push_back(pretS);
	string outstring;
	for (unsigned int i = 0; i < atr.size(); i++) {

		outstring += atr[i];
		if (i < atr.size() - 1) {

			outstring += ",";
		}
	}
	return outstring;

}