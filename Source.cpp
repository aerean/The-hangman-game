#include <iostream>
#include <stdlib.h>
#include "spanzuratoarea.h"

joc Joc;

void Intro()
{
	std::cout << std::endl << std::endl;
	std::cout << "Bun venit la jocul de spanzuratoarea. \n";
	std::cout << "O sa urmeze alegerea cuvantului, apoi jocul propriu zis. \n";
}

void introducereSolutie()
{
	std::string confirmare = "";
    std::string solutia = "";
	while (confirmare[0] != 'd' && confirmare[0] != 'D')
	{
		std::cout << "******************************************************\n";
		std::cout << "Introduceti un cuvant pentru a putea fi folosit la joc ";
		std::getline(std::cin, solutia);
		std::cout << "Se confirma cuvant (d/n)? ";
		std::getline(std::cin, confirmare);
	}
	Joc.modifCuvant(solutia);
}

void desenStickMan(int n)
{
	if (n == 0)
	{
		std::cout << "     |    \n";
		std::cout << "     |    \n\n\n\n";
	}
	else if (n == 1)
	{
		std::cout << "     |     \n";
		std::cout << "     |     \n";
		std::cout << "     O     \n\n\n";
	}
	else if (n == 2)
	{
		std::cout << "     |    \n";
		std::cout << "     |    \n";
		std::cout << "     O    \n";
		std::cout << "     |    \n";
		std::cout << "     |    \n";
	}
	else if (n == 3)
	{
		std::cout << "     |     \n";
		std::cout << "     |     \n";
		std::cout << "     O     \n";
		std::cout << "    /|   \n";
		std::cout << "     |     \n";
	}
	else if (n == 4)
	{
		std::cout << "     |     \n";
		std::cout << "     |     \n";
		std::cout << "     O     \n";
		std::cout << "    /|\\   \n";
		std::cout << "     |     \n";
	}
	else if (n == 5)
	{
		std::cout << "     |     \n";
		std::cout << "     |     \n";
		std::cout << "     O     \n";
		std::cout << "    /|\\   \n";
		std::cout << "     |     \n";
		std::cout << "    /      ";
	}
	else 
	{
		std::cout << "     |     \n";
		std::cout << "     |     \n";
		std::cout << "     O     \n";
		std::cout << "    /|\\   \n";
		std::cout << "     |     \n";
		std::cout << "    / \\   ";
	}
	/*else
	{
		std::cout << "     |     \n";
	    std::cout << "     |     \n";
		std::cout << "     O     \n";
		std::cout << "    /|\\   \n";
		std::cout << "     |     \n";
		std::cout << "    / \\   ";
	}*/
	return;
}

std::string campInitial()
{
	std::string cuvant = Joc.getCuvant();
	std::string camp(cuvant.length(),'_');
	for (std::size_t i = 0; i < cuvant.length(); i++)
	{
		if (cuvant[0] == cuvant[i])
			camp[i] = cuvant[0];
		if (cuvant[cuvant.length() - 1] == cuvant[i])
			camp[i] = cuvant[cuvant.length() - 1];
	}
	return camp;
}

void afisareCampCuvant(std::string camp)
{
	std::cout << "\n\nCuvantul: ";
	for (std::size_t i = 0; i < camp.length(); i++)
	{
		std::cout << camp[i] << " ";
	}
	std::cout << std::endl;
}

void afisareIncercari()
{
	std::vector<char> incercari = Joc.getVariante();
	std::cout << std::endl<<"Incercari: ";
	for (std::size_t i = 0; i != incercari.size(); i++)
		std::cout << incercari[i] << " , ";
	std::cout << std::endl;
}

int verificaSpatiiGoale(std::string camp)
{
	int n = 0;
	for (std::size_t i = 0; i < camp.length(); i++)
		if (camp[i] == '_')
			n++;
	return n;
}

void play()
{
	Joc.reset();
	introducereSolutie();
	system("cls");
	std::string camp = campInitial();
	while (Joc.getJocCastigat() == false && Joc.getNrVariante()<6)
	{
		system("cls");
		desenStickMan(Joc.getNrVariante());
		afisareCampCuvant(camp);
		afisareIncercari();
		std::cout << "\nintroduce o litera ";
		char c=getchar();
		getchar();
		camp = Joc.verificaVarianta(c, camp);
		int n = verificaSpatiiGoale(camp);
		Joc.modifJocCastigat(n);
	}
	if (Joc.getJocCastigat() == true)
	{
		system("cls");
		desenStickMan(Joc.getNrVariante());
		afisareCampCuvant(camp);
		afisareIncercari();
		std::cout << "\n***************\n";
		std::cout << "* Felicitari! *\n";
		std::cout << "***************\n";
	}
	else
	{
		system("cls");
		desenStickMan(Joc.getNrVariante());
		afisareCampCuvant(camp);
		afisareIncercari();
		std::cout << "\n------------------------------\n";
		std::cout << "Nu a mers bine..\nMai mult noroc data viitoare..\n";
	}
	return;
}

bool joacaIar() {
	std::string raspuns = "";
	std::cout << "\nJoci iar (d/n)? ";
	std::getline(std::cin, raspuns);
	return (raspuns[0] == 'd') || (raspuns[0] == 'D');
}

int main()
{
	bool prag = true;
	while (prag == true)
	{
		Intro();
		play();
		prag = joacaIar();
	}

	return 0;
}