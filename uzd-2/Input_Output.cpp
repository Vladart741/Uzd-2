#include "Kintamieji.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Funkcijos.h"

void Nuskaitymas()
{
	fd.open("Duomenys.txt");
	if (!fd)
	{
		std::cerr << "Failas tuscias!";
	}
	else
	{
		while (!fd.eof())
		{

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
		}
	}
	fd.close();

	std::sort(Studentai.begin(), Studentai.end(), // SORTAS PAGAL VARDUS
		[](const Duomenys &left, const Duomenys &right)
	{ return (left.Vardas < right.Vardas); });
}
void Spausdinimas()
{
	fr.open("Rezultatai.txt");

	for (int i = 0; i != Studentai.size(); i++)
	{
		double suma = 0;
		int n = 0;
		for (int j = 0; j != Studentai[i].pazymiai.size(); j++)
		{
			suma = suma + Studentai[i].pazymiai[j];
			n++;
		}
		Studentai[i].galutinis_vidurkis = Studentai[i].egzaminas*0.6 + ((suma/n) * 0.4);
		if (n % 2 == 0)
		{
			Studentai[i].pazymiai.push_back(Studentai[i].egzaminas);
			std::sort(Studentai[i].pazymiai.begin(), Studentai[i].pazymiai.end());
			Studentai[i].galutinis_mediana = Studentai[i].pazymiai[(n+1) / 2];
		}
		else
		{
			Studentai[i].pazymiai.push_back(Studentai[i].egzaminas);
			std::sort(Studentai[i].pazymiai.begin(), Studentai[i].pazymiai.end());
			Studentai[i].galutinis_mediana = (Studentai[i].pazymiai[((n+1) / 2) + 1] + Studentai[i].pazymiai[((n+1) / 2) - 1]) / 2;
		}
	}

	fr.width(20); fr << std::left << "Pavarde";
	fr.width(20); fr << std::left << "Vardas";
	fr.width(20); fr << std::left << "Galutinis-vidurkis";
	fr.width(20); fr << std::left << "Galutinis-mediana";
	fr << std::endl;

	for (int i = 0; i != Studentai.size(); i++)
	{
		fr.width(20); fr << std::left << Studentai[i].Pavarde;
		fr.width(20); fr << std::left << Studentai[i].Vardas;
		fr.width(20); fr << std::left << std::setprecision(3) << Studentai[i].galutinis_vidurkis;
		fr.width(20); fr << std::left << Studentai[i].galutinis_mediana;
		fr << std::endl;

	}
	fr.close();
}