#include <iostream>
#include "ui.h"
#include "service.h"
#include "teste.h"

using namespace std;

void initService(Service& s)
{
	RepoFile<Carte> r("carti.txt", "cartiOut.txt");
	s.setRepo(r);
}
int main() {
	test1();
	test2();
	Service serv;
	initService(serv);
	UI ui;
	ui.setService(serv);
	ui.run();
	return 0;
}
