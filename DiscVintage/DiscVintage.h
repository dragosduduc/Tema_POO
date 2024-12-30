#ifndef DISCVINTAGE_H
#define DISCVINTAGE_H

#include "Produs.h"

class DiscVintage: public Produs {
    bool isMint;
    int coefRaritate;
    static int nrDiscVintage;
public:
    DiscVintage() = default;
    DiscVintage(string, float, bool, int);
    ~DiscVintage() = default;
    static void addDiscVintage(int);
    static int getNrDiscVintage();
    string getTip() const;
    float getPretTotal() const;
    void afisare() const;
};

#endif //DISCVINTAGE_H
