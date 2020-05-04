#include "user.h"



User::User()
{
}

User::User(string u, string p) :userName(u), userPass(p)
{
}

string User::getUserName()
{
	return userName;
}

string User::getUserPass()
{
	return userPass;
}

void User::setUserName(string u)
{
	userName = u;
}

void User::setUserPass(string p)
{
	userPass = p;
}

bool User::operator==(const User& u)
{
	return (userName == u.userName) and (userPass == u.userPass);
}

string User::toString()
{
	return userName + " " + userPass;
}

string User::toStringDelimiter(char delimiter)
{
	return userName + delimiter + userPass;
}


User::~User()
{
}
