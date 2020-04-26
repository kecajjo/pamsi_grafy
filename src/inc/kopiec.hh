#ifndef KOPIEC_HH
#define KOPIEC_HH

#include "wektor.hh"

// kolejka na kopcu, posiadajaca najmniejszy element w korzeniu
template <typename typ>
class kopiec{

    wektor<typ> kolejka;
    void podmien(typ *pierwszy, typ *drugi);
    void napraw_kopiec_po_usunieciu();
    void napraw_kopiec_po_dodaniu();

    public:
    void dodaj(typ do_dodania); // dodaje element do kolejki
    typ sciagnij(); // zwraca i usuwa najmniejszy element
    typ pokaz_najmniejszy(); // zwraca najmniejszy element bez usuwania go
    int rozmiar();
    bool czy_pusta();
};
#include "../kopiec.cpp"

#endif