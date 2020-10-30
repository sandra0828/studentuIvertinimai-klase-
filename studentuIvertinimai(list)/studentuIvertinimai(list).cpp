// studentuIvertinimai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Asmuo.h"
#include "duomenuNuskaitymas.h"
#include "duomenuIvedimas.h"
#include "galutinisPazymys.h"
#include "duomenuIsvedimas.h"
#include "duomenuPasirinkimas.h"
#include "failoSukurimas.h"
#include "studentuSarasoDalinimas.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::list;


int main()
{
    srand(time(0));

    list <Asmuo> studentai;
    list <Asmuo> galvociai;
    list <Asmuo> vargsiukai;

    string skaiciavimoBudas;
    cout << "Pasirinkite, kaip skaiciuoti galutini bala: 'a' - naudojant vidurki; 'b' - naudojant mediana" << endl;
    cin >> skaiciavimoBudas;

    cout << "Failas su 1000 irasu: \n";
    naujasFailas(1000, 5);
    duomenuNuskaitymas(studentai, "kursiokai1000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas);
    naujiSarasai(galvociai, vargsiukai, "1000");
    cout << endl;

    cout << "Failas su 10000 irasu: \n";
    naujasFailas(10000, 5);
    duomenuNuskaitymas(studentai, "kursiokai10000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas);
    naujiSarasai(galvociai, vargsiukai, "10000");
    cout << endl;

    cout << "Failas su 1000000 irasu: \n";
    naujasFailas(100000, 5);
    duomenuNuskaitymas(studentai, "kursiokai100000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas);
    naujiSarasai(galvociai, vargsiukai, "100000");
    cout << endl;

    cout << "Failas su 10000000 irasu: \n";
    naujasFailas(1000000, 5);
    duomenuNuskaitymas(studentai, "kursiokai1000000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas);
    naujiSarasai(galvociai, vargsiukai, "1000000");
    cout << endl;

    cout << "Failas su 100000000 irasu: \n";
    naujasFailas(10000000, 5);
    duomenuNuskaitymas(studentai, "kursiokai10000000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai, skaiciavimoBudas);
    naujiSarasai(galvociai, vargsiukai, "10000000");
    cout << endl;

    return 0;
}
