#pragma once
#include "service.h"
#include <string>
using namespace std;

class ui
{
private:
	Service s;
	User u;
	int login();
	void logout();
public:
	ui();
	ui(Service&);
	void showMenu();
	~ui();
};