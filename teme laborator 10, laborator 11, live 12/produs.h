#pragma once
#include "articol.h"

class produs :public Articol {

private:
	std::string end_date;

public:
	produs();
	~produs();
	produs(const produs&);
	produs(std::string, std::string, std::string, int, int, std::string);
	//std::string toString();
	std::string toStringDelimiter(std::string);
	//Setter
	void set_end_date(std::string);

	//Getter
	std::string get_end_date();

	//Overloading operators
	virtual Articol* clone();
	produs& operator=(const produs&);
	bool operator == (const produs&);

};