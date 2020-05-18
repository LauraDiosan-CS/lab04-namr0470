#pragma once
#include "repoFile.h"
#include "repoFileCSV.h"
#include "repoFileTXT.h"
#include <cassert>
class TestsProduct {

public:

	void testImplicitConstructor() {
		Articol product;
		assert(product.get_id() == "");
		assert(product.get_name() == "");
		assert(product.get_date() == "");
		assert(product.get_price() == 0);
		assert(product.get_number_of_pieces() == 0);

	}

	void testConstructorWithParameters() {

		Articol product("1", "Conserva", "12.12.2000", 20, 20);
		assert(product.get_id() == "1");
		assert(product.get_name() == "Conserva");
		assert(product.get_date() == "12.12.2000");
		assert(product.get_price() == 20);
		assert(product.get_number_of_pieces() == 20);

	}

	void testCopyConstructor() {
		Articol product("1", "Conserva", "12.12.2000", 20, 20);
		Articol product1(product);

		assert(product.get_id() == product1.get_id());
		assert(product.get_name() == product1.get_name());
		assert(product.get_date() == product1.get_date());
		assert(product.get_price() == product1.get_price());
		assert(product.get_number_of_pieces() == product1.get_number_of_pieces());

	}

	void testClone() {
		Articol product("1", "Conserva", "12.12.2000", 20, 20);
		Articol* productClone = (Articol*)product.clone();
		assert(product == *productClone);
		assert(&product != productClone);
	}

	void testToString()
	{
		Articol product("1", "Conserva", "12.12.2000", 20, 20);

		assert(product.toStringDelimiter(" ") == "1 Conserva 12.12.2000 20 20");
		assert(product.toStringDelimiter(",") == "1,Conserva,12.12.2000,20,20");
	}

	void allTestsProduct() {

		testImplicitConstructor();
		testConstructorWithParameters();
		testCopyConstructor();
		testClone();
		testToString();
	}
};