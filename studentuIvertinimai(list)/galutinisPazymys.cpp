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


void galutinisPazymys(list <Asmuo> &studentai, string skaiciavimoBudas)
{

    if (skaiciavimoBudas != "a" && skaiciavimoBudas != "b")
    {
        cout << "Nepasirinktas skaiciavimo budas, naudojamas vidurkis " << endl;
    }

    for (Asmuo &asmuo : studentai)
    {
        
        if (skaiciavimoBudas == "a") // naudojamas vidurkis
        {
            asmuo.galutinis = vidurkis(asmuo.pazymiai);
        }
        else if (skaiciavimoBudas == "b") // naudojama mediana
        {
            asmuo.galutinis = mediana(asmuo.pazymiai);
        }
        else
        {
            asmuo.galutinis = vidurkis(asmuo.pazymiai);
        }
        
        asmuo.galutinis = asmuo.galutinis * 0.4 + asmuo.egzaminas * 0.6;
    }

    /*for (int i = 0; i < studentai.size(); i++)
    {
        if (skaiciavimoBudas == "a") // naudojamas vidurkis
        {
            studentai.at(i).galutinis = vidurkis(studentai.at(i).pazymiai);
        }
        else if (skaiciavimoBudas == "b") // naudojama mediana
        {
            studentai.at(i).galutinis = mediana(studentai.at(i).pazymiai);
        }
        else
        {
            studentai.at(i).galutinis = vidurkis(studentai.at(i).pazymiai);
        }

        studentai.at(i).galutinis = studentai.at(i).galutinis * 0.4 + studentai.at(i).egzaminas * 0.6;
    }*/

}