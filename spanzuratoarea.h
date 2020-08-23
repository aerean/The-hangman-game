#pragma once
#include <string>
#include <vector>

class joc 
{
	std::string cuvant;
	bool joc_castigat;
	std::vector<char> variante;

public:
	joc();
	void reset();
	std::string getCuvant();
	bool getJocCastigat();
	std::vector<char> getVariante();
	int getNrVariante();
	void modifCuvant(std::string);
	void modifJocCastigat(int);
	std::string verificaVarianta(char,std::string);
};
