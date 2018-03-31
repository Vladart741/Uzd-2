#include<string>
#include "Struktura.h"

#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

void Failu_Generatorius(std::string pav, int n);
void Output(std::string pav);
bool Rusiavimas(double vidurkis);
double Galutinis_Vidurkis(std::vector<int>pazymiai, int egzaminas);
double Galutinis_Mediana(std::vector<int>pazymiai, int egzaminas);
int main();

#endif
