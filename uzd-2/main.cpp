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
	std::cout << "(3) jei norite sugeneruoti ir nuskaityti nauja faila." << std::endl;

	int ats;
	std::cin >> ats;
	if (ats == 1)
	{
		std::cout << "Iveskite failo pavadinima: ";
		std::cin >> pav;
/////////////////////////////////////////////////////// VEKTORIAI ////////////////////////////////////////////////////////////////////////////////////
		auto start1 = std::chrono::high_resolution_clock::now();

		InputOutput_VEKTORIUS(pav); 

		auto finish1 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed1 = finish1 - start1;
		std::cout << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
/////////////////////////////////////////////////////// LISTAI ////////////////////////////////////////////////////////////////////////////////////
		auto start2 = std::chrono::high_resolution_clock::now();

		InputOutput_LISTAI(pav); 

		auto finish2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed2 = finish2 - start2;
		std::cout << "Programos vykdymo laikas su list: " << elapsed2.count() << " s\n";
/////////////////////////////////////////////////////// DEKAI ////////////////////////////////////////////////////////////////////////////////////
		auto start3 = std::chrono::high_resolution_clock::now();
		InputOutput_DEKAI(pav);
		auto finish3 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed3 = finish3 - start3;
		std::cout << "Programos vykdymo laikas su deque: " << elapsed3.count() << " s\n";

		system("pause");
	}
	else if (ats == 3)
	{
		pav = "Duomenys.txt";
		std::cout << "Iveskite failo dydi: ";
		std::cin >> n;


		Failu_Generatorius(pav, n);
/////////////////////////////////////////////////////// VEKTORIAI ////////////////////////////////////////////////////////////////////////////////////
		auto start1 = std::chrono::high_resolution_clock::now();

		Failu_Generatorius(pav, n);
		InputOutput_VEKTORIUS(pav);

		auto finish1 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed1 = finish1 - start1;
		std::cout << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
/////////////////////////////////////////////////////// LISTAI ////////////////////////////////////////////////////////////////////////////////////
		auto start2 = std::chrono::high_resolution_clock::now();

		Failu_Generatorius(pav, n);
		InputOutput_LISTAI(pav);

		auto finish2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed2 = finish2 - start2;
		std::cout << "Programos vykdymo laikas su list: " << elapsed2.count() << " s\n";
/////////////////////////////////////////////////////// DEKAI ////////////////////////////////////////////////////////////////////////////////////
		auto start3 = std::chrono::high_resolution_clock::now();

		Failu_Generatorius(pav, n);
		InputOutput_DEKAI(pav);

		auto finish3 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed3 = finish3 - start3;
		std::cout << "Programos vykdymo laikas su deque: " << elapsed3.count() << " s\n";

		system("pause");
	}
	else if (ats == 2)
	{
		std::cout << "Iveskite failo pavadinima: ";
		std::cin >> pav;
		pav = pav + ".txt";
		std::cout << "Iveskite failo dydi: ";
		std::cin >> n;

		Failu_Generatorius(pav, n);
		std::cout << std::endl;
		std::cout << "Sugeneruota sekmingai." << std::endl;
		std::cout << std::endl;
		main();
	}

	else
	{
		std::cout << "Iveskite:<" << std::endl;
		std::cout << "SKAICIU (1) jei norite nuskatityti egzistuojanti faila." << std::endl;
		std::cout << "SKAICIU (2) jei norite sugeneruoti nauja faila." << std::endl;
	}

	

	return 0;
}