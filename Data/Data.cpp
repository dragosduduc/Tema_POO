#include "Data.h"

Data::Data() {
    auto now = chrono::system_clock::now();
    auto time = chrono::system_clock::to_time_t(now);
    auto local_time = *localtime(&time);
    zi = local_time.tm_mday;
    luna = local_time.tm_mon + 1;
    an = local_time.tm_year + 1900;
}

Data::Data(int z, int l, int a): zi{z}, luna{l}, an{a} {};

int Data::getZi() const {
    return zi;
}
int Data::getLuna() const {
    return luna;
}
int Data::getAn() const {
    return an;
}
void Data::setZi(int z) {
    zi = z;
}
void Data::setLuna(int l) {
    luna = l;
}
void Data::setAn(int a) {
    an = a;
}

// validarea datei
bool Data::isDateValid() {

    // data curentă
    Data crt;

    // se verifică dacă data furnizată este reală și că nu este în viitor
    if (an < 1800 || an > crt.an)
        throw std::invalid_argument("Anul este invalid.\n");
    if ((an == crt.an && luna > crt.luna) || luna <= 0 || luna > 12)
        throw std::invalid_argument("Luna este invalida.\n");
    if ((an == crt.an && luna == crt.luna && zi > crt.zi) || zi <= 0 || zi > 31)
        throw std::invalid_argument("Ziua este invalida.\n");

    // se verifică specific dacă ziua dată se potrivește cu luna dată
    int zileValide[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((an % 4 == 0 && an % 100 != 0) || an % 400 == 0)
        zileValide[1] = 29;
    if (zi > zileValide[luna - 1])
        throw std::invalid_argument("Ziua este invalida.\n");

    // dacă data a trecut de aceste verificări, înseamnă că este validă
    return true;
}

// calcularea timpului trecut de la momentul dat prin argument până la momentul prezent
Data Data::getTimeGap() const {

    Data crt;
    if (an > crt.an || (an == crt.an && luna > crt.luna) || (an == crt.an && luna == crt.luna && zi > crt.zi))
        throw std::invalid_argument("Momentul de timp furnizat este in viitor.\n");

    Data dif{0, 0, 0};
    dif.an = crt.an - an;
    dif.luna = crt.luna - luna;
    dif.zi = crt.zi - zi;

    if (dif.zi < 0) {
        dif.zi += 30;
        dif.luna--;
    }

    if (dif.luna < 0) {
        dif.luna += 12;
        dif.an--;
    }

    return dif;
}

ostream& operator<<(ostream& dev, const Data& data) {
    dev << data.zi << " " << data.luna << " " << data.an;
    return dev;
}