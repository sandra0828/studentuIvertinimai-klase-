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

bool arSkaicius(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
        {
            return false;
        }
    return true;
}

void pazymiuIvedimas(Asmuo &stud)
{
    string egzaminas;

    cout << "Iveskite egzamino ivertinima 0-10: " << endl;
    cin >> egzaminas;

    int skaicius = arSkaicius(egzaminas);

    if (skaicius == true)
    {
        int egz = std::stoi(egzaminas);

        if (egz >= 0 && egz <= 10)
        {
            stud.egzaminas = egz;
        }
        else
        {
            cout << "Ivestas netinkamas pazymys, egzaminui priskiriamas 0" << endl;
            stud.egzaminas = 0;
        }
    }
    else
    {
        cout << "Neivestas pazymys, egzaminui priskiriamas 0" << endl;
        stud.egzaminas = 0;
    }
    

    bool arIvestas = true; // ar ivestas dar vienas pazymys 
    string pazymys;
    bool arNulis = true;

    while (arIvestas == true)
    {
        cout << "Iveskite pazymi arba, jei ivesti visi pazymiai, iveskite -1: (ivedus spauskite enter)" << endl;
        cin >> pazymys;

        int skaicius = arSkaicius(pazymys);

        if ((skaicius == true) || (pazymys == "-1"))
        {
            int paz = std::stoi(pazymys);
            if (paz >= 0 && paz <= 10)
            {
                stud.pazymiai.push_back(paz);
                arNulis = false;
            }
            else if (paz == -1 && arNulis == true)
            {
                cout << "Neivestas nei vienas pazymys" << endl;
                continue;
            }
            else if (paz == -1)
            {
                arIvestas = false; // ivestas jau ne pazymys, o ivedimo stabdymo zenklas
            }
            else
            {
                cout << "Pazymys gali buti 0-10" << endl;
                continue;
            }
        }
        else
        {
            cout << "Klaida, ivestas simbolis" << endl;
            continue;
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

    if (kiek < 1) kiek = 1;

    cout << "Semestro pazymiai: ";
    for (int i = 0; i < kiek; i++)
    {
        int random = rand() % 10 + 1;
        cout << random << " ";
        stud.pazymiai.push_back(random);
    }
    cout << endl;  
}

float galutinisPazymys(Asmuo stud, string skaiciavimoBudas)
{
    float semestroRez;

    if (skaiciavimoBudas == "a") // naudojamas vidurkis
    {
        semestroRez = vidurkis(stud.pazymiai);
    }
    else if (skaiciavimoBudas == "b") // naudojama mediana
    {
        semestroRez = mediana(stud.pazymiai);
    }
    else
    {
        cout << "Nepasirinktas skaiciavimo budas, naudojamas vidurkis " << endl;
        semestroRez = vidurkis(stud.pazymiai);
    }

    stud.galutinis = semestroRez * 0.4 + stud.egzaminas * 0.6;

    return stud.galutinis;
}

void duomenuIvedimas(vector <Asmuo>& stud)
{
    int studentuSk;
    cout << "Kiek bus studentu? " << endl;
    cin >> studentuSk;

    for (int i = 0; i < studentuSk; i++)
    {
        Asmuo studentoDuomenys; // laikinas kintamasis vieno studento duomenims saugoti
        cout << "Iveskite studento varda, pavarde: " << endl;
        cin >> studentoDuomenys.vardas >> studentoDuomenys.pavarde;

        string kokiePazymiai; // ar bus ivedami ranka, ar generuojami atsitiktinai
        cout << "Jei norite ivesti studento pazymius -  iveskite 'a', jei generuoti atsitiktinai - iveskite 'b'" << endl;
        cin >> kokiePazymiai;

        if (kokiePazymiai == "a")
        {
            pazymiuIvedimas(studentoDuomenys);
        }
        else if (kokiePazymiai == "b")
        {
            atsitiktiniaiPazymiai(studentoDuomenys);
        }
        else
        {
            cout << "Nepasirinktas ivedimo budas, parenkamas pazymiu ivedimas" << endl;
            pazymiuIvedimas(studentoDuomenys);
        }

        stud.push_back(studentoDuomenys);
    }
}

int main()
{
    srand(time(0));

    vector <Asmuo> studentai;

    duomenuIvedimas(studentai);

    if (studentai.size() > 0)
    {
        string skaiciavimoBudas;
        cout << "Pasirinkite, kaip skaiciuoti galutini bala: 'a' - naudojant vidurki; 'b' - naudojant mediana" << endl;
        cin >> skaiciavimoBudas;

        for (int i = 0; i < studentai.size(); i++)
        {
            studentai.at(i).galutinis = galutinisPazymys(studentai.at(i), skaiciavimoBudas);
        }

        // duomenu isvedimas
        cout << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) / Galutinis(Med.) " << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        for (int i = 0; i < studentai.size(); i++)
        {
            cout << left << setw(15) << studentai.at(i).vardas << " | " << setw(20) << studentai.at(i).pavarde << " | " << fixed << setprecision(2) << studentai.at(i).galutinis << endl;
        }
    }
    else
    {
        cout << "Nera duomenu" << endl;
    }

    return 0;
}

