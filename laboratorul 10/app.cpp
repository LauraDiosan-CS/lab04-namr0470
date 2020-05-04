#include "IRepository.h"
#include "RepositoryFileCSV.h"
#include "RepositoryInMemory.h"
#include "animal.h"
#include "produs.h"
#include "service.h"
#include "ui.h"
#include "testRepo.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "teste: " << endl;;
	runCSVTests();
	runInMemoryTests();
	runTXTTests();
	cout << "good"<<endl;
	IRepository<Animal>* repoAnimal = new RepositoryFileCSV<Animal>("Animal.csv");
	((RepositoryFile<Animal>*) repoAnimal)->loadFromFile();

	IRepository<Produs>* repoProdus = new RepositoryFileCSV<Produs>("Produs.csv");
	((RepositoryFile<Produs>*) repoProdus)->loadFromFile();

	IRepository<User>* repoUser = new RepositoryInMemory<User>();

	Service s(repoUser, repoAnimal, repoProdus);
	ui u(s);
	u.showMenu();
	return 0;

}
