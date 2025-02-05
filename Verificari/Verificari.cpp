#include "Verificari.h"

// validarea numelui
bool isNameValid(string name) {
    int nameSize = name.size();
    // se verifică dacă are lungimea potrivită
    if (nameSize < 3 || nameSize > 30)
        throw std::length_error("Numele trebuie sa aiba lungime de minim 3 si maxim 30 de caractere.\n");

    // se verifică dacă este format doar din litere
    for (int i = 0; i < nameSize; i++)
        if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z'))
            throw std::invalid_argument("Numele trebuie sa contina doar litere.\n");

    // dacă numele a trecut de aceste verificări, inseamnă că este valid
    return true;
}

// validarea CNP-ului
bool isCNPValid(string CNP) {
    int CNPSize = CNP.size();
    // se verifică dacă are lungimea potrivită
    if (CNPSize != 13)
        throw std::length_error("CNP-ul este format din 13 cifre.\n");

    // se verifică dacă este format doar din cifre
    for (int i = 0; i < CNPSize; i++)
        if (CNP[i] < '0' || CNP[i] > '9')
            throw std::invalid_argument("CNP-ul trebuie sa fie valid.\n");

    // se verifică dacă prima cifră (corespunzătoare genului și secolului) este validă
    if (CNP[0] < '1' || CNP[0] > '8')
        throw std::invalid_argument("CNP-ul trebuie sa fie valid.\n");

    // se extrage data nașterii
    int zi_nastere = stoi(CNP.substr(5, 2));
    int luna_nastere = stoi(CNP.substr(3, 2));
    int an_nastere;
    if (CNP[0] == '1' || CNP[0] == '2')
        an_nastere = 1900 + stoi(CNP.substr(1, 2));
    else if (CNP[0] == '3' || CNP[0] == '4')
        an_nastere = 1800 + stoi(CNP.substr(1, 2));
    else
        an_nastere = 2000 + stoi(CNP.substr(1, 2));

    // se verifică dacă persoana a împlinit 18 ani
    Data data_nastere{zi_nastere, luna_nastere, an_nastere};
    if (data_nastere.getTimeGap().getAn() < 18)
        throw std::invalid_argument("Persoana trebuie sa aiba cel putin 18 ani.\n");

    // se verifică dacă luna este validă
    if (luna_nastere < 1 || luna_nastere > 12)
        throw std::invalid_argument("CNP-ul trebuie sa fie valid.\n");

    // se verifică dacă ziua este validă
    int zileValide[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // se verifică dacă anul este bisect
    if ((an_nastere % 4 == 0 && an_nastere % 100 != 0) || an_nastere % 400 == 0)
        zileValide[1] = 29;
    // se verifică dacă ziua este validă
    if (zi_nastere > zileValide[luna_nastere - 1])
        throw std::invalid_argument("CNP-ul trebuie sa fie valid.\n");

    // se verifică dacă cifra de control este validă
    string verif = "279146358279";
    int check = 0;
    for (int i = 0; i < CNPSize - 1; i++)
        check = check + (CNP[i] - '0') * (verif[i] - '0');
    check = check % 11;
    if ((check < 10 && check != (CNP[12] - '0')) || (check == 10 && CNP[12] != '1'))
        throw std::invalid_argument("CNP-ul trebuie sa fie valid.\n");

    // dacă CNP-ul a trecut de aceste verificări, înseamnă că este valid
    return true;
}

// formatarea numelui
string formatName(string name) {
    int nameSize = name.size();
    // primul caracter se schimbă în literă mare
    if (name[0] >= 'a' && name[0] <= 'z')
        name[0] = name[0] - 'a' + 'A';

    // restul caracterelor se schimbă în litere mari
    for (int i = 1; i < nameSize; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z')
            name[i] = name[i] + 'a' - 'A';
    }
    return name;
}

// verificarea tipului de produs
bool isTypeValid(int productType) {
    if (productType < 1 || productType > 4)
        throw std::invalid_argument("Produsul trebuie sa apartina uneia dintre categoriile mentionate mai sus.\n");
    return true;
}

// verificarea numărului de produse introduse in stoc, acesta trebuie să fie natural si diferit de 0
bool isNumberPositive(int number) {
    if (number <= 0)
        throw std::invalid_argument("Numarul de produse adaugate trebuie sa fie un numar natural diferit de 0.\n");
    return true;
}

// verificarea coeficientului de raritate, folosita la citirea unui obiect de tip DiscVintage
bool isRarityValid(int number) {
    if (number < 1 || number > 5)
        throw std::invalid_argument("Coeficientul de raritate are valori intregi de la 1 la 5.\n");
    return true;
}

// verificarea lungimii parolei, folosita la angajare()
bool isPasswordValid(string password) {
    if (password.size() < 6)
        throw std::length_error("Parola trebuie sa aiba minim 6 caractere.\n");
    return true;
}