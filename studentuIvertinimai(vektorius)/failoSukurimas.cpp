#include "failoSukurimas.h"

void naujasFailas(int n, int kiekPazymiu)
{
	string skaicius = to_string(n);

	auto start = std::chrono::high_resolution_clock::now();

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
		string skaicius = to_string(i+1);

		fr << left << setw(15) << "Vardas" + skaicius << setw(20) << "Pavarde" + skaicius;

		using hrClock = std::chrono::high_resolution_clock;
		std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
		std::uniform_int_distribution<int> dist(0, 10);

		for (int j = 0; j < kiekPazymiu; j++)
		{
			fr << setw(5) << dist(mt);
		}

		fr << setw(5) << dist(mt) << endl;
	}

	fr.close();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Failo sukurimas uztruko: " << diff.count() << " s\n";
} 
