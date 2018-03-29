#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <fstream>
#include <algorithm>

int main()
{
	std::cout << "Ar norite ivesti ranka(1), ar nuskaityti is failo(2)? ";
startas:
	int pasirinkimas;
	std::cin >> pasirinkimas;
	std::cout << std::endl;

	if (pasirinkimas == 1)
	{
		std::cout << "Iveskite varda, pavarde, egz paz" << std::endl;
		std::string vardas;
		std::string pavarde;
		int n;
		int egzamino_balas;
		std::cin >> vardas >> pavarde >> n >> egzamino_balas;
		double galutinis;
		double vidurkis;
		std::vector<int> pazymiai;

		std::default_random_engine nr;
		std::uniform_int_distribution<int> uniform_dist(1, 10);

		/*start: // Galima ivesti kiek norima pazymiu i vectoriu
		int x;
		if(x!=0)
		{
		std::cin>>x;
		pazymiai.push_back(x);
		n++; // prie int n reikia pakeist i int n=0
		goto start;
		}*/

		int suma = 0;
		for (int i = 0; i < n; i++)
		{
			int x = uniform_dist(nr);
			pazymiai.push_back(x);
			suma = suma + x;
		}
		galutinis = 0.4*(suma / n) + 0.6*egzamino_balas;
		std::cout << vardas << " " << pavarde << std::endl;
		for (int i = 0; i < n; i++)
		{
			std::cout << pazymiai[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::setprecision(2) << galutinis;
	}

	else if (pasirinkimas == 2)
	{
		struct Duomenys
		{
			std::string Vardas;
			std::string Pavarde;
			std::vector<int>pazymiai;
			int egzaminas;
			double galutinis_vidurkis;
			double galutinis_mediana;
		};


		std::ifstream fd;
		fd.open("Duomenys.txt");
		std::vector<Duomenys>Studentai;

		if (!fd)
		{
			std::cerr << "Failas tuscias!";
		}
		else
		{
			while (!fd.eof())
			{
				std::string Vardas;
				std::string Pavarde;
				std::vector<int>pazymiai;
				int egzaminas;

				fd >> Vardas;
				fd >> Pavarde;
				for (int i = 0; i < 5; i++)
				{
					int x;
					fd >> x;
					pazymiai.push_back(x);
				}
				fd >> egzaminas;

				Duomenys something = { Vardas,Pavarde,pazymiai,egzaminas };
				Studentai.push_back(something);
			}
		}
		fd.close();

		std::ofstream fr;
		fr.open("Rezultatai.txt");

		std::sort(Studentai.begin(), Studentai.end(), // SORTAS PAGAL VARDUS
			[](const Duomenys &left, const Duomenys &right)
		{ return (left.Vardas < right.Vardas); });

		for (int i = 0; i != Studentai.size(); i++)
		{
			double suma = 0;
			int n = 1;
			for (int j = 0; j != Studentai[i].pazymiai.size(); j++)
			{
				suma = suma + Studentai[i].pazymiai[j];
				n++;
			}
			Studentai[i].galutinis_vidurkis = (Studentai[i].egzaminas + suma) / n;
			if (n % 2 == 0)
			{
				Studentai[i].pazymiai.push_back(Studentai[i].egzaminas);
				std::sort(Studentai[i].pazymiai.begin(), Studentai[i].pazymiai.end());
				Studentai[i].galutinis_mediana = Studentai[i].pazymiai[n / 2];
			}
			else
			{
				Studentai[i].pazymiai.push_back(Studentai[i].egzaminas);
				std::sort(Studentai[i].pazymiai.begin(), Studentai[i].pazymiai.end());
				Studentai[i].galutinis_mediana = (Studentai[i].pazymiai[(n / 2) + 1] + Studentai[i].pazymiai[(n / 2) - 1]) / 2;
			}
		}

		fr.width(20); fr << std::left << "Pavarde";
		fr.width(20); fr << std::left << "Vardas";
		fr.width(20); fr << std::left << "Galutinis-vidurkis";
		fr.width(20); fr << std::left << "Galutinis-mediana";
		fr << std::endl;

		for (int i = 0; i != Studentai.size(); i++)
		{
			fr.width(20); fr << std::left << Studentai[i].Pavarde;
			fr.width(20); fr << std::left << Studentai[i].Vardas;
			fr.width(20); fr << std::left << std::setprecision(3) << Studentai[i].galutinis_vidurkis;
			fr.width(20); fr << std::left << Studentai[i].galutinis_mediana;
			fr << std::endl;

		}
		fr.close();
	}

	else
	{
		std::cout << "Iveskite 1 jei norite ivesti duomenys ranka, arba 2 jei norite nuskaityti is failo" << std::endl;
		goto startas;
	}
	return 0;
}