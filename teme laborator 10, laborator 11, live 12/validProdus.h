#pragma once
#include "produs.h"
#include "exceptie.h"

class ValidatorProdus
{
private:
	int err;
	string mesaj;
public:
	ValidatorProdus();
	int validate(produs, int);
	string toString();
	~ValidatorProdus();
};