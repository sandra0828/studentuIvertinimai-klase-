// studentuIvertinimai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;

struct Asmuo {
    string vardas, pavarde;
    int pazymiai[10], egzaminas;
    float galutinis = 0;
};

float vidurkis(int pazymiai[])
{
    float suma = 0;
    for (int i = 0; i < 5; i++)
    {
        suma += pazymiai[i];
    }

    return suma / 5;
}

float mediana(int pazymiai[])
{
    // pazymiu masyvo surusiavimas
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++)
        {
            if (pazymiai[i] < pazymiai[j])
            {
                int temp = pazymiai[i];
                pazymiai[i] = pazymiai[j];
                pazymiai[j] = temp;
            }
        }
    }

    return pazymiai[2]; // vidurinis narys is surusiuoto masyvo
}

int main()
{
    Asmuo studentas;

    cout << "Iveskite studento varda, pavarde, egzamino ivertinima ir 5 semestro pazymius: " << endl;
    cin >> studentas.vardas >> studentas.pavarde >> studentas.egzaminas;
    for (int i = 0; i < 5; i++) {
        cin >> studentas.pazymiai[i];
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

