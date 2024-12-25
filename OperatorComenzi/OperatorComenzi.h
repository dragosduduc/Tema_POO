#ifndef OPERATORCOMENZI_H
#define OPERATORCOMENZI_H

#include "Angajat.h"
using namespace std;

class OperatorComenzi: public Angajat {
    float coeficientSalariu = 1;
public:
    OperatorComenzi() = default;
    OperatorComenzi(string, string, string, int, int, int);
    float getSalariu() const;
    void afisare() const;
};

#endif //OPERATORCOMENZI_H
