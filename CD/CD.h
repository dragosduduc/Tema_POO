#ifndef CD_H
#define CD_H

#include "Disc.h"

class CD: public Disc {
    static int nrCDs;
public:
    CD() = default;
    CD(string, float, string, string, Data);
    ~CD() = default;
    static void addCD(int);
    static int getNrCDs();
};

#endif //CD_H
