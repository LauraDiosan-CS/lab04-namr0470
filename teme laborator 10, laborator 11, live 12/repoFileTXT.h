#pragma once
#include "repoFile.h"
#include <fstream>
#include "animal.h"
#include "produs.h"

class RepositoryFileTXT : public RepositoryFile {
public:
	RepositoryFileTXT();
	RepositoryFileTXT(string);
	~RepositoryFileTXT();
	void loadFromFile();
	void saveToFile();
};