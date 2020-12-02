#include "Asmuo.h"


Asmuo::Asmuo(std::istream& is, int kiekZodziu)
{
    nuskaityti(is, kiekZodziu);
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