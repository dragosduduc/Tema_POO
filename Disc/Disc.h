#ifndef DISC_H
#define DISC_H

#include "Produs.h"

class Disc: public Produs {
protected:
    string trupa, casaDiscuri;
    Data punereVanzare;
public:
    Disc() = default;
    Disc(string, float, string, string, Data);
    ~Disc() = 0;
    float getPretTotal() const;
    virtual void afisare() const;
    virtual string getTip() const = 0;
};

#endif //DISC_H
