#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <random>
#include <fstream>
#include <chrono>
#include "Struktura.h"
#include "Funkcijos.h"
#include <iomanip>

bool Pagal_Varda(const Duomenys_Listai& x, const Duomenys_Listai& y) { return x.Vardas < y.Vardas; }

void InputOutput_VEKTORIUS(std::string pav)
{
	std::vector<Duomenys_Vektoriai>Studentai;

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

			Duomenys_Vektoriai something = { Vardas,Pavarde,pazymiai,egzaminas };
			Studentai.push_back(something);

			// SKAICIAVIMAI GAL_VID, GAL_MED IR RUSIAVIMAS
			Studentai[i].galutinis_vidurkis = Galutinis_Vidurkis(Studentai[i].pazymiai, Studentai[i].egzaminas);
			Studentai[i].galutinis_mediana = Galutinis_Mediana(Studentai[i].pazymiai, Studentai[i].egzaminas);
			Studentai[i].rusiavimas = Rusiavimas(Studentai[i].galutinis_vidurkis);

			i++;
		}
	}
	// SORTAS PAGAL VARDUS
	std::sort(Studentai.begin(), Studentai.end(), [](const Duomenys_Vektoriai &left, const Duomenys_Vektoriai &right)
	{ return (left.Vardas < right.Vardas); });
	fd.close();


	std::ofstream fr;
	fr.open("Rezultatai_Vektoriai.txt");

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
void InputOutput_DEKAI(std::string pav)
{
	std::deque<Duomenys_Dekai>Studentai;

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
			std::deque<int>pazymiai;
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

			Duomenys_Dekai something = { Vardas,Pavarde,pazymiai,egzaminas };
			Studentai.push_back(something);

			// SKAICIAVIMAI GAL_VID, GAL_MED IR RUSIAVIMAS
			Studentai[i].galutinis_vidurkis = Galutinis_Vidurkis(Studentai[i].pazymiai, Studentai[i].egzaminas);
			Studentai[i].galutinis_mediana = Galutinis_Mediana(Studentai[i].pazymiai, Studentai[i].egzaminas);
			Studentai[i].rusiavimas = Rusiavimas(Studentai[i].galutinis_vidurkis);

			i++;
		}
	}
	// SORTAS PAGAL VARDUS
	std::sort(Studentai.begin(), Studentai.end(), [](const Duomenys_Dekai &left, const Duomenys_Dekai &right)
	{ return (left.Vardas < right.Vardas); });
	fd.close();


	std::ofstream fr;
	fr.open("Rezultatai_Dekai.txt");

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

	for (int i = 1; i != Studentai.size(); i++)
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
void InputOutput_LISTAI(std::string pav)
{
	std::list<Duomenys_Listai>Studentai;

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
			std::list<int>pazymiai;
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
			double Gal_vid = Galutinis_Vidurkis(pazymiai, egzaminas);
			double Gal_med = Galutinis_Mediana(pazymiai, egzaminas);
			bool rusiavimas = Rusiavimas(Gal_vid);

			Duomenys_Listai something = { Vardas,Pavarde,pazymiai,egzaminas,Gal_vid,Gal_med,rusiavimas };
			Studentai.push_back(something);

			i++;
		}
	}

	Studentai.sort(Pagal_Varda); // SORTAS PAGAL VARDUS

	fd.close();

	std::ofstream fr;
	fr.open("Rezultatai_Listai.txt");

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

	for (auto i : Studentai)
	{
		//SPAUSDINIMAS

		fr.width(15); fr << std::left << i.Pavarde;
		fr.width(15); fr << std::left << i.Vardas;
		for (auto j : i.pazymiai)
		{
			fr.width(15); fr << std::left << j;
		}
		fr.width(15); fr << std::left << i.egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << i.galutinis_vidurkis;
		fr.width(20); fr << std::left << i.galutinis_mediana;
		if (i.rusiavimas == true)
		{
			fr.width(20); fr << std::left << "Kietiakas";
		}
		else if (i.rusiavimas == false)
		{
			fr.width(20); fr << std::left << "Vargsiukas";
		}
		fr << std::endl;
	}



	fr.close();
}