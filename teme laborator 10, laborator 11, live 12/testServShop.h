#pragma once
#include "serviceShop.h"
#include "repoFileTXT.h"
#include "repoFileCSV.h"
#include <cassert>

class TestsServiceShop {

public:
	TestsServiceShop() {

		RepositoryFile* repositoryFile = new RepositoryFileTXT("TestsServiecShop.txt");
		Articol* pet = new animal("u1q", "Doberman", "12.12.2000", 300, 2, 5);
		Articol* petStuff = new produs("1u2sd", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		repositoryFile->addArticol(pet);
		repositoryFile->addArticol(petStuff);
		repositoryFile->saveToFile();

		RepositoryFile* repositoryFile1 = new RepositoryFileCSV("TestsServiecShop.csv");
		/*Product* pet1 = new Pet("u1q", "Doberman", "12.12.2000", 300, 2, 5);
		Product* petStuff1 = new PetStuff("1u2sd", "Conserva", "12.12.2000", 20, 20, "12.12.2001");*/
		repositoryFile1->addArticol(pet);
		repositoryFile1->addArticol(petStuff);
		repositoryFile1->saveToFile();
	}
	void addPetTXT() {

		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		ServiceShop serviceShop(repositoryFile);
		serviceShop.addShop("1", "Doberman", "12.12.2000", 300, 2, 5);
		Articol* pet = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		assert(*repositoryFile->getArticol(0) == *pet->clone());
	}

	void addPetStuffTXT() {

		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		ServiceShop serviceShop(repositoryFile);
		serviceShop.addShop("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		Articol* petStuff = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		assert(*repositoryFile->getArticol(0) == *petStuff->clone());
	}

	void addPetCSV() {

		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		ServiceShop serviceShop(repositoryFile);
		serviceShop.addShop("1", "Doberman", "12.12.2000", 300, 2, 5);
		Articol* pet = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		assert(*repositoryFile->getArticol(0) == *pet->clone());
	}

	void addPetStuffCSV() {

		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		ServiceShop serviceShop(repositoryFile);
		serviceShop.addShop("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		Articol* petStuff = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		assert(*repositoryFile->getArticol(0) == *petStuff->clone());
	}
	void testGetAllTXT()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		ServiceShop serviceShop(repositoryFile);
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		repositoryFile->addArticol(pet);
		repositoryFile->addArticol(petStuff);
		vector<Articol*> produce = serviceShop.getAll();

		assert(*produce[0] == *pet->clone());//assert(*produce[0] == *pet);
		assert(*produce[1] == *petStuff->clone());

	}

	void testGetAllCSV()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		ServiceShop serviceShop(repositoryFile);
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		serviceShop.addShop("123", "asd", "12.12.2000", 3, 4, 2);
		serviceShop.addShop("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		vector<Articol*> produce = serviceShop.getAll();

		assert(*produce[0] == *pet->clone());//assert(*produce[0] == *pet);
		assert(*produce[1] == *petStuff->clone());

	}
	void testUpdateProdusTXTPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		ServiceShop serviceShop(repositoryFile);

		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		animal* pet1 = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		animal* pet2 = new animal("2", "Retriver", "12.02.2020", 203, 1, 2);
		serviceShop.addShop("123", "asd", "12.12.2000", 3, 4, 2);
		serviceShop.updateArticol("123", "asd", "12.12.2000", 3, 4, 2, "1", "Doberman", "12.12.2000", 300, 2, 5);
		assert(*repositoryFile->getArticol(0) == *pet1);
		serviceShop.updateArticol("1", "Doberman", "12.12.2000", 300, 2, 5, "2", "Retriver", "12.02.2020", 203, 1, 2);
		assert(*repositoryFile->getArticol(0) == *pet2);
	}

	void testUpdateProdusTXTPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		ServiceShop serviceShop(repositoryFile);
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		produs* petStuff1 = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		produs* petStuff2 = new produs("2", "Sfoara", "14.05.2010", 10, 14, "14.05.2010");
		serviceShop.addShop("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		serviceShop.updateArticol("123", "asd", "12.12.200", 3, 5, "12.12.2001", "1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		assert(*repositoryFile->getArticol(0) == *petStuff1);
		serviceShop.updateArticol("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001", "2", "Sfoara", "14.05.2010", 10, 14, "14.05.2010");
		assert(*repositoryFile->getArticol(0) == *petStuff2);
	}

	void testUpdateProdusCSVPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		ServiceShop serviceShop(repositoryFile);

		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		animal* pet1 = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		animal* pet2 = new animal("2", "Retriver", "12.02.2020", 203, 1, 2);
		serviceShop.addShop("123", "asd", "12.12.2000", 3, 4, 2);
		serviceShop.updateArticol("123", "asd", "12.12.2000", 3, 4, 2, "1", "Doberman", "12.12.2000", 300, 2, 5);
		assert(*repositoryFile->getArticol(0) == *pet1);
		serviceShop.updateArticol("1", "Doberman", "12.12.2000", 300, 2, 5, "2", "Retriver", "12.02.2020", 203, 1, 2);
		assert(*repositoryFile->getArticol(0) == *pet2);
	}

	void testUpdateProdusCSVPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		ServiceShop serviceShop(repositoryFile);
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		produs* petStuff1 = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		produs* petStuff2 = new produs("2", "Sfoara", "14.05.2010", 10, 14, "14.05.2010");
		serviceShop.addShop("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		serviceShop.updateArticol("123", "asd", "12.12.200", 3, 5, "12.12.2001", "1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		assert(*repositoryFile->getArticol(0) == *petStuff1);
		serviceShop.updateArticol("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001", "2", "Sfoara", "14.05.2010", 10, 14, "14.05.2010");
		assert(*repositoryFile->getArticol(0) == *petStuff2);
	}

	void testDeleteProdusTXTPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		ServiceShop serviceShop(repositoryFile);

		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		serviceShop.addShop("123", "asd", "12.12.2000", 3, 4, 2);
		animal* pet1 = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		serviceShop.addShop("1", "Doberman", "12.12.2000", 300, 2, 5);
		serviceShop.deleteShop("1", "Doberman", "12.12.2000", 300, 2, 5);
		assert(serviceShop.getSize() == 1);
		assert(*serviceShop.getArticol(0) == *pet);
		serviceShop.deleteShop("123", "asd", "12.12.2000", 3, 4, 2);
		assert(serviceShop.getSize() == 0);
	}

	void testDeleteProdusTXTPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		ServiceShop serviceShop(repositoryFile);

		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		produs* petStuff1 = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		serviceShop.addShop("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		serviceShop.addShop("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		serviceShop.deleteShop("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		assert(serviceShop.getSize() == 1);
		assert(*serviceShop.getArticol(0) == *petStuff);
		serviceShop.deleteShop("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		assert(serviceShop.getSize() == 0);
	}

	void testDeleteProdusCSVPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		ServiceShop serviceShop(repositoryFile);

		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		serviceShop.addShop("123", "asd", "12.12.2000", 3, 4, 2);
		animal* pet1 = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		serviceShop.addShop("1", "Doberman", "12.12.2000", 300, 2, 5);
		serviceShop.deleteShop("1", "Doberman", "12.12.2000", 300, 2, 5);
		assert(serviceShop.getSize() == 1);
		assert(*serviceShop.getArticol(0) == *pet);
		serviceShop.deleteShop("123", "asd", "12.12.2000", 3, 4, 2);
		assert(serviceShop.getSize() == 0);
	}

	void testDeleteProdusCSVPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		ServiceShop serviceShop(repositoryFile);

		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		produs* petStuff1 = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		serviceShop.addShop("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		serviceShop.addShop("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		serviceShop.deleteShop("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		assert(serviceShop.getSize() == 1);
		assert(*serviceShop.getArticol(0) == *petStuff);
		serviceShop.deleteShop("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		assert(serviceShop.getSize() == 0);
	}

	void runAllTestsShop() {

		addPetTXT();
		addPetStuffTXT();
		addPetCSV();
		addPetStuffCSV();

		testGetAllTXT();
		testGetAllCSV();

		testUpdateProdusTXTPet();
		testUpdateProdusCSVPet();
		testUpdateProdusTXTPetStuff();
		testUpdateProdusCSVPetStuff();

		testDeleteProdusTXTPet();
		testDeleteProdusCSVPet();
		testDeleteProdusTXTPetStuff();
		testDeleteProdusCSVPetStuff();
	}

};