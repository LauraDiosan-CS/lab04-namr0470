#pragma once
#include <vector>
#include <string>
class Response {

private:
	std::vector<std::string>messageError;
	bool success;
public:
	Response() {
		this->success = false;
	}
	void append(std::string str) {
		this->messageError.push_back(str);
	}

	std::vector<std::string> getAll() {
		return this->messageError;
	}

	int size() {
		return this->messageError.size();
	}

	bool isSuccess() {

		return success;
	}

	void setSuccess(bool status) {
		this->success = status;
	}
};