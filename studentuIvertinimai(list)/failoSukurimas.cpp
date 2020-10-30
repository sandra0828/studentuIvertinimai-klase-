#include "failoSukurimas.h"

void naujasFailas(int n, int kiekPazymiu)
{
	string skaicius = to_string(n);

	ofstream fr("kursiokai" + skaicius + ".txt");

	fr << left << setw(15) << "Vardas" << setw(20) << "Pavarde";
	for (int i = 0; i < kiekPazymiu; i++)
	{
		string skaicius = to_string(i + 1);
		fr << setw(5) << "ND" + skaicius;
	}
	fr << setw(5) << "Egz" << endl;


	for (int i = 0; i < n; i++)
	{
		Asmuo asmuo;
		string skaicius = to_string(i+1);

		asmuo.vardas = "Vardas" + skaicius;
		asmuo.pavarde = "Pavarde" + skaicius;
		fr << left << setw(15) << asmuo.vardas << setw(20) << asmuo.pavarde;

		using hrClock = std::chrono::high_resolution_clock;
		std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
		std::uniform_int_distribution<int> dist(0, 10);

		for (int j = 0; j < kiekPazymiu; j++)
		{
			asmuo.pazymiai.push_back(dist(mt));
			fr << setw(5) << asmuo.pazymiai.at(j);
		}

		asmuo.egzaminas = dist(mt);
		fr << setw(5) << asmuo.egzaminas << endl;
	}

	fr.close();
}
