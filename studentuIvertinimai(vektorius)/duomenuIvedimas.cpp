#include "duomenuIvedimas.h"

void pazymiuIvedimas(vector <int>& paz, int& egz)
{
    string egzaminas;

    cout << "Iveskite egzamino ivertinima 0-10: " << endl;
    cin >> egzaminas;

    pazymioTikrinimas(egzaminas);
    egz = std::stoi(egzaminas);

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
            paz.push_back(std::stoi(pazymys));
        }
    }
}

void duomenuIvedimas(vector <Studentas>& stud)
{
    int studentuSk;
    cout << "Kiek bus studentu? " << endl;
    cin >> studentuSk;

    string vardas, pavarde;
    vector <int> pazymiai;
    int egzaminas;

    for (int i = 0; i < studentuSk; i++)
    {
        cout << "Iveskite studento varda, pavarde: " << endl;
        cin >> vardas >> pavarde;

        string kokiePazymiai; // ar bus ivedami ranka, ar generuojami atsitiktinai
        cout << "Jei norite ivesti studento pazymius -  iveskite 'a', jei generuoti atsitiktinai - iveskite 'b'" << endl;
        cin >> kokiePazymiai;

        if (kokiePazymiai == "a")
        {
            pazymiuIvedimas(pazymiai, egzaminas);
        }
        else if (kokiePazymiai == "b")
        {
            atsitiktiniaiPazymiai(pazymiai, egzaminas);
        }
        else
        {
            cout << "Nepasirinktas ivedimo budas, parenkamas pazymiu ivedimas" << endl;
            pazymiuIvedimas(pazymiai, egzaminas);
        }

        Studentas asmuo(vardas, pavarde, pazymiai, egzaminas);
        stud.push_back(asmuo);
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