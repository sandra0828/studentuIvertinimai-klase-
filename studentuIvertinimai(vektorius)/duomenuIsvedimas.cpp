#include "duomenuIsvedimas.h"

void duomenuIsvedimas(vector <Asmuo> studentai)
{
    sort(studentai.begin(), studentai.end(), palyginimasPagalVarda);

    cout << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) / Galutinis(Med.) " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < studentai.size(); i++)
    {
        cout << left << setw(15) << studentai.at(i).gautiVarda() << " | " << setw(20) << studentai.at(i).gautiPavarde() << " | " << fixed << setprecision(2) << studentai.at(i).gautiGalutini() << endl;
    }
}