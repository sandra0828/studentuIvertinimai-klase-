#pragma once
#include "Asmuo.h"
#include "galutinisPazymys.h"
#include "pagalbine.h"
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>

using std::ofstream;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;


void studentuRusiavimas(vector <Studentas>& studentai, vector <Studentas>& galvociai, vector <Studentas>& vargsiukai, string skaiciavimoBudas, string strategija);
void naujiSarasai(vector <Studentas>& galvociai, vector <Studentas>& vargsiukai, string kiek);