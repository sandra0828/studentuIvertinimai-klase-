#include "duomenuIsvedimas.h"

void duomenuIsvedimas(vector <Asmuo> studentai)
{
    sort(studentai.begin(), studentai.end(), palyginimas);

    cout << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) / Galutinis(Med.) " << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < studentai.size(); i++)
    {
        cout << left << setw(15) << studentai.at(i).vardas << " | " << setw(20) << studentai.at(i).pavarde << " | " << fixed << setprecision(2) << studentai.at(i).galutinis << endl;
    }
}