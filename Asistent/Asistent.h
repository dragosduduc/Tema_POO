#ifndef ASISTENT_H
#define ASISTENT_H

#include "Angajat.h"

class Asistent: public Angajat {
    float coeficientSalariu = 0.75;
    static int nrAsistenti;
public:
    Asistent() = default;
    Asistent(string, string, string, int, int, int);
    static void newAsistent();
    static void resignAsistent();
    static int getNrAsistent();
    float getCoefSalariu() const;
    float getSalariu() const;
    void afisare() const;
};

#endif //ASISTENT_H
