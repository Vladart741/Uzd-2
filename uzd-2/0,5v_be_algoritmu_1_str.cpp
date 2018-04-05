#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <fstream>
#include "Struktura.h"
#include "Funkcijos.h"
#include <iomanip>

bool Pagal_Varda_Vektoriai(const Duomenys_Vektoriai& x, const Duomenys_Vektoriai& y) { return x.Vardas < y.Vardas; }
bool Pagal_Varda_Listai(const Duomenys_Listai& x, const Duomenys_Listai& y) { return x.Vardas < y.Vardas; }
bool Pagal_Varda_Dekai(const Duomenys_Dekai& x, const Duomenys_Dekai& y) { return x.Vardas < y.Vardas; }

/*struct rusiavimas_vektoriai_vargsiukai
{
bool operator() (const Duomenys_Vektoriai& a)
{
if (a.galutinis_vidurkis < 5)
{
return true;
}
else
{
return false;
}
}
};
struct rusiavimas_vektoriai_kietiakai
{
bool operator() (const Duomenys_Vektoriai& a)
{
if (a.galutinis_vidurkis >= 5)
{
return true;
}
else
{
return false;
}
}
};

struct rusiavimas_listai_vargsiukai
{
bool operator() (const Duomenys_Listai& a)
{
if (a.galutinis_vidurkis < 5)
{
return true;
}
else
{
return false;
}
}
};
struct rusiavimas_listai_kietiakai
{
bool operator() (const Duomenys_Listai& a)
{
if (a.galutinis_vidurkis >= 5)
{
return true;
}
else
{
return false;
}
}
};

struct rusiavimas_dekai_vargsiukai
{
bool operator() (const Duomenys_Dekai& a)
{
if (a.galutinis_vidurkis < 5)
{
return true;
}
else
{
return false;
}
}
};
struct rusiavimas_dekai_kietiakai
{
bool operator() (const Duomenys_Dekai& a)
{
if (a.galutinis_vidurkis >= 5)
{
return true;
}
else
{
return false;
}
}
};
*/


void InputOutput_VEKTORIUS_Pirma_Strategija_BE_ALGORITMU(std::string pav)
{
	std::vector<Duomenys_Vektoriai>Studentai;
	std::vector<Duomenys_Vektoriai>Kietiakai;
	std::vector<Duomenys_Vektoriai>Vargsiukai;

	std::ifstream fd;
	fd.open(pav);
	if (!fd)
	{
		std::cerr << std::endl;
		std::cerr << "Failas " << pav << " neegzistuoja." << std::endl;
		std::cerr << std::endl;
		main();
	}
	else
	{

		while (!fd.eof())
		{
			std::string Vardas;
			std::string Pavarde;
			std::vector<double>pazymiai;
			double egzaminas;
			fd >> Vardas;
			fd >> Pavarde;
			for (int i = 0; i < 5; i++)
			{
				double x;
				fd >> x;
				pazymiai.push_back(x);
			}
			fd >> egzaminas;

			// SKAICIAVIMAI GAL_VID, GAL_MED IR RUSIAVIMAS
			double Gal_vid = Galutinis_Vidurkis(pazymiai, egzaminas);
			double Gal_med = Galutinis_Mediana(pazymiai, egzaminas);

			Duomenys_Vektoriai something = { Vardas,Pavarde,pazymiai,egzaminas,Gal_vid,Gal_med };
			Studentai.push_back(something);

			if (Gal_vid < 5)
			{
				Vargsiukai.push_back(something);
			}
			else if (Gal_vid >= 5)
			{
				Kietiakai.push_back(something);
			}

		}
	}
	// SORTAS PAGAL VARDUS
	std::sort(Studentai.begin(), Studentai.end(), Pagal_Varda_Vektoriai);

	//std::copy_if(Studentai.begin(), Studentai.end(), std::back_inserter(Vargsiukai),rusiavimas_vektoriai_vargsiukai());
	//std::copy_if(Studentai.begin(), Studentai.end(), std::back_inserter(Kietiakai), rusiavimas_vektoriai_kietiakai());




	fd.close();


	std::ofstream fr;
	fr.open("Rezultatai_Vektoriai.txt");

	fr.width(15); fr << std::left << "Pavarde";
	fr.width(15); fr << std::left << "Vardas";
	fr.width(15); fr << std::left << "ND-1";
	fr.width(15); fr << std::left << "ND-2";
	fr.width(15); fr << std::left << "ND-3";
	fr.width(15); fr << std::left << "ND-4";
	fr.width(15); fr << std::left << "ND-5";
	fr.width(15); fr << std::left << "Egzaminas";
	fr.width(20); fr << std::left << "Galutinis-vidurkis";
	fr.width(20); fr << std::left << "Galutinis-mediana";
	fr.width(20); fr << std::left << "Kategorija";
	fr << std::endl;

	for (int i = 1; i != Kietiakai.size(); i++)
	{
		//SPAUSDINIMAS KIETAKUS
		fr.width(15); fr << std::left << Kietiakai[i].Pavarde;
		fr.width(15); fr << std::left << Kietiakai[i].Vardas;
		for (int j = 0; j < 5; j++)
		{
			fr.width(15); fr << std::left << Kietiakai[i].pazymiai[j];
		}
		fr.width(15); fr << std::left << Kietiakai[i].egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << Kietiakai[i].galutinis_vidurkis;
		fr.width(20); fr << std::left << Kietiakai[i].galutinis_mediana;
		fr.width(20); fr << std::left << "Kietiakas";

		fr << std::endl;
	}
	for (int i = 1; i != Vargsiukai.size(); i++)
	{
		//SPAUSDINIMAS VARGSIUKUS
		fr.width(15); fr << std::left << Vargsiukai[i].Pavarde;
		fr.width(15); fr << std::left << Vargsiukai[i].Vardas;
		for (int j = 0; j < 5; j++)
		{
			fr.width(15); fr << std::left << Vargsiukai[i].pazymiai[j];
		}
		fr.width(15); fr << std::left << Vargsiukai[i].egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << Vargsiukai[i].galutinis_vidurkis;
		fr.width(20); fr << std::left << Vargsiukai[i].galutinis_mediana;
		fr.width(20); fr << std::left << "Vargsiukas";
		fr << std::endl;
	}
	fr.close();
}
void InputOutput_DEKAI_Pirma_Strategija_BE_ALGORITMU(std::string pav)
{
	std::deque<Duomenys_Dekai>Studentai;
	std::deque<Duomenys_Dekai>Kietiakai;
	std::deque<Duomenys_Dekai>Vargsiukai;
	std::ifstream fd;
	fd.open(pav);
	if (!fd)
	{
		std::cerr << std::endl;
		std::cerr << "Failas " << pav << " neegzistuoja." << std::endl;
		std::cerr << std::endl;
		main();
	}
	else
	{
		while (!fd.eof())
		{
			std::string Vardas;
			std::string Pavarde;
			std::deque<double>pazymiai;
			double egzaminas;
			fd >> Vardas;
			fd >> Pavarde;
			for (int i = 0; i < 5; i++)
			{
				double x;
				fd >> x;
				pazymiai.push_back(x);
			}
			fd >> egzaminas;

			// SKAICIAVIMAI GAL_VID, GAL_MED IR RUSIAVIMAS
			double Gal_vid = Galutinis_Vidurkis(pazymiai, egzaminas);
			double Gal_med = Galutinis_Mediana(pazymiai, egzaminas);

			Duomenys_Dekai something = { Vardas,Pavarde,pazymiai,egzaminas,Gal_vid,Gal_med };
			Studentai.push_back(something);

			if (Gal_vid < 5)
			{
				Vargsiukai.push_back(something);
			}
			else if (Gal_vid >= 5)
			{
				Kietiakai.push_back(something);
			}

		}
	}
	// SORTAS PAGAL VARDUS
	std::sort(Studentai.begin(), Studentai.end(), Pagal_Varda_Dekai);

	//std::copy_if(Studentai.begin(), Studentai.end(), std::back_inserter(Vargsiukai), rusiavimas_dekai_vargsiukai());
	//std::copy_if(Studentai.begin(), Studentai.end(), std::back_inserter(Kietiakai), rusiavimas_dekai_kietiakai());

	fd.close();



	std::ofstream fr;
	fr.open("Rezultatai_Dekai.txt");

	fr.width(15); fr << std::left << "Pavarde";
	fr.width(15); fr << std::left << "Vardas";
	fr.width(15); fr << std::left << "ND-1";
	fr.width(15); fr << std::left << "ND-2";
	fr.width(15); fr << std::left << "ND-3";
	fr.width(15); fr << std::left << "ND-4";
	fr.width(15); fr << std::left << "ND-5";
	fr.width(15); fr << std::left << "Egzaminas";
	fr.width(20); fr << std::left << "Galutinis-vidurkis";
	fr.width(20); fr << std::left << "Galutinis-mediana";
	fr.width(20); fr << std::left << "Kategorija";
	fr << std::endl;

	for (int i = 1; i != Kietiakai.size(); i++)
	{
		//SPAUSDINIMAS KIETAKUS
		fr.width(15); fr << std::left << Kietiakai[i].Pavarde;
		fr.width(15); fr << std::left << Kietiakai[i].Vardas;
		for (int j = 0; j < 5; j++)
		{
			fr.width(15); fr << std::left << Kietiakai[i].pazymiai[j];
		}
		fr.width(15); fr << std::left << Kietiakai[i].egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << Kietiakai[i].galutinis_vidurkis;
		fr.width(20); fr << std::left << Kietiakai[i].galutinis_mediana;
		fr.width(20); fr << std::left << "Kietiakas";

		fr << std::endl;
	}
	for (int i = 1; i != Vargsiukai.size(); i++)
	{
		//SPAUSDINIMAS VARGSIUKUS
		fr.width(15); fr << std::left << Vargsiukai[i].Pavarde;
		fr.width(15); fr << std::left << Vargsiukai[i].Vardas;
		for (int j = 0; j < 5; j++)
		{
			fr.width(15); fr << std::left << Vargsiukai[i].pazymiai[j];
		}
		fr.width(15); fr << std::left << Vargsiukai[i].egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << Vargsiukai[i].galutinis_vidurkis;
		fr.width(20); fr << std::left << Vargsiukai[i].galutinis_mediana;
		fr.width(20); fr << std::left << "Vargsiukas";
		fr << std::endl;
	}
	fr.close();
}
void InputOutput_LISTAI_Pirma_Strategija_BE_ALGORITMU(std::string pav)
{
	std::list<Duomenys_Listai>Studentai;
	std::list<Duomenys_Listai>Kietiakai;
	std::list<Duomenys_Listai>Vargsiukai;

	std::ifstream fd;
	fd.open(pav);
	if (!fd)
	{
		std::cerr << std::endl;
		std::cerr << "Failas " << pav << " neegzistuoja." << std::endl;
		std::cerr << std::endl;
		main();
	}
	else
	{
		while (!fd.eof())
		{
			std::string Vardas;
			std::string Pavarde;
			std::list<double>pazymiai;
			double egzaminas;
			fd >> Vardas;
			fd >> Pavarde;
			for (int i = 0; i < 5; i++)
			{
				double x;
				fd >> x;
				pazymiai.push_back(x);
			}
			fd >> egzaminas;
			double Gal_vid = Galutinis_Vidurkis(pazymiai, egzaminas);
			double Gal_med = Galutinis_Mediana(pazymiai, egzaminas);

			Duomenys_Listai something = { Vardas,Pavarde,pazymiai,egzaminas,Gal_vid,Gal_med };
			Studentai.push_back(something);

			if (Gal_vid < 5)
			{
				Vargsiukai.push_back(something);
			}
			else if (Gal_vid >= 5)
			{
				Kietiakai.push_back(something);
			}

		}
	}



	Studentai.sort(Pagal_Varda_Listai); // SORTAS PAGAL VARDUS

										//std::copy_if(Studentai.begin(), Studentai.end(), std::back_inserter(Vargsiukai), rusiavimas_listai_vargsiukai());
										//std::copy_if(Studentai.begin(), Studentai.end(), std::back_inserter(Kietiakai), rusiavimas_listai_kietiakai());


	fd.close();

	std::ofstream fr;
	fr.open("Rezultatai_Listai.txt");

	fr.width(15); fr << std::left << "Pavarde";
	fr.width(15); fr << std::left << "Vardas";
	fr.width(15); fr << std::left << "ND-1";
	fr.width(15); fr << std::left << "ND-2";
	fr.width(15); fr << std::left << "ND-3";
	fr.width(15); fr << std::left << "ND-4";
	fr.width(15); fr << std::left << "ND-5";
	fr.width(15); fr << std::left << "Egzaminas";
	fr.width(20); fr << std::left << "Galutinis-vidurkis";
	fr.width(20); fr << std::left << "Galutinis-mediana";
	fr.width(20); fr << std::left << "Kategorija";
	fr << std::endl;

	for (auto i : Kietiakai)
	{
		//SPAUSDINIMAS

		fr.width(15); fr << std::left << i.Pavarde;
		fr.width(15); fr << std::left << i.Vardas;
		for (auto j : i.pazymiai)
		{
			fr.width(15); fr << std::left << j;
		}
		fr.width(15); fr << std::left << i.egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << i.galutinis_vidurkis;
		fr.width(20); fr << std::left << i.galutinis_mediana;
		fr.width(20); fr << std::left << "Kietiakas";
		fr << std::endl;
	}
	for (auto i : Vargsiukai)
	{
		//SPAUSDINIMAS

		fr.width(15); fr << std::left << i.Pavarde;
		fr.width(15); fr << std::left << i.Vardas;
		for (auto j : i.pazymiai)
		{
			fr.width(15); fr << std::left << j;
		}
		fr.width(15); fr << std::left << i.egzaminas;
		fr.width(20); fr << std::left << std::setprecision(3) << i.galutinis_vidurkis;
		fr.width(20); fr << std::left << i.galutinis_mediana;
		fr.width(20); fr << std::left << "Vargsiukas";
		fr << std::endl;
	}
	fr.close();
}