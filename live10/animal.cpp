#include "animal.h"
#include "utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;



Animal::Animal()
{
	pret = 0.0;
	varsta = 0;
	nr_exemplare = 0;
}



Animal::Animal(string c, string n, double p, string d, int v, int nr)
{
	cod = c;
	nume = n;
	pret = p;
	data = d;
	varsta = v;
	nr_exemplare = nr;
}


Animal::Animal(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	cod = tokens[0];
	nume = tokens[1];
	pret = stoi(tokens[2]);
	data = tokens[3];
	varsta = stoi(tokens[4]);
	nr_exemplare = stoi(tokens[5]);
}

Animal::Animal(const Animal& a)
{
	cod = a.cod;
	nume = a.nume;
	pret = a.pret;
	data = a.data;
	varsta = a.varsta;
	nr_exemplare = a.nr_exemplare;
}

string Animal::getCod()
{
	return cod;
}

string Animal::getNume()
{
	return nume;
}

double Animal::getPret()
{
	return pret;
}

string Animal::getData()
{
	return data;
}

int Animal::getVarsta()
{
	return varsta;
}

int Animal::getNrExemplare()
{
	return nr_exemplare;
}

void Animal::setCod(string c)
{
	cod = c;
}

void Animal::setNume(string n)
{
	nume = n;
}

void Animal::setPret(double p)
{
	pret = p;
}

void Animal::setData(string d)
{
	data = d;
}

void Animal::setVarsta(int v)
{
	varsta = v;
}

void Animal::setNrExemplare(int nr)
{
	nr_exemplare = nr;
}

bool Animal::operator==(const Animal& a)
{
	return (cod == a.cod) && (nume == a.nume) && (pret == a.pret) && (data == a.data) && (varsta == a.varsta) && (nr_exemplare == a.nr_exemplare);
}

string Animal::toString()
{

	return cod + " " + nume + " " + to_string(pret) + data + to_string(varsta) + " " + to_string(nr_exemplare);
}

string Animal::toStringDelimiter(char delim)
{
	return cod + delim + nume + delim + to_string(pret) + delim + data + delim + to_string(varsta) + delim + to_string(nr_exemplare);
}


Animal::~Animal()
{
}
