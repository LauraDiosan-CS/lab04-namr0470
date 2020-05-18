#pragma once
#include <ostream>
#include "utils.h"
using namespace std;

class Comanda {
protected:
	string articol;
	int pret;
public:
	Comanda();
	Comanda(string articol, int pret);
	Comanda(const Comanda& c);
	~Comanda() {};
	virtual string getArticol();
	virtual int getPret();
	void setArticol(string a);
	void setPret(int  pret);
	string toStringCSV();
};