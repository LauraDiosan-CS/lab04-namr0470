#pragma once
#include <string>
using namespace std;

class User
{
private:
	string userName;
	string userPass;
public:
	User();
	User(string, string);
	~User();

	string getUserName();
	string getUserPass();

	void setUserName(string);
	void setUserPass(string);

	bool operator==(const User& u);
	string toString();
	string toStringDelimiter(char delimiter);
};