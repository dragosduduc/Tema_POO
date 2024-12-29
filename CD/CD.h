#ifndef CD_H
#define CD_H

#include "Disc.h"

class CD: public Disc {
public:
    CD() = default;
    CD(string, float, string, string, Data);
    ~CD() = default;
};

#endif //CD_H
