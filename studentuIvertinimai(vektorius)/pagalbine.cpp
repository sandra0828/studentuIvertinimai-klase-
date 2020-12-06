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

void atsitiktiniaiPazymiai(vector <int>& paz, int& egz)
{
    egz = rand() % 10 + 1;
    cout << "Egzamino pazymys: " << egz << endl;

    int kiek;
    cout << "Kiek sugeneruoti pazymiu? : " << endl;
    cin >> kiek;

    if (kiek < 1) kiek = 1;

    cout << "Semestro pazymiai: ";
    for (int i = 0; i < kiek; i++)
    {
        int random = rand() % 10 + 1;
        cout << random << " ";
        paz.push_back(random);
    }
    cout << endl;
}