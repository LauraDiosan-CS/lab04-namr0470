#pragma once
#include "cheltuieli.h"
#include <vector>

using namespace std;

class repoSTL {
private:
	vector<Cheltuieli> elem;
public:
	repoSTL();
	void addElem(Cheltuieli);
	bool findElem(Cheltuieli);
	void delElem(Cheltuieli);
	void updateElem(Cheltuieli, int, int, char*);
	Cheltuieli getItemFromPos(int);
	vector<Cheltuieli> getAll();
	int dim();
	~repoSTL();
};