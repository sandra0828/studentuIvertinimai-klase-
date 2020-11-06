#pragma once
#include "Asmuo.h"
#include "galutinisPazymys.h"
#include <vector>
#include <chrono>
#include <fstream>

using std::ofstream;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::list;


void studentuRusiavimas(list <Asmuo> studentai, list <Asmuo>& galvociai, list <Asmuo>& vargsiukai, string skaiciavimoBudas);
void naujiSarasai(list <Asmuo> galvociai, list <Asmuo> vargsiukai, string kiek);