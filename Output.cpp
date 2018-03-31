#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include "Struktura.h"
#include "Funkcijos.h"
#include <iomanip>



void Output(std::string pav)
{
	std::vector<Duomenys>Studentai;

	std::ifstream fd;
	fd.open(pav);
	if (!fd)
	{
		std::cerr << std::endl;
		std::cerr << "Failas " << pav << " neegzistuoja." << std::endl;
		std::cerr << std::endl;
		main();
	}
	else
	{
		int i = 0;
		while (!fd.eof())
		{
			std::string Vardas;
			std::string Pavarde;
			std::vector<int>pazymiai;
			int egzaminas;
			fd >> Vardas;
			fd >> Pavarde;
			for (int i = 0; i < 5; i++)
			{
				int x;
				fd >> x;
				pazymiai.push_back(x);
			}
			fd >> egzaminas;

			Duomenys something = { Vardas,Pavarde,pazymiai,egzaminas };
			Studentai.push_back(something);

			// SKAICIAVIMAI GAL_VID, GAL_MED IR RUSIAVIMAS
			Studentai[i].galutinis_vidurkis = Galutinis_Vidurkis(Studentai[i].pazymiai, Studentai[i].egzaminas);
			Studentai[i].galutinis_mediana = Galutinis_Mediana(Studentai[i].pazymiai, Studentai[i].egzaminas);
			Studentai[i].rusiavimas = Rusiavimas(Studentai[i].galutinis_vidurkis);

			i++;
		}
	}
	// SORTAS PAGAL VARDUS
	std::sort(Studentai.begin(), Studentai.end(), [](const Duomenys &left, const Duomenys &right)
	{ return (left.Vardas < right.Vardas); });
	fd.close();


	std::ofstream fr;
	fr.open("Rezultatai.txt");

	fr.width(15); fr << std::left << "Pavarde";
	fr.width(15); fr << std::left << "Vardas";
	fr.width(15); fr << std::left << "ND-1";
	fr.width(15); fr << std::left << "ND-2";
	fr.width(15); fr << std::left << "ND-3";
	fr.width(15); fr << std::left << "ND-4";
	fr.width(15); fr << std::left << "ND-5";
	fr.width(15); fr << std::left << "Egzaminas";
	fr.width(20); fr << std::left << "Galutinis-vidurkis";
	fr.width(20); fr << std::left << "Galutinis-mediana";
	fr.width(20); fr << std::left << "Kategorija";
	fr << std::endl;

	for (int i = 1; i !=Studentai.size(); i++)
	{
		//SPAUSDINIMAS
		fr.width(15); fr << std::left << Studentai[i].Pavarde;
		fr.width(15); fr << std::left << Studentai[i].Vardas;
		for (int j = 0; j < 5; j++)
		{
			fr.width(15); fr << std::left << Studentai[i].pazymiai[j];
		}
		fr.width(15); fr << std::left << Studentai[i].egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << Studentai[i].galutinis_vidurkis;
		fr.width(20); fr << std::left << Studentai[i].galutinis_mediana;
		if (Studentai[i].rusiavimas == true)
		{
			fr.width(20); fr << std::left << "Kietiakas";
		}
		else if (Studentai[i].rusiavimas == false)
		{
			fr.width(20); fr << std::left << "Vargsiukas";
		}
		fr << std::endl;
	}

	

	fr.close();
}