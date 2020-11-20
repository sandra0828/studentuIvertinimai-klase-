#pragma once
#include "Asmuo.h"
#include "galutinisPazymys.h"
#include "pagalbine.h"
#include <vector>
#include <chrono>
#include <fstream>

using std::ofstream;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;


void studentuRusiavimas(vector <Asmuo> studentai, vector <Asmuo>& galvociai, vector <Asmuo>& vargsiukai, string skaiciavimoBudas, string strategija);
void naujiSarasai(vector <Asmuo> galvociai, vector <Asmuo> vargsiukai, string kiek);