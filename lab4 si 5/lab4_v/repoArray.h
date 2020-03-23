#pragma once
#include "magazin.h"

class repoArray {
private:
	Magazin elem[10];
	int size;
public:
	repoArray();
	void addElem(Magazin);
	int findElem(Magazin);
	Magazin getItemFromPos(int);
	void delElem(Magazin);
	void updateElem(Magazin, char*, char*, int);
	Magazin* getAll();
	int dim();
	~repoArray();
};