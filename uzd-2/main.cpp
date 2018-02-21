#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>

int main()
{
    std::cout << "Iveskite varda, pavarde, egz paz" << std::endl;
    std::string vardas;
    std::string pavarde;
    int n;
    int egzamino_balas;
    std::cin>>vardas>>pavarde>>n>>egzamino_balas;
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
    for(int i=0; i<n; i++)
    {
        int x = uniform_dist(nr);
        pazymiai.push_back(x);
        suma = suma + x;
    }
    galutinis = 0.4*(suma/n)+0.6*egzamino_balas;
    std::cout<<vardas<<" "<<pavarde<<std::endl;
    for(int i=0; i<n;i++)
    {
        std::cout<<pazymiai[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<std::setprecision(2)<<galutinis;

    return 0;
}
