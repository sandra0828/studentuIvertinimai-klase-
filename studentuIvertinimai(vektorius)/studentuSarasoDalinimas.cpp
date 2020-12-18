#include "studentuSarasoDalinimas.h"

void studentuRusiavimas(vector <Studentas>& studentai, vector <Studentas>& galvociai, vector <Studentas>& vargsiukai, string skaiciavimoBudas, string strategija)
{
    galutinisPazymys(studentai, skaiciavimoBudas);

    auto start = std::chrono::high_resolution_clock::now();
    int n = studentai.size();

    if (strategija == "1")
    {
        vector <Studentas>::iterator it = std::partition(studentai.begin(), studentai.end(), arDaugiau_5);
        copy(studentai.begin(), it, back_inserter(galvociai));
        copy(it, studentai.end(), back_inserter(vargsiukai));
        studentai.clear();
    }
    else if (strategija == "3")
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (studentai.at(i).gautiGalutini() >= 5)
            {
                galvociai.push_back(studentai.at(i));
                studentai.pop_back();
            }
            else
            {
                vargsiukai.push_back(studentai.at(i));
                studentai.pop_back();
            }
        }
    }
    else
    {
        vector <Studentas>::iterator it = std::partition (studentai.begin(), studentai.end(), arDaugiau_5);
        std::move(studentai.begin(), it, back_inserter(galvociai));
        studentai.erase(studentai.begin(), it);
        vargsiukai = studentai;
        studentai.clear();
     
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    std::cout << "Studentu padalinimas i du sarasus uztruko: " << diff.count() << " s\n";
}

void naujiSarasai(vector <Studentas>& galvociai, vector <Studentas>& vargsiukai, string kiek)
{
    auto start = std::chrono::high_resolution_clock::now();
    ofstream fr1("Galvociai" + kiek + ".txt");

    fr1 << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) / Galutinis(Med.) " << endl;
    for (int i = 0; i < galvociai.size(); i++)
    {
        fr1 << left << setw(15) << galvociai.at(i).gautiVarda() << " | " << setw(20) << galvociai.at(i).gautiPavarde() << " | " << fixed << setprecision(2) << galvociai.at(i).gautiGalutini() << endl;
    }
    fr1.close();
    galvociai.clear();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Galvociu saraso irasymo i faila trukme: " << diff.count() << " s\n";


    auto start2 = std::chrono::high_resolution_clock::now();
    ofstream fr2("Vargsiukai" + kiek + ".txt");

    fr2 << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) / Galutinis(Med.) " << endl;
    for (int i = 0; i < vargsiukai.size(); i++)
    {
        fr2 << left << setw(15) << vargsiukai.at(i).gautiVarda() << " | " << setw(20) << vargsiukai.at(i).gautiPavarde() << " | " << fixed << setprecision(2) << vargsiukai.at(i).gautiGalutini() << endl;
    }
    fr2.close();
    vargsiukai.clear();

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    std::cout << "Vargsiuku saraso irasymo i faila trukme: " << diff2.count() << " s\n";
}
