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

int main()
{
    Asmuo studentas;

    cout << "Iveskite studento varda, pavarde, egzamino ivertinima ir 5 semestro pazymius: " << endl;
    cin >> studentas.vardas >> studentas.pavarde >> studentas.egzaminas;
    float suma = 0; // laikinas kintamasis vidurkio apskaiciavimui
    for (int i = 0; i < 5; i++) {
        cin >> studentas.pazymiai[i];
        suma += studentas.pazymiai[i];
    }

    studentas.galutinis = (suma / 5) * 0.4 + studentas.egzaminas * 0.6;

    cout << left << setw(15)  << "Vardas"  << " | " << setw(20) << "Pavarde"  <<  " | " <<  "Galutinis (Vid.) " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << left << setw(15)  << studentas.vardas  << " | " << setw(20) << studentas.pavarde  << " | " << fixed << setprecision(2) << studentas.galutinis;
}

