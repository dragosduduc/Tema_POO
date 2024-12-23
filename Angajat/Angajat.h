#ifndef ANGAJAT_H
#define ANGAJAT_H

#include "Data.h"
#include <string>
using namespace std;

class Angajat {
protected:
    string nume, prenume, CNP;
    Data dataAngajare;
    const int ID;
    int salariuBaza = 3500;
public:
    static int nrAngajati, nrDemisionati;
    Angajat() = default;
    Angajat(string, string, string, int, int, int);
    bool operator==(const Angajat&) const;
    virtual ~Angajat() = default;
    virtual float getSalariu() const = 0;
    virtual string getNume() const;
    virtual string getPrenume() const;
    virtual bool isBirthMonth() const;
    virtual void changeName();

    static void resign(vector<Angajat*>&);

    virtual void afisare() const;
};

#endif //ANGAJAT_H
