// studentuIvertinimai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Asmuo.h"
#include "duomenuNuskaitymas.h"
#include "duomenuIvedimas.h"
#include "galutinisPazymys.h"
#include "duomenuIsvedimas.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;


int main()
{
    srand(time(0));

    vector <Asmuo> studentai;

    int kokieDuomenys;
    cout << "Jei norite ivesti duomenis, spauskite 1; jei norite nuskaityti duomenis, spauskite 2" << endl;
    cin >> kokieDuomenys;

    if (kokieDuomenys == 1)
    {
        duomenuIvedimas(studentai);
    }
    else if (kokieDuomenys == 2)
    {
        duomenuNuskaitymas(studentai);
    }
    else
    {
        cout << "Nepasirinktas duomenu nuskaitymo budas" << endl;
        return -1;
    }

    if (studentai.size() > 0)
    {
        galutinisPazymys(studentai);
        duomenuIsvedimas(studentai);
    }
    else
    {
        cout << "Nera duomenu" << endl;
    }

    return 0;
}

