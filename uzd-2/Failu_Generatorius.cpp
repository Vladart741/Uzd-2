#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include "Struktura.h"
#include "Funkcijos.h"
#include <iomanip>


void Failu_Generatorius(std::string pav, int n)
{
	std::vector<Duomenys>Studentai;
	std::ofstream fr;
	fr.open(pav);

	std::default_random_engine nr;
	std::uniform_int_distribution<int> gen1(1, 10);
	std::default_random_engine nr2;
	std::uniform_int_distribution<int> gen2(1, n);


	for (int i = 0; i < n; i++)
	{
		std::string Vardas = "Vardas";
		std::string Pavarde = "Pavarde";
		int egzaminas;
		int x = gen2(nr);
		std::string sk = std::to_string(x);

		Vardas = Vardas + sk;

		Pavarde = Pavarde + sk;

		std::vector<int>pazymiai;

		for (int j = 0; j < 5; j++)
		{
			int x = gen1(nr);
			pazymiai.push_back(x);
		}
		egzaminas = gen1(nr);
		Duomenys smth = { Vardas, Pavarde, pazymiai, egzaminas };
		Studentai.push_back(smth);

		//SPAUSDINIMAS
		fr.width(15); fr << std::left << Studentai[i].Vardas;
		fr.width(15); fr << std::left << Studentai[i].Pavarde;
		for (int j = 0; j < 5; j++)
		{
			fr.width(15); fr << std::left << Studentai[i].pazymiai[j];
		}
		fr.width(15); fr << std::left << Studentai[i].egzaminas;
		fr << std::endl;
		
	}


	fr.close();
}