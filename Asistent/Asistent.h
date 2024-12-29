#ifndef ASISTENT_H
#define ASISTENT_H

#include "Angajat.h"

class Asistent: public Angajat {
    float coeficientSalariu = 0.75;
public:
    Asistent() = default;
    Asistent(string, string, string, int, int, int);
    float getSalariu() const;
    void afisare() const;
};

#endif //ASISTENT_H
