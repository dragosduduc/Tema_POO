#include "OperatorComenzi.h"

int OperatorComenzi::nrOperatori = 0;

// constructor cu parametri
OperatorComenzi::OperatorComenzi(string arg_CNP, string arg_nume, string arg_prenume, string arg_parola, int arg_zi, int arg_luna, int arg_an): Angajat{arg_CNP, arg_nume, arg_prenume, arg_parola, arg_zi, arg_luna, arg_an} {
    nrOperatori++;
}

void OperatorComenzi::newOperator() {
    nrOperatori++;
}

void OperatorComenzi::resignOperator() {
    nrOperatori--;
}

int OperatorComenzi::getNrOperator() {
    return nrOperatori;
}

float OperatorComenzi::getCoefSalariu() const {
    return coeficientSalariu;
}

// getSalariu()
float OperatorComenzi::getSalariu() const {
    float total = (salariuBaza + 100 * dataAngajare.getTimeGap().getAn()) * coeficientSalariu + 100 * this->isBirthMonth();
    return total;
}

// funcție de afișare
void OperatorComenzi::afisare() const {
    Angajat::afisare();
    cout << "Operator Comenzi.";
}