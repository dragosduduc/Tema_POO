#include "Comanda.h"

int Comanda::cnt = 0;

Comanda::Comanda(const vector<pair<Produs*, int>>& produseDorite): id{cnt++}, produse{produseDorite}, timpIncepere{chrono::system_clock::now()}, operatorAsignat{nullptr}, finalizata{0} {

    validareComanda(produseDorite);

    for (auto it = produse.begin(); it != produse.end(); it++) {
        valoareTotala += it->first->getPretTotal() * it->second;
        durataTotal += it->second * 60;
    }
}

void Comanda::validareComanda(const vector<pair<Produs*, int>>& produseDorite) {

    float valoareBaza = 0;
    int numarDiscuri = 0;
    int numarArticole = 0;

    for (auto it = produseDorite.begin(); it != produseDorite.end(); it++) {
        valoareBaza += it->first->getPretBaza() * it->second;

        if (dynamic_cast<CD*>(it->first) || dynamic_cast<Vinil*>(it->first) || dynamic_cast<DiscVintage*>(it->first))
            numarDiscuri += it->second;
        else if (dynamic_cast<ArticolVestimentar*>(it->first))
            numarArticole += it->second;
    }

    if (valoareBaza < 100)
        throw invalid_argument("           Comanda nu a putut fi plasata deoarece trebuie sa aiba o valoare minimă de 100 RON!");
    if (numarDiscuri > 5)
        throw invalid_argument("           Comanda nu a putut fi plasata deoarece nu poate contine mai mult de 5 discuri!");
    if (numarArticole > 3)
        throw invalid_argument("           Comanda nu a putut fi plasata deoarece nu poate contine mai mult de 3 articole vestimentare!");
}

int Comanda::timpRamas() {
    if (finalizata)
        return 0;

    auto timpCurent = chrono::system_clock::now();
    auto timpTrecut = chrono::duration_cast<chrono::seconds>(timpCurent - timpIncepere).count();
    int timpRamas = durataTotal - static_cast<int>(timpTrecut);

    if (timpRamas > 0)
        return timpRamas;
    return 0;
}

bool Comanda::esteFinalizata() {
    if (!finalizata) {
        auto timpCurent = chrono::system_clock::now();
        auto timpTrecut = chrono::duration_cast<chrono::seconds>(timpCurent - timpIncepere).count();

        if (timpTrecut >= durataTotal)
            finalizata = 1;
    }
    return finalizata;
}

int Comanda::getId() const {
    return id;
}

float Comanda::getValoare() const {
    return valoareTotala;
}

OperatorComenzi* Comanda::getOperator() const {
    return operatorAsignat;
}

void Comanda::setOperator(OperatorComenzi* op) {
    operatorAsignat = op;
}