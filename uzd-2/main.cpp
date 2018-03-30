#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <fstream>
#include <algorithm>
#include "Funkcijos.h"

int main()
{
	std::cout << "Ar norite ivesti ranka(1), ar nuskaityti is failo(2)? ";
startas:
	int pasirinkimas;
	std::cin >> pasirinkimas;
	std::cout << std::endl;

	if (pasirinkimas == 1)
	{
		std::string vardas;
		std::string pavarde;
		int n;
		int egzamino_balas;
		double galutinis;
		//double vidurkis;
		std::vector<int> pazymiai_ranka;

		std::cout << "Iveskite varda, pavarde, egz paz" << std::endl;

		std::cin >> vardas >> pavarde >> n >> egzamino_balas;

		std::default_random_engine nr;
		std::uniform_int_distribution<int> uniform_dist(1, 10);

		/*start: // Galima ivesti kiek norima pazymiu i vectoriu
		int x;
		if(x!=0)
		{
		std::cin>>x;
		pazymiai_ranka.push_back(x);
		n++; // prie int n reikia pakeist i int n=0
		goto start;
		}*/

		int suma = 0;
		for (int i = 0; i < n; i++)
		{
			int x = uniform_dist(nr);
			pazymiai_ranka.push_back(x);
			suma = suma + x;
		}
		galutinis = 0.4*(suma / n) + 0.6*egzamino_balas;
		std::cout << vardas << " " << pavarde << std::endl;
		for (int i = 0; i < n; i++)
		{
			std::cout << pazymiai_ranka[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::setprecision(2) << galutinis;
		return 0;
	}

	else if (pasirinkimas == 2)
	{
		try
		{
			Nuskaitymas();
			Spausdinimas();
		}
		catch (std::exception& e)
		{
			std::cerr << "Nerastas Input_Output.cpp failas!";
		}
	}

	else
	{
		std::cout << "Iveskite 1 jei norite ivesti duomenys ranka, arba 2 jei norite nuskaityti is failo" << std::endl;
		goto startas;
	}
	return 0;
}