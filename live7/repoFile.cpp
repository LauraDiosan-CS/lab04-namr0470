#include "repoFile.h"
#include <fstream>
#include <string>
using namespace std;

repoFile::repoFile(){}

repoFile::~repoFile() {}

repoFile::repoFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* titlu = new char[10];
	char* autor = new char[10];
	char* status = new char[10];
	while (!f.eof()) {
		f >> titlu >> autor >> status;
		if (titlu != "" and autor != "" and status != "") {
			Entitate e(titlu, autor, status);
			elem.push_back(e);
		}
	}
	delete[] titlu;
	delete[] autor;
	delete[] status;
	f.close();
}

void repoFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* titlu = new char[10];
	char* autor = new char[10];
	char* status = new char[10];
	while (!f.eof()) {
		f >> titlu >> autor >> status;
		if (strcmp(titlu, "") != 0 and strcmp(autor, "") != 0 and strcmp(status, "") != 0) {
			Entitate c(titlu, autor, status);
			elem.push_back(c);
		}
	}
	delete[] titlu;
	delete[] autor;
	delete[] status;
	f.close();
}