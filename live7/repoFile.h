#pragma once
#include "entitate.h"
#include <vector>
using namespace std;

class repoFile {
private:
	vector<Entitate> elem;
	const char* fis;
public:
	repoFile();
	repoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	~repoFile();
};