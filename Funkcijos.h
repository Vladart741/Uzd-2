#include<string>
#include<list>
#include<vector>
#include<deque>
#include "Struktura.h"

#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

// VEKTORIAI
double Galutinis_Vidurkis(std::vector<int>pazymiai, int egzaminas);
double Galutinis_Mediana(std::vector<int>pazymiai, int egzaminas);
void InputOutput_VEKTORIUS(std::string pav);


// LISTAI
double Galutinis_Mediana(std::list<int>pazymiai, int egzaminas);
double Galutinis_Vidurkis(std::list<int>pazymiai, int egzaminas);
void InputOutput_LISTAI(std::string pav);


// DEKAI
double Galutinis_Mediana(std::deque<int>pazymiai, int egzaminas);
double Galutinis_Vidurkis(std::deque<int>pazymiai, int egzaminas);
void InputOutput_DEKAI(std::string pav);


// BENDROS
void Failu_Generatorius(std::string pav, int n);
bool Rusiavimas(double vidurkis);
int main();

#endif
