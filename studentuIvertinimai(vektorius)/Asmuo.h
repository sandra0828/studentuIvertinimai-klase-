#pragma once

#include <string>

using std::string;

class Asmuo {
protected:
    std::string vardas;
    std::string pavarde;
public:
    Asmuo(string v = " ", string p = " ") : vardas{ v }, pavarde{ p } {}

    inline std::string gautiVarda() const { return vardas; }
    inline std::string gautiPavarde() const { return pavarde; }

    virtual string kokiaManoProfesija() = 0;
};