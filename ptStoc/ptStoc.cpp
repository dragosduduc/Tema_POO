#include "ptStoc.h"

void adaugareProdus(map<int, pair<Produs*, int>>& vect) {

    // obiectul care se adaugă în map
    Produs* newP;

    // se stabilește tipul produsului adaugat in stoc (cu verificare)
    int tip;
    bool ok = 0;
    while (ok == 0) {
        cout << "Ce produs doriti sa adaugati in stoc? (1-Articol Vestimentar, 2-CD, 3-Vinil, 4-Disc Vintage): ";
        cin >> tip;
        try{
            ok = isTypeValid(tip);
        } catch (const std::invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    // se citesc datele tipului respectiv de angajat
    if (tip == 1) {
        cout << "Veti introduce informatiile pentru un articol vestimentar." << endl;

        string nume;
        cout << endl << "Numele articolului vestimentar: ";
        cin >> nume;

        float pret;
        cout << "Pretul de baza al articolului vestimentar: ";
        cin >> pret;

        string brand;
        cout << "Marca articolului vestimentar: ";
        cin >> brand;

        string culoare;
        cout << "Culoarea articolului vestimentar: ";
        cin >> culoare;

        int nr;
        ok = 0;
        while (ok == 0) {
            cout << "Numarul de astfel de articole vestimentare care se adauga in stoc: ";
            cin >> nr;
            try {
                ok = isNumberPositive(nr);
            } catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        // adaugăm în map perechea, unde cheia este codul obiectului
        newP = new ArticolVestimentar{nume, pret, brand, culoare};
        vect[newP->getCod()] = make_pair(newP, nr);
        cout << "Ati adaugat cu succes " << nr << " obiecte de tip ArticolVestimentar." << endl;

    } else if (tip == 2) {
        cout << "Veti introduce informatiile pentru un CD." << endl;

        string nume;
        cout << endl << "Numele CD-ului: ";
        cin >> nume;

        float pret;
        cout << "Pretul de baza al CD-ului: ";
        cin >> pret;

        string band;
        cout << "Trupa care a compus CD-ul: ";
        cin >> band;

        string recordLabel;
        cout << "Casa de discuri care a realizat CD-ul: ";
        cin >> recordLabel;

        int zi, luna, an;
        ok = 0;
        Data lansare;
        while (ok == 0) {
            cout << "Data la care a fost lansat CD-ul: ";
            cin >> zi >> luna >> an;
            lansare.setZi(zi);
            lansare.setLuna(luna);
            lansare.setAn(an);
            try {
                ok = lansare.isDateValid();
            }catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        int nr;
        ok = 0;
        while (ok == 0) {
            cout << "Numarul de astfel de CD-uri care se adauga in stoc: ";
            cin >> nr;
            try {
                ok = isNumberPositive(nr);
            } catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        // adaugăm în map perechea, unde cheia este codul obiectului
        newP = new CD{nume, pret, band, recordLabel, lansare};
        vect[newP->getCod()] = make_pair(newP, nr);
        cout << "Ati adaugat cu succes " << nr << " obiecte de tip CD." << endl;

    } else if (tip == 3) {
        cout << "Veti introduce informatiile pentru un Vinil." << endl;

        string nume;
        cout << endl << "Numele Vinilului: ";
        cin >> nume;

        float pret;
        cout << "Pretul de baza al Vinilului: ";
        cin >> pret;

        string band;
        cout << "Trupa care a compus Vinilul: ";
        cin >> band;

        string recordLabel;
        cout << "Casa de discuri care a realizat Vinilul: ";
        cin >> recordLabel;

        int zi, luna, an;
        ok = 0;
        Data lansare;
        while (ok == 0) {
            cout << "Data la care a fost lansat Vinilul: ";
            cin >> zi >> luna >> an;
            lansare.setZi(zi);
            lansare.setLuna(luna);
            lansare.setAn(an);
            try {
                ok = lansare.isDateValid();
            }catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        int nr;
        ok = 0;
        while (ok == 0) {
            cout << "Numarul de astfel de Viniluri care se adauga in stoc: ";
            cin >> nr;
            try {
                ok = isNumberPositive(nr);
            } catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        // adaugăm în map perechea, unde cheia este codul obiectului
        newP = new Vinil{nume, pret, band, recordLabel, lansare};
        vect[newP->getCod()] = make_pair(newP, nr);
        cout << "Ati adaugat cu succes " << nr << " obiecte de tip Vinil." << endl;

    } else if (tip == 4) {
        cout << "Veti introduce informatiile pentru un Disc Vintage." << endl;

        string nume;
        cout << endl << "Numele Disc-ului Vintage: ";
        cin >> nume;

        float pret;
        cout << "Pretul de baza al Disc-ului Vintage: ";
        cin >> pret;

        bool mint;
        cout << "Disc-ului Vintage este mint? (Da - 1/true, Nu - 0/false: ";
        cin >> mint;

        int rarity;
        ok = 0;
        while (ok == 0) {
            cout << "Coeficientul de raritate al Disc-ului Vintage (un intreg intre 1 si 5): ";
            cin >> rarity;
            try {
                ok = isRarityValid(rarity);
            } catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        int nr;
        ok = 0;
        while (ok == 0) {
            cout << "Numarul de astfel de Disc-uri Vintage care se adauga in stoc: ";
            cin >> nr;
            try {
                ok = isNumberPositive(nr);
            } catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        // adaugăm în map perechea, unde cheia este codul obiectului
        newP = new DiscVintage{nume, pret, mint, rarity};
        vect[newP->getCod()] = make_pair(newP, nr);
        cout << "Ati adaugat cu succes " << nr << " obiecte de tip DiscVintage." << endl;
    }
}

// se modifica stocul unui produs aflat deja în catalogul magazinului
void modifStoc(map<int, pair<Produs*, int>>& vect) {
    cout << "Al carui produs doriti sa modificati stocul?" << endl;

    // se afișează toate produsele din catalog, pentru ca utilizatorul să aleagă al cărui produs dorește să îi modifice stocul
    map<int, pair<Produs*, int>>::iterator it = vect.begin();
    for (it = vect.begin(); it != vect.end(); it++) {
        (*it).second.first->afisare();
        cout << " ";
        cout << (*it).second.second;
        cout << endl;
    }

    // se introduce codul produsului dorit
    cout << endl;
    int key;
    cin >> key;

    // se introduce canditatea cu care se modifică stocul
    cout << "Cum doriti sa modificati cantitatea? (pentru a introduce 'n' bucati tastati n, pentru a elimina 'n' bucati tastati -n." << endl;
    int delta;
    cin >> delta;

    // se caută cheia (codul produsului) în map și se modifică int-ul din pair (second.second)
    it = vect.find(key);
    if (it != vect.end())
        if ((*it).second.second + delta >= 0) {
            (*it).second.second += delta;
            cout << "Stoc actualizat cu succes." << endl;
        } else
            cout << "Nu exista suficiente produse in stoc." << endl;
    else
        cout << "Nu exista niciun produs cu acest cod." << endl;
}