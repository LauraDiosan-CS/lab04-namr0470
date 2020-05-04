#include "service.h"
#include "user.h"

Service::Service(){}

Service::~Service() {}

Service::Service(IRepository<User>* repoUser, IRepository<Animal>* repoAnimal, IRepository<Produs>* repoProdus)
{
	this->repoUser = repoUser;
	this->repoAnimal = repoAnimal;
	this->repoProdus = repoProdus;

	User user1("Vlad", "parola123");
	User user2("Oana", "vaca");

	repoUser->add(user1);
	repoUser->add(user2);
}

bool Service::login(string u, string p)
{
	User user(u, p);

	return repoUser->find(user) != -1;
}

void Service::logout(string n, string p)
{
	User u(n, p);
	repoUser->remove(u);
}

