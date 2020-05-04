#include "produs.h"
#include "utils.h"
using namespace std;


Produs::Produs()
{
	p_pret = 0.0;
	p_nr_exemplare = 0;
}

Produs::Produs(Animal& an, int c, string n, double p , string di, string de, int nr)
{
	a = an;
	p_cod = c;
	p_nume = n;
	p_pret = p;
	p_data_in = di;
	p_data_exp = de;
	p_nr_exemplare = nr;
}

Produs::Produs(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	a.cod = stoi(tokens[0]);
	a.nume = tokens[1];
	a.pret = stoi(tokens[2]);
	a.data = tokens[3];
	a.varsta = stoi(tokens[4]);
	a.nr_exemplare = stoi(tokens[5]);

	p_cod = stoi(tokens[6]);
	p_nume = tokens[7];
	p_pret = stoi(tokens[8]);
	p_data_in = tokens[9];
	p_data_exp = tokens[10];
	p_nr_exemplare = stoi(tokens[11]);
}

Produs::Produs(const Produs& p)
{
	a = p.a;
	p_cod = p.p_cod;
	p_nume = p.p_nume;
	p_pret = p.p_pret;
	p_data_in = p.p_data_in;
	p_data_exp = p.p_data_exp;
	p_nr_exemplare = p.p_nr_exemplare;
}

Animal Produs::getAnimal()
{
	return a;
}

void Produs::setAnimal(Animal& ap)
{
	a = ap;
}

void Produs::setCod(int c)
{
	p_cod = c;
}

int Produs::getCod()
{
	return p_cod;
}

void Produs::setNume(string n)
{
	p_nume = n;
}

string Produs::getNume()
{
	return p_nume;
}

void Produs::setPret(double p)
{
	p_pret = p;
}

double Produs::getPret()
{
	return p_pret;
}

void Produs::setDataI(string d)
{
	p_data_in = d;
}

string Produs::getDataI()
{
	return p_data_in;
}

void Produs::setDataE(string d)
{
	p_data_exp = d;
}

string Produs::getDataE()
{
	return p_data_exp;
}

void Produs::setNrEx(int n)
{
	p_nr_exemplare = n;
}

int Produs::getNrEx()
{
	return p_nr_exemplare;
}

bool Produs::operator==(const Produs& p)
{
	return a.operator==(p.a) and (p_cod == p.p_cod) and (p_nume == p.p_nume) and (p_pret == p.p_pret) and (p_data_in == p.p_data_in) and (p_data_exp == p.p_data_exp) and (p_nr_exemplare == p.p_nr_exemplare);
}

string Produs::toString()
{
	return a.toString() + " " + to_string(p_cod) + " " + p_nume + " " + to_string(p_pret) + " " + p_data_in + " " + p_data_exp + " " + to_string(p_nr_exemplare);
}

string Produs::toStringDelimiter(char delim)
{
	return a.toStringDelimiter(delim) + delim + to_string(p_cod) + delim + p_nume + delim + to_string(p_pret) + delim + p_data_in + delim + p_data_exp + delim + to_string(p_nr_exemplare);
}

Produs::~Produs()
{
}
