#include "studentuSarasoDalinimas.h"

void studentuRusiavimas(vector <Asmuo> studentai, vector <Asmuo>& galvociai, vector <Asmuo>& vargsiukai, string skaiciavimoBudas)
{
    galutinisPazymys(studentai, skaiciavimoBudas);

    auto start = std::chrono::high_resolution_clock::now();
    int n = studentai.size();
    for (int i = n-1; i >= 0; i--)
    {
      if (studentai.at(i).galutinis >= 5)
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

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Studentu padalinimas i du sarasus, pasalinant pradini vektoriu, uztruko: " << diff.count() << " s\n";
}

void naujiSarasai(vector <Asmuo> galvociai, vector <Asmuo> vargsiukai, string kiek)
{
    auto start = std::chrono::high_resolution_clock::now();
    ofstream fr1("Galvociai" + kiek + ".txt");

    fr1 << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) / Galutinis(Med.) " << endl;
    for (int i = 0; i < galvociai.size(); i++)
    {
        fr1 << left << setw(15) << galvociai.at(i).vardas << " | " << setw(20) << galvociai.at(i).pavarde << " | " << fixed << setprecision(2) << galvociai.at(i).galutinis << endl;
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
        fr2 << left << setw(15) << vargsiukai.at(i).vardas << " | " << setw(20) << vargsiukai.at(i).pavarde << " | " << fixed << setprecision(2) << vargsiukai.at(i).galutinis << endl;
    }
    fr2.close();
    vargsiukai.clear();

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    std::cout << "Vargsiuku saraso irasymo i faila trukme: " << diff2.count() << " s\n";
}
