#pragma once
#include "repoFile.h"
#include <fstream>
#include "animal.h"
#include "produs.h"

class RepositoryFileCSV : public RepositoryFile {
public:
	RepositoryFileCSV();
	RepositoryFileCSV(string);
	~RepositoryFileCSV();
	void loadFromFile();
	void saveToFile();
};