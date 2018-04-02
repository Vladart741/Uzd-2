#include <iostream>
#include <vector>
#include <deque>
#include <list>

#ifndef KINTAMIEJI_H
#define KINTAMIEJI_H

struct Duomenys_Vektoriai
{
	std::string Vardas;
	std::string Pavarde;
	std::vector<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
};
struct Duomenys_Listai
{
	std::string Vardas;
	std::string Pavarde;
	std::list<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
};
struct Duomenys_Dekai
{
	std::string Vardas;
	std::string Pavarde;
	std::deque<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
};

#endif