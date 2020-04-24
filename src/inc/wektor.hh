#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>

template <typename typ>
class wektor{
    int pojemnosc;
    int rozmiar;
    typ *tablica; // wskaznik na tablice

    public:
    wektor();
    wektor(typ do_dodania); // tworzy wektor z jednym elementem o podanej wartosci;
    ~wektor();
    void dodaj(typ dodano);
    void usun();
    void usun(int indeks);
    void wyczysc();
    typ operator[](int indeks) const;
    typ& operator[](int indeks);
    int zwroc_rozmiar(){return this->rozmiar;}
};

#include "../wektor.cpp"

#endif