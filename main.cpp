#include "ptAngajare.h"
#include <vector>

int main() {

    int nrElem;
    cout << "Cati angajati are firma?" << endl << "Numar angajati: ";
    cin >> nrElem;

    // crearea vectorului initial de angajați
    int cnt = 0;
    vector<Angajat*> angajati(nrElem);
    vector<Angajat*>::iterator it = angajati.begin();
    for (it = angajati.begin(); it < angajati.end(); it++) {
        cout << "---CANDIDATUL " << ++cnt << "---" << endl;
        (*it) = angajare();
    }
    for (it = angajati.begin(); it < angajati.end(); it++) {
        (*it)->afisare();
        cout << endl;
    }

    // schimbarea numelui celui de-al doilea angajat
    it = angajati.begin();
    (*(it + 1))->changeName();
    for (it = angajati.begin(); it < angajati.end(); it++) {
        (*it)->afisare();
        cout << endl;
    }

    // demisia unui angajat
    Angajat::resign(angajati);
    nrElem--;

    // angajarea unei persoane noi
    cout << endl << "Un nou angajat!" << endl << endl;
    angajati.push_back(angajare());
    nrElem++;
    for (it = angajati.begin(); it < angajati.end(); it++) {
        (*it)->afisare();
        cout << endl;
    }

    return 0;
}