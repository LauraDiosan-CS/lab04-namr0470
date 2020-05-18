#pragma once
#include "servAcc.h"
#include <cassert>
#include <string>

class TestsAccount {

public:
	void testAccount() {

		std::string id, pass;
		id = "Alina";
		pass = "parol";
		Account account(id, pass);

		assert(account.get_id() == id);
		assert(account.get_pass() == pass);
	}

	void testValidator() {

		std::fstream fin;
		fin.open("TestAccountDataBase.txt", std::ios::trunc | std::ios::out);
		if (fin.is_open()) {
			fin.clear();
			fin.close();
		}

		FileRepoAccount repo("TestAccountDataBase.txt");
		ValidatorUser validator(repo);
		std::string id, pass;
		id = "Ana";
		pass = "parol";
		Account account(id, pass);
		repo.saveinFile(account);
		assert(validator.id_exist(id) == account);
	}

	void testFileRepoAccount() {
		std::fstream fin;
		fin.open("TestAccountDataBase.txt", std::ios::trunc | std::ios::out);
		if (fin.is_open()) {
			fin.clear();
			fin.close();
		}

		FileRepoAccount repo("TestAccountDataBase.txt");
		std::string id, pass;
		id = "Ana";
		pass = "parol";
		Account account(id, pass);
		repo.saveinFile(account);
		assert(repo.isInFile(id) == account);

		id = "David";
		pass = "parola123";

		Account account1(id, pass);
		repo.saveinFile(account1);
		assert(repo.isInFile(id) == account1);
	}

	void testErrorMessages() {

		Response response;
		response.append("Success");
		response.setSuccess(true);
		std::vector<std::string> array = response.getAll();
		int n = int(response.size());

		assert(response.isSuccess() == true);
		for (int i = 0; i < n; i++) {
			assert(array[i] == "Success");
		}
	}

	void testAccountServiceSigIn() {
		std::fstream fin;
		fin.open("TestAccountDataBase.txt", std::ios::trunc | std::ios::out);
		if (fin.is_open()) {
			fin.clear();
			fin.close();
		}

		FileRepoAccount repo("TestAccountDataBase.txt");
		ServiceAccount service(repo);
		std::string id, pass;
		id = "Alin";
		pass = "parol";
		Response response = service.signIn(id, pass);
		bool isSuccess = response.isSuccess();
		assert(isSuccess == true);

		std::vector<std::string> arraystr;
		arraystr.push_back("----------- Sign in successful -----------");
		arraystr.push_back("");
		for (int i = 0; i < response.size(); i++) {
			assert(response.getAll()[i] == arraystr[i]);
		}


		id = "Alin";
		pass = "parol123";
		response = service.signIn(id, pass);
		isSuccess = response.isSuccess();
		assert(isSuccess == false);
		std::vector<std::string> message;
		message.push_back("----------------------");
		message.push_back("ID already exist ");
		message.push_back("----------------------");
		message.push_back("Try again (1) or sign in (0)");
		message.push_back("");

		for (int i = 0; i < response.size(); i++) {

			assert(response.getAll()[i] == message[i]);
		}


	}

	void testAccountServiceLogIn() {
		std::fstream fin;
		fin.open("TestAccountDataBase.txt", std::ios::trunc | std::ios::out);
		if (fin.is_open()) {
			fin.clear();
			fin.close();
		}

		FileRepoAccount repo("TestAccountDataBase.txt");
		ServiceAccount service(repo);
		std::string id, pass;
		id = "Alin";
		pass = "parol";
		Account account(id, pass);
		repo.saveinFile(account);
		Response response = service.login(id, pass);
		bool isSuccess = response.isSuccess();
		std::vector<std::string>arraystr;
		arraystr.push_back("----------- Login successful -----------");
		arraystr.push_back("");
		assert(isSuccess == true);

		for (int i = 0; i < response.size(); i++) {
			assert(response.getAll()[i] == arraystr[i]);
		}


		id = "Alin";
		pass = "parol123";
		response = service.login(id, pass);
		isSuccess = response.isSuccess();
		assert(isSuccess == false);

		std::vector<std::string> message;
		message.push_back("----------------------");
		message.push_back("ID or password incorrect");
		message.push_back("Try again (1) or sign in (0)");
		message.push_back("");

		for (int i = 0; i < response.size(); i++) {

			assert(response.getAll()[i] == message[i]);
		}
	}

	void runTests() {

		testAccount();
		testValidator();
		testFileRepoAccount();
		testErrorMessages();
		testAccountServiceSigIn();
		testAccountServiceLogIn();
	}
};