#include "GestiuneComenzi.h"

bool comp1(pair<OperatorComenzi*, float> a, pair<OperatorComenzi*, float> b) {
    return a.second > b.second;
}

bool comp2(Angajat* a, Angajat* b) {
    if (a->getSalariu() != b->getSalariu()) {
        return a->getSalariu() > b->getSalariu();
    }
    if (a->getNume() != b->getNume()) {
        return a->getNume() < b->getNume();
    }
    return a->getPrenume() < b->getPrenume();
}

GestiuneComenzi::GestiuneComenzi(vector<Angajat*>& ang) : angajati{ang} {};

int GestiuneComenzi::numarComenziActive(OperatorComenzi* op) {
    int count = 0;
    for (auto it = comenziActive.begin(); it != comenziActive.end(); it++)
        if ((*it)->getOperator() == op)
            count++;
    return count;
}

OperatorComenzi* GestiuneComenzi::gasesteOperator() {

    OperatorComenzi* operatorBun = nullptr;
    int minComenzi = 3;
    for (auto it = angajati.begin(); it != angajati.end(); it++) {
        auto* crt = dynamic_cast<OperatorComenzi*>(*it);
        if (crt != nullptr) {
            int comenziCurente = numarComenziActive(crt);
            if (comenziCurente < minComenzi) {
                operatorBun = crt;
                minComenzi = comenziCurente;
            }
        }
    }
    return operatorBun;
}

void GestiuneComenzi::adaugaComanda(Comanda* comanda) {

    auto* op = gasesteOperator();
    if (op != nullptr) {
        comanda->setOperator(op);
        comenziActive.push_back(comanda);
        cout << "           Comanda #" << comanda->getId() << " a fost asignata operatorului " << op->getNume() << " " << op->getPrenume() << endl;
    } else {
        comenziInAsteptare.push_back(comanda);
        cout << "           Nu exista operatori disponibili. Comanda #" << comanda->getId() << " a fost pusa in asteptare." << endl;
    }
}

void GestiuneComenzi::actualizeazaStareComenzi() {

    auto it = comenziActive.begin();
    while (it != comenziActive.end()) {
        if ((*it)->esteFinalizata() == 1) {
            cout << "                                                                                                              Comanda #" << (*it)->getId() << " a fost finalizata!" << endl << endl;
            comenziFinalizate.push_back(*it);
            it = comenziActive.erase(it);
        } else
            ++it;
    }

    it = comenziInAsteptare.begin();
    while (it != comenziInAsteptare.end()) {
        auto* op = gasesteOperator();
        if (op == nullptr)
            break;

        (*it)->setOperator(op);
        comenziActive.push_back(*it);
        cout << "                                                                             Comanda #" << (*it)->getId() << " a fost mutata din asteptare la operatorul " << op->getNume() << " " << op->getPrenume() << endl << endl;
        it = comenziInAsteptare.erase(it);
    }
    cout << endl << endl;
}

void GestiuneComenzi::afiseazaStatusOperatori() const {

    map<OperatorComenzi*, int> comenziPerOperator;
    for (auto it = comenziActive.begin(); it != comenziActive.end(); it++)
        comenziPerOperator[(*it)->getOperator()]++;

    for (auto it = angajati.begin(); it != angajati.end(); it++) {
        auto* op = dynamic_cast<OperatorComenzi*>(*it);
        if (op != nullptr)
            cout << "                                 " << op->getNume() << " " << op->getPrenume() << ": " << comenziPerOperator[op] << " comenzi active" << endl;
    }
}

int GestiuneComenzi::getNrActive() const {
    return comenziActive.size();
}

int GestiuneComenzi::getNrAsteptare() const {
    return comenziInAsteptare.size();
}

int GestiuneComenzi::getNrFinalizate() const {
    return comenziFinalizate.size();
}

const vector<Comanda*>& GestiuneComenzi::getComenziActive() const {
    return comenziActive;
}

const vector<Comanda*>& GestiuneComenzi::getComenziAsteptare() const {
    return comenziInAsteptare;
}

const vector<Comanda*>& GestiuneComenzi::getComenziFinalizate() const {
    return comenziFinalizate;
}

float GestiuneComenzi::getValoareTotalaOperator(OperatorComenzi* op) const {
    float total = 0;
    for(auto it = comenziFinalizate.begin(); it != comenziFinalizate.end(); it++)
        if((*it)->getOperator() == op)
            total += (*it)->getValoare();
    return total;
}

int GestiuneComenzi::getNumarComenziOperator(OperatorComenzi* op) const {
    int cnt = 0;
    for(auto it = comenziFinalizate.begin(); it != comenziFinalizate.end(); it++)
        if((*it)->getOperator() == op)
            cnt++;
    return cnt;
}

void GestiuneComenzi::genereazaRaportComenziProcesate() const {

    map<OperatorComenzi*, int> comenziPerOperator;
    for (auto it = angajati.begin(); it != angajati.end(); it++) {
        auto* op = dynamic_cast<OperatorComenzi*>(*it);
        if (op != nullptr)
            comenziPerOperator[op] = getNumarComenziOperator(op);
    }

    pair<OperatorComenzi*, int> best{nullptr, -1};
    for (auto it = comenziPerOperator.begin(); it != comenziPerOperator.end(); it++)
        if (it->second > best.second) {
            best.first = it->first;
            best.second = it->second;
        }

    ofstream out("nr_comenzi_max.csv");
    out << "Nume,Prenume,Comenzi Procesate" << endl;

    if (best.first == nullptr)
        cout << "           Nu a putut fi gasit angajatul cu cele mai multe comenzi procesate." << endl;
    out << best.first->getNume() << "," << best.first->getPrenume() << "," << best.second << endl;
}

void GestiuneComenzi::genereazaRaportValoareComenzi() const {

    vector<pair<OperatorComenzi*, float>> operatoriValoare;
    for (auto it = angajati.begin(); it != angajati.end(); it++) {
        auto* op = dynamic_cast<OperatorComenzi*>(*it);
        if (op != nullptr)
            operatoriValoare.push_back({op, getValoareTotalaOperator(op)});
    }

    sort (operatoriValoare.begin(), operatoriValoare.end(), comp1);

    ofstream out("top3ang_val_comenzi.csv");
    out << "Nume,Prenume,Valoare Totala Comenzi" << endl;

    for (int i = 0; i < 3; i++)
        out << operatoriValoare[i].first->getNume() << "," << operatoriValoare[i].first->getPrenume() << "," << operatoriValoare[i].second << endl;
}

void GestiuneComenzi::genereazaRaportSalarii() const {

    vector<Angajat*> angajatiSortati;
    for (auto it = angajati.begin(); it != angajati.end(); it++)
        angajatiSortati.push_back(*it);

    sort(angajatiSortati.begin(), angajatiSortati.end(), comp2);

    ofstream out("top3_salarii.csv");
    out << "Nume,Prenume,Salariu" << endl;

    for (int i = 0; i < 3; i++)
        out << angajatiSortati[i]->getNume() << "," << angajatiSortati[i]->getPrenume() << "," << angajatiSortati[i]->getSalariu() << endl;
}