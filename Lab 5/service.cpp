#include <iostream>
#include <string>
#include "service.h"
#include <algorithm>

using namespace std;

//constructor
service::service() {
	this->rep;
	this->undoList.push_back(this->rep);
}

//destructor
service::~service() {
}

//adauga un element de tip entitate in Repo
void service::adauga(Magazin& m) {
	this->undoList.push_back(this->rep);
	rep.addElem(m);
}

//sterge un element
void service::deleteElem(Magazin& m) {
	this->undoList.push_back(this->rep);
	rep.delElem(m);
}

//actualizarea unui element
void service::update(Magazin& m) {
	this->undoList.push_back(this->rep);
	rep.update(m);
}

//insereaza un element de tip entitate pe o anumita pozitie
void service::insert(Magazin& m) {
	rep.insertElem(m);
}

//afisare all
vector<Magazin> service::getAll() {
	return rep.getAll();
}

//incarca elemente de tip entitate in repo
void service::incarcaElemente() {
	rep.incarcaElemente();
}

//undo
void service::undo() {
	auto actual_state = undoList.back();
	undoList.pop_back();
	this->rep = actual_state;
	this->undoList = undoList;
}


