#ifndef PRODUS_H
#define PRODUS_H

#include "Verificari.h"

class Produs {
protected:
    string nume;
    float pretBaza;
    const int cod;
    static int cnt;
public:
    Produs() = default;
    Produs(string, float);
    virtual ~Produs() = 0;
    int getCod() const;
    float getPretBaza() const;
    virtual string getTip() const = 0;
    virtual float getPretTotal() const = 0;
    virtual void afisare() const;
};

#endif //PRODUS_H
