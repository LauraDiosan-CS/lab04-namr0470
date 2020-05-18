#include "repoFile.h"

RepositoryFile::RepositoryFile()
{
}

RepositoryFile::RepositoryFile(string fileName)
{
	this->fileName = fileName;
}

RepositoryFile::~RepositoryFile()
{
}

void RepositoryFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

vector<Articol*> RepositoryFile::getAll()
{
	return this->articol;
}

int RepositoryFile::getSize()
{
	return this->articol.size();
}

Articol* RepositoryFile::getArticol(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->articol[pos]->clone();
	}
	return new Articol();
}

void RepositoryFile::addArticol(Articol* p)
{
	this->articol.push_back(p->clone());
	this->saveToFile();
}

void RepositoryFile::updateArticol(Articol* pVechi, Articol* pNou)
{
	for (int i = 0; i < this->articol.size(); i++)
	{
		if (*(this->getArticol(i)) == *pVechi)
		{
			delete this->articol[i];
			this->articol[i] = pNou->clone();
			this->saveToFile();
			return;
		}
	}
}

int RepositoryFile::find(Articol* e) {

	auto it = std::find(articol.begin(), articol.end(), e);
	if (it != articol.end()) return distance(articol.begin(), it);
	return -1;
}

void RepositoryFile::deleteArticol(Articol* p)
{
	for (int i = 0; i < this->articol.size(); i++)
	{
		// this->produce.begin() + i <=> un iterator care pointeaza spre pozitia i din vector
		if (**(this->articol.begin() + i) == *p)
		{
			delete this->articol[i];
			//este necesar un iterator pt. metoda erase
			this->articol.erase(this->articol.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

void RepositoryFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->articol[i];
	}
	this->articol.clear();
}

