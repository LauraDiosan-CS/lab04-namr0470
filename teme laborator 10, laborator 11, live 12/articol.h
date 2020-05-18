#pragma once
#include <ostream>

class Articol {

protected:

	std::string id, name, date;
	int price, number_of_pieces;

public:

	//Constructors

	Articol(); //Default constructor
	~Articol(); //Desctructor
	Articol(const Articol&); //Copy Constructor
	Articol(std::string, std::string, std::string, int, int); //Constructor's Member Initializer
	virtual Articol* clone();

	//Setters
	void set_id(std::string);
	void set_name(std::string);
	void set_date(std::string);
	void set_price(int);
	void set_number_of_pieces(int);

	//Getters
	std::string get_id();
	std::string get_name();
	std::string get_date();
	int get_price();
	int get_number_of_pieces();

	//Overloading operators

	virtual std::string toStringDelimiter(std::string);

	Articol& operator =(const Articol&);
	bool operator == (const Articol&);
};