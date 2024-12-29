#ifndef ARTICOLVESTIMENTAR_H
#define ARTICOLVESTIMENTAR_H

#include "Produs.h"

class ArticolVestimentar: public Produs {
    string marca, culoare;
public:
    ArticolVestimentar() = default;
    ArticolVestimentar(string, float, string, string);
    ~ArticolVestimentar() = default;
    float getPretTotal() const;
    void afisare() const;
};

#endif //ARTICOLVESTIMENTAR_H
