#include "repoArray.h"

repoArray::repoArray() { size = 0; }

void repoArray::addElem(Magazin m) {
	elem[size++] = m;
}

int repoArray::findElem(Magazin m) {
	int i = 0;
	while (i < size) {
		if (elem[i] == m) return i;
	}
	return -1;
}

void repoArray::delElem(Magazin m) {
	int i = findElem(m);
	if (i != -1)
	{
		elem[i] = elem[size - 1];
	}
	size--;
}

void repoArray::updateElem(Magazin m, char* nume, char* data, int pret) {
	int i = findElem(m);
	elem[i].setNume(nume);
	elem[i].setData(data);
	elem[i].setPret(pret);
}

Magazin* repoArray::getAll() {
	return elem;
}

int repoArray::dim() {
	return size;
}

repoArray::~repoArray() {
}

Magazin repoArray::getItemFromPos(int i) {
	return elem[i];
}
