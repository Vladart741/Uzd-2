#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <fstream>

#ifndef KINTAMIEJI_H
#define KINTAMIEJI_H

struct Duomenys_Vektoriai
{
	std::string Vardas;
	std::string Pavarde;
	std::vector<int>pazymiai;
	int egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	bool rusiavimas;
};
struct Duomenys_Listai
{
	std::string Vardas;
	std::string Pavarde;
	std::list<int>pazymiai;
	int egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	bool rusiavimas;
};
struct Duomenys_Dekai
{
	std::string Vardas;
	std::string Pavarde;
	std::deque<int>pazymiai;
	int egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	bool rusiavimas;
};

#endif
