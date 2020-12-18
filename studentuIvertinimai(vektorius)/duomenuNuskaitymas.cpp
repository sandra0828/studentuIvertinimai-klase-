#include "duomenuNuskaitymas.h"

void duomenuNuskaitymas(vector <Studentas>& stud, string failoVardas)
{
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

    while (!fd.eof())
    {
        Studentas asmuo(fd, kiekZodziu);
        stud.push_back(asmuo);
    }

    fd.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo nuskaitymas uztruko: " << diff.count() << " s\n";
}