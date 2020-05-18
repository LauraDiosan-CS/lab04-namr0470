#pragma once
#include "articol.h"
#include "utils.h"
#include <cstring>

using namespace std;

class RepositoryFile {
protected:

	vector<Articol*> articol;
	string fileName;
public:
	RepositoryFile();
	RepositoryFile(string);
	~RepositoryFile();
	void setFileName(string);

	vector<Articol*> getAll();
	int getSize();
	Articol* getArticol(int);
	void addArticol(Articol*);
	void updateArticol(Articol*, Articol*);
	void deleteArticol(Articol*);
	int find(Articol*);
	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};


