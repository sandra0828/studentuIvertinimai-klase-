#include "duomenuPasirinkimas.h"

void duomenuPasirinkimas(vector <Asmuo>& studentai)
{
    int kokieDuomenys;
    cout << "Jei norite ivesti duomenis, spauskite 1; jei norite nuskaityti duomenis, spauskite 2" << endl;
    cin >> kokieDuomenys;
    bool tinkamas;
    do {
        tinkamas = true;
        try {
            if (cin.fail())
            {
                tinkamas = false;
                throw std::runtime_error("Ivestas netinkamas simbolis \n");
            }
            if (kokieDuomenys != 1 && kokieDuomenys != 2)
            {
                tinkamas = false;
                throw std::runtime_error("Nepasirinktas variantas \n");
            }
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskite pasirinkima is naujo" << endl;
            cin >> kokieDuomenys;

        }
    } while (tinkamas == false || cin.fail() == true);



    if (kokieDuomenys == 1)
    {
        //duomenuIvedimas(studentai);
    }
    else
    {
        duomenuNuskaitymas(studentai, "kursiokai.txt");
    }
}