#pragma once
#include "animal.h"


class Produs
{
private:
	Animal a;
	string p_cod;
	string p_nume;
	double p_pret;
	string p_data_in;
	string p_data_exp;
	int p_nr_exemplare;
public:
	Produs();
	Produs(Animal&, string, string, double, string, string, int);
	Produs(string, char);
	Produs(const Produs&);
	~Produs();

	Animal getAnimal();
	void setAnimal(Animal&);

	string getCod();
	void setCod(string);

	string getNume();
	void setNume(string);

	double getPret();
	void setPret(double);

	string getDataI();
	void setDataI(string);

	string getDataE();
	void setDataE(string);

	int getNrEx();
	void setNrEx(int);
	

	bool operator==(const Produs&);
	string toString();
	string toStringDelimiter(char delim);
	
};