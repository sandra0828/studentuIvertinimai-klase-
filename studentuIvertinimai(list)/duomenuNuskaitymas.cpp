#include "duomenuNuskaitymas.h"

void duomenuNuskaitymas(list <Asmuo>& stud, string failoVardas)
{
    // is pradziu suskaiciuojama, kiek bus is viso kintamuju
    auto start = std::chrono::high_resolution_clock::now();
    ifstream fd(failoVardas);

    try
    {
        if (fd.fail())
            throw std::runtime_error("Failas nerastas \n");
    }
    catch (const std::runtime_error& e)
    {
        cout << e.what();
        return;
    }

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

        fd >> studentoDuomenys.vardas >> ws >> studentoDuomenys.pavarde >> ws;
        string pazymys;

        // pazymiu skaicius randamas is visu stulpeliu skaiciaus atimant vardo, pavardes ir egzamino stulpelius
        for (int i = 0; i < kiekZodziu - 3; i++)
        {
            fd >> pazymys >> ws;
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
        fd >> egzaminas >> ws;

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
        stud.push_front(studentoDuomenys);
    }
    fd.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo nuskaitymas uztruko: " << diff.count() << " s\n";
}