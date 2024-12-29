#include "Manager.h"

int Manager::nrManageri = 0;

// constructor cu parametri
Manager::Manager(string arg_nume, string arg_prenume, string arg_CNP, int arg_zi, int arg_luna, int arg_an): Angajat{arg_nume, arg_prenume, arg_CNP, arg_zi, arg_luna, arg_an} {
    Manager::nrManageri++;
}

void Manager::newManager() {
    nrManageri++;
}

void Manager::resignManager() {
    nrManageri--;
}

int Manager::getNrManager() {
    return nrManageri;
}

float Manager::getCoefSalariu() const {
    return coeficientSalariu;
}

// getSalariu()
float Manager::getSalariu() const {
    float total = (salariuBaza + 100 * dataAngajare.getTimeGap().getAn()) * coeficientSalariu;
    return total;
}

// funcție de afișare
void Manager::afisare() const {
    Angajat::afisare();
    cout << coeficientSalariu << " ";
}