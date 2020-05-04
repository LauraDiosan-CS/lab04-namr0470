#include "ui.h"
#include <iostream>
using namespace std;


ui::ui() {}

ui::ui(Service& ss)
{
	s = ss;
}

ui::~ui(){}

int ui::login()
{
	string user, pass;
	u.setUserName(user);
	u.setUserPass(pass);
	cout << " Dati userul: " << endl;
	cin >> user;
	cout << " Parola: " << endl;
	cin >> pass;
	return s.login(user, pass);
}

void ui::logout()
{
	s.logout(u.getUserName(), u.getUserPass());
}

void ui::showMenu()
{
	bool gata = false;
	int rez = login();
	if (rez != -1)
	{
		while (!gata)
		{
			cout << " 0. Logout " << endl;
			int opt;
			cout << " Dati optiunea: " << endl;
			cin >> opt;
			switch (opt) {
			case 0: {logout(); gata = true; }
			}
		}
	}
	else cout << " Autentificare esuata! " << endl;
}