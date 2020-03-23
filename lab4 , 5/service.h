#pragma once
#pragma once

#include <iostream>
#include <string>
#include "repoSTL.h"
using std::vector;

using namespace std;


class service
{
private:
	repoSTL rep;
public:
	service();
	~service();
	void adauga(Magazin& m);
	void insert(Magazin& m);
	void deleteElem(Magazin& m);
	void update(Magazin& m);
	vector<Magazin> getAll();
	void incarcaElemente();
};
