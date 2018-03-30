#include <iostream>
#include <vector>
#include <fstream>

#ifndef KINTAMIEJI_H
#define KINTAMIEJI_H

// VERSIJOS 0.1


// VERSIJOS 0.2
struct Duomenys
{
	std::string Vardas;
	std::string Pavarde;
	std::vector<int>pazymiai;
	int egzaminas;
	double galutinis_vidurkis;
	double galutinis_mediana;
};


std::vector<Duomenys>Studentai;
std::string Vardas;
std::string Pavarde;
std::vector<int>pazymiai;
int egzaminas;

std::ifstream fd;

std::ofstream fr;

#endif
