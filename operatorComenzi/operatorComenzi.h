#ifndef OPERATORCOMENZI_H
#define OPERATORCOMENZI_H

#include "Angajat.h"
using namespace std;

class operatorComenzi: public Angajat {
    float coeficientSalariu = 1;
public:
    operatorComenzi() = default;
    operatorComenzi(string, string, string, int, int, int);
    float getSalariu() const;

    void afisare() const;
};

#endif //OPERATORCOMENZI_H
