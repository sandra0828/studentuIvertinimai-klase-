#include "duomenuIvedimas.h"

void pazymiuIvedimas(Asmuo& stud)
{
    string egzaminas;

    cout << "Iveskite egzamino ivertinima 0-10: " << endl;
    cin >> egzaminas;

    int skaicius = arSkaicius(egzaminas);

    if (skaicius == true)
    {
        int egz = std::stoi(egzaminas);

        if (egz >= 0 && egz <= 10)
        {
            stud.egzaminas = egz;
        }
        else
        {
            cout << "Ivestas netinkamas pazymys, egzaminui priskiriamas 0" << endl;
            stud.egzaminas = 0;
        }
    }
    else
    {
        cout << "Neivestas pazymys, egzaminui priskiriamas 0" << endl;
        stud.egzaminas = 0;
    }


    bool arIvestas = true; // ar ivestas dar vienas pazymys 
    string pazymys;
    bool arNulis = true;

    while (arIvestas == true)
    {
        cout << "Iveskite pazymi arba, jei ivesti visi pazymiai, iveskite -1: (ivedus spauskite enter)" << endl;
        cin >> pazymys;

        int skaicius = arSkaicius(pazymys);

        if ((skaicius == true) || (pazymys == "-1"))
        {
            int paz = std::stoi(pazymys);
            if (paz >= 0 && paz <= 10)
            {
                stud.pazymiai.push_back(paz);
                arNulis = false;
            }
            else if (paz == -1 && arNulis == true)
            {
                cout << "Neivestas nei vienas pazymys" << endl;
                continue;
            }
            else if (paz == -1)
            {
                arIvestas = false; // ivestas jau ne pazymys, o ivedimo stabdymo zenklas
            }
            else
            {
                cout << "Pazymys gali buti 0-10" << endl;
                continue;
            }
        }
        else
        {
            cout << "Klaida, ivestas simbolis" << endl;
            continue;
        }
    }
}

void duomenuIvedimas(vector <Asmuo>& stud)
{
    int studentuSk;
    cout << "Kiek bus studentu? " << endl;
    cin >> studentuSk;

    for (int i = 0; i < studentuSk; i++)
    {
        Asmuo studentoDuomenys; // laikinas kintamasis vieno studento duomenims saugoti
        cout << "Iveskite studento varda, pavarde: " << endl;
        cin >> studentoDuomenys.vardas >> studentoDuomenys.pavarde;

        string kokiePazymiai; // ar bus ivedami ranka, ar generuojami atsitiktinai
        cout << "Jei norite ivesti studento pazymius -  iveskite 'a', jei generuoti atsitiktinai - iveskite 'b'" << endl;
        cin >> kokiePazymiai;

        if (kokiePazymiai == "a")
        {
            pazymiuIvedimas(studentoDuomenys);
        }
        else if (kokiePazymiai == "b")
        {
            atsitiktiniaiPazymiai(studentoDuomenys);
        }
        else
        {
            cout << "Nepasirinktas ivedimo budas, parenkamas pazymiu ivedimas" << endl;
            pazymiuIvedimas(studentoDuomenys);
        }

        stud.push_back(studentoDuomenys);
    }
}