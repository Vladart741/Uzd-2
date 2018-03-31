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
	std::vector<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	bool rusiavimas;
};
struct Duomenys_Listai
{
	std::string Vardas;
	std::string Pavarde;
	std::list<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	bool rusiavimas;
};
struct Duomenys_Dekai
{
	std::string Vardas;
	std::string Pavarde;
	std::deque<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	bool rusiavimas;
};

struct  Kietiakai_Dekai
{
	std::string Vardas;
	std::string Pavarde;
	std::deque<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	const bool rusiavimas = true;
};
struct  Vargsiukai_Dekai
{
	std::string Vardas;
	std::string Pavarde;
	std::deque<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	const bool rusiavimas = false;
};

struct  Kietiakai_Listai
{
	std::string Vardas;
	std::string Pavarde;
	std::list<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	const bool rusiavimas = true;
};
struct  Vargsiukai_Listai
{
	std::string Vardas;
	std::string Pavarde;
	std::list<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	const bool rusiavimas = false;
};

struct  Kietiakai_Vektoriai
{
	std::string Vardas;
	std::string Pavarde;
	std::vector<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	const bool rusiavimas = true;
};
struct  Vargsiukai_Vektoriai
{
	std::string Vardas;
	std::string Pavarde;
	std::vector<double>pazymiai;
	double egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	const bool rusiavimas = false;
};

#endif