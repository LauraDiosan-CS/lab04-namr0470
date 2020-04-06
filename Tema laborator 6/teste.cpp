#include "entitate.h"
#include "repo.h"
#include "assert.h"
#include "service.h"


void test1() {
	Entitate t("Invitatia la vals","Mihail Drumes", "da");
	Entitate t1("Jane Eyre", "Charlotte Bronte", "da");
	Entitate t2("Harry Potter", "J. K. Rowling", "nu");
	repoT<Entitate> elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
}


void test2() {
	Entitate t("Invitatia la vals", "Mihail Drumes", "da");
	Entitate t1("Jane Eyre", "Charlotte Bronte", "da");
	Entitate t2("Harry Potter", "J. K. Rowling", "nu");
	repoT<Entitate> elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	deque<Entitate> rez = elem.getAll();
	assert(rez.size() == 3);
}

void test3() {
	Entitate t("Invitatia la vals", "Mihail Drumes", "da");
	Entitate t_nou("Jane Eyre", "Charlotte Bronte", "da");
	repoT<Entitate> elem;
	elem.addElem(t);
	elem.addElem(t_nou);
	deque<Entitate> rez = elem.getAll();
	assert(rez.size() == 2);
	elem.deleteElem(t_nou);
	deque<Entitate> rez1 = elem.getAll();
	assert(rez1.size() == 1);

}


