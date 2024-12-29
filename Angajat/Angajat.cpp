#include "Angajat.h"

//nrAngajati reprezintă numărul de angajări făcute vreodată de companie
//nrDemisionati reprezintă numărul de demisii făcute vreodată de companie
//numărul de angajați curenți la companie este nrAngajati - nrDemisionati
int Angajat::nrAngajati = 0;
int Angajat::nrDemisionati = 0;

// constructor cu parametri
Angajat::Angajat(string arg_nume, string arg_prenume, string arg_CNP, int arg_zi, int arg_luna, int arg_an): nume{arg_nume}, prenume{arg_prenume}, CNP{arg_CNP}, ID{nrAngajati++}, dataAngajare{arg_zi, arg_luna, arg_an} {};

// getNume()
string Angajat::getNume() const {
    return nume;
}

// getPrenume()
string Angajat::getPrenume() const {
    return prenume;
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
        cout << endl << "Noul nume al angajatului " << nume << " " << prenume << ": ";
        cin >> newName;
        try {
            ok = isNameValid(newName);
        }
        catch (std::exception& e) {
            cout << e.what() << endl;
        }
    }
    nume = formatName(newName);
    cout << "Numele angajatului " << oldName << " " << prenume << " a fost schimbat cu succes in " << nume << " " << prenume << "." << endl << endl;
}

// funcție de demisie
void Angajat::resign(vector<Angajat*>& vect) {
    cout << endl << "Cine demisioneaza? Introduceti un numar valid." << endl << endl;
    // se afișează toți angajații
    int cnt = 0;
    vector<Angajat*>::iterator it = vect.begin();
    for (it = vect.begin(); it < vect.end(); it++) {
        cout << ++cnt << ": ";
        (*it)->afisare();
        cout << endl;
    }

    // se stabilește cine demisionează
    int poz;
    bool ok = 0;
    while (ok == 0) {
        cout << endl << "Numarul angajatului:";
        cin >> poz;
        if (poz < 1 || poz > vect.size())
            cout << "Ati introdus un numar invalid." << endl;
        else
            ok = 1;
    }

    // se reține numele persoanei, pentru a fi afișate la mesajul de confirmare a demisiei
    string nume_dem = vect[poz - 1]->getNume();
    string prenume_dem = vect[poz - 1]->getPrenume();

    // se sterge elementul din memorie și din vector
    delete vect[poz - 1];
    vect.erase(vect.begin() + poz - 1);

    // se incrementează variabila statică nrDemisionati
    Angajat::newDemisionat();

    // se afișează mesajul de confirmare și se afișează vectorul de angajați rămas
    cout << "Angajatul " << nume_dem << " " << prenume_dem << " a demisionat cu succes. Angajatii ramasi in companie sunt:" << endl;
    cnt = 0;
    for (it = vect.begin(); it < vect.end(); it++) {
        cout << ++cnt << ": ";
        (*it)->afisare();
        cout << endl;
    }
}

// se crește variabila statica nrDemisionati - folosită la resign()
void Angajat::newDemisionat() {
    nrDemisionati++;
}

// funcție de afișare
void Angajat::afisare() const {
    cout << nume << " " << prenume  << " " << CNP << " " << dataAngajare.getZi() << " " << dataAngajare.getLuna()  << " " << dataAngajare.getAn() << " " << ID << " " << this->getSalariu() << " ";
}
