#include <vector>
#include <algorithm>


double Galutinis_Mediana(std::vector<int>pazymiai, int egzaminas)
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
