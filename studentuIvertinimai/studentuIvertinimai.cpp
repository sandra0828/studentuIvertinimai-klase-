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


int main()
{
    srand(time(0));

    vector <Asmuo> studentai;
    vector <Asmuo> galvociai;
    vector <Asmuo> vargsiukai;


    //naujasFailas(1000, 5);
    duomenuNuskaitymas(studentai, "kursiokai1000.txt");
    studentuRusiavimas(studentai, galvociai, vargsiukai);
    naujiSarasai(galvociai, vargsiukai, "1000");

    //naujasFailas(10000, 5);
    //duomenuNuskaitymas(studentai, "kursiokai10000.txt");

    //naujasFailas(100000, 5);
    //duomenuNuskaitymas(studentai, "kursiokai100000.txt");

    //naujasFailas(1000000, 5);
    //duomenuNuskaitymas(studentai, "kursiokai1000000.txt");

    //naujasFailas(10000000, 5);
    //duomenuNuskaitymas(studentai, "kursiokai10000000.txt");


    /*duomenuPasirinkimas(studentai);
    if (studentai.size() > 0)
    {
        string skaiciavimoBudas;
        cout << "Pasirinkite, kaip skaiciuoti galutini bala: 'a' - naudojant vidurki; 'b' - naudojant mediana" << endl;
        cin >> skaiciavimoBudas;

        galutinisPazymys(studentai, skaiciavimoBudas);
        duomenuIsvedimas(studentai);
    }
    else
    {
        cout << "Nera duomenu" << endl;
    } */
    
    return 0;
}

