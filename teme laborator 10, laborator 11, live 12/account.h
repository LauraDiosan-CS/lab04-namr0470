#pragma once
#include <string>
#include <istream>

class Account {

private:
	std::string id, password;

public:
	Account() {

		this->id = "";
		this->password = "";
	}
	Account(std::string id, std::string password) {
		this->id = id;
		this->password = password;
	}
	Account(const Account& account) {
		this->id = account.id;
		this->password = account.password;
	}
	~Account() {

		this->id = "";
		this->password = "";
	}

	//Getters
	std::string get_id() {
		return this->id;
	}

	std::string get_pass() {
		return this->password;
	}

	//Setters
	void set_name(std::string new_id) {
		this->id = new_id;
	}
	void set_pass(std::string new_pass) {
		this->password = new_pass;
	}

	//Overloading oprators

	bool operator ==(const Account& account) {

		return account.id == id and account.password == password;
	}

	friend std::istream& operator >>(std::istream& is, Account& account) {
		is >> account.id >> account.password;
		return is;
	}

	friend std::ostream& operator <<(std::ostream& os, Account account) {
		os << account.id << ' ' << account.password << std::endl;
		return os;
	}

};