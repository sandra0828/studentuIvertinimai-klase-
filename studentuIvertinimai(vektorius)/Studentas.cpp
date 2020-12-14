#include "Studentas.h"


Studentas::Studentas(std::istream& is, int kiekZodziu)
{
    nuskaityti(is, kiekZodziu);
}

Studentas::Studentas(string vardas_n, string pavarde_n, std::vector<int> pazymiai_n, int egzaminas_n) : Asmuo(vardas_n, pavarde_n)
{
    pazymiai = pazymiai_n;
    egzaminas = egzaminas_n;
}

Studentas& Studentas:: operator=(const Studentas& a) // priskyrimo operatorius
{
    if (&a == this) return *this;

    vardas = a.vardas;
    pavarde = a.pavarde;
    pazymiai = a.pazymiai;
    egzaminas = a.egzaminas;
    galutinis = a.galutinis;
    return *this;
}

int &Studentas:: operator[](int i) // grazina studento i-taji namu darbu pazymi
{
    if (i < 0 || i >= pazymiai.size())
    {
        throw std::out_of_range{ "Tokio pazymio nera" };
    }
    return pazymiai.at(i);
}

void Studentas::nuskaityti(std::istream& is, int kiekZodziu)
{
    is >> vardas >> ws >> pavarde >> ws;

    string pazymys;
    for (int i = 0; i < kiekZodziu - 3; i++)
    {
        is >> pazymys >> ws;
        int paz;
        if (arSkaicius(pazymys) == true)
        {
            paz = std::stoi(pazymys);
        }
        else
        {
            paz = 0;
        }
        pazymiai.push_back(paz);
    }

    string egzaminasl;
    is >> egzaminasl >> ws;

    int egz;

    if (arSkaicius(egzaminasl) == true)
    {
        egz = std::stoi(egzaminasl);
    }
    else
    {
        egz = 0;
    }

    egzaminas = egz;
}

double Studentas:: galutinisBalas(float (*funkcija) (vector <int>))
{
    galutinis = funkcija(pazymiai);
    galutinis = galutinis * 0.4 + egzaminas * 0.6;
    return galutinis;
}

bool palyginimasPagalVarda(const Studentas& a, const Studentas& b)
{
    if (a.gautiVarda() != b.gautiVarda())
    {
        return a.gautiVarda() < b.gautiVarda();
    }
    if (a.gautiVarda() == b.gautiVarda())
    {
        return a.gautiPavarde() < b.gautiPavarde();
    }
}

bool palyginimasPagalPazymi(const Studentas& a, const Studentas& b)
{
    return a.gautiGalutini() < b.gautiGalutini();
}

bool arDaugiau_5(const Studentas& a)
{
    return a.gautiGalutini() >= 5;
}