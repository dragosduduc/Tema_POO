#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <chrono>
using namespace std;

class Data {
    int zi, luna, an;
public:
    Data();
    Data(int, int, int);

    int getZi() const;
    int getLuna() const;
    int getAn() const;
    void setZi(int);
    void setLuna(int);
    void setAn(int);

    bool isDateValid();
    Data getTimeGap() const;

    friend ostream& operator<<(ostream&, const Data&);



};

#endif //DATA_H
