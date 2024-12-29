#include "ptAngajare.h"
#include "ptStoc.h"
#include <thread>


int main() {
    // introduc 5 angajați (1 + 3 + 1)
    vector<Angajat*> angajati{5};
    angajati[0] = new Manager{"5040529450027", "Duduc", "Dragos", 29, 5, 2024};
    angajati[1] = new OperatorComenzi{"5040529450027", "Martin", "Razvan", 10, 10, 2024};
    angajati[2] = new OperatorComenzi{"5040529450027", "Fotin", "Mihnea", 3, 8, 2024};
    angajati[3] = new OperatorComenzi{"5040529450027", "Haralambie", "Mihai", 5, 5, 2024};
    angajati[4] = new Asistent{"5040529450027", "Bacanu", "Alexandru", 1, 4, 2024};

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

    int pagina = 0;
    int optiune;

    while (true) {
        system("cls");

        switch(pagina) {

            case 0:
                cout << "----------------------------------------------------------------------PAGINA DE PORNIRE---------------------------------------------------------------------" << endl << endl;
                cout << "   SITUATIE MAGAZIN: Angajati: " << Manager::getNrManager() << " Manageri, " << OperatorComenzi::getNrOperator() << " Operatori comenzi, " << Asistent::getNrAsistent() << " Asistenti | Produse: " << ArticolVestimentar::getNrArticoleVestimentare() << " Articole Vestimentare, " << CD::getNrCDs() << " CD-uri, " << Vinil::getNrVinil() << " Viniluri, " << DiscVintage::getNrDiscVintage() << " Disc-uri Vintage." << endl;
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

                if (optiune == 1 && (okStoc() && okAng())) pagina = 1;
                else if (optiune == 2) pagina = 2;
                else if (optiune == 9) pagina = 9;
                break;

            case 1:
                cout << "-----------------------------------------------------------------------PLASATI O COMANDA--------------------------------------------------------------------" << endl << endl;
                cout << "Apasati 1 pentru a va intoarce." << endl;
                cout << "Pentru a parasi aplicatie, tastati 9." << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune;

                if (optiune == 1) pagina = 0;
                else if (optiune == 9) pagina = 9;
                break;

            case 2:
                cout << "----------------------------------------------------------------------SETARILE MAGAZINULUI------------------------------------------------------------------" << endl << endl;
                cout << "Apasati 1 pentru a va intoarce." << endl;
                cout << "Pentru a parasi aplicatie, tastati 9." << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune;

                if (optiune == 1) pagina = 0;
                else if (optiune == 9) pagina = 9;
                break;

            case 9:
                for (int i = 0; i < 20; i++)
                    cout << endl;

            cout << "------------------------------------------------Va multumim pentru vizita si va mai asteptam la ROCK the SHOP!----------------------------------------------";
            this_thread::sleep_for(chrono::seconds(4));
            return 0;
        }
    }
}