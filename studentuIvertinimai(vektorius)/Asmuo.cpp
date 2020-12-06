#include "Asmuo.h"


Asmuo::Asmuo(std::istream& is, int kiekZodziu)
{
    nuskaityti(is, kiekZodziu);
}

Asmuo::Asmuo(string vardas_n, string pavarde_n, std::vector<int> pazymiai_n, int egzaminas_n)
{
    vardas = vardas_n;
    pavarde = pavarde_n;
    pazymiai = pazymiai_n;
    egzaminas = egzaminas_n;
}

Asmuo& Asmuo:: operator=(const Asmuo& a) // priskyrimo operatorius
{
    if (&a == this) return *this;

    vardas = a.vardas;
    pavarde = a.pavarde;
    pazymiai = a.pazymiai;
    egzaminas = a.egzaminas;
    galutinis = a.galutinis;
    return *this;
}

void Asmuo::nuskaityti(std::istream& is, int kiekZodziu)
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

double Asmuo:: galutinisBalas(float (*funkcija) (vector <int>))
{
    galutinis = funkcija(pazymiai);
    galutinis = galutinis * 0.4 + egzaminas * 0.6;
    return galutinis;
}

bool palyginimasPagalVarda(const Asmuo& a, const Asmuo& b)
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

bool palyginimasPagalPazymi(const Asmuo& a, const Asmuo& b)
{
    return a.gautiGalutini() < b.gautiGalutini();
}

bool arDaugiau_5(const Asmuo& a)
{
    return a.gautiGalutini() >= 5;
}