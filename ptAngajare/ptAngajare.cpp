#include "ptAngajare.h"

// funcție de angajare
Angajat* angajare() {

    // se verifică, în primul rând, dacă CNP-ul persoanei este valid și dacă persoana a împlinit 18 ani
    bool ok = 0;
    string CNP;
    while (ok == 0) {
        cout << "           CNP: ";
        cin >> CNP;
        try {
            ok = isCNPValid(CNP);
        }
        catch (std::exception& e) {
            cout << "           " << e.what() << endl;
        }
    }

    // se verifică dacă numele este valid și se formatează
    cout << endl << endl;
    ok = 0;
    string nume;
    while (ok == 0) {
        cout << "           Nume: ";
        cin >> nume;
        try {
            ok = isNameValid(nume);
        }
        catch (std::exception& e) {
            cout << "           " << e.what() << endl;
        }
    }
    nume = formatName(nume);

    // se verifică dacă prenumele este valid și se formatează
    cout << endl << endl;
    ok = 0;
    string prenume;
    while (ok == 0) {
        cout << "           Prenume: ";
        cin >> prenume;
        try {
            ok = isNameValid(prenume);
        }
        catch (std::exception& e) {
            cout << "           " << e.what() << endl;
        }
    }
    prenume = formatName(prenume);

    // se citește parola contului angajatului
    cout << endl << endl;
    ok = 0;
    string parola;
    while (ok == 0) {
        cout << "           Parola contului de angajat: ";
        cin >> parola;
        try {
            ok = isPasswordValid(parola);
        }
        catch (std::exception& e) {
            cout << "           " << e.what() << endl;
        }
    }

    // se verifică dacă data este validă
    cout << endl << endl;
    ok = 0;
    int zi, luna, an;
    while (ok == 0) {
        cout << "           Ziua, luna si anul angajarii: ";
        cin >> zi >> luna >> an;
        Data dataAng{zi, luna, an};
        try {
            ok = dataAng.isDateValid();
        }
        catch (std::exception& e) {
            cout << "           " << e.what() << endl;
        }
    }

    // se stabilește tipul angajatului
    cout << endl << endl;
    ok = 0;
    int tip;
    while (ok == 0) {
        cout << "           Tipul angajatului (1-Manager, 2-Operator comenzi, 3-Asistent): ";
        cin >> tip;
        if (tip < 1 || tip > 3)
            cout << "           Tip inexistent." << endl << endl;
        else
            ok = 1;
    }

    cout << endl << endl;
    cout << "           Felicitari! " << nume << " " << prenume << " a fost angajat(a) cu succes.";

    // se creează obiectul dorit
    switch (tip) {
        case 1:
            return new Manager(CNP, nume, prenume, parola, zi, luna, an);
        case 2:
            return new OperatorComenzi(CNP, nume, prenume, parola, zi, luna, an);
        case 3:
            return new Asistent(CNP, nume, prenume, parola, zi, luna, an);
        default:
            cout << "A aparut o eroare in evaluarea tipului de angajat." << endl;
            return nullptr;
    }
}

// se verifică numărul și tipul angajaților, folosit în interfață la asigurarea că magazinul functionează corect
bool okAng() {
    if (Manager::getNrManager() >= 1 && OperatorComenzi::getNrOperator() >= 3 && Asistent::getNrAsistent() >= 1)
        return true;
    return false;
}