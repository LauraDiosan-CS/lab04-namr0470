#pragma once
#include "magazin.h"
#include <vector>

using namespace std;

class repoSTL {
private:
	vector<Magazin> elem;
public:
	repoSTL();
	repoSTL(const repoSTL& r);
	void addElem(Magazin);
	bool findElem(Magazin);
	vector<Magazin>deleteElem(Magazin);
	void update(Magazin);
	void delElem(Magazin);
	void incarcaElemente();
	Magazin getItemFromPos(int);
	vector<Magazin> getAll();
	int getSize();
	void insertElem(Magazin& m);
	~repoSTL();
};