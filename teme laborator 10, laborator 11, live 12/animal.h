#pragma once
#include "articol.h"

class animal :public Articol {

private:
	int age;

public:
	//Constructors 

	animal();//Default constructor
	~animal();//Destructor
	animal(const animal&);//Copy constructor
	animal(std::string, std::string, std::string, int, int, int);//Constructor's Member Initializer
	//std::string toString();
	std::string toStringDelimiter(std::string);
	//Setter
	void set_age(int);

	//Getter
	int get_age();

	//Overloading operators
	virtual Articol* clone();
	animal& operator=(const animal&);
	bool operator == (const animal&);
};