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

void pazymiuIvedimas(Asmuo &stud)
{
    cout << "Iveskite egzamino ivertinima: " << endl;
    cin >> stud.egzaminas;

    bool arIvestas = true; // ar ivestas dar vienas pazymys 
    int pazymys;

    while (arIvestas == true)
    {
        cout << "Iveskite pazymi arba, jei ivesti visi pazymiai, iveskite -1: (ivedus spauskite enter)" << endl;
        cin >> pazymys;

        if (pazymys == -1)
        {
            arIvestas = false; // ivestas jau ne pazymys, o ivedimo stabdymo zenklas
        }
        else
        {
            stud.pazymiai.push_back(pazymys);
        }
    }
}

void atsitiktiniaiPazymiai(Asmuo &stud)
{
    stud.egzaminas = rand() % 10 + 1;
    cout << "Egzamino pazymys: " << stud.egzaminas << endl;

    int kiek;
    cout << "Kiek sugeneruoti pazymiu? : " << endl;
    cin >> kiek;

    cout << "Semestro pazymiai: ";
    for (int i = 0; i < kiek; i++)
    {
        int random = rand() % 10 + 1;
        cout << random << " ";
        stud.pazymiai.push_back(random);
    }
    cout << endl;
    
}

int main()
{
    srand(time(0));

    vector <Asmuo> studentas;
    int studentuSk;
    cout << "Kiek bus studentu? " << endl;
    cin >> studentuSk;

    
    for (int i = 0; i < studentuSk; i++)
    {
        Asmuo studentoDuomenys; // laikinas kintamasis vieno studento duomenims saugoti
        cout << "Iveskite studento varda, pavarde: " << endl;
        cin >> studentoDuomenys.vardas >> studentoDuomenys.pavarde;

        int kokiePazymiai; // ar bus ivedami ranka, ar generuojami atsitiktinai
        cout << "Jei norite ivesti studento pazymius -  iveskite 1, jei generuoti atsitiktinai - iveskite 2" << endl;
        cin >> kokiePazymiai;

        if (kokiePazymiai == 1)
        {
            pazymiuIvedimas(studentoDuomenys);
        }
        else if (kokiePazymiai == 2)
        {
            atsitiktiniaiPazymiai(studentoDuomenys);
        }
        else
        {
            return -1;
        }

        int skaiciavimoBudas;
        cout << "Pasirinkite, kaip skaiciuoti galutini bala: 1 - naudojant vidurki; 2 - naudojant mediana" << endl;
        cin >> skaiciavimoBudas;

        if (skaiciavimoBudas == 1) // naudojamas vidurkis
        {
            float semestroRez = vidurkis(studentoDuomenys.pazymiai);
            studentoDuomenys.galutinis = semestroRez * 0.4 + studentoDuomenys.egzaminas * 0.6;
        }
        else if (skaiciavimoBudas == 2) // naudojama mediana
        {
            float semestroRez = mediana(studentoDuomenys.pazymiai);
            studentoDuomenys.galutinis = semestroRez * 0.4 + studentoDuomenys.egzaminas * 0.6;
        }
        else
        {
            return -1;
        }

        studentas.push_back(studentoDuomenys);

    }

    // duomenu isvedimas
    cout << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) / Galutinis(Med.) " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < studentuSk; i++)
    {
        cout << left << setw(15) << studentas.at(i).vardas << " | " << setw(20) << studentas.at(i).pavarde << " | " << fixed << setprecision(2) << studentas.at(i).galutinis << endl;
    }

    return 0;
}

