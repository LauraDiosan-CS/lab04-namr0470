#pragma once
#include "animal.h"
#include "exceptie.h"
#include "repoFile.h"

class ValidatorAnimal
{
private:
	int err;
	string mesaj;
public:
	ValidatorAnimal();
	int validate(animal, int contor);
	void showMesaj();
	string toString();
	~ValidatorAnimal();
};