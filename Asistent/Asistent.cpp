#include "Asistent.h"

int Asistent::nrAsistenti = 0;

// constructor cu parametri
Asistent::Asistent(string arg_CNP, string arg_nume, string arg_prenume, string arg_parola, int arg_zi, int arg_luna, int arg_an): Angajat{arg_CNP, arg_nume, arg_prenume, arg_parola, arg_zi, arg_luna, arg_an} {
    nrAsistenti++;
}

void Asistent::newAsistent() {
    nrAsistenti++;
}

void Asistent::resignAsistent() {
    nrAsistenti--;
}

int Asistent::getNrAsistent() {
    return nrAsistenti;
}

float Asistent::getCoefSalariu() const {
    return coeficientSalariu;
}

// getSalariu()
float Asistent::getSalariu() const {
    float total = (salariuBaza + 100 * dataAngajare.getTimeGap().getAn()) * coeficientSalariu + 100 * this->isBirthMonth();
    return total;
}

// funcție de afișare
void Asistent::afisare() const {
    Angajat::afisare();
    cout << "Asistent.";
}