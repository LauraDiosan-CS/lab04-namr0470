#include "repoArray.h"

repoArray::repoArray() { size = 0; }

void repoArray::addElem(Cheltuieli c) {
	elem[size++] = c;
}

int repoArray::findElem(Cheltuieli c) {
	int i = 0;
	while (i < size) {
		if (elem[i] == c) return i;
	}
	return -1;
}

void repoArray::delElem(Cheltuieli c) {
	int i = findElem(c);
	if (i != -1)
	{
		elem[i] = elem[size - 1];
	}
	size--;
}

void repoArray::updateElem(Cheltuieli c, int zi, int pret, char* tip) {
	int i = findElem(c);
	elem[i].setZi(zi);
	elem[i].setPret(pret);
	elem[i].setTip(tip);
}

Cheltuieli* repoArray::getAll() {
	return elem;
}

int repoArray::dim() {
	return size;
}

repoArray::~repoArray() {
}

Cheltuieli repoArray::getItemFromPos(int i) {
	return elem[i];
}