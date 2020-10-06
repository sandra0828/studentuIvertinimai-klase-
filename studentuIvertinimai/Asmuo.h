#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::vector;
using std::ifstream;
using std::getline;
using std::stringstream;

struct Asmuo {
    string vardas, pavarde;
    int egzaminas;
    float galutinis = 0;
    std:: vector<int> pazymiai;
};
