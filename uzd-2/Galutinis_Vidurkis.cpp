#include <vector>


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
