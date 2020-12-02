#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "pagalbine.h"

using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::ws;

class Asmuo {
private:
    std::string vardas;
    std::string pavarde;
    int egzaminas;
    float galutinis = 0;
    std::vector<int> pazymiai;
public:
    Asmuo() : egzaminas(0) { }
    Asmuo(std::istream& is, int kiekZodziu);
    inline std::string gautiVarda() const { return vardas; }
    inline std::string gautiPavarde() const { return pavarde; }
    inline float gautiGalutini() const { return galutinis; }
    void nuskaityti(std::istream& is, int kiekZodziu);
    double galutinisBalas(float (*funkcija) (vector <int>));
};

bool palyginimasPagalVarda(const Asmuo& a, const Asmuo& b);
bool palyginimasPagalPazymi(const Asmuo& a, const Asmuo& b);
bool arDaugiau_5(const Asmuo& a);
