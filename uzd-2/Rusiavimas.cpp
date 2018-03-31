
bool Rusiavimas(double vidurkis)
{
	bool rusiavimas;
	if (vidurkis<5)
	{
		rusiavimas = false;
	}
	else if (vidurkis >= 5)
	{
		rusiavimas = true;
	}
	return rusiavimas;
}