#include "GestiuneComenzi.h"
#include <thread>

int main() {
    /*
    //SETUL 1: introduc 4 angajați (1 + 2 + 1)
    vector<Angajat*> angajati{5};
    angajati[0] = new Manager{"5040529450027", "Duduc", "Dragos", "000000", 29, 5, 2024};
    angajati[1] = new OperatorComenzi{"2910815340028", "Martin", "Razvan", "111111", 10, 10, 2024};
    angajati[2] = new OperatorComenzi{"5030202410129", "Fotin", "Mihnea", "222222", 3, 8, 2024};
    angajati[3] = new Asistent{"6000101460018", "Bacanu", "Alexandru", "444444", 1, 4, 2024};

    // introduc 8 produse (2 + 2 + 2 + 2)
    map<int, pair<Produs*, int>> stoc;

    Produs* newP = new ArticolVestimentar{"Tricou Nirvana", 200, "Nirvana-Merch-Ltd.", "Negru"};
    stoc[newP->getCod()] = make_pair(newP, 2);
    ArticolVestimentar::addArticoleVestimentare(2);

    newP = new CD{"Back-in-Black", 60, "AC/DC", "Compass-Point", Data{25, 7, 1980}};
    stoc[newP->getCod()] = make_pair(newP, 2);
    CD::addCD(2);

    newP = new Vinil{"...And-Justice-for-All", 360, "Metallica", "One-on-One", Data{25, 8, 1988}};
    stoc[newP->getCod()] = make_pair(newP, 2);
    Vinil::addVinil(2);

    newP = new DiscVintage{"Queen-II", 235, true, 5};
    stoc[newP->getCod()] = make_pair(newP, 2);
    DiscVintage::addDiscVintage(2);
    */

    /*
    //SETUL 2: introduc 5 angajați (1 + 3 + 1)
    vector<Angajat*> angajati{5};
    angajati[0] = new Manager{"5040529450027", "Duduc", "Dragos", "000000", 29, 5, 2024};
    angajati[1] = new OperatorComenzi{"2910815340028", "Martin", "Razvan", "111111", 10, 10, 2024};
    angajati[2] = new OperatorComenzi{"5030202410129", "Fotin", "Mihnea", "222222", 3, 8, 2024};
    angajati[3] = new OperatorComenzi{"1880726100196", "Haralambie", "Mihai", "333333", 5, 5, 2024};
    angajati[4] = new Asistent{"6000101460018", "Bacanu", "Alexandru", "444444", 1, 4, 2024};

    // introduc 7 produse (1 + 2 + 2 + 2)
    map<int, pair<Produs*, int>> stoc;

    Produs* newP = new ArticolVestimentar{"Tricou Nirvana", 200, "Nirvana-Merch-Ltd.", "Negru"};
    stoc[newP->getCod()] = make_pair(newP, 1);
    ArticolVestimentar::addArticoleVestimentare(1);

    newP = new CD{"Back-in-Black", 60, "AC/DC", "Compass-Point", Data{25, 7, 1980}};
    stoc[newP->getCod()] = make_pair(newP, 2);
    CD::addCD(2);

    newP = new Vinil{"...And-Justice-for-All", 360, "Metallica", "One-on-One", Data{25, 8, 1988}};
    stoc[newP->getCod()] = make_pair(newP, 2);
    Vinil::addVinil(2);

    newP = new DiscVintage{"Queen-II", 235, true, 5};
    stoc[newP->getCod()] = make_pair(newP, 2);
    DiscVintage::addDiscVintage(2);
    */


    //SETUL 3: introduc 5 angajați (1 + 3 + 1)
    vector<Angajat*> angajati{5};
    angajati[0] = new Manager{"5040529450027", "Duduc", "Dragos", "000000", 29, 5, 2024};
    angajati[1] = new OperatorComenzi{"2910815340028", "Martin", "Razvan", "111111", 10, 10, 2024};
    angajati[2] = new OperatorComenzi{"5030202410129", "Fotin", "Mihnea", "222222", 3, 8, 2024};
    angajati[3] = new OperatorComenzi{"1880726100196", "Haralambie", "Mihai", "333333", 5, 5, 2024};
    angajati[4] = new Asistent{"6000101460018", "Bacanu", "Alexandru", "444444", 1, 4, 2024};

    // introduc 80 produse (20 + 20 + 20 + 20)
    map<int, pair<Produs*, int>> stoc;

    Produs* newP = new ArticolVestimentar{"Tricou Nirvana", 200, "Nirvana-Merch-Ltd.", "Negru"};
    stoc[newP->getCod()] = make_pair(newP, 20);
    ArticolVestimentar::addArticoleVestimentare(20);

    newP = new CD{"Back-in-Black", 60, "AC/DC", "Compass-Point", Data{25, 7, 1980}};
    stoc[newP->getCod()] = make_pair(newP, 20);
    CD::addCD(20);

    newP = new Vinil{"...And-Justice-for-All", 360, "Metallica", "One-on-One", Data{25, 8, 1988}};
    stoc[newP->getCod()] = make_pair(newP, 20);
    Vinil::addVinil(20);

    newP = new DiscVintage{"Queen-II", 235, true, 5};
    stoc[newP->getCod()] = make_pair(newP, 20);
    DiscVintage::addDiscVintage(20);


    GestiuneComenzi gestiuneComenzi(angajati);

    int pagina = 0;
    int optiune;

    while (true) {
        system("cls");

        switch(pagina) {

            case 0: {
                cout << "-----------------------------------------------------------------------PAGINA DE PORNIRE--------------------------------------------------------------------" << endl << endl;
                cout << "   SITUATIE MAGAZIN: Angajati: " << Manager::getNrManager() << " Manageri, " << OperatorComenzi::getNrOperator() << " Operatori comenzi, " << Asistent::getNrAsistent() << " Asistenti | Produse: " << ArticolVestimentar::getNrArticoleVestimentare() << " ART. VEST., " << CD::getNrCDs() << " CD, " << Vinil::getNrVinil() << " VINIL, " << DiscVintage::getNrDiscVintage() << " DISC VIN." << endl;
                if (okAng() && okStoc()) {
                    cout << "                     Magazinul functioneaza corespunzator." << endl << endl << endl << endl << endl << endl << endl;
                    cout << "           Daca sunteti CLIENT, tastati 1 pentru a realiza o comanda." << endl << endl << endl;
                }else {
                    cout << "                     Magazinul NU functioneaza corespunzator." << endl << endl << endl << endl << endl << endl << endl;
                    cout << "           Daca sunteti CLIENT, din pacate nu puteti realiza o comanda. Momentan, magazinul nu functioneaza." << endl << endl << endl;
                }
                cout << "           Daca sunteti ANGAJAT, tastati 2 pentru a accesa setarile magazinului." << endl << endl << endl;
                cout << "           Pentru a parasi aplicatia, tastati 9." << endl << endl << endl;
                for (int i = 0; i < 8; i++)
                    cout << endl;
                cout << "           Actiunea dumneavoastra: ";
                cin >> optiune;

                if (optiune == 1 && (okStoc() && okAng()))
                    pagina = 1;
                else if (optiune == 2)
                    pagina = 2;
                else if (optiune == 9)
                    pagina = 9;
                break;

            }case 1: {
                cout << "-----------------------------------------------------------------------PLASATI O COMANDA--------------------------------------------------------------------" << endl << endl;

                auto it = stoc.begin();
                for (it = stoc.begin(); it != stoc.end(); it++) {
                    cout << "                      ";
                    (*it).second.first->afisare();
                    cout << (*it).second.second << " bucati.";
                    cout << endl << endl;
                }

                vector<pair<Produs*, int>> produseComanda;

                while (true) {
                    cout << endl << endl << "           Introduceti ID-ul produsului dorit (-1 pentru finalizare): ";
                    int idProdus;
                    cin >> idProdus;

                    if(idProdus == -1) {
                        break;
                    }

                    auto it = stoc.find(idProdus);
                    if(it == stoc.end()) {
                        cout << "           Produsul nu exista in stoc!" << endl;
                        continue;
                    }

                    cout << endl << "           Introduceti cantitatea dorita: ";
                    int cantitate;
                    cin >> cantitate;

                    if(cantitate <= 0 || cantitate > it->second.second) {
                        cout << "           Cantitate invalida!" << endl;
                        continue;
                    }

                    produseComanda.push_back({it->second.first, cantitate});
                    modifStocCOMANDA(it, cantitate);
                }

                if (produseComanda.size() > 0) {
                    try {
                        Comanda* comandaNoua = new Comanda(produseComanda);
                        gestiuneComenzi.adaugaComanda(comandaNoua);
                    } catch(const exception& e) {
                        cout << endl << e.what() << endl;
                    }
                } else
                    cout << "           Nu ati introdus niciun produs in comanda." << endl;

                cout << endl << endl << endl << endl << endl << endl << "           Tastati 1 pentru a plasa o noua comanda." << endl;
                cout << endl << endl << "           Tastati 8 pentru a va intoarce la pagina de pornire." << endl;
                cout << endl << endl << "           Tastati 9 pentru a parasi aplicatia." << endl;
                cout << endl << endl << "           Optiunea dumneavoastra: ";
                cin >> optiune;

                if (optiune == 1)
                    break;
                else if (optiune == 8)
                    pagina = 0;
                else if (optiune == 9)
                    pagina = 9;
                break;

            }case 2: {
                cout << "-----------------------------------------------------------------------------LOGIN--------------------------------------------------------------------------" << endl << endl;
                cout << "   Pentru a putea accesa setarile magazinului, trebuie sa va logati in contul de angajat." << endl << endl << endl << endl;
                string user, parola;
                cout << "           Introduceti CNP-ul dumneavoastra: ";
                cin >> user;
                try {
                    isCNPValid(user);
                }catch (const std::exception& e){
                    cout << endl << "           " << e.what();
                    this_thread::sleep_for(chrono::seconds(3));
                    break;
                }
                bool gasit = 0;
                auto it = angajati.begin();
                for (it = angajati.begin(); it != angajati.end() && gasit == 0; it++)
                    if ((*it)->getCNP() == user)
                        gasit = 1;
                if (gasit == 0) {
                    cout << endl << "           CNP-ul dumneavoastra nu a fost gasit in baza de date.";
                    this_thread::sleep_for(chrono::seconds(3));
                    break;
                }
                it--;
                cout << endl << endl << "           Buna ziua, " << (*it)->getNume() << " " << (*it)->getPrenume() << ". Va rog, introduceti parola contului dumneavoastra: ";
                cin >> parola;
                if ((*it)->getParola() != parola) {
                    cout << endl << "           Ati introdus parola gresita.";
                    this_thread::sleep_for(chrono::seconds(3));
                    break;
                }
                pagina = 3;
                break;

            }case 3: {
                cout << "----------------------------------------------------------------------SETARILE MAGAZINULUI------------------------------------------------------------------" << endl << endl;
                cout << endl << endl << endl << endl << endl << endl << endl;
                cout << "           Tastati 1 pentru a interactiona cu angajatii magazinului." << endl << endl << endl;
                cout << "           Tastati 2 pentru a interactiona cu stocul de produse al magazinului." << endl << endl << endl;
                cout << "           Tastati 3 pentru a monitoriza comenzile plasate." << endl << endl << endl;
                cout << "           Tastati 4 pentru a genera o raportare." << endl << endl << endl;
                cout << "           Tastati 8 pentru a va intoarce la pagina de pornire." << endl << endl << endl;
                cout << "           Tastati 9 pentru a parasi aplicatia." << endl << endl << endl;
                for (int i = 0; i < 8; i++)
                    cout << endl;
                cout << "           Actiunea dumneavoastra: ";
                cin >> optiune;

                if (optiune == 8)
                    pagina = 0;
                else if (optiune == 1)
                    pagina = 4;
                else if (optiune == 2)
                    pagina = 10;
                else if (optiune == 3)
                    pagina = 15;
                else if (optiune == 4)
                    pagina = 16;
                else if (optiune == 9)
                    pagina = 9;
                break;

            }case 4: {
                cout << "---------------------------------------------------------------------ANGAJATII MAGAZINULUI------------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                auto it = angajati.begin();
                for (it = angajati.begin(); it != angajati.end(); it++) {
                    cout << "                      ";
                    (*it)->afisare();
                    cout << endl << endl;
                }
                cout << endl << endl << endl;
                cout << "           Tastati 1 pentru a adauga un nou angajat in baza de date a magazinului." << endl << endl << endl;
                cout << "           Tastati 2 pentru a modifica numele unui angajat din baza de date a magazinului." << endl << endl << endl;
                cout << "           Tastati 3 pentru a elimina un angajat din baza de date a magazinului." << endl << endl << endl;
                cout << "           Tastati 4 pentru a calcula salariul unui angajat in luna curenta." << endl << endl << endl;
                cout << "           Tastati 8 pentru a va intoarce la setarile magazinului." << endl << endl << endl;
                cout << "           Tastati 9 pentru a parasi aplicatia." << endl << endl << endl;
                for (int i = 0; i < 4; i++)
                    cout << endl;
                cout << "           Actiunea dumneavoastra: ";
                cin >> optiune;

                if (optiune == 1)
                    pagina = 5;
                else if (optiune == 2)
                    pagina = 6;
                else if (optiune == 3)
                    pagina = 7;
                else if (optiune == 4)
                    pagina = 8;
                else if (optiune == 8)
                    pagina = 3;
                else if (optiune == 9)
                    pagina = 9;
                break;

            }case 5: {
                cout << "----------------------------------------------------------------------ADAUGATI UN ANGAJAT-------------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                cout << "           Introduceti datele candidatului." << endl << endl << endl << endl;;
                angajati.push_back(angajare());
                pagina = 4;
                this_thread::sleep_for(chrono::seconds(3));
                break;

            }case 6: {
                cout << "----------------------------------------------------------------MODIFICATI NUMELE UNUI ANGAJAT--------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                auto it = angajati.begin();
                for (it = angajati.begin(); it != angajati.end(); it++) {
                    cout << "                      ";
                    (*it)->afisare();
                    cout << endl << endl;
                }
                int newID;
                cout << endl << endl << endl << "           Carui angajat doriti sa ii schimbam numele? Introduceti ID-ul acestui angajat: ";
                cin >> newID;
                bool gasit = 0;
                for (it = angajati.begin(); it != angajati.end() && gasit == 0; it++)
                    if ((*it)->getID() == newID)
                        gasit = 1;
                if (gasit == 0) {
                    cout << "           Ati introdus un ID care nu se afla in baza de date.";
                    this_thread::sleep_for(chrono::seconds(3));
                    break;
                }
                it--;
                (*it)->changeName();
                pagina = 4;
                this_thread::sleep_for(chrono::seconds(3));
                break;

            }case 7: {
                cout << "---------------------------------------------------------------------ELIMINATI UN ANGAJAT-------------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                auto it = angajati.begin();
                for (it = angajati.begin(); it != angajati.end(); it++) {
                    cout << "                      ";
                    (*it)->afisare();
                    cout << endl << endl;
                }
                int newID;
                cout << endl << endl << endl << "           Introduceti ID-ul angajatului care se elimina din baza de date: ";
                cin >> newID;
                bool gasit = 0;
                for (it = angajati.begin(); it != angajati.end() && gasit == 0; it++)
                    if ((*it)->getID() == newID)
                        gasit = 1;
                if (gasit == 0) {
                    cout << "           Ati introdus un ID care nu se afla in baza de date.";
                    this_thread::sleep_for(chrono::seconds(3));
                    break;
                }
                it--;
                Angajat::resign(angajati, it);
                pagina = 4;
                this_thread::sleep_for(chrono::seconds(3));
                break;

            }case 8: {
                cout << "---------------------------------------------------------------------SALARIUL ANGAJATILOR-------------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                auto it = angajati.begin();
                for (it = angajati.begin(); it != angajati.end(); it++) {
                    cout << "                      ";
                    (*it)->afisare();
                    cout << endl << endl;
                }
                int newID;
                cout << endl << endl << endl << "           Introduceti ID-ul angajatului al carui salariu doriti sa il aflati: ";
                cin >> newID;
                bool gasit = 0;
                for (it = angajati.begin(); it != angajati.end() && gasit == 0; it++)
                    if ((*it)->getID() == newID)
                        gasit = 1;
                if (gasit == 0) {
                    cout << "           Ati introdus un ID care nu se afla in baza de date.";
                    this_thread::sleep_for(chrono::seconds(3));
                    break;
                }
                it--;
                Data crt;
                cout << endl << endl << "           Angajatul " << (*it)->getNume() << " " << (*it)->getPrenume() << " are un salariu de " << (*it)->getSalariu() << " RON in luna ";
                switch (crt.getLuna()) {
                    case 1: cout << "ianuarie."; break;
                    case 2: cout << "februarie."; break;
                    case 3: cout << "martie."; break;
                    case 4: cout << "aprilie."; break;
                    case 5: cout << "mai."; break;
                    case 6: cout << "iunie."; break;
                    case 7: cout << "iulie."; break;
                    case 8: cout << "august."; break;
                    case 9: cout << "septembrie."; break;
                    case 10: cout << "octombrie."; break;
                    case 11: cout << "noiembrie."; break;
                    case 12: cout << "decembrie."; break;
                }
                pagina = 4;
                this_thread::sleep_for(chrono::seconds(3));
                break;

            }case 9: {
                for (int i = 0; i < 20; i++)
                    cout << endl;

                cout << "------------------------------------------------Va multumim pentru vizita si va mai asteptam la ROCK the SHOP!----------------------------------------------";
                this_thread::sleep_for(chrono::seconds(3));
                return 0;

            }case 10: {
                cout << "----------------------------------------------------------------------STOCUL MAGAZINULUI--------------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                auto it = stoc.begin();
                for (it = stoc.begin(); it != stoc.end(); it++) {
                    cout << "                      ";
                    (*it).second.first->afisare();
                    cout << (*it).second.second << " bucati.";
                    cout << endl << endl;
                }
                cout << endl << endl << endl;
                cout << "           Tastati 1 pentru a adauga un nou produs in baza de date a magazinului." << endl << endl << endl;
                cout << "           Tastati 2 pentru a modifica cantitatea unui produs din baza de date a magazinului." << endl << endl << endl;
                cout << "           Tastati 3 pentru a elimina un produs din baza de date a magazinului." << endl << endl << endl;
                cout << "           Tastati 4 pentru a calcula pretul unui produs din baza de date a magazinului." << endl << endl << endl;
                cout << "           Tastati 8 pentru a va intoarce la setarile magazinului." << endl << endl << endl;
                cout << "           Tastati 9 pentru a parasi aplicatia." << endl << endl << endl;
                for (int i = 0; i < 4; i++)
                    cout << endl;
                cout << "           Actiunea dumneavoastra: ";
                cin >> optiune;

                if (optiune == 1)
                    pagina = 11;
                else if (optiune == 2)
                    pagina = 12;
                else if (optiune == 3)
                    pagina = 13;
                else if (optiune == 4)
                    pagina = 14;
                else if (optiune == 8)
                    pagina = 3;
                else if (optiune == 9)
                    pagina = 9;
                break;

            }case 11: {
                cout << "----------------------------------------------------------------------ADAUGATI UN PRODUS--------------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                adaugareProdus(stoc);
                pagina = 10;
                this_thread::sleep_for(chrono::seconds(3));
                break;

            }case 12: {
                cout << "---------------------------------------------------------------MODIFICATI CANTITATEA UNUI PRODUS------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                bool modificat = modifStoc(stoc);
                if (modificat == 0) {
                    this_thread::sleep_for(chrono::seconds(3));
                    break;
                }
                pagina = 10;
                this_thread::sleep_for(chrono::seconds(3));
                break;

            }case 13: {
                cout << "----------------------------------------------------------------------ELIMINATI UN PRODUS-------------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                bool sters = stergeStoc(stoc);
                if (sters == 0) {
                    this_thread::sleep_for(chrono::seconds(3));
                    break;
                }
                pagina = 10;
                this_thread::sleep_for(chrono::seconds(3));
                break;

            }case 14: {
                cout << "----------------------------------------------------------------------PRETUL UNUI PRODUS--------------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                bool afisat = preturiStoc(stoc);
                if (afisat == 0) {
                    this_thread::sleep_for(chrono::seconds(3));
                    break;
                }
                pagina = 10;
                this_thread::sleep_for(chrono::seconds(5));
                break;

            }case 15: {
                cout << "---------------------------------------------------------------------MONITORIZARE COMENZI-------------------------------------------------------------------" << endl << endl;

                gestiuneComenzi.actualizeazaStareComenzi();

                cout << "           COMENZI IN PROCESARE:" << endl;
                if(gestiuneComenzi.getNrActive() > 0) {
                    for(auto it = gestiuneComenzi.getComenziActive().begin(); it != gestiuneComenzi.getComenziActive().end(); it++) {
                        cout << "                                 Comanda #" << (*it)->getId() << endl;
                        cout << "                                 Operator: " << (*it)->getOperator()->getNume() << " " << (*it)->getOperator()->getPrenume() << endl;
                        cout << "                                 Timp ramas: " << (*it)->timpRamas() << " secunde" << endl;
                        cout << "                                 Valoare totala: " << (*it)->getValoare() << " RON" << endl << endl;
                    }
                } else
                    cout << "                                 Nu exista comenzi in curs de procesare." << endl << endl;

                cout << "           COMENZI IN ASTEPTARE:" << endl;
                if(gestiuneComenzi.getNrAsteptare() > 0) {
                    for(auto it = gestiuneComenzi.getComenziAsteptare().begin(); it != gestiuneComenzi.getComenziAsteptare().end(); it++) {
                        cout << "                                 Comanda #" << (*it)->getId() << endl;
                        cout << "                                 Valoare totala: " << (*it)->getValoare() << " RON" << endl;
                        cout << "                                 Status: Asteapta operator disponibil" << endl << endl;
                    }
                } else
                    cout << "                                 Nu exista comenzi in asteptare." << endl << endl;

                cout << "           COMENZI FINALIZATE:" << endl;
                if(gestiuneComenzi.getNrFinalizate() > 0) {
                    auto comenziFinalizate = gestiuneComenzi.getComenziFinalizate();
                    for(auto it = comenziFinalizate.begin(); it != comenziFinalizate.end(); ++it) {
                        cout << "                                 Comanda #" << (*it)->getId() << endl;
                        cout << "                                 Procesata de: " << (*it)->getOperator()->getNume() << " " << (*it)->getOperator()->getPrenume() << endl;
                        cout << "                                 Valoare totala: " << (*it)->getValoare() << " RON" << endl << endl;
                    }
                } else
                    cout << "                                 Nu exista comenzi finalizate." << endl << endl;

                cout << "           STATUS OPERATORI:" << endl;
                gestiuneComenzi.afiseazaStatusOperatori();

                cout << endl << endl << endl << endl;
                cout << "           Tastati 7 pentru a reimprospata pagina." << endl << endl;
                cout << "           Tastati 8 pentru a va intoarce la pagina anterioara." << endl << endl;
                cout << "           Tastati 9 pentru a parasi aplicatia." << endl << endl << endl << endl;
                cout << "           Optiunea dumneavoastra: ";
                cin >> optiune;

                if(optiune == 7)
                    break;
                else if(optiune == 8)
                    pagina = 3;
                else if(optiune == 9)
                    pagina = 9;
                break;

            }case 16: {
                cout << "---------------------------------------------------------------------RAPORTARI------------------------------------------------------------------" << endl << endl;
                cout << endl << endl;
                cout << "           Tastati 1 pentru a genera angajatul cu cele mai multe comenzi procesate." << endl << endl << endl;
                cout << "           Tastati 2 pentru a genera top 3 angajati care au gestionat cele mai valoroase comenzi." << endl << endl << endl;
                cout << "           Tastati 3 pentru a genera top 3 angajati cu cel mai mare salariu." << endl << endl << endl;
                cout << "           Tastati 8 pentru a va intoarce la setarile magazinului." << endl << endl << endl;
                cout << "           Tastati 9 pentru a parasi aplicatia." << endl << endl << endl;
                for (int i = 0; i < 4; i++)
                    cout << endl;
                cout << "           Actiunea dumneavoastra: ";
                cin >> optiune;

                if (optiune == 1) {
                    gestiuneComenzi.genereazaRaportComenziProcesate();
                    for (int i = 0; i < 5; i++)
                        cout << endl;
                    cout << "           S-a generat cu succes raportul 'nr_comenzi_max.csv'." << endl;
                    pagina = 16;
                    this_thread::sleep_for(chrono::seconds(3));
                }
                if (optiune == 2) {
                    gestiuneComenzi.genereazaRaportValoareComenzi();
                    for (int i = 0; i < 5; i++)
                        cout << endl;
                    cout << "           S-a generat cu succes raportul 'top3ang_val_comenzi.csv'." << endl;
                    pagina = 16;
                    this_thread::sleep_for(chrono::seconds(3));
                }
                if (optiune == 3) {
                    gestiuneComenzi.genereazaRaportSalarii();
                    for (int i = 0; i < 5; i++)
                        cout << endl;
                    cout << "           S-a generat cu succes raportul 'top3_salarii.csv'." << endl;
                    pagina = 16;
                    this_thread::sleep_for(chrono::seconds(3));
                }
                else if (optiune == 8)
                    pagina = 3;
                else if (optiune == 9)
                    pagina = 9;
                break;
            }
        }
    }
}