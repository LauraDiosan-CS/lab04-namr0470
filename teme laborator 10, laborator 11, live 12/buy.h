#pragma once
#include "comanda.h"

class Shopping : public Comanda {
private:
	string listaCump;
public:
	Shopping();
	Shopping(string, int, string);
	Shopping(const Shopping& s);
	Shopping(string, char);
	~Shopping();
	string getListaCumparaturi();
	string getMagazin();
	Shopping& operator=(const Shopping& s);
	bool operator==(const Shopping& s);
	friend istream& operator>>(istream& is, Shopping& s);
	friend ostream& operator<<(ostream& os, const Shopping& s);
};