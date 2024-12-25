#ifndef MANAGER_H
#define MANAGER_H

#include "Angajat.h"
using namespace std;

class Manager: public Angajat {
    float coeficientSalariu = 1.25;
public:
    Manager() = default;
    Manager(string, string, string, int, int, int);
    float getSalariu() const;
    void afisare() const;
};

#endif //MANAGER_H
