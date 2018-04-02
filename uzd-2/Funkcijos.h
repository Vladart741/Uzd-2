#include<string>
#include<list>
#include<vector>
#include<deque>
#include "Struktura.h"

#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

// VEKTORIAI
double Galutinis_Vidurkis(std::vector<double>pazymiai, double egzaminas);
double Galutinis_Mediana(std::vector<double>pazymiai, double egzaminas);
void InputOutput_VEKTORIUS(std::string pav);
void InputOutput_VEKTORIUS_Pirma_Strategija(std::string pav);
void InputOutput_VEKTORIUS_Antra_Strategija(std::string pav);

// LISTAI
double Galutinis_Mediana(std::list<double>pazymiai, double egzaminas);
double Galutinis_Vidurkis(std::list<double>pazymiai, double egzaminas);
void InputOutput_LISTAI(std::string pav);
void InputOutput_LISTAI_Pirma_Strategija(std::string pav);
void InputOutput_LISTAI_Antra_Strategija(std::string pav);

// DEKAI
double Galutinis_Mediana(std::deque<double>pazymiai, double egzaminas);
double Galutinis_Vidurkis(std::deque<double>pazymiai, double egzaminas);
void InputOutput_DEKAI(std::string pav);
void InputOutput_DEKAI_Pirma_Strategija(std::string pav);
void InputOutput_DEKAI_Antra_Strategija(std::string pav);

// BENDROS
void Failu_Generatorius(std::string pav, int n);
int main();



#endif
