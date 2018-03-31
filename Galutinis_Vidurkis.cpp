#include <vector>
#include <list>
#include <deque>

// VEKTORIAI
double Galutinis_Vidurkis(std::vector<int>pazymiai, int egzaminas)
{
	double nd_suma = 0;
	for (int i = 0; i != pazymiai.size(); i++)
	{
		nd_suma = nd_suma + pazymiai[i];
	}
	double galutinis_vidurkis;
	galutinis_vidurkis = (egzaminas*0.6) + ((nd_suma / pazymiai.size())*0.4);
	return galutinis_vidurkis;
}
// LISTAI
double Galutinis_Vidurkis(std::list<int>pazymiai, int egzaminas)
{
	double nd_suma = 0;
	for (auto i : pazymiai)
	{
		nd_suma = nd_suma + i;
	}
	double galutinis_vidurkis;
	galutinis_vidurkis = (egzaminas*0.6) + ((nd_suma / pazymiai.size())*0.4);
	return galutinis_vidurkis;
}
// DEKAI
double Galutinis_Vidurkis(std::deque<int>pazymiai, int egzaminas)
{
	double nd_suma = 0;
	for (int i = 0; i != pazymiai.size(); i++)
	{
		nd_suma = nd_suma + pazymiai[i];
	}
	double galutinis_vidurkis;
	galutinis_vidurkis = (egzaminas*0.6) + ((nd_suma / pazymiai.size())*0.4);
	return galutinis_vidurkis;
}

