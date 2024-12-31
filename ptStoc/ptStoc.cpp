#include "ptStoc.h"

void adaugareProdus(map<int, pair<Produs*, int>>& vect) {

    // obiectul care se adaugă în map
    Produs* newP;

    // se stabilește tipul produsului adaugat in stoc (cu verificare)
    int tip;
    bool ok = 0;
    while (ok == 0) {
        cout << "           Ce produs doriti sa adaugati in stoc? (1-Articol Vestimentar, 2-CD, 3-Vinil, 4-Disc Vintage): ";
        cin >> tip;
        try{
            ok = isTypeValid(tip);
        } catch (const std::invalid_argument& e) {
            cout << "           " << e.what() << endl;
        }
    }

    // se citesc datele tipului respectiv de angajat
    if (tip == 1) {
        cout << endl << "           Veti introduce informatiile pentru un articol vestimentar." << endl << endl;

        string nume;
        cout << endl << endl << "           Nume: ";
        cin >> nume;

        float pret;
        cout << endl << endl << "           Pret de baza: ";
        cin >> pret;

        string brand;
        cout << endl << endl << "           Marca: ";
        cin >> brand;

        string culoare;
        cout << endl << endl << "           Culoare: ";
        cin >> culoare;

        int nr;
        ok = 0;
        while (ok == 0) {
            cout << endl << endl << "           Cantitate: ";
            cin >> nr;
            try {
                ok = isNumberPositive(nr);
            } catch (const std::invalid_argument& e) {
                cout << "           " << e.what() << endl;
            }
        }

        // adaugăm în map perechea, unde cheia este codul obiectului
        newP = new ArticolVestimentar{nume, pret, brand, culoare};
        vect[newP->getCod()] = make_pair(newP, nr);
        ArticolVestimentar::addArticoleVestimentare(nr);
        cout << endl << endl << "           Ati adaugat cu succes " << nr << " obiecte de tip ArticolVestimentar." << endl;

    } else if (tip == 2) {
        cout << endl << "           Veti introduce informatiile pentru un CD." << endl;

        string nume;
        cout << endl << endl << "           Nume: ";
        cin >> nume;

        float pret;
        cout << endl << endl << "           Pret de baza: ";
        cin >> pret;

        string band;
        cout << endl << endl << "           Compozitor: ";
        cin >> band;

        string recordLabel;
        cout << endl << endl << "           Casa de discuri: ";
        cin >> recordLabel;

        int zi, luna, an;
        ok = 0;
        Data lansare;
        while (ok == 0) {
            cout << endl << endl << "           Data de lansare: ";
            cin >> zi >> luna >> an;
            lansare.setZi(zi);
            lansare.setLuna(luna);
            lansare.setAn(an);
            try {
                ok = lansare.isDateValid();
            }catch (const std::invalid_argument& e) {
                cout << "           " << e.what() << endl;
            }
        }

        int nr;
        ok = 0;
        while (ok == 0) {
            cout << endl << endl << "           Cantitate: ";
            cin >> nr;
            try {
                ok = isNumberPositive(nr);
            } catch (const std::invalid_argument& e) {
                cout << "           " << e.what() << endl;
            }
        }

        // adaugăm în map perechea, unde cheia este codul obiectului
        newP = new CD{nume, pret, band, recordLabel, lansare};
        vect[newP->getCod()] = make_pair(newP, nr);
        CD::addCD(nr);
        cout << endl << endl << "           Ati adaugat cu succes " << nr << " obiecte de tip CD." << endl;

    } else if (tip == 3) {
        cout << "           Veti introduce informatiile pentru un Vinil." << endl;

        string nume;
        cout << endl << endl << "           Nume: ";
        cin >> nume;

        float pret;
        cout << endl << endl << "           Pret de baza: ";
        cin >> pret;

        string band;
        cout << endl << endl << "           Compozitor: ";
        cin >> band;

        string recordLabel;
        cout << endl << endl << "           Casa de discuri: ";
        cin >> recordLabel;

        int zi, luna, an;
        ok = 0;
        Data lansare;
        while (ok == 0) {
            cout << endl << endl << "           Data de lansare: ";
            cin >> zi >> luna >> an;
            lansare.setZi(zi);
            lansare.setLuna(luna);
            lansare.setAn(an);
            try {
                ok = lansare.isDateValid();
            }catch (const std::invalid_argument& e) {
                cout << "           " << e.what() << endl;
            }
        }

        int nr;
        ok = 0;
        while (ok == 0) {
            cout << endl << endl << "           Cantitate: ";
            cin >> nr;
            try {
                ok = isNumberPositive(nr);
            } catch (const std::invalid_argument& e) {
                cout << "           " << e.what() << endl;
            }
        }

        // adaugăm în map perechea, unde cheia este codul obiectului
        newP = new Vinil{nume, pret, band, recordLabel, lansare};
        vect[newP->getCod()] = make_pair(newP, nr);
        Vinil::addVinil(nr);
        cout << endl << endl << "           Ati adaugat cu succes " << nr << " obiecte de tip Vinil." << endl;

    } else if (tip == 4) {
        cout << "           Veti introduce informatiile pentru un Disc Vintage." << endl;

        string nume;
        cout << endl << endl << "           Nume: ";
        cin >> nume;

        float pret;
        cout << endl << endl << "           Pret de baza: ";
        cin >> pret;

        bool mint;
        cout << endl << endl << "           Este mint? (Da - 1/true, Nu - 0/false): ";
        cin >> mint;

        int rarity;
        ok = 0;
        while (ok == 0) {
            cout << endl << endl << "           Coeficient de raritate (1 - 5): ";
            cin >> rarity;
            try {
                ok = isRarityValid(rarity);
            } catch (const std::invalid_argument& e) {
                cout << "           " << e.what() << endl;
            }
        }

        int nr;
        ok = 0;
        while (ok == 0) {
            cout << endl << endl << "           Numarul de astfel de Disc-uri Vintage care se adauga in stoc: ";
            cin >> nr;
            try {
                ok = isNumberPositive(nr);
            } catch (const std::invalid_argument& e) {
                cout << "           " << e.what() << endl;
            }
        }

        // adaugăm în map perechea, unde cheia este codul obiectului
        newP = new DiscVintage{nume, pret, mint, rarity};
        vect[newP->getCod()] = make_pair(newP, nr);
        DiscVintage::addDiscVintage(nr);
        cout << endl << endl << "           Ati adaugat cu succes " << nr << " obiecte de tip DiscVintage." << endl;
    }
}

// se modifica stocul unui produs aflat deja în catalogul magazinului
bool modifStoc(map<int, pair<Produs*, int>>& vect) {

    // se afișează toate produsele din catalog, pentru ca utilizatorul să aleagă al cărui produs dorește să îi modifice stocul
    auto it = vect.begin();
    for (it = vect.begin(); it != vect.end(); it++) {
        cout << "                      ";
        (*it).second.first->afisare();
        cout << (*it).second.second << " bucati.";
        cout << endl << endl;
    }

    cout << endl << endl << "           Introduceti ID-ul produsului a carui cantitate doriti sa o modificati: ";

    // se introduce codul produsului dorit
    int key;
    cin >> key;

    // se verifica cheia
    it = vect.find(key);
    if (it == vect.end()) {
        cout << endl << endl << "           Nu exista niciun produs cu acest cod.";
        return 0;
    }

    // se introduce canditatea cu care se modifică stocul
    cout << endl << endl << "           Cate produse se adauga? (pentru a adauga 'n' bucati, tastati n; pentru a elimina 'n' bucati, tastati -n): ";
    int delta;
    cin >> delta;

    // se caută cheia (codul produsului) în map și se modifică int-ul din pair (second.second)
    it = vect.find(key);
    if ((*it).second.second + delta >= 0) {
        (*it).second.second += delta;
        cout << endl << endl << "           Stoc actualizat cu succes!";

        // se modifică variabila statică corespunzătoare
        if (typeid(*((*it).second.first)) == typeid(ArticolVestimentar))
            ArticolVestimentar::addArticoleVestimentare(delta);
        else if (typeid(*((*it).second.first)) == typeid(CD))
            CD::addCD(delta);
        else if (typeid(*((*it).second.first)) == typeid(Vinil))
            Vinil::addVinil(delta);
        else if (typeid(*((*it).second.first)) == typeid(DiscVintage))
            DiscVintage::addDiscVintage(delta);
        return 1;
    }
    cout << endl << endl << "           Nu exista suficiente produse in stoc.";
    return 0;
}

// se modifica stocul unui produs aflat deja în catalogul magazinului IN COMANDA
void modifStocCOMANDA(map<int, pair<Produs*, int>>::iterator it, int quant) {

    // se actualizează cantitatea din pair
    (*it).second.second -= quant;

    // se modifică variabila statică corespunzătoare
    if (typeid(*((*it).second.first)) == typeid(ArticolVestimentar))
        ArticolVestimentar::addArticoleVestimentare(-quant);
    else if (typeid(*((*it).second.first)) == typeid(CD))
        CD::addCD(-quant);
    else if (typeid(*((*it).second.first)) == typeid(Vinil))
        Vinil::addVinil(-quant);
    else if (typeid(*((*it).second.first)) == typeid(DiscVintage))
        DiscVintage::addDiscVintage(-quant);
}

// se verifică numărul și tipul produselor, folosit în interfață la asigurarea că magazinul functionează corect
bool okStoc() {
    if (ArticolVestimentar::getNrArticoleVestimentare() >= 2 && CD::getNrCDs() >= 2 && Vinil::getNrVinil() >= 2 && DiscVintage::getNrDiscVintage() >= 2)
        return true;
    return false;
}

bool stergeStoc(map<int, pair<Produs*, int>>& vect) {

    // se afișează toate produsele din catalog, pentru ca utilizatorul să aleagă ce produs dorește să șteargă
    auto it = vect.begin();
    for (it = vect.begin(); it != vect.end(); it++) {
        cout << "                      ";
        (*it).second.first->afisare();
        cout << (*it).second.second << " bucati.";
        cout << endl << endl;
    }

    cout << endl << endl << "           Introduceti ID-ul produsului pe care doriti sa il eliminati complet din stoc: ";

    // se introduce codul produsului dorit
    int key;
    cin >> key;

    // se verifica cheia
    it = vect.find(key);
    if (it == vect.end()) {
        cout << endl << endl << "           Nu exista niciun produs cu acest ID.";
        return 0;
    }

    // se elibereaza memoria pointer-ului din pair și se șterge elementul din map
    delete (*it).second.first;
    vect.erase(it);

    cout << endl << endl << "           Produsul a fost eliminat cu succes din stoc!";
    return 1;
}

bool preturiStoc(map<int, pair<Produs*, int>>& vect) {

    auto it = vect.begin();
    for (it = vect.begin(); it != vect.end(); it++) {
        cout << "                      ";
        (*it).second.first->afisare();
        cout << (*it).second.second << " bucati.";
        cout << endl << endl;
    }

    cout << endl << endl << "           Introduceti ID-ul produsului pentru care va intereseaza pretul: ";

    // se introduce codul produsului dorit
    int key;
    cin >> key;

    // se verifica cheia
    it = vect.find(key);
    if (it == vect.end()) {
        cout << endl << endl << "           Nu exista niciun produs cu acest ID.";
        return 0;
    }

    // se afișează prețul total
    cout << endl << endl << "           Dupa adaugarea taxelor de impachetare si transport, un produs dintre cele selectate costa " << (*it).second.first->getPretTotal() << " RON.";
    return 1;
}