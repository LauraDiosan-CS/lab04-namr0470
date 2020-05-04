#include "testRepo.h"
#include "assert.h"

#include <iostream>
using namespace std;

//void TestRepo::runCSVTests()
void runCSVTests()
{
	//Animale
	RepositoryFile<Animal>* repoAnimal = new RepositoryFileCSV<Animal>("Animal.csv");
	((RepositoryFileCSV<Animal>*)repoAnimal)->loadFromFile();

	/*Animal ani(3, "elefant", 112.5, "12.12.2019", 4, 11);
	repoAnimal->add(ani);
	((RepositoryFileCSV<Animal>*)repoAnimal)->saveToFile();

	assert(repoAnimal->find(ani) != -1);

	Animal a1(3, "elefant", 112.5, "12.12.2019", 4, 31);
	repoAnimal->update(ani, a1);
	assert(repoAnimal->find(a1) != -1);
	assert(repoAnimal->find(ani) ==-1);
	assert(repoAnimal->size() != 0);*/


	Animal a1("pwf6", "papagal", 100, "01.04.2020", 2, 5);
	Animal a2("d59g", "canar", 70, "07.03.2020", 3, 1);
	Animal a3("eh79", "hamster", 60, "03.05.2020", 1, 3);
	((RepositoryFileCSV<Animal>*)repoAnimal)->saveToFile();

	assert(repoAnimal.size() == 3);


	//Produse
	const char* fileNameProduse = "Produs.csv";
	Animal a("1", "sconcs", 11.5, "14.03.2019", 4, 11);
	RepositoryFile<Produs>* repoProdus = new RepositoryFileCSV<Produs>(fileNameProduse);
	((RepositoryFileCSV<Produs>*)repoProdus)->loadFromFile();

	Produs p(a, "2", "sampon", 5.5, "11.09.2019", "10.10.2025", 20);
	repoProdus->add(p);
	assert(repoProdus->size() == 1); 
	Produs p1(a, "2", "mancare", 15.5, "11.09.2019", "10.10.2025", 20);
	repoProdus->add(p1);
	assert(repoProdus->size() == 2); 

	repoProdus->remove(p1);
	assert(repoProdus->size() == 1); 

	assert(repoProdus->find(p1) == -1);

	std::cout << endl << "Repo CSV good" << endl;
}


//void TestRepo::runTXTTests()
void runTXTTests()
{
	//Animale
	RepositoryFile<Animal>* repoAnimal = new RepositoryFileTXT<Animal>("Animal.txt");
	((RepositoryFileTXT<Animal>*)repoAnimal)->loadFromFile();

	Animal ani("3", "elefant", 112.5, "12.12.2019", 4, 11);
	repoAnimal->add(ani);
	((RepositoryFileTXT<Animal>*)repoAnimal)->saveToFile();

	assert(repoAnimal->find(ani) != -1);

	Animal a1("3", "elefant", 112.5, "12.12.2019", 4, 31);
	repoAnimal->update(ani, a1);
	assert(repoAnimal->find(a1) != -1);
	assert(repoAnimal->find(ani) == -1);
	assert(repoAnimal->size() != 0);


	//Produse
	const char* fileNameProduse = "Produs.txt";
	Animal a("1", "sconcs", 11.5, "14.03.2019", 4, 11);
	RepositoryFile<Produs>* repoProdus = new RepositoryFileTXT<Produs>(fileNameProduse);

	Produs p(a, "2", "sampon", 5.5, "11.09.2019", "10.10.2025", 20);
	repoProdus->add(p);
	Produs p1(a, "2", "mancare", 15.5, "11.09.2019", "10.10.2025", 20);
	repoProdus->add(p1);
	assert(repoProdus->size() == 2);

	repoProdus->remove(p1);
	assert(repoProdus->size() == 1);

	assert(repoProdus->find(p1) == -1);
	std::cout << endl << "Repo txt good"<<endl;
}


//void TestRepo::runInMemoryTests()
void runInMemoryTests()
{
	IRepository<User>* repoUseri = new RepositoryInMemory<User>();
	User u("Paula", "parola123");

	repoUseri->add(u);
	assert(repoUseri->size() == 1);

	assert(repoUseri->find(u) == 0);

	repoUseri->remove(u);
	assert(repoUseri->find(u) == -1);
	
	std::cout << endl<< "Repo in memory good"<<endl;
}


