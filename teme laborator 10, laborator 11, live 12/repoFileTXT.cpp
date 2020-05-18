#include "repoFileTXT.h"


RepositoryFileTXT::RepositoryFileTXT() : RepositoryFile()
{
}

RepositoryFileTXT::RepositoryFileTXT(string fileName) : RepositoryFile(fileName)
{
}

RepositoryFileTXT::~RepositoryFileTXT()
{
}

void RepositoryFileTXT::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string line;
		char delim = ' ';
		while (getline(f, line))
		{
			std::vector<std::string> tokens = splitLine(line, delim);

			if (tokens[0] == "AA") {

				string id = tokens[1];
				string name = tokens[2];
				string date = tokens[3];
				int price = stoi(tokens[4]);
				int number_of_pieces = stoi(tokens[5]);
				int age = stoi(tokens[6]);

				Articol *pet = new animal(id, name, date, price, number_of_pieces, age);
				this->articol.push_back(pet);


			}
			else
				if (tokens[0] == "AP") {

					string id = tokens[1];
					string name = tokens[2];
					string date = tokens[3];
					int price = stoi(tokens[4]);
					int number_of_pieces = stoi(tokens[5]);
					string end_date = tokens[6];

					Articol* petStuff = new produs(id, name, date, price, number_of_pieces, end_date);
					this->articol.push_back(petStuff);
				}
		}
		f.close();
	}
}

void RepositoryFileTXT::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Articol* elem : this->articol)
		{
			f << elem->toStringDelimiter(" ") << endl;
		}
	}
}
