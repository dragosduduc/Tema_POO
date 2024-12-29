#ifndef ANGAJAT_H
#define ANGAJAT_H

#include "Verificari.h"

class Angajat {
protected:
    static int nrAngajati, nrDemisionati;
    string nume, prenume, CNP;
    Data dataAngajare;
    const int ID;
    int salariuBaza = 3500;
public:
    Angajat() = default;
    Angajat(string, string, string, int, int, int);
    virtual ~Angajat() = default;
    virtual float getSalariu() const = 0;
    string getNume() const;
    string getPrenume() const;
    virtual float getCoefSalariu() const = 0;
    bool isBirthMonth() const;
    void changeName();
    static void resign(vector<Angajat*>&);
    static void newDemisionat();
    virtual void afisare() const;
};

#endif //ANGAJAT_H
