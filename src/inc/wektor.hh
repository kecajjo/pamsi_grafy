#ifndef WEKTOR_HH
#define WEKTOR_HH

template <typename typ>
class wektor{
    unsigned int pojemnosc;
    unsigned int rozmiar;
    typ *tablica; // wskaznik na tablice

    public:
    void dodaj(typ);
    void usun_ostatni();
    void usun_element(int miejsce);
    void wyczysc();
    //TODO przeciazenia [ ]
};

#include "../wektor.cpp"

#endif