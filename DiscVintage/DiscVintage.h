#ifndef DISCVINTAGE_H
#define DISCVINTAGE_H

#include "Produs.h"

class DiscVintage: public Produs {
    bool isMint;
    int coefRaritate;
public:
    DiscVintage() = default;
    DiscVintage(string, float, bool, int);
    ~DiscVintage() = default;
    float getPretTotal() const;
    void afisare() const;
};

#endif //DISCVINTAGE_H
