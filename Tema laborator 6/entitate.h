#pragma once

#include <ostream>
using namespace std;

class Entitate {
private:
	char* titlu;
	char* autor;
	char* status;
public:
	Entitate();
	Entitate(const char* titlu, const char* autor, const char* status);
	Entitate(const Entitate&);
	Entitate& operator=(const Entitate&);
	char* getTitlu();
	char* getAutor();
	char* getStatus();
	void setTitlu(char* titlu);
	void setAutor(char* autor);
	void setStatus(char* status);
	bool operator==(const Entitate&);
	friend ostream& operator<<(ostream& os, const Entitate& s);
	void afisare();
	~Entitate();
};