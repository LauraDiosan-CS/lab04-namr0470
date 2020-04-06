#include "service.h"
#include <algorithm>
using namespace std;

serviceT::serviceT(){}

serviceT::~serviceT(){}

void serviceT::addElem(const char* titlu, const char* autor, const char* status) {
	Entitate c(titlu, autor, status);
	rep.addElem(c);
}

void serviceT::delElem(const char* titlu, const char* autor, const char* status) {
	Entitate c(titlu, autor, status);
	rep.deleteElem(c);
}

Entitate serviceT::updateElem(Entitate carte, char* titlu, char* autor, char* status) {
	rep.updateElem(carte, titlu, autor, status);
	return carte;
}

vector<Entitate> serviceT::getAll() {
	deque<Entitate> rez = rep.getAll();
	vector<Entitate> v(rez.begin(), rez.end());
	return v;
}



