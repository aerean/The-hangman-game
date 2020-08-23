#include "spanzuratoarea.h"

joc::joc()
{
	reset();
}

void joc::reset()
{
	cuvant = "";
	joc_castigat = false;
	variante.clear();
	return;
}

std::string joc::getCuvant()
{
	return cuvant;
}

bool joc::getJocCastigat()
{
	return joc_castigat;
}

std::vector<char> joc::getVariante()
{
	return variante;
}

int joc::getNrVariante()
{
	return variante.size();
}

void joc::modifCuvant(std::string cuvant)
{
	this->cuvant = cuvant;
	return;
}

void joc::modifJocCastigat(int n)
{
	if (n == 0)
		joc_castigat = true;
	return;
}

std::string joc::verificaVarianta(char c,std::string camp)
{
	int m = 0;
	for (std::size_t i = 1; i < camp.length()-1; i++)
	{
		if (c == cuvant[i])
		{
			camp[i] = c;
			m++;
		}
	}
	if (m == 0)
		variante.push_back(c);
	return camp;
}
