#pragma once
#include "repoFile.h"
#include "repoFileCSV.h"
#include "repoFileTXT.h"
#include <cassert>
class TestsPetStuff {

public:

	void testImplicitConstructor() {
		produs petStuff;
		assert(petStuff.get_id() == "");
		assert(petStuff.get_name() == "");
		assert(petStuff.get_date() == "");
		assert(petStuff.get_price() == 0);
		assert(petStuff.get_number_of_pieces() == 0);
		assert(petStuff.get_end_date() == "");
	}

	void testConstructorWithParameters() {

		produs petStuff("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		assert(petStuff.get_id() == "1");
		assert(petStuff.get_name() == "Conserva");
		assert(petStuff.get_date() == "12.12.2000");
		assert(petStuff.get_price() == 20);
		assert(petStuff.get_number_of_pieces() == 20);
		assert(petStuff.get_end_date() == "12.12.2001");
	}

	void testCopyConstructor() {
		produs petStuff("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		produs petStuff1(petStuff);

		assert(petStuff.get_id() == petStuff1.get_id());
		assert(petStuff.get_name() == petStuff1.get_name());
		assert(petStuff.get_date() == petStuff1.get_date());
		assert(petStuff.get_price() == petStuff1.get_price());
		assert(petStuff.get_number_of_pieces() == petStuff1.get_number_of_pieces());
		assert(petStuff.get_end_date() == petStuff1.get_end_date());
	}

	void testClone() {
		produs petStuff("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");
		produs* petStuffClone = (produs*)petStuff.clone();
		assert(petStuff == *petStuffClone);
		assert(&petStuff != petStuffClone);
	}

	void testToString()
	{
		produs petStuff("1", "Conserva", "12.12.2000", 20, 20, "12.12.2001");

		assert(petStuff.toStringDelimiter(" ") == "AP 1 Conserva 12.12.2000 20 20 12.12.2001");
		assert(petStuff.toStringDelimiter(",") == "AP,1,Conserva,12.12.2000,20,20,12.12.2001");
	}

	void allTestsPetStuff() {

		testImplicitConstructor();
		testConstructorWithParameters();
		testCopyConstructor();
		testClone();
		testToString();
	}
};