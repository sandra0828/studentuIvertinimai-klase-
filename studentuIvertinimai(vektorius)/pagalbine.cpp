#include "pagalbine.h"

bool arSkaicius(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
        {
            return false;
        }
    return true;
}

/*void atsitiktiniaiPazymiai(Asmuo& stud)
{
    stud.egzaminas = rand() % 10 + 1;
    cout << "Egzamino pazymys: " << stud.egzaminas << endl;

    int kiek;
    cout << "Kiek sugeneruoti pazymiu? : " << endl;
    cin >> kiek;

    if (kiek < 1) kiek = 1;

    cout << "Semestro pazymiai: ";
    for (int i = 0; i < kiek; i++)
    {
        int random = rand() % 10 + 1;
        cout << random << " ";
        stud.pazymiai.push_back(random);
    }
    cout << endl;
}*/