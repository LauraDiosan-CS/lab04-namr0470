#pragma once
#include "repoFile.h"
#include "repoFileCSV.h"
#include "repoFileTXT.h"
#include <cassert>
class TestsPet {

public:

	void testImplicitConstructor() {
		animal pet;
		assert(pet.get_id() == "");
		assert(pet.get_name() == "");
		assert(pet.get_date() == "");
		assert(pet.get_price() == 0);
		assert(pet.get_number_of_pieces() == 0);
		assert(pet.get_age() == 0);
	}

	void testConstructorWithParameters() {

		animal pet("123", "asd", "12.12.2000", 3, 4, 2);
		assert(pet.get_id() == "123");
		assert(pet.get_name() == "asd");
		assert(pet.get_date() == "12.12.2000");
		assert(pet.get_price() == 3);
		assert(pet.get_number_of_pieces() == 4);
		assert(pet.get_age() == 2);
	}

	void testCopyConstructor() {
		animal pet("123", "asd", "12.12.2000", 3, 4, 2);
		animal pet1(pet);

		assert(pet.get_id() == pet1.get_id());
		assert(pet.get_name() == pet1.get_name());
		assert(pet.get_date() == pet1.get_date());
		assert(pet.get_price() == pet1.get_price());
		assert(pet.get_number_of_pieces() == pet1.get_number_of_pieces());
		assert(pet.get_age() == pet1.get_age());
	}

	void testClone() {
		animal pet("123", "asd", "12.12.2000", 3, 4, 2);
		animal* petClone = (animal*)pet.clone();
		assert(pet == *petClone);
		assert(&pet != petClone);
	}

	void testToString()
	{
		animal pet("123", "asd", "12.12.2000", 3, 4, 2);

		assert(pet.toStringDelimiter(" ") == "AA 123 asd 12.12.2000 3 4 2");
		assert(pet.toStringDelimiter(",") == "AA,123,asd,12.12.2000,3,4,2");
	}

	void allTestsPet() {

		testImplicitConstructor();
		testConstructorWithParameters();
		testCopyConstructor();
		testClone();
		testToString();
	}
};