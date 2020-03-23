#pragma once
#pragma once

#include <iostream>
#include <string>
#include "Service.h"

using namespace std;

class UI {
private:
	service serv;
public:
	UI();
	~UI();
	void adauga(service& serv);
	void update(service& serv);
	void deleteElem(service& serv);
	void insereaza(service& serv);
	void afisareAll(service& serv);
	void incarcaElemente(service& serv);
	//void afisareIN(service& serv);
	int getinput();
	void afisaremeniu();

};
