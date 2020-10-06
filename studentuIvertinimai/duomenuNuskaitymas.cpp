#include "duomenuNuskaitymas.h"


bool arSkaicius(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
        {
            return false;
        }
    return true;
}

void duomenuNuskaitymas(vector <Asmuo>& stud)
{
    // is pradziu suskaiciuojama, kiek bus is viso kintamuju
    ifstream fd("kursiokai.txt");

    if (fd.fail()) {
        cout << "Failas nerastas" << endl;
    }
    else
    {
        string input;
        getline(fd, input);

        stringstream ss(input);
        string zodis;
        int kiekZodziu = 0;

        while (ss >> zodis) {
            ++kiekZodziu;
        }

        // nuskaitomi duomenys
        while (!fd.eof())
        {
            Asmuo studentoDuomenys;

            fd >> studentoDuomenys.vardas >> studentoDuomenys.pavarde;
            string pazymys;

            // pazymiu skaicius randamas is visu stulpeliu skaiciaus atimant vardo, pavardes ir egzamino stulpelius
            for (int i = 0; i < kiekZodziu - 3; i++)
            {
                fd >> pazymys;
                int paz;
                if (arSkaicius(pazymys) == true)
                {
                    paz = std::stoi(pazymys);
                }
                else
                {
                    paz = 0;
                }
                studentoDuomenys.pazymiai.push_back(paz);
            }

            string egzaminas;
            fd >> egzaminas;
            int egz;

            if (arSkaicius(egzaminas) == true)
            {
                egz = std::stoi(egzaminas);
            }
            else
            {
                egz = 0;
            }

            studentoDuomenys.egzaminas = egz;
            stud.push_back(studentoDuomenys);
        }
    }
}