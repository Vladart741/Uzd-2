#include <vector>
#include <list>
#include <algorithm>
#include <deque>

// VEKTORIAI
double Galutinis_Mediana(std::vector<double>pazymiai, double egzaminas)
{
	double galutinis_mediana;
	if (pazymiai.size() % 2 == 0)
	{
		pazymiai.push_back(egzaminas);
		std::sort(pazymiai.begin(), pazymiai.end());
		galutinis_mediana = pazymiai[pazymiai.size() / 2];
	}
	else
	{
		pazymiai.push_back(egzaminas);
		std::sort(pazymiai.begin(), pazymiai.end());
		galutinis_mediana = ((pazymiai[(pazymiai.size() / 2) - 1] + pazymiai[(pazymiai.size() + 1) / 2]) / 2);
	}
	return galutinis_mediana;
}
// LIST
double Galutinis_Mediana(std::list<double>pazymiai, double egzaminas)
{
	double galutinis_mediana;
	if (pazymiai.size() % 2 == 0)
	{
		pazymiai.push_back(egzaminas);
		pazymiai.sort();

		std::list<double>::iterator it = pazymiai.begin();
		double x = pazymiai.size() / 2;
		std::advance(it, x);
		galutinis_mediana = *it;
	}
	else
	{
		pazymiai.push_back(egzaminas);
		pazymiai.sort();

		std::list<double>::iterator it1 = pazymiai.begin();
		std::list<double>::iterator it2 = pazymiai.begin();
		double x = (pazymiai.size() / 2) - 1;
		double y = (pazymiai.size() / 2) + 1;

		std::advance(it1, x);
		std::advance(it2, y);

		double tarpinis1 = *it1;
		double tarpinis2 = *it2;
		galutinis_mediana = (tarpinis1 + tarpinis2) / 2;
	}
	return galutinis_mediana;
}
// DEKAI
double Galutinis_Mediana(std::deque<double>pazymiai, double egzaminas)
{
	double galutinis_mediana;
	if (pazymiai.size() % 2 == 0)
	{
		pazymiai.push_back(egzaminas);
		std::sort(pazymiai.begin(), pazymiai.end());
		galutinis_mediana = pazymiai[pazymiai.size() / 2];
	}
	else
	{
		pazymiai.push_back(egzaminas);
		std::sort(pazymiai.begin(), pazymiai.end());
		galutinis_mediana = ((pazymiai[(pazymiai.size() / 2) - 1] + pazymiai[(pazymiai.size() + 1) / 2]) / 2);
	}
	return galutinis_mediana;
}