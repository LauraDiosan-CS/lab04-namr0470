#include <iostream>
#include <string>
#include "UI.h"
#include <ctime> 
#include <time.h>
#include <string.h>
#include "teste.h"
#include "Magazin.h"
#include "repoSTL.h"

using namespace std;

UI::UI() {
	this->serv;
}

UI::~UI() {

}

//ui pentru adaugare
void UI::adauga(service& serv) {
	int pret;
	char nume[10];
	char data[20];
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
	cout << endl;
	cout << "Dati data: ";
	cin >> data;
	cout << endl;
	Magazin m(nume, data, pret);
	serv.adauga(m);
}

void UI::deleteElem(service& serv) {
	int poz = 0; int nr_elem;
	vector<Magazin> elem = serv.getAll();
	nr_elem = elem.size();
	cout << "Dati pozitia elementului pe care doriti sa-l stergeti: (intre 1 si " << nr_elem << ") ";
	cin >> poz;
	cout << endl;
	serv.deleteElem(elem[poz - 1]);

}

void UI::update(service& serv) {
	int elem_update = 0;
	int nr_poz = 0;
	vector<Magazin> elem = serv.getAll();
	nr_poz = elem.size();
	cout << "Dati pozitia elementului pe care doriti sa-l schimbati: (intre 1 si " << nr_poz << ") ";
	cin >> elem_update;
	cout << endl;
	serv.update(elem[elem_update - 1]);
}

//ui pt inserare
void UI::insereaza(service& serv) {
	int pret;
	char nume[10];
	char data[20];
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
	cout << endl;
	cout << "Dati data: ";
	cin >> data;
	cout << endl;
	Magazin m(nume, data, pret);
	serv.adauga(m);
}

//afiseaza toate elem din vector
void UI::afisareAll(service& serv) {
	vector<Magazin> elem = serv.getAll();
	for (int i = 0; i < elem.size(); i++) {
		cout << i + 1 << ".) ";
		elem[i].afisare();
		cout << endl;
	}
}

//incarca elemente
void UI::incarcaElemente(service& serv) {
	serv.incarcaElemente();
}


//ia input de la tastatura pt o optiune din meniu
int UI::getinput() {
	int choice;
	cin >> choice;
	return choice;
}

//afisarea meniului
void UI::afisaremeniu()
{
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << endl << "Main Menu\n" << endl;
	cout << "Optiuni:\n";
	cout << "1 - Adaugare\n";
	cout << "2 - Stergere\n";
	cout << "3 - Update\n";
	cout << "4 - Afisare\n";
	cout << "5 - Exit\n";
	cout << endl << "Alegeti optiunea: ";
}