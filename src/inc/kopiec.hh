#ifndef KOPIEC_HH
#define KOPIEC_HH

#include "wektor.hh"
#include <climits>

template <typename typ>
struct para{
    typ nazwa;
    int priorytet;
    para(){this->nazwa = static_cast<typ>(0);this->priorytet = INT_MAX;}
    para(typ nowa_nazwa){this->nazwa = nowa_nazwa;this->priorytet = INT_MAX;}
    bool operator ==(para<typ> por){if(this->priorytet == por.priorytet){return true;} return false;}
    bool operator >(para<typ> por){if(this->priorytet > por.priorytet){return true;} return false;}
    bool operator >=(para<typ> por){if(this->priorytet >= por.priorytet){return true;} return false;}
    bool operator <(para<typ> por){if(this->priorytet < por.priorytet){return true;} return false;}
    bool operator <=(para<typ> por){if(this->priorytet <= por.priorytet){return true;} return false;}
};

// kolejka na kopcu, posiadajaca najmniejszy element w korzeniu
template <typename typ>
class kopiec{

    wektor< para<typ> > kolejka;
    void podmien(para<typ> *pierwszy, para<typ> *drugi);
    void napraw_kopiec_po_usunieciu();
    void napraw_kopiec_po_dodaniu();

    public:
    void dodaj(typ do_dodania, int priorytet); // dodaje element do kolejki
    para<typ> sciagnij(); // zwraca i usuwa najmniejszy element
    para<typ> pokaz_najmniejszy(); // zwraca najmniejszy element bez usuwania go
    int rozmiar();
    bool czy_pusta();
    //int zmien_priorytet(para<typ> *element, int nowy_priorytet); // wymaga osobnego przechowywania indeksow

};
#include "../kopiec.cpp"

#endif