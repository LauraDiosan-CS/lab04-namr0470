#pragma once
#include "Entitate.h" 
#include <deque>

using namespace std;

template <typename T>
class repoT
{
private:
	deque <T> elem;

public:
	repoT();
	~repoT();
	void addElem(T);
	void updateElem(T,char*,char*,char*);
	void deleteElem(T);
	deque<T> getAll();
	int getSize();
};



//constructor fara param
template <class T>
repoT<T>::repoT() {
}

//destructorul
template <typename T>
repoT<T>::~repoT()
{}

//adaugarea unui element
template <typename T>
void repoT<T>::addElem(T carte) {
	this->elem.push_back(carte);
}

//returnarea tuturor elementelor
template <typename T>
deque<T> repoT<T>::getAll() {
	return this->elem;
}

//dimensiunea vectorului
template <typename T>
int repoT<T>::getSize() {
	return this->elem.size();
}

//actualizare
template <typename T>
void repoT<T>::updateElem(T carte,  char* titlu, char* autor, char* status) {
	/*vector<Entitate>::iterator it;
	it = find(elem.begin(), elem.end(), carte);
	if (it != elem.end()) {
		(*it).setTitlu(titlu);
		(*it).setAutor(autor);
		(*it).setStatus(status);
	}*/
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == carte) {
			elem[i].setTitlu(titlu);
			elem[i].setAutor(autor);
			elem[i].setStatus(status);
		}
	}
}

//stergere dupa pozitie
template <typename T>
void repoT<T>::deleteElem(T carte) {
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i] == carte) {
			int pos = i;
			elem.erase(elem.begin() + pos);
		}
	}
}

