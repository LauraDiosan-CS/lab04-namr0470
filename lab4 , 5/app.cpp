// lab4_v.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "service.h"
#include "teste.h"
#include "magazin.h"
#include "repoSTL.h"
#include "ui.h"

using namespace std;

int main()
{
	cout << "start tests..." << endl;
	test1();
	test2();
	test3();
	test4();
	cout << "succes" << endl;

	int n;
	int option;
	UI u;
	service serv;
	u.incarcaElemente(serv); //ca sa avem deja cateva elemente
	u.afisareAll(serv);
	bool stop = false;
	while (stop == false) {
		u.afisaremeniu();
		option = u.getinput();
		if (option == 1) {
			u.adauga(serv);
			u.afisareAll(serv);
		}
		if (option == 2) {
			u.deleteElem(serv);
			u.afisareAll(serv);
		}
		if (option == 3) {
			u.update(serv);
			u.afisareAll(serv);
		}
		if (option == 4) {
			u.afisareAll(serv);
		}
		if (option == 5) {
			stop = true;
		}
	}
	return 0;
}