#pragma once
#include "repoFile.h"
#include "animal.h"
#include "produs.h"
#include <typeinfo>
class ServiceShop {

private:
	RepositoryFile* repositoryFile;

public:
	//ServiceShop() {}
	ServiceShop(RepositoryFile* repositoryFile) :repositoryFile(repositoryFile) {}

	void addShop(std::string id, std::string name, std::string date, int price, int number_of_pieces, int age) {

		Articol* pet = new animal(id, name, date, price, number_of_pieces, age);
		repositoryFile->addArticol(pet);
	}

	void addShop(std::string id, std::string name, std::string date, int price, int number_of_pieces, std::string end_date) {

		Articol* petStuff = new produs(id, name, date, price, number_of_pieces, end_date);
		repositoryFile->addArticol(petStuff);
	}

	vector<Articol*> allPets() {

		vector<Articol*> arrayPet;
		vector<Articol*>array = this->repositoryFile->getAll();
		for (int i = 0; i < array.size(); i++)
		{
			const std::type_info& type_info = typeid(*array[i]);
			if (type_info == typeid(animal))
				arrayPet.push_back(array[i]);
		}
		return arrayPet;
	}

	vector<Articol*> allPetsStuff() {

		vector<Articol*> arrayPetStuff;
		vector<Articol*>array = this->repositoryFile->getAll();
		for (int i = 0; i < array.size(); i++)
		{
			const std::type_info& type_info = typeid(*array[i]);
			if (type_info == typeid(produs))
				arrayPetStuff.push_back(array[i]);
		}
		return arrayPetStuff;
	}

	vector<Articol*> getAll() {

		return repositoryFile->getAll();
	}

	int find(Articol* product) {

		return this->repositoryFile->find(product);
	}

	void updateArticol(std::string id, std::string name, std::string date, int price, int number_of_pieces, int age,
		std::string id1, std::string name1, std::string date1, int price1, int number_of_pieces1, int age1) {

		Articol* pet = new animal(id, name, date, price, number_of_pieces, age);
		Articol* pet1 = new animal(id1, name1, date1, price1, number_of_pieces1, age1);
		this->repositoryFile->updateArticol(pet, pet1);
	}

	void updateArticol(std::string id, std::string name, std::string date, int price, int number_of_pieces, std::string end_date,
		std::string id1, std::string name1, std::string date1, int price1, int number_of_pieces1, std::string end_date1) {

		Articol* petStuff = new produs(id, name, date, price, number_of_pieces, end_date);
		Articol* petStuff1 = new produs(id1, name1, date1, price1, number_of_pieces1, end_date1);
		this->repositoryFile->updateArticol(petStuff, petStuff1);
	}

	void deleteShop(std::string id, std::string name, std::string date, int price, int number_of_pieces, std::string end_date) {

		Articol* petStuff = new produs(id, name, date, price, number_of_pieces, end_date);
		this->repositoryFile->deleteArticol(petStuff);
	}
	void deleteShop(std::string id, std::string name, std::string date, int price, int number_of_pieces, int age) {

		Articol* pet = new animal(id, name, date, price, number_of_pieces, age);
		this->repositoryFile->deleteArticol(pet);
	}

	int getSize() {
		return this->repositoryFile->getSize();
	}

	Articol* getArticol(int pos) {
		return this->repositoryFile->getArticol(pos);
	}
	///////////
	void searchFunctionPet(int op, string elem)
	{
		if (op == 1)
		{
			vector<Articol*> rez;
			vector<Articol*> animale = allPets();
			for (int i = 0; i < animale.size(); i++)
			{
				if(animale[i]->get_name() == elem)
					rez.push_back(animale[i]);
			}
		}
		else if (op == 2)
		{
			vector<Articol*> rez;
			vector<Articol*> animale = allPets();
			for (int i = 0; i < animale.size(); i++)
			{
				if (animale[i]->get_date() == elem)
					rez.push_back(animale[i]);
			}
		}
	}
	///////////
	
	//////////
	void searchFuncionPetStuff(int op, string elem)
	{
		if (op == 1)
		{
			vector<Articol*> rez;
			vector<Articol*> produse = allPetsStuff();
			for (int i = 0; i < produse.size(); i++)
			{
				if (produse[i]->get_name() == elem)
					rez.push_back(produse[i]);
			}
		}
		else if (op == 2)
		{
			vector<Articol*> rez;
			vector<Articol*> produse = allPetsStuff();
			for (int i = 0; i < produse.size(); i++)
			{
				if (produse[i]->get_date() == elem)
					rez.push_back(produse[i]);
			}
		}
	}
	/////////
};