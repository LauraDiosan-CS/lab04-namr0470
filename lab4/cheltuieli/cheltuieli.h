#pragma once

class Cheltuieli{
private:
	int zi;
	int pret;
	char* tip;
public:
	Cheltuieli();
	Cheltuieli(int, int, const char*);
	Cheltuieli(const Cheltuieli&);
	Cheltuieli& operator=(const Cheltuieli&);
	int getZi();
	int getPret();
	char* getTip();
	void setZi(int);
	void setPret(int);
	void setTip(char*);
	bool operator==(const Cheltuieli&);
	~Cheltuieli();
};