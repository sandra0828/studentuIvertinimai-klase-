#include "duomenuIvedimas.h"

void pazymiuIvedimas(Asmuo& stud)
{
    string egzaminas;

    cout << "Iveskite egzamino ivertinima 0-10: " << endl;
    cin >> egzaminas;

    pazymioTikrinimas(egzaminas);
    int egz = std::stoi(egzaminas);
    stud.egzaminas = egz;


    bool arIvestas = true; // ar ivestas dar vienas pazymys 
    string pazymys;
    bool arNulis = true;

    while (arIvestas == true)
    {
        cout << "Iveskite semestro pazymi arba, jei ivesti visi pazymiai, iveskite -1: (ivedus spauskite enter)" << endl;
        cin >> pazymys;

        if (pazymys == "-1" && arNulis == true)
        {
            cout << "Neivestas nei vienas pazymys" << endl;
            continue;
        }
        else if (pazymys == "-1" && arNulis == false)
        {
            arIvestas = false;
        }
        else
        {
            arNulis = false;
            pazymioTikrinimas(pazymys);
            int paz = std::stoi(pazymys);
            stud.pazymiai.push_back(paz);
        }
    }
}

void duomenuIvedimas(std::list <Asmuo>& stud)
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

void pazymioTikrinimas(string &pazymys)
{
    bool tinkamas;
    do {
        tinkamas = true;
        try {
            if (arSkaicius(pazymys) == false)
            {
                tinkamas = false;
                throw std::runtime_error("Ivestas netinkamas simbolis \n");
            }
            if (arSkaicius(pazymys) == true)
            {
                int paz = std::stoi(pazymys);
                if (paz < 0 || paz > 10)
                {
                    tinkamas = false;
                    throw std::runtime_error("Ivestas netinkamas pazymys (turi buti 0-10) \n");
                }
            }
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskite pazymi is naujo" << endl;
            cin >> pazymys;

        }

    } while (tinkamas == false);
}