#include <iostream>
#include <vector>
#include <fstream>

#ifndef KINTAMIEJI_H
#define KINTAMIEJI_H

struct Duomenys
{
	std::string Vardas;
	std::string Pavarde;
	std::vector<int>pazymiai;
	int egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
	bool rusiavimas;
};
	

#endif