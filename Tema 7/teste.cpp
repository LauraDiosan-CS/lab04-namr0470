#include "entitate.h"
#include "repoFile.h"
#include "assert.h"
#include "service.h"


void test1() {
	Carte t("Invitatia la vals","Mihail Drumes", "disponibila");
	Carte t1("Jane Eyre", "Charlotte Bronte", "disponibila");
	Carte t2("Harry Potter", "J. K. Rowling", "imprumutat");
	RepoFile<Carte> elem;
	deque<Carte> carti;
	const char* fileIn = "carti.txt";
	const char* fileOut = "cartiOut.txt";
	elem.setFileIn(fileIn);
	elem.load_from_file();
	assert(elem.size() == 3);
	elem.addCarte(t);
	elem.saveToFile(fileOut);
	assert(elem.size() == 4);
	elem.deleteCarte(t);
	elem.saveToFile(fileOut);
	assert(elem.size() == 3);
}


void test2() {
	RepoFile<Carte> rep;
	Service service;
	char titlu[100] = "Vasile";
	char autor[100] = "Ion";
	char status[20] = "imprumutat";
	Carte c1(titlu, autor, status);
	service.addCarte(titlu, autor, status);
	assert(service.getSize() == 1);
	deque<Carte> carti = service.getAll();
	char autor1[100] = "Ion";
	char status1[20] = "disponibil";
	Carte c2(titlu, autor1, status1);
	service.updateCarte(c1, c2);
	assert(service.getSize() == 1);
	service.deleteCarte(c2);
	assert(service.getSize() == 0);

}


