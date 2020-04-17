#ifndef LISTA_HH
#define LISTA_HH

#include <iostream>

template <typename typ>
struct element {
    typ *wartosc;
    element *nastepny;

    element(){
        wartosc = nullptr;
        nastepny = nullptr;}
    element(typ zmienna){
        wartosc = new typ(zmienna);
        nastepny = nullptr;}
    ~element(){delete wartosc;}

    bool operator ==(element porownywany){
        if(this->wartosc == porownywany->wartosc) return true;
        else return false;}

};

template <typename typ>
class lista {

    element<typ> *pierwszy_element;
    element<typ> *ostatni_element;

    public:
    lista();
    element<typ>* pierwszy(); // zwraca wskaznik na pierwszy element
    element<typ>* ostatni(); // zwraca wskaznik na ostatni element
    unsigned int rozmiar();
    void dodaj_na_poczatek(typ dodaj);
    void dodaj_na_koniec(typ dodaj);
    void usun_pierwszy();
    bool czy_pusta();
    void usun_element(typ odniesienie); // usuwa pierwszy napotkany element na liscie rowny przekazanej zmiennej
    void wyczysc(); // usuwa wszystkie elementy z listy

    class iterator{ // klasa sluzaca do iterowania po liście
        element<typ> *aktualny_element;
        lista<typ> *przypisana_lista;

        public:
        iterator();
        iterator(lista<typ> *moja_lista);
        element<typ>* iteruj(unsigned int numer_elem); // iteruje liste
        element<typ>* iteruj(element<typ> *wskazany_elem, unsigned int numer_elem); // iteruje liste od wskazanego elementu
        element<typ>* operator ++(); // przeciazenie operatora ++
        element<typ>* operator ++(int); // przeciazenie operatora ++
        void operator =(lista<typ> &moja_lista); // przypisanie iteratora do listy
        void operator =(iterator moj_iter); // przypisanie iteratora do innego
        element<typ>* przeszukaj(typ szukany);
        element<typ>* wartosc(); // zwraca wskaznik na aktualny element
        void poczatek(); // iterator jako aktualny element ma 1szy element listy
    };
};

#include "../lista.cpp"

#endif