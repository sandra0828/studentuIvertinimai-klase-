// studentuIvertinimai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Antrastes.h";


int main()
{
    srand(time(0));


    vector <Studentas> studentai;
    vector <Studentas> galvociai;
    vector <Studentas> vargsiukai;

    string failoPavadinimas;
    cout << "Iveskite duomenu failo pavadinima: " << endl;
    cin >> failoPavadinimas;

    string failoDydis;
    cout << "Iveskite failo dydi (kiek eiluciu sudaro faila):" << endl;
    cin >> failoDydis;

    duomenuNuskaitymas(studentai, failoPavadinimas + ".txt");
    
    if (studentai.size() > 0)
    {
        string skaiciavimoBudas;
        cout << "Pasirinkite, kaip skaiciuoti galutini bala: 'a' - naudojant vidurki; 'b' - naudojant mediana" << endl;
        cin >> skaiciavimoBudas;

        string sarasoDalinimoStrategija;
        cout << "Pasirinkite saraso dalinimo strategija: 1, 2, 3" << endl;
        cin >> sarasoDalinimoStrategija;

        studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas, sarasoDalinimoStrategija);
        naujiSarasai(galvociai, vargsiukai, failoDydis);
    }
    return 0;
}

