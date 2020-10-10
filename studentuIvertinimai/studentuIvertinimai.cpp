// studentuIvertinimai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Asmuo.h"
#include "duomenuNuskaitymas.h"
#include "duomenuIvedimas.h"
#include "galutinisPazymys.h"
#include "duomenuIsvedimas.h"
#include "duomenuPasirinkimas.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

int main()
{
    srand(time(0));

    vector <Asmuo> studentai;
    duomenuPasirinkimas(studentai);

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

