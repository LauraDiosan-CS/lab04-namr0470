#pragma once

#include <ostream>
using namespace std;

class Magazin {
private:
	char* nume;
	char* data;
	int pret;
public:
	Magazin();
	Magazin(const char* nume, const char* data, int pret);
	Magazin(const Magazin&);
	Magazin& operator=(const Magazin&);
	char* getNume();
	char* getData();
	int getPret();
	void setNume(char* nume);
	void setData(char* data);
	void setPret(int pret);
	bool operator==(const Magazin&);
	friend ostream& operator<<(ostream& os, const Magazin& m);
	void afisare();
	~Magazin();
};