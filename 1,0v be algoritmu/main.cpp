#include <iostream>
#include <vector>
#include "Funkcijos.h"
#include <chrono>
#include <fstream>

int main()
{
	std::string pav;
	int n;

	std::cout << "Iveskite:" << std::endl;

	std::cout << "(1) jei norite sugeneruoti nauja faila." << std::endl;
	std::cout << "(2) jei norite nuskatityti egzistuojanti faila." << std::endl;
	std::cout << "(3) jei norite sugeneruoti ir nuskaityti nauja faila." << std::endl;
	std::cout << "(4) jei norite nuskatityti egzistuojanti faila pagal PIRMA STRATEGIJA" << std::endl;
	std::cout << "(5) jei norite nuskatityti egzistuojanti faila pagal ANTRA STRATEGIJA" << std::endl;

	pradzia:
	std::string ats;
	std::cin >> ats;
	if (ats == "2")
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
	else if (ats == "3")
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
	else if (ats == "1")
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
	else if (ats == "4")
	{
		std::cout << "Jei norite nuskaityti 1 faila, iveskite (1) " << std::endl;
		std::cout << "Jei norite nuskaityti visus failus, iveskite (5) " << std::endl;
		taskas:
		std::cin >> ats;
		if (ats == "1")
		{
			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> pav;
			/////////////////////////////////////////////////////// VEKTORIAI ////////////////////////////////////////////////////////////////////////////////////
			auto start1 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Pirma_Strategija(pav);

			auto finish1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed1 = finish1 - start1;
			std::cout << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
			/////////////////////////////////////////////////////// LISTAI ////////////////////////////////////////////////////////////////////////////////////
			auto start2 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Pirma_Strategija(pav);

			auto finish2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed2 = finish2 - start2;
			std::cout << "Programos vykdymo laikas su list: " << elapsed2.count() << " s\n";
			/////////////////////////////////////////////////////// DEKAI ////////////////////////////////////////////////////////////////////////////////////
			auto start3 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Pirma_Strategija(pav);

			auto finish3 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed3 = finish3 - start3;
			std::cout << "Programos vykdymo laikas su deque: " << elapsed3.count() << " s\n";

			system("pause");
		}
		else if (ats == "5")
		{
			{std::ofstream fr("VEKTORIAI_REZULTATAI.txt");
			auto start1 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Pirma_Strategija("Duomenys1.txt");

			auto finish1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed1 = finish1 - start1;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start2 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Pirma_Strategija("Duomenys2.txt");

			auto finish2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed2 = finish2 - start2;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed2.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start3 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Pirma_Strategija("Duomenys3.txt");

			auto finish3 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed3 = finish3 - start3;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed3.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start4 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Pirma_Strategija("Duomenys4.txt");

			auto finish4 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed4 = finish4 - start4;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed4.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start5 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Pirma_Strategija("Duomenys5.txt");

			auto finish5 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed5 = finish5 - start5;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed5.count() << " s\n";
			} // VEKTORIU REZ
			{std::ofstream fr("DEKAI_REZULTATAI.txt");
			auto start1 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Pirma_Strategija("Duomenys1.txt");

			auto finish1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed1 = finish1 - start1;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start2 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Pirma_Strategija("Duomenys2.txt");

			auto finish2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed2 = finish2 - start2;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed2.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start3 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Pirma_Strategija("Duomenys3.txt");

			auto finish3 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed3 = finish3 - start3;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed3.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start4 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Pirma_Strategija("Duomenys4.txt");

			auto finish4 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed4 = finish4 - start4;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed4.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start5 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Pirma_Strategija("Duomenys5.txt");

			auto finish5 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed5 = finish5 - start5;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed5.count() << " s\n";
			} // DEKU REZ
			{std::ofstream fr("LISTAI_REZULTATAI.txt");
			auto start1 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Pirma_Strategija("Duomenys1.txt");

			auto finish1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed1 = finish1 - start1;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start2 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Pirma_Strategija("Duomenys2.txt");

			auto finish2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed2 = finish2 - start2;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed2.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start3 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Pirma_Strategija("Duomenys3.txt");

			auto finish3 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed3 = finish3 - start3;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed3.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start4 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Pirma_Strategija("Duomenys4.txt");

			auto finish4 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed4 = finish4 - start4;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed4.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start5 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Pirma_Strategija("Duomenys5.txt");

			auto finish5 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed5 = finish5 - start5;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed5.count() << " s\n";
			} // LISTU REZ
		}
		else
		{
			std::cout << "SKAICIU (1) Jei norite nuskaityti 1 faila" << std::endl;
			std::cout << "SKAICIU (5) Jei norite nuskaityti visus failus" << std::endl;
			goto taskas;
		}
	}
	else if (ats == "5")
	{
		std::cout << "Jei norite nuskaityti 1 faila, iveskite (1) "<< std::endl;
		std::cout << "Jei norite nuskaityti visus failus, iveskite (5) " << std::endl;
		taskas2:
		std::cin >> ats;
		if (ats == "1")
		{
			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> pav;
			/////////////////////////////////////////////////////// VEKTORIAI ////////////////////////////////////////////////////////////////////////////////////
			auto start1 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Antra_Strategija(pav);

			auto finish1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed1 = finish1 - start1;
			std::cout << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
			/////////////////////////////////////////////////////// LISTAI ////////////////////////////////////////////////////////////////////////////////////
			auto start2 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Antra_Strategija(pav);

			auto finish2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed2 = finish2 - start2;
			std::cout << "Programos vykdymo laikas su list: " << elapsed2.count() << " s\n";
			/////////////////////////////////////////////////////// DEKAI ////////////////////////////////////////////////////////////////////////////////////
			auto start3 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Antra_Strategija(pav);

			auto finish3 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed3 = finish3 - start3;
			std::cout << "Programos vykdymo laikas su deque: " << elapsed3.count() << " s\n";

			system("pause");
		}
		else if (ats == "5")
		{
			{std::ofstream fr("VEKTORIAI_REZULTATAI.txt");
			auto start1 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Antra_Strategija("Duomenys1.txt");

			auto finish1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed1 = finish1 - start1;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start2 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Antra_Strategija("Duomenys2.txt");

			auto finish2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed2 = finish2 - start2;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed2.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start3 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Antra_Strategija("Duomenys3.txt");

			auto finish3 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed3 = finish3 - start3;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed3.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start4 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Antra_Strategija("Duomenys4.txt");

			auto finish4 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed4 = finish4 - start4;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed4.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start5 = std::chrono::high_resolution_clock::now();

			InputOutput_VEKTORIUS_Antra_Strategija("Duomenys5.txt");

			auto finish5 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed5 = finish5 - start5;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed5.count() << " s\n";
			} // VEKTORIU REZ
			{std::ofstream fr("DEKAI_REZULTATAI.txt");
			auto start1 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Antra_Strategija("Duomenys1.txt");

			auto finish1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed1 = finish1 - start1;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start2 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Antra_Strategija("Duomenys2.txt");

			auto finish2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed2 = finish2 - start2;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed2.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start3 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Antra_Strategija("Duomenys3.txt");

			auto finish3 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed3 = finish3 - start3;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed3.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start4 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Antra_Strategija("Duomenys4.txt");

			auto finish4 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed4 = finish4 - start4;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed4.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start5 = std::chrono::high_resolution_clock::now();

			InputOutput_DEKAI_Antra_Strategija("Duomenys5.txt");

			auto finish5 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed5 = finish5 - start5;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed5.count() << " s\n";
			} // DEKU REZ
			{std::ofstream fr("LISTAI_REZULTATAI.txt");
			auto start1 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Antra_Strategija("Duomenys1.txt");

			auto finish1 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed1 = finish1 - start1;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed1.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start2 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Antra_Strategija("Duomenys2.txt");

			auto finish2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed2 = finish2 - start2;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed2.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start3 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Antra_Strategija("Duomenys3.txt");

			auto finish3 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed3 = finish3 - start3;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed3.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start4 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Antra_Strategija("Duomenys4.txt");

			auto finish4 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed4 = finish4 - start4;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed4.count() << " s\n";
			/////////////////////////////////////////////////////////////////////////////////////
			auto start5 = std::chrono::high_resolution_clock::now();

			InputOutput_LISTAI_Antra_Strategija("Duomenys5.txt");

			auto finish5 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed5 = finish5 - start5;
			fr << "Programos vykdymo laikas su vektoriais: " << elapsed5.count() << " s\n";
			} // LISTU REZ
		}
		else
		{
			std::cout << "SKAICIU (1) Jei norite nuskaityti 1 faila" << std::endl;
			std::cout << "SKAICIU (5) Jei norite nuskaityti visus failus" << std::endl;
			goto taskas2;
		}
	}


	else
	{
		std::cout << "Iveskite:<" << std::endl;
		std::cout << "SKAICIU (1) jei norite nuskatityti egzistuojanti faila." << std::endl;
		std::cout << "SKAICIU (2) jei norite sugeneruoti nauja faila." << std::endl;
		std::cout << "SKAICIU (3) jei norite sugeneruoti ir nuskaityti nauja faila." << std::endl;
		std::cout << "SKAICIU (4) jei norite nuskatityti egzistuojanti faila pagal PIRMA STRATEGIJA" << std::endl;
		std::cout << "SKAICIU (5) jei norite nuskatityti egzistuojanti faila pagal ANTRA STRATEGIJA" << std::endl;
		goto pradzia;
	}



	return 0;
}
