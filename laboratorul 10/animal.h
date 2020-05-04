#pragma once

#include <string>
using namespace std;

class Animal
{
private:
	int cod;
	string nume;
	double pret;
	string data;
	int varsta;
	int nr_exemplare;
public:
	Animal();
	Animal(int, string, double, string, int, int);
	Animal(string, char);
	Animal(const Animal&);

	int getCod();
	string getNume();
	double getPret();
	string getData();
	int getVarsta();
	int getNrExemplare();

	void setCod(int);
	void setNume(string);
	void setPret(double);
	void setData(string);
	void setVarsta(int);
	void setNrExemplare(int);

	bool operator==(const Animal&);
	string toString();
	string toStringDelimiter(char);
	~Animal();
	friend class Produs;
};

