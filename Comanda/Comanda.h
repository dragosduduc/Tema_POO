#ifndef COMANDA_H
#define COMANDA_H

#include "ptStoc.h"
#include "ptAngajare.h"

class Comanda {
private:
    static int cnt;
    const int id;
    vector<pair<Produs*, int>> produse;
    chrono::system_clock::time_point timpIncepere;
    int durataTotal = 0;
    OperatorComenzi* operatorAsignat;
    bool finalizata;
    float valoareTotala = 0;
public:
    Comanda() = default;
    Comanda(const vector<pair<Produs*, int>>&);
    void validareComanda(const vector<pair<Produs*, int>>&);
    int timpRamas();
    bool esteFinalizata();
    int getId() const;
    float getValoare() const;
    OperatorComenzi* getOperator() const;
    void setOperator(OperatorComenzi*);
};

#endif //COMANDA_H
