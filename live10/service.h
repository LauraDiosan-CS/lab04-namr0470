#pragma once
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"
#include "animal.h"
#include "produs.h"
#include "user.h"


class Service {
private:
	IRepository<User>* repoUser;
	IRepository<Animal>* repoAnimal;
	IRepository<Produs>* repoProdus;
public:
	Service();
	Service(IRepository<User>*, IRepository<Animal>*, IRepository<Produs>*);
	bool login(string, string);
	void logout(string, string);
	~Service();
};