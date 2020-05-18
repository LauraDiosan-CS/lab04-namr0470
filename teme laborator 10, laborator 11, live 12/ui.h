#pragma once
#include "serviceShop.h"
#include "uiAcc.h"
#include "validator.h"
#include <iostream>
#include <typeinfo>
class UI {

private:
	ServiceShop serviceShop;
	UIAccount uiAccout;
	Validator validator;
public:


	UI(ServiceShop serviceShop, UIAccount uiAccout, Validator validator) :
		serviceShop(serviceShop), uiAccout(uiAccout), validator(validator) {}

	void printShop() {

		vector<Articol*>arrayPet, arrayPetStuff;
		arrayPet = this->serviceShop.allPets();
		arrayPetStuff = this->serviceShop.allPetsStuff();

		cout << endl << "Pets:" << endl;
		for (auto elem : arrayPet) {
			cout << elem->toStringDelimiter(" ") << endl;
		}
		cout << endl << "Pet stuffs:" << endl;
		for (auto elem : arrayPetStuff) {
			cout << elem->toStringDelimiter(" ") << endl;
		}

	}

	void addPet() {

		std::string id;
		std::string name;
		std::string date;
		int price;
		int number_of_pieces;
		cout << "Give an ID: ";
		do {
			cin >> id;
			if (!validator.idExist(id))
				cout << endl << "This ID already exist, please try again: ";
		} while (!validator.idExist(id));
		cout << "Give a name: ";
		cin >> name;
		cout << "Give an date: ";
		do {
			cin >> date;
			if (!except_date(date))
				cout << "Invalid data, try again: ";
		} while (!except_date(date));

		price = validator.inputCommndRead("Give a price: ");
		number_of_pieces = validator.inputCommndRead("Give a number of pieces: ");
		int age = validator.inputCommndRead("Give an age: ");

		this->serviceShop.addShop(id, name, date, price, number_of_pieces, age);
	}

	void deletePet() {

		std::string id;
		std::string name;
		std::string date;
		int price;
		int number_of_pieces;
		cout << "Give an ID: ";
		do {
			cin >> id;
			if (validator.idExist(id))
				cout << endl << "This ID dosn't exist, please try again: ";
		} while (validator.idExist(id));
		cout << "Give a name: ";
		cin >> name;
		cout << "Give an date: ";
		do {
			cin >> date;
			if (!except_date(date))
				cout << "Invalid data, try again: ";
		} while (!except_date(date));

		price = validator.inputCommndRead("Give a price: ");
		number_of_pieces = validator.inputCommndRead("Give a number of pieces: ");
		int age = validator.inputCommndRead("Give an age: ");

		this->serviceShop.deleteShop(id, name, date, price, number_of_pieces, age);
	}

	void updatePet() {

		std::string id;
		std::string name;
		std::string date;
		int price;
		int number_of_pieces;
		cout << "Old produce " << endl;
		cout << "Give an ID: ";
		do {
			cin >> id;
			if (validator.idExist(id))
				cout << endl << "This ID dosen't exist, please try again: ";
		} while (validator.idExist(id));
		cout << "Give a name: ";
		cin >> name;
		cout << "Give an date: ";
		do {
			cin >> date;
			if (!except_date(date))
				cout << "Invalid data, try again: ";
		} while (!except_date(date));

		price = validator.inputCommndRead("Give a price: ");
		number_of_pieces = validator.inputCommndRead("Give a number of pieces: ");
		int age = validator.inputCommndRead("Give an age: ");

		std::string id1;
		std::string name1;
		std::string date1;
		int price1;
		int number_of_pieces1;
		cout << "New produce " << endl;
		cout << "Give an ID: ";
		do {
			cin >> id1;
			if (!validator.idExist(id1))
				cout << endl << "This ID already exist, please try again: ";
		} while (!validator.idExist(id1));
		cout << "Give a name: ";
		cin >> name1;
		cout << "Give an date: ";
		do {
			cin >> date1;
			if (!except_date(date1))
				cout << "Invalid data, try again: ";
		} while (!except_date(date1));

		price1 = validator.inputCommndRead("Give a price: ");
		number_of_pieces1 = validator.inputCommndRead("Give a number of pieces: ");
		int age1 = validator.inputCommndRead("Give an age: ");

		this->serviceShop.updateArticol(id, name, date, price, number_of_pieces, age, id1, name1, date1, price1, number_of_pieces1, age1);
	}

	void updatePetStuff() {

		std::string id;
		std::string name;
		std::string date;
		int price;
		int number_of_pieces;
		cout << "Old produce " << endl;
		cout << "Give an ID: ";
		do {
			cin >> id;
			if (validator.idExist(id))
				cout << endl << "This ID already exist, please try again: ";
		} while (validator.idExist(id));
		cout << "Give a name: ";
		cin >> name;
		cout << "Give an date: ";
		do {
			cin >> date;
			if (!except_date(date))
				cout << "Invalid data, try again: ";
		} while (!except_date(date));

		price = validator.inputCommndRead("Give a price: ");
		number_of_pieces = validator.inputCommndRead("Give a number of pieces: ");
		std::string end_date;
		do {
			cin >> end_date;
			if (!except_date(end_date))
				cout << "Invalid data, try again: ";
		} while (!except_date(end_date));

		std::string id1;
		std::string name1;
		std::string date1;
		int price1;
		int number_of_pieces1;
		cout << "New produce " << endl;
		cout << "Give an ID: ";
		do {
			cin >> id1;
			if (!validator.idExist(id1))
				cout << endl << "This ID already exist, please try again: ";
		} while (!validator.idExist(id1));
		cout << "Give a name: ";
		cin >> name1;
		cout << "Give an date: ";
		do {
			cin >> date1;
			if (!except_date(date1))
				cout << "Invalid data, try again: ";
		} while (!except_date(date1));

		price1 = validator.inputCommndRead("Give a price: ");
		number_of_pieces1 = validator.inputCommndRead("Give a number of pieces: ");
		std::string end_date1;
		do {
			cin >> end_date;
			if (!except_date(end_date1))
				cout << "Invalid data, try again: ";
		} while (!except_date(end_date1));

		this->serviceShop.updateArticol(id, name, date, price, number_of_pieces, end_date, id1, name1, date1, price1, number_of_pieces1, end_date1);
	}

	void addPetStuff() {

		std::string id;
		std::string name;
		std::string date;
		int price;
		int number_of_pieces;
		cout << "Give an ID: ";
		do {
			cin >> id;
			if (!validator.idExist(id))
				cout << endl << "This ID already exist, please try again: ";
		} while (!validator.idExist(id));

		cout << "Give a name: ";
		cin >> name;
		cout << "Give an date: ";
		do {
			cin >> date;
			if (!except_date(date))
				cout << "Invalid data, try again: ";
		} while (!except_date(date));

		price = validator.inputCommndRead("Give a price: ");
		number_of_pieces = validator.inputCommndRead("Give a number of pieces: ");
		std::string end_date;
		do {
			cin >> end_date;
			if (!except_date(end_date))
				cout << "Invalid data, try again: ";
		} while (!except_date(end_date));

		this->serviceShop.addShop(id, name, date, price, number_of_pieces, end_date);
	}
	void deletePetStuff() {

		std::string id;
		std::string name;
		std::string date;
		int price;
		int number_of_pieces;
		cout << "Give an ID: ";
		do {
			cin >> id;
			if (!validator.idExist(id))
				cout << endl << "This ID already exist, please try again: ";
		} while (!validator.idExist(id));

		cout << "Give a name: ";
		cin >> name;
		cout << "Give an date: ";
		do {
			cin >> date;
			if (except_date(date))
				cout << "Invalid data, try again: ";
		} while (except_date(date));

		price = validator.inputCommndRead("Give a price: ");
		number_of_pieces = validator.inputCommndRead("Give a number of pieces: ");
		std::string end_date;
		do {
			cin >> end_date;
			if (!except_date(end_date))
				cout << "Invalid data, try again: ";
		} while (!except_date(end_date));

		this->serviceShop.deleteShop(id, name, date, price, number_of_pieces, end_date);
	}
	////////////////
	void searchPet()
	{
		std::string name;
		std::string date;
		int op;
		cout << " 1.Search by name " << "\n";
		cout << " 2.Search by date " << "\n";
		cin >> op;
		if (op == 1) { cout << "nume: "; cin >> name; this->serviceShop.searchFunctionPet(op, name); }
		if (op == 2) { cout << "data: "; cin >> date; this->serviceShop.searchFunctionPet(op, date); }
	}
	/////////////////
	void searchPetStuff()
	{
		std::string name;
		std::string date;
		int op;
		cout << " 1.Search by name " << "\n";
		cout << " 2.Search by date " << "\n";
		cin >> op;
		if (op == 1) { cout << "nume: "; cin >> name; this->serviceShop.searchFuncionPetStuff(op, name); }
		if (op == 2) { cout << "data: "; cin >> date; this->serviceShop.searchFuncionPetStuff(op, date);
		}
	}

	///////
	void buy_pet() {
		std::string name;
		std::cout << "nume: ";
		std::cin >> name;
	}
	//////



	void runShop() {

		printShop();
		bool done = false;
		do {
			menu();
			int opt = validator.inputCommndRead("Command: ");
			switch (opt) {
			case 0: {cout << endl << "----------Logout----------" << endl << endl; done = true; break; }
			case 1: {addPet(); break; }
			case 2: {addPetStuff(); break; }
			case 3: {printShop(); break; }
			case 4: {updatePet(); break; }//update Pet
			case 5: {updatePetStuff(); break; }//update PetStuff
			case 6: {deletePet(); break; }//delete Pet
			case 7: {deletePetStuff(); break; }//delete PetStuff
				  //teste Service
			}
		} while (!done);
	}

	void run() {
		bool response = this->uiAccout.runAccount();
		if (response) {
			runShop();
			run();
		}
	}
};