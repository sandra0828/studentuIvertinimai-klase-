#pragma once
#include "Asmuo.h"
#include "galutinisPazymys.h"
#include <vector>
#include <chrono>
#include <fstream>
#include "pagalbine.h"

using std::ofstream;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::list;


void studentuRusiavimas(list <Asmuo>& studentai, list <Asmuo>& galvociai, list <Asmuo>& vargsiukai, string skaiciavimoBudas, string strategija);
void naujiSarasai(list <Asmuo>& galvociai, list <Asmuo>& vargsiukai, string kiek);