#include "studentuSarasoDalinimas.h"

void studentuRusiavimas(list <Asmuo>& studentai, list <Asmuo>& galvociai, list <Asmuo>& vargsiukai, string skaiciavimoBudas, string strategija)
{
    galutinisPazymys(studentai, skaiciavimoBudas);

    auto start = std::chrono::high_resolution_clock::now();
    int n = studentai.size();

    if (strategija == "1")
    {
        studentai.sort(pazymiuPalyginimas);
        list<Asmuo>::iterator it = std::find_if(studentai.begin(), studentai.end(), arMaziau_5);
        vargsiukai.assign(studentai.begin(), it);
        galvociai.assign(it, studentai.end());
        studentai.clear();

    }
    else if (strategija == "3")
    {
        for (int i = 0; i < n; i++)
        {
            if (studentai.front().galutinis >= 5)
            {
                galvociai.push_front(studentai.front());
            }
            else
            {
                vargsiukai.push_front(studentai.front());
            }
            studentai.pop_front();
        }
    }
    else
    {
        studentai.sort(pazymiuPalyginimas);
        list<Asmuo>::iterator it = std::find_if(studentai.begin(), studentai.end(), arMaziau_5);
        vargsiukai.splice(vargsiukai.begin(), studentai, studentai.begin(), it);
        galvociai.splice(galvociai.begin(), studentai, it, studentai.end());
    }


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Studentu padalinimas i du sarasus, pasalinant pradini vektoriu, uztruko: " << diff.count() << " s\n";
}

void naujiSarasai(list <Asmuo>& galvociai, list <Asmuo>& vargsiukai, string kiek)
{
    ofstream fr1("Galvociai" + kiek + ".txt");

    fr1 << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) / Galutinis(Med.) " << endl;
    for (Asmuo asmuo: galvociai)
    {
        fr1 << left << setw(15) << asmuo.vardas << " | " << setw(20) << asmuo.pavarde << " | " << fixed << setprecision(2) << asmuo.galutinis << endl;
    }
    fr1.close();
    galvociai.clear();

    ofstream fr2("Vargsiukai" + kiek + ".txt");

    fr2 << left << setw(15) << "Vardas" << " | " << setw(20) << "Pavarde" << " | " << "Galutinis (Vid.) / Galutinis(Med.) " << endl;
    for (Asmuo asmuo: vargsiukai)
    {
        fr2 << left << setw(15) << asmuo.vardas << " | " << setw(20) << asmuo.pavarde << " | " << fixed << setprecision(2) << asmuo.galutinis << endl;
    }
    fr2.close();
    vargsiukai.clear();

}
