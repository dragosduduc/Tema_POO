#ifndef OPERATORCOMENZI_H
#define OPERATORCOMENZI_H

#include "Angajat.h"

class OperatorComenzi: public Angajat {
    float coeficientSalariu = 1;
    static int nrOperatori;
public:
    OperatorComenzi() = default;
    OperatorComenzi(string, string, string, int, int, int);
    static void newOperator();
    static void resignOperator();
    static int getNrOperator();
    float getCoefSalariu() const;
    float getSalariu() const;
    void afisare() const;
};

#endif //OPERATORCOMENZI_H
