// studentuIvertinimai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Antrastes.h";


int main()
{
    srand(time(0));

    vector <Asmuo> studentai;
    vector <Asmuo> galvociai;
    vector <Asmuo> vargsiukai;

    string skaiciavimoBudas;
    cout << "Pasirinkite, kaip skaiciuoti galutini bala: 'a' - naudojant vidurki; 'b' - naudojant mediana" << endl;
    cin >> skaiciavimoBudas;

    string sarasoDalinimoStrategija;
    cout << "Pasirinkite saraso dalinimo strategija: 1, 2, 3" << endl;
    cin >> sarasoDalinimoStrategija;


    cout << "Failas su 1000 irasu: \n";
    //naujasFailas(1000, 5);
    duomenuNuskaitymas(studentai, "kursiokai1000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas, sarasoDalinimoStrategija);
    naujiSarasai(galvociai, vargsiukai, "1000");
    cout << endl;

    cout << "Failas su 10000 irasu: \n";
    //naujasFailas(10000, 5);
    duomenuNuskaitymas(studentai, "kursiokai10000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas, sarasoDalinimoStrategija);
    naujiSarasai(galvociai, vargsiukai, "10000");
    cout << endl;

    cout << "Failas su 100000 irasu: \n";
    //naujasFailas(100000, 5);
    duomenuNuskaitymas(studentai, "kursiokai100000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas, sarasoDalinimoStrategija);
    naujiSarasai(galvociai, vargsiukai, "100000");
    cout << endl;

    cout << "Failas su 1000000 irasu: \n";
    //naujasFailas(1000000, 5);
    duomenuNuskaitymas(studentai, "kursiokai1000000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas, sarasoDalinimoStrategija);
    naujiSarasai(galvociai, vargsiukai, "1000000");
    cout << endl;

    return 0;
}

