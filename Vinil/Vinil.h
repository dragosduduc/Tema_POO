#ifndef VINIL_H
#define VINIL_H

#include "Disc.h"

class Vinil: public Disc {
    static int nrVinil;
public:
    Vinil() = default;
    Vinil(string, float, string, string, Data);
    ~Vinil() = default;
    static void addVinil(int);
    static int getNrVinil();
};

#endif //VINIL_H
