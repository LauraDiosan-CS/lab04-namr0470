#include "repo.h"

#include <iostream>
#include <ctime> 
#include <time.h>

using namespace std;


//constructor fara param*
repo::repo() {
	this->elem;
}

//constuctor de copiere*
repo::repo(const repo& r) {
	this->elem = r.elem;
}


//adaugarea unui element*
void repo::addElem(Magazin m) {
	elem.push_back(m);
}



//gasirea unui element (true sau false)*
bool repo::findElem(Magazin m) {
	vector<Magazin>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end()) return true;
	return false;

}

//dimensiunea vectorului*
int repo::getSize() {
	return elem.size();
}

//gasirea elementului dupa o pozitie data*
Magazin repo::getItemFromPos(int i) {
	return elem[i];
}

//destructorul*
repo::~repo()
{}

//returnarea tuturor elementelor*
vector<Magazin> repo::getAll() {
	return elem;
}

//stergerea unui element*
void repo::delElem(Magazin s) {
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == s) {
			int pos = i;
			elem.erase(elem.begin() + pos);
		}
	}
}

//eliminare dupa pozitie
vector<Magazin> repo::deleteElem(Magazin s) {
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == s) {
			int pos = i;
			elem.erase(elem.begin() + pos);
		}
	}
	return elem;
}

//actualizarea unui element*
void repo::update(Magazin s) {
	for (int i = 0; i < elem.size(); i++)
		if (elem[i] == s)
		{
			cout << "Introduceti modificarile: " << endl;
			int pret;
			char nume[20];
			char data[10];
			cout << "Dati data: ";
			cin >> data;
			cout << "Dati pretul: ";
			cin >> pret;
			int cont = 0;
			if (pret < 0)
			{
				while (cont == 0)
				{
					cout << "Dati un numar intreg pozitiv! " << endl;
					cin >> pret;
					if (pret >= 0)
						cont++;
				}
			}
			cout << "Dati numele: ";
			cin >> nume;
			elem[i].setNume(nume);
			elem[i].setPret(pret);
			elem[i].setData(data);
			return;
		}
}

//incarcarea unor elemente*
void repo::incarcaElemente() {
	Magazin m1 = Magazin("deodorant", "12.01.2020", 30);
	Magazin m2 = Magazin("sapun", "13.01.2020", 10);
	Magazin m3 = Magazin("faina", "12.05.2020", 90);

	elem.push_back(m1);
	elem.push_back(m2);
	elem.push_back(m3);
}

//insereaza element pe o pozitie data*
void repo::insertElem(Magazin& m) {
	int pos;
	cout << "Dati pos";
	cin >> pos;
	elem.insert(elem.begin() + pos, m);

}

