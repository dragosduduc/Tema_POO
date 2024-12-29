#ifndef MANAGER_H
#define MANAGER_H

#include "Angajat.h"

class Manager: public Angajat {
    float coeficientSalariu = 1.25;
    static int nrManageri;
public:
    Manager() = default;
    Manager(string, string, string, int, int, int);
    static void newManager();
    static void resignManager();
    static int getNrManager();
    float getCoefSalariu() const;
    float getSalariu() const;
    void afisare() const;
};

#endif //MANAGER_H
