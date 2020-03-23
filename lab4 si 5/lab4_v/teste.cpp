#include "magazin.h"
#include "repoArray.h"
#include "teste.h"
#include "service.h"
#include <iostream>
#include <cassert>
#include <assert.h>
#include <string.h>
#include <cstddef>

using namespace std;

void test1() {
	Magazin t1 = Magazin();
	assert(t1.getPret() == 0);
	assert(t1.getData() == NULL);
	assert(t1.getNume() == NULL);
}

void test2() {
	Magazin t2 = Magazin("vata", "17.02.2018", 12);
	assert(t2.getPret() == 12);
	//assert(strcmp(t2.getData, "17.02.2018")==0);
	//assert(strcmp(t2.getNume, "vata")==0);
}

void test3()
{
	Magazin t("vata", "17.02.2018", 12);
	Magazin t1("chipsuri", "11.02.2018", 7);
	Magazin t2("ciocolata", "17.02.2018", 4);
	repoSTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
}

void test4()
{
	Magazin t("ciocolata", "17.02.2018", 4);
	Magazin t1("sapun", "17.02.2018", 5);
	Magazin t2("suc", "17.07.2018", 10);
	repoSTL elem;
	elem.addElem(t);
	elem.addElem(t1);
	elem.addElem(t2);
	assert(elem.getSize() == 3);
	elem.delElem(t);
	assert(elem.getSize() != 3);
	assert(elem.findElem(t1) == true);
	assert(elem.getItemFromPos(0) == t1);
}

