#include "Asistent.h"

// constructor cu parametri
Asistent::Asistent(string arg_nume, string arg_prenume, string arg_CNP, int arg_zi, int arg_luna, int arg_an): Angajat{arg_nume, arg_prenume, arg_CNP, arg_zi, arg_luna, arg_an} {};

// getSalariu()
float Asistent::getSalariu() const {
    float total = (salariuBaza + 100 * dataAngajare.getTimeGap().getAn()) * coeficientSalariu + 100 * this->isBirthMonth();
    return total;
}

// funcție de afișare
void Asistent::afisare() const {
    Angajat::afisare();
    cout << coeficientSalariu << " ";
}