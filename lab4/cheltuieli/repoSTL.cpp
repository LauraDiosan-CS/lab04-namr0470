#include "repoSTL.h"


repoSTL::repoSTL() {
}

void repoSTL::addElem(Cheltuieli c) {
	elem.push_back(c);
}

void repoSTL::delElem(Cheltuieli c) {
	vector<Cheltuieli>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end()) elem.erase(it);
}

bool repoSTL::findElem(Cheltuieli c) {
	vector<Cheltuieli>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end()) return true;
	return false;
}

int repoSTL::dim() {
	return elem.size();
}

Cheltuieli repoSTL::getItemFromPos(int i) {
	return elem[i];
}

repoSTL::~repoSTL()
{}

vector<Cheltuieli>repoSTL::getAll() {
	return elem;
}

void repoSTL::updateElem(Cheltuieli c, int zi, int pret, char* tip) {
	for (int i = 0; i < elem.size(); i++)
	{
		if (elem[i] == c)
		{
			elem[i].setZi(zi);
			elem[i].setPret(pret);
			elem[i].setTip(tip);
		}
	}
}
