#include "Angajat.h"

#include "Asistent.h"
#include "Manager.h"
#include "OperatorComenzi.h"

//nrAngajati reprezintă numărul de angajări făcute vreodată de companie
//nrDemisionati reprezintă numărul de demisii făcute vreodată de companie
//numărul de angajați curenți la companie este nrAngajati - nrDemisionati
int Angajat::nrAngajati = 0;
int Angajat::nrDemisionati = 0;

// constructor cu parametri
Angajat::Angajat(string arg_CNP, string arg_nume, string arg_prenume, string arg_parola, int arg_zi, int arg_luna, int arg_an): CNP{arg_CNP}, nume{arg_nume}, prenume{arg_prenume}, parola{arg_parola}, ID{nrAngajati++}, dataAngajare{arg_zi, arg_luna, arg_an} {};

// getNume()
string Angajat::getNume() const {
    return nume;
}

// getPrenume()
string Angajat::getPrenume() const {
    return prenume;
}

// getCNP()
string Angajat::getCNP() const {
    return CNP;
}

// getarola()
string Angajat::getParola() const {
    return parola;
}

int Angajat::getID() const {
    return ID;
}

// verifică dacă ziua de naștere a angajatului se află în luna curentă, în vederea acordării bonusului de 100 RON
bool Angajat::isBirthMonth() const {
    Data crt;
    int luna_nastere = stoi(CNP.substr(3, 2));
    if (luna_nastere == crt.getLuna())
        return true;
    return false;
}

// schimbare de nume
void Angajat::changeName() {
    string oldName = nume;
    bool ok = 0;
    string newName;
    while (ok == 0) {
        cout << endl << endl << "           Noul nume al angajatului " << nume << " " << prenume << ": ";
        cin >> newName;
        try {
            ok = isNameValid(newName);
        }
        catch (std::exception& e) {
            cout << "           " << e.what() << endl;
        }
    }
    nume = formatName(newName);
    cout << endl << endl << "           Numele angajatului " << oldName << " " << prenume << " a fost schimbat cu succes in " << nume << " " << prenume << "." << endl << endl;
}

// funcție de demisie
void Angajat::resign(vector<Angajat*>& vect, vector<Angajat*>::iterator it) {

    // se incrementează variabilele statice corespunzătoare
    Angajat::newDemisionat();
    if ((*it)->getCoefSalariu() == 1.25)
        Manager::resignManager();
    else if ((*it)->getCoefSalariu() == 1)
        OperatorComenzi::resignOperator();
    else if ((*it)->getCoefSalariu() == 0.75)
        Asistent::resignAsistent();

    // se reține numele persoanei, pentru a fi afișate la mesajul de confirmare a demisiei
    string nume_dem = (*it)->getNume();
    string prenume_dem = (*it)->getPrenume();

    // se sterge elementul din memorie și din vector
    delete *it;
    vect.erase(it);

    // se afișează mesajul de confirmare și se afișează vectorul de angajați rămas
    cout << endl << endl << "           Angajatul " << nume_dem << " " << prenume_dem << " a fost eliminat cu succes din baza de date.";
}

// se crește variabila statica nrDemisionati - folosită la resign()
void Angajat::newDemisionat() {
    nrDemisionati++;
}

// funcție de afișare
void Angajat::afisare() const {
    cout << "ID = " << ID << ", " << nume << " " << prenume  << ", CNP =  " << CNP << ", angajat de la " << dataAngajare << " " << "pe pozitia de ";
}
