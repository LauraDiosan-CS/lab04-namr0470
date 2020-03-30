
#pragma once

#include <iostream>
#include <string>
#include "repo.h"
using std::vector;

using namespace std;


class service
{
private:
	repo rep;
	vector <repo> undoList;
public:
	service();
	~service();
	void adauga(Magazin& m);
	void insert(Magazin& m);
	void deleteElem(Magazin& m);
	void update(Magazin& m);
	vector<Magazin> getAll();
	void incarcaElemente();
	void undo();
};
