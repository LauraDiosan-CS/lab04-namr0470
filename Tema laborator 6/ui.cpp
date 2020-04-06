#pragma once
#include "entitate.h"
#include "service.h"
#include "ui.h"
#include <iostream>

using namespace std;

void ui::addElem() {
	char* titlu = new char[10];
	char* autor = new char[10];
	char* status = new char[10];
	cout << "Dati titlul: ";
	cin >> titlu;
	cout << "Dati autorul: ";
	cin >> autor;
	cout << "Dati statusul: ";
	cin >> status;
	serv.addElem(titlu, autor, status);
	cout << "Adaugat cu succes!";
}

void ui::deleteElem() {
	char* titlu = new char[10];
	char* autor = new char[10];
	char* status = new char[10];
	cout << "Dati titlul de sters: ";
	cin >> titlu;
	cout << "Dati autorul de sters: ";
	cin >> autor;
	cout << "Dati statusul de sters: ";
	cin >> status;
	serv.delElem(titlu, autor, status);
	
}

void ui::updateElem() {
	cout << "Dati cartea de actualizat: ";
	char* titlu = new char[10];
	char* autor = new char[10];
	char* status = new char[10];
	cout << "Dati titlul: ";
	cin >> titlu;
	cout << "Dati autorul: ";
	cin >> autor;
	cout << "Dati statusul: ";
	cin >> status;
	Entitate carte(titlu, autor, status);

	char* titluN = new char[10];
	char* autorN = new char[10];
	char* statusN = new char[10];
	cout << "Dati titlul nou: ";
	cin >> titluN;
	cout << "Dati autorul nou: ";
	cin >> autorN;
	cout << "Dati statusul nou: ";
	cin >> statusN;
	serv.updateElem(carte, titluN, autorN, statusN);
}

void ui::showAll() {
	cout << " Toate cartile: " << endl;
	cout << "----------------" << endl;
	vector<Entitate> carti = serv.getAll();
	for (Entitate e : carti)//"range based for loop"~Java,C#
		cout << e;
	cout << "| ------------------------ |" << endl;
}

ui::ui(){}

ui::~ui(){}

ui::ui(serviceT& s) {
	serv = s;
}

void ui::showui() {
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << " OPTIUNI: " << endl;
		cout << " 1. Adauga " << endl;
		cout << " 2. Sterge " << endl;
		cout << " 3. Update " << endl;
		cout << " 4. Afisare totala " << endl;
		cout << " 0. Exit " << endl;
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		switch (opt)
		{
		case 1: {addElem(); break; }
		case 2: {deleteElem(); break; }
		case 3: {updateElem(); break; }
		case 4: {showAll(); break; }
		case 0: {gata = true; cout << " La revedere! " << endl; }
		default:
			cout << "Optiune invalida!";
		}
	}
}