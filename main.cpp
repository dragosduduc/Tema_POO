#include "ptAngajare.h"
#include "ptStoc.h"

int main() {

    int nrElem;
    cout << "Cati angajati are firma?" << endl << "Numar angajati: ";
    cin >> nrElem;

    // crearea vectorului initial de angajați
    int cnt = 0;
    vector<Angajat*> angajati(nrElem);
    vector<Angajat*>::iterator it_ang = angajati.begin();
    for (it_ang = angajati.begin(); it_ang != angajati.end(); it_ang++) {
        cout << "---CANDIDATUL " << ++cnt << "---" << endl;
        (*it_ang) = angajare();
    }
    for (it_ang = angajati.begin(); it_ang < angajati.end(); it_ang++) {
        (*it_ang)->afisare();
        cout << endl;
    }

    // schimbarea numelui celui de-al doilea angajat
    it_ang = angajati.begin();
    (*(it_ang + 1))->changeName();
    for (it_ang = angajati.begin(); it_ang < angajati.end(); it_ang++) {
        (*it_ang)->afisare();
        cout << endl;
    }

    // demisia unui angajat
    Angajat::resign(angajati);
    nrElem--;

    // angajarea unei persoane noi
    cout << endl << "Un nou angajat!" << endl << endl;
    Angajat* newAng = angajare();
    if (newAng != nullptr) {
        angajati.push_back(newAng);
        nrElem++;
    }else {
        cout << endl << "Noua persoana nu a putut fi angajata." << endl;
    }
    for (it_ang = angajati.begin(); it_ang < angajati.end(); it_ang++) {
        (*it_ang)->afisare();
        cout << endl;
    }

    // structura pentru stoc, în care se adaugă două tipuri de produse
    map<int, pair<Produs*, int>> stoc;
    adaugareProdus(stoc);
    adaugareProdus(stoc);

    // se afișează stocul și prețul total al fiecărui produs din stoc
    map<int, pair<Produs*, int>>::iterator it_stoc = stoc.begin();
    for (it_stoc = stoc.begin(); it_stoc != stoc.end(); it_stoc++) {
        (*it_stoc).second.first->afisare();
        cout << endl;
        cout << (*it_stoc).second.first->getPretTotal();
        cout << endl;
    }

    // se modifică stocul unui produs și se afișează din nou pentru verificare
    modifStoc(stoc);
    it_stoc = stoc.begin();
    for (it_stoc = stoc.begin(); it_stoc != stoc.end(); it_stoc++) {
        (*it_stoc).second.first->afisare();
        cout << " ";
        cout << (*it_stoc).second.second;
        cout << endl;
    }

    for (it_stoc = stoc.begin(); it_stoc != stoc.end(); it_stoc++) {
        (*it_stoc).second.first->afisare();
        cout << endl;
        cout << (*it_stoc).second.first->getPretBaza();
        cout << endl;
    }

    return 0;
}