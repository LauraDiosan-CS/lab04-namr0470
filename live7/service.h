#pragma once
#include "repo.h"
#include "entitate.h"

#include<vector>
using namespace std;

class serviceT {
private:
	repoT<Entitate> rep;
public:
	serviceT();
	void addElem(const char* titlu, const char* autor, const char* status);
	void delElem(const char* titlu, const char* autor, const char* status);
	Entitate updateElem(Entitate, char* titlu, char* autor, char* status);
	vector<Entitate> getAll();
	~serviceT();
};
