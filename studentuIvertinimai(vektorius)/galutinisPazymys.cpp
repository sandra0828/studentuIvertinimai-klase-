#include "galutinisPazymys.h"

float vidurkis(vector <int> pazymiai)
{
    float suma = 0;
    for (int i = 0; i < pazymiai.size(); i++)
    {
        suma += pazymiai[i];
    }

    return suma / pazymiai.size();
}

float mediana(vector <int> pazymiai)
{
    sort(pazymiai.begin(), pazymiai.end());

    int dydis = pazymiai.size();

    if (dydis % 2 == 0)
    {
        return (float)(pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2;
    }
    else
    {
        return (float)pazymiai[dydis / 2];
    }
}

void galutinisPazymys(vector <Asmuo> &studentai, string skaiciavimoBudas)
{
    if (skaiciavimoBudas != "a" && skaiciavimoBudas != "b")
    {
        cout << "Nepasirinktas skaiciavimo budas, naudojamas vidurkis " << endl;
    }
    if (skaiciavimoBudas == "b") // naudojama mediana
    {
        for (int i = 0; i < studentai.size(); i++)
        {
            studentai.at(i).galutinisBalas(mediana);
        }
    }
    else  // naudojamas vidurkis
    {
        for (int i = 0; i < studentai.size(); i++)
        {
            studentai.at(i).galutinisBalas(vidurkis);
        }
    } 



}