#pragma once
#include "cheltuieli.h"

class repoArray {
private:
	Cheltuieli elem[10];
	int size;
public:
	repoArray();
	void addElem(Cheltuieli);
	int findElem(Cheltuieli);
	Cheltuieli getItemFromPos(int);
	void delElem(Cheltuieli);
	void updateElem(Cheltuieli, int, int, char*);
	Cheltuieli* getAll();
	int dim();
	~repoArray();
};