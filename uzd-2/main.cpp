#include <iostream>
#include <vector>
#include "Funkcijos.h"
#include <chrono>

int main()
{
	std::string pav;
	int n;

	std::cout << "Iveskite:<" << std::endl;
	std::cout << "(1) jei norite nuskatityti egzistuojanti faila." << std::endl;
	std::cout << "(2) jei norite sugeneruoti nauja faila." << std::endl;

	int ats;
	std::cin >> ats;
	if (ats == 1)
	{
		std::cout << "Iveskite failo pavadinima: ";
		std::cin >> pav;

		auto start = std::chrono::high_resolution_clock::now();

		Output(pav);

		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
		std::cin >> n;
	}
	else if (ats == 2)
	{
		pav = "Duomenys.txt";
		std::cout << "Iveskite failo dydi: ";
		std::cin >> n;

		auto start = std::chrono::high_resolution_clock::now();

		Failu_Generatorius(pav, n);
		Output(pav);

		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
		std::cin >> n;
	}
	else
	{
		std::cout << "Iveskite:<" << std::endl;
		std::cout << "SKAICIU (1) jei norite nuskatityti egzistuojanti faila." << std::endl;
		std::cout << "SKAICIU (2) jei norite sugeneruoti nauja faila." << std::endl;
	}

	

	return 0;
}