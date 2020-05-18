#pragma once
#include "repoFile.h"
#include "repoFileCSV.h"
#include "repoFileTXT.h"
#include <cassert>

class TestsRepositoryFile {

public:

	TestsRepositoryFile()
	{
		animal* pet = new animal("u1q", "Doberman", "12.12.2000", 300, 2, 5);
		produs* petStuff = new produs("1u2sd", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		this->produseIn.push_back(pet);
		this->produseIn.push_back(petStuff);
	}
	vector<Articol*> produseIn;
	void testGetSizeTXT()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		assert(repositoryFile->getSize() == 0);
		repositoryFile->addArticol(new Articol());
		assert(repositoryFile->getSize() == 1);
	}

	void testGetSizeCSV()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		assert(repositoryFile->getSize() == 0);
		repositoryFile->addArticol(new Articol());
		assert(repositoryFile->getSize() == 1);
	}

	void testGetAllTXT()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		repositoryFile->addArticol(pet);
		repositoryFile->addArticol(petStuff);
		vector<Articol*> produce = repositoryFile->getAll();

		assert(*produce[0] == *pet->clone());//assert(*produce[0] == *pet);
		assert(*produce[1] == *petStuff->clone());

	}

	void testGetAllCSV()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		repositoryFile->addArticol(pet);
		repositoryFile->addArticol(petStuff);
		vector<Articol*> produce = repositoryFile->getAll();

		assert(*produce[0] == *pet->clone());//assert(*produce[0] == *pet);
		assert(*produce[1] == *petStuff->clone());

	}

	void testGetProdusTXTPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		repositoryFile->addArticol(pet);
		assert(*repositoryFile->getArticol(0) == *pet->clone());
		assert(*repositoryFile->getArticol(-1) == *(new Articol()));
		assert(*repositoryFile->getArticol(1) == *(new Articol()));
	}

	void testGetProdusTXTPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		repositoryFile->addArticol(petStuff);
		assert(*repositoryFile->getArticol(0) == *petStuff->clone());
		assert(*repositoryFile->getArticol(-1) == *(new Articol()));
		assert(*repositoryFile->getArticol(1) == *(new Articol()));
	}

	void testGetProdusCSVPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		repositoryFile->addArticol(pet);
		assert(*repositoryFile->getArticol(0) == *pet->clone());
		assert(*repositoryFile->getArticol(-1) == *(new Articol()));
		assert(*repositoryFile->getArticol(1) == *(new Articol()));
	}

	void testGetProdusCSVPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		repositoryFile->addArticol(petStuff);
		assert(*repositoryFile->getArticol(0) == *petStuff->clone());
		assert(*repositoryFile->getArticol(-1) == *(new Articol()));
		assert(*repositoryFile->getArticol(1) == *(new Articol()));
	}

	void testAddProdusTXTPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		repositoryFile->addArticol(pet);
		assert(*repositoryFile->getArticol(0) == *pet->clone());
	}

	void testAddProdusCSVPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		repositoryFile->addArticol(pet);
		assert(*repositoryFile->getArticol(0) == *pet->clone());
	}

	void testAddProdusTXTPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		repositoryFile->addArticol(petStuff);
		assert(*repositoryFile->getArticol(0) == *petStuff->clone());
	}

	void testAddProdusCSVPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		repositoryFile->addArticol(petStuff);
		assert(*repositoryFile->getArticol(0) == *petStuff->clone());
	}

	void testUpdateProdusTXTPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		animal* pet1 = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		animal* pet2 = new animal("2", "Retriver", "12.02.2020", 203, 1, 2);
		repositoryFile->addArticol(pet);
		repositoryFile->updateArticol(pet, pet1);
		assert(*repositoryFile->getArticol(0) == *pet1);
		repositoryFile->updateArticol(pet1, pet2);
		assert(*repositoryFile->getArticol(0) == *pet2);
	}

	void testUpdateProdusTXTPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		produs* petStuff1 = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		produs* petStuff2 = new produs("2", "Sfoara", "14.05.2010", 10, 14, "14.05.2010");
		repositoryFile->addArticol(petStuff);
		repositoryFile->updateArticol(petStuff, petStuff1);
		assert(*repositoryFile->getArticol(0) == *petStuff1);
		repositoryFile->updateArticol(petStuff1, petStuff2);
		assert(*repositoryFile->getArticol(0) == *petStuff2);
	}

	void testUpdateProdusCSVPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		animal* pet1 = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		animal* pet2 = new animal("2", "Retriver", "12.02.2020", 203, 1, 2);
		repositoryFile->addArticol(pet);
		repositoryFile->updateArticol(pet, pet1);
		assert(*repositoryFile->getArticol(0) == *pet1);
		repositoryFile->updateArticol(pet1, pet2);
		assert(*repositoryFile->getArticol(0) == *pet2);
	}

	void testUpdateProdusCSVPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		produs* petStuff1 = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		produs* petStuff2 = new produs("2", "Sfoara", "14.05.2010", 10, 14, "14.05.2010");
		repositoryFile->addArticol(petStuff);
		repositoryFile->updateArticol(petStuff, petStuff1);
		assert(*repositoryFile->getArticol(0) == *petStuff1);
		repositoryFile->updateArticol(petStuff1, petStuff2);
		assert(*repositoryFile->getArticol(0) == *petStuff2);
	}

	void testDeleteProdusTXTPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		repositoryFile->addArticol(pet);
		animal* pet1 = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		repositoryFile->addArticol(pet1);
		repositoryFile->deleteArticol(pet1);
		assert(repositoryFile->getSize() == 1);
		assert(*repositoryFile->getArticol(0) == *pet);
		repositoryFile->deleteArticol(pet);
		assert(repositoryFile->getSize() == 0);
	}

	void testDeleteProdusTXTPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT();
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		produs* petStuff1 = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		repositoryFile->addArticol(petStuff);
		repositoryFile->addArticol(petStuff1);
		repositoryFile->deleteArticol(petStuff1);
		assert(repositoryFile->getSize() == 1);
		assert(*repositoryFile->getArticol(0) == *petStuff);
		repositoryFile->deleteArticol(petStuff);
		assert(repositoryFile->getSize() == 0);
	}

	void testDeleteProdusCSVPet()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		animal* pet = new animal("123", "asd", "12.12.2000", 3, 4, 2);
		repositoryFile->addArticol(pet);
		animal* pet1 = new animal("1", "Doberman", "12.12.2000", 300, 2, 5);
		repositoryFile->addArticol(pet1);
		repositoryFile->deleteArticol(pet1);
		assert(repositoryFile->getSize() == 1);
		assert(*repositoryFile->getArticol(0) == *pet);
		repositoryFile->deleteArticol(pet);
		assert(repositoryFile->getSize() == 0);
	}

	void testDeleteProdusCSVPetStuff()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV();
		produs* petStuff = new produs("123", "asd", "12.12.200", 3, 5, "12.12.2001");
		produs* petStuff1 = new produs("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		repositoryFile->addArticol(petStuff);
		repositoryFile->addArticol(petStuff1);
		repositoryFile->deleteArticol(petStuff1);
		assert(repositoryFile->getSize() == 1);
		assert(*repositoryFile->getArticol(0) == *petStuff);
		repositoryFile->deleteArticol(petStuff);
		assert(repositoryFile->getSize() == 0);
	}

	void testLoadFromFileTXT()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT("TestShop.txt");
		repositoryFile->loadFromFile();
		//assert(repositoryFile->getSize() == this->produseIn.size());
		//assert(*repositoryFile->getArticol(0) == *this->produseIn[0]);
		//assert(*repositoryFile->getArticol(1) == *this->produseIn[1]);
	}

	void testLoadFromFileCSV()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV("TestShop.csv");
		repositoryFile->loadFromFile();
		//assert(repositoryFile->getSize() == this->produseIn.size());
		//assert(*repositoryFile->getArticol(0) == *this->produseIn[0]);
		//assert(*repositoryFile->getArticol(1) == *this->produseIn[1]);
	}

	void testSavetoFileTXT()
	{
		RepositoryFile* repositoryFile = new RepositoryFileTXT("TestShop.txt");
		repositoryFile->loadFromFile();
		repositoryFile->setFileName("TestShopOut.txt");
		animal* pet = new animal("u1q", "Doberman", "12.12.2000", 300, 2, 5);
		repositoryFile->addArticol(pet);
		repositoryFile->saveToFile();
		repositoryFile->loadFromFile();
		//assert(repositoryFile->getSize() == this->produseIn.size() + 1);

		vector<Articol*> produse = repositoryFile->getAll();
		for (int i = 0; i < repositoryFile->getSize() - 1; i++)
		{
			assert(*produse[i] == *this->produseIn[i]);
		}
		assert(*produse[produse.size() - 1] == *pet);
	}

	void testSavetoFileCSV()
	{
		RepositoryFile* repositoryFile = new RepositoryFileCSV("TestShop.csv");
		repositoryFile->loadFromFile();
		repositoryFile->setFileName("TestShopOut.csv");
		animal* pet = new animal("u1q", "Doberman", "12.12.2000", 300, 2, 5);
		repositoryFile->addArticol(pet);
		repositoryFile->saveToFile();
		repositoryFile->loadFromFile();
		//assert(repositoryFile->getSize() == this->produseIn.size() + 1);

		vector<Articol*> produse = repositoryFile->getAll();
		for (int i = 0; i < repositoryFile->getSize() - 1; i++)
		{
			assert(*produse[i] == *this->produseIn[i]);
		}
		assert(*produse[produse.size() - 1] == *pet);

	}

	void allTestsRepositoryFile() {

		testGetSizeTXT();
		testGetSizeCSV();
		testGetAllTXT();
		testGetAllCSV();
		testGetProdusTXTPet();
		testGetProdusTXTPetStuff();
		testGetProdusCSVPet();
		testGetProdusCSVPetStuff();
		testAddProdusTXTPet();
		testAddProdusTXTPetStuff();
		testAddProdusCSVPet();
		testAddProdusCSVPetStuff();
		testUpdateProdusTXTPet();
		testUpdateProdusTXTPetStuff();
		testUpdateProdusCSVPet();
		testUpdateProdusCSVPetStuff();
		testDeleteProdusTXTPet();
		testDeleteProdusTXTPetStuff();
		testDeleteProdusCSVPet();
		testDeleteProdusCSVPetStuff();
		testLoadFromFileTXT();
		testLoadFromFileCSV();
		testSavetoFileTXT();
		testSavetoFileCSV();
	}
};