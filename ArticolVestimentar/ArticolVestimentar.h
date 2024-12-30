#ifndef ARTICOLVESTIMENTAR_H
#define ARTICOLVESTIMENTAR_H

#include "Produs.h"

class ArticolVestimentar: public Produs {
    string marca, culoare;
    static int nrArticoleVestimentare;
public:
    ArticolVestimentar() = default;
    ArticolVestimentar(string, float, string, string);
    ~ArticolVestimentar() = default;
    static void addArticoleVestimentare(int);
    static int getNrArticoleVestimentare();
    string getTip() const;
    float getPretTotal() const;
    void afisare() const;
};

#endif //ARTICOLVESTIMENTAR_H