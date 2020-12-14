#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Asmuo.h"
#include "pagalbine.h"

using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::ws;

class Studentas : public Asmuo{
private:
    int egzaminas;
    float galutinis = 0;
    std::vector<int> pazymiai;
public:
    Studentas(string v = " ", string p = " ") : egzaminas(0), Asmuo(v, p) { }
    Studentas(std::istream& is, int kiekZodziu);
    Studentas(string vardas_n, string pavarde_n, std::vector<int> pazymiai_n, int egzaminas_n);
    //Studentas(const Studentas& a) : Asmuo(a.vardas, a.pavarde), pazymiai(a.pazymiai),
        //egzaminas(a.egzaminas), galutinis(a.galutinis) {}; // kopijavimo konstruktorius
    Studentas& operator=(const Studentas& a); // priskyrimo operatorius
    int& operator[](int i); // grazina studento i-taji namu darbu pazymi

    inline float gautiGalutini() const { return galutinis; }
    void nuskaityti(std::istream& is, int kiekZodziu);
    double galutinisBalas(float (*funkcija) (vector <int>));

    ~Studentas() {}
};

bool palyginimasPagalVarda(const Studentas& a, const Studentas& b);
bool palyginimasPagalPazymi(const Studentas& a, const Studentas& b);
bool arDaugiau_5(const Studentas& a);
