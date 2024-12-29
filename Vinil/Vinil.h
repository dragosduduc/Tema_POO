#ifndef VINIL_H
#define VINIL_H

#include "Disc.h"

class Vinil: public Disc {
public:
    Vinil() = default;
    Vinil(string, float, string, string, Data);
    ~Vinil() = default;
};

#endif //VINIL_H
