#ifndef GESTIUNECOMENZI_H
#define GESTIUNECOMENZI_H

#include "Comanda.h"
#include <fstream>

class GestiuneComenzi {
private:
    vector<Comanda*> comenziActive;
    vector<Comanda*> comenziInAsteptare;
    vector<Comanda*> comenziFinalizate;
    vector<Angajat*>& angajati;
public:
    GestiuneComenzi() = default;
    GestiuneComenzi(vector<Angajat*>&);
    int numarComenziActive(OperatorComenzi*);
    OperatorComenzi* gasesteOperator();
    void adaugaComanda(Comanda*);
    void actualizeazaStareComenzi();
    void afiseazaStatusOperatori() const;
    int getNrActive() const;
    int getNrAsteptare() const;
    int getNrFinalizate() const;
    const vector<Comanda*>& getComenziActive() const;
    const vector<Comanda*>& getComenziAsteptare() const;
    const vector<Comanda*>& getComenziFinalizate() const;

    float getValoareTotalaOperator(OperatorComenzi* op) const;
    int getNumarComenziOperator(OperatorComenzi* op) const;
    void genereazaRaportComenziProcesate() const;
    void genereazaRaportValoareComenzi() const;
    void genereazaRaportSalarii() const;
};

#endif //GESTIUNECOMENZI_H
