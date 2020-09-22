// studentuIvertinimai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::vector;


struct Asmuo {
    string vardas, pavarde;
    int egzaminas;
    float galutinis = 0;
    vector<int> pazymiai;
};

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

int main()
{
    Asmuo studentas;

    cout << "Iveskite studento varda, pavarde, egzamino ivertinima: " << endl;
    cin >> studentas.vardas >> studentas.pavarde >> studentas.egzaminas;

    bool arIvestas = true; // ar ivestas dar vienas pazymys 
    int pazymys;

    while (arIvestas == true)
    {
        cout << "Iveskite pazymi arba, jei ivesti visi pazymiai, iveskite -1: " << endl;
        cin >> pazymys;

        if (pazymys == -1)
        {
            arIvestas = false; // ivestas jau ne pazymys, o ivedimo stabdymo zenklas
        }
        else
        {
            studentas.pazymiai.push_back(pazymys);
        }
    }

    int skaiciavimoBudas;
    cout << "Pasirinkite, kaip skaiciuoti galutini bala: 1 - naudojant vidurki; 2 - naudojant mediana" << endl;
    cin >> skaiciavimoBudas;

    if (skaiciavimoBudas == 1) // naudojamas vidurkis
    {
        float semestroRez = vidurkis(studentas.pazymiai);
        studentas.galutinis = semestroRez * 0.4 + studentas.egzaminas * 0.6;

        cout << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << left << setw(15) << studentas.vardas << " | " << setw(20) << studentas.pavarde << " | " << fixed << setprecision(2) << studentas.galutinis;
    }
    else if (skaiciavimoBudas == 2) // naudojama mediana
    {
        float semestroRez = mediana(studentas.pazymiai);
        studentas.galutinis = semestroRez * 0.4 + studentas.egzaminas * 0.6;

        cout << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Med.) " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << left << setw(15) << studentas.vardas << " | " << setw(20) << studentas.pavarde << " | " << fixed << setprecision(2) << studentas.galutinis;
    }
    else
    {
        return -1;
    }

    return 0;
}

