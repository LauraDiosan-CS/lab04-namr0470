//#include "repo.h"
//
//#include <iostream>
//
//using namespace std;
//
//
////constructor fara param
//template <typename T>
//repo<T>::repo() {
//}
//
////destructorul
//template <typename T>
//repo<T>::~repo()
//{}
//
////adaugarea unui element
//template <typename T>
//void repo<T>::addElem(T carte) {
//	this->elem.push_back(carte);
//}
//
////returnarea tuturor elementelor
//template <typename T>
//deque<T> repo<T>::getAll() {
//	return this->elem;
//}
//
////dimensiunea vectorului
//template <typename T>
//int repo<T>::getSize() {
//	return this->elem.size();
//}
//
////actualizare
//template <typename T>
//void repo<T>::updateElem(int p, T carte) {
//	this->elem[p] = carte;
//}
//
////stergere dupa pozitie
//template <typename T>
//void repo<T>::deleteElem(int p) {
//	if (p > -1) {
//		this->elem.erase(this->elem.begin() + p);
//	}
//}