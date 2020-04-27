#ifndef LISTA_2_KIER_HH
#define LISTA_2_KIER_HH

#include <iostream>
#include <climits>

template <typename typ>
struct element_2_kier {
    element_2_kier *poprzedni;
    typ *wartosc;
    element_2_kier *nastepny;

    element_2_kier(){
        wartosc = nullptr;
        nastepny = nullptr;
        poprzedni = nullptr;}
    element_2_kier(typ zmienna){
        wartosc = new typ(zmienna);
        nastepny = nullptr;
        poprzedni = nullptr;}
    ~element_2_kier(){if(wartosc !=nullptr) delete wartosc;}

    bool operator ==(element_2_kier porownywany){
        if(this->wartosc == porownywany->wartosc) return true;
        else return false;}
    //typ& operator*() const{return this->wartosc;}
};

template <typename typ>
class lista_2_kier {

    element_2_kier<typ> *pierwszy_element;
    element_2_kier<typ> *ostatni_element;

    public:
    lista_2_kier();
/*     element_2_kier<typ>* iteruj(unsigned int iter);
    element_2_kier<typ>* iteruj_od_konca(unsigned int iter); */
    element_2_kier<typ>* pierwszy(); // zwraca wskaznik na pierwszy element_2_kier
    element_2_kier<typ>* ostatni(); // zwraca wskaznik na ostatni eleme
    int rozmiar();
    void dodaj_na_poczatek(typ dodaj);
    void dodaj_na_koniec(typ dodaj);
    void usun_pierwszy();
    void usun_ostatni();
    void usun_element(typ odniesienie); // usuwa pierwszy napotkany element_2_kier na liscie rowny przekazanej zmiennej
    void usun_element(element_2_kier<typ>* do_usuniecia); // usuwa element_2_kier znajac na niego wskaznik
    bool czy_pusta();
    void wyczysc(); // usuwa wszystkie elementy z listy

    class iterator{ // klasa sluzaca do iterowania po liście
        element_2_kier<typ> *aktualny_element;
        lista_2_kier<typ> *przypisana_lista;

        public:
        iterator();
        iterator(lista_2_kier<typ> *moja_lista);
        typ iteruj(unsigned int numer_elem); // iteruje liste
        typ iteruj(element_2_kier<typ> *wskazany_elem, unsigned int numer_elem); // iteruje liste od wskazanego elementu
        typ iteruj_wstecz(unsigned int numer_elem); // iteruje liste wstecz
        typ iteruj_wstecz(element_2_kier<typ> *wskazany_elem, unsigned int numer_elem); // iteruje liste wstecz od wskazanego elementu
        typ operator ++(); // przeciazenie operatora ++
        typ operator ++(int); // przeciazenie operatora ++
        typ operator --(); // przeciazenie operatora ++
        typ operator --(int); // przeciazenie operatora ++
        void operator =(lista_2_kier<typ> &moja_lista); // przypisanie iteratora do listy
        void operator =(iterator moj_iter); // przypisanie iteratora do innego
        element_2_kier<typ>* przeszukaj(typ szukany);// zwraca wskaznik na element lub nullptr, jesli go nie znajdzie
        typ* wartosc(); // zwraca wskaznik na wartosc aktualnego elmentu
        typ* wartosc(int indeks); //zwraca wskaznik na wartosc elementu o podanym indeksie
        element_2_kier<typ>* zwroc_elem(); // zwraca wskaznik na aktualny element_2_kier
        element_2_kier<typ>* zwroc_elem(int indeks); // zwraca wskaznik na element_2_kier o podanym indeksie
        void poczatek(); // iterator jako aktualny element ma 1szy element listy
        void koniec(); // iterator jako aktualny element ma ostatni element listy
        int rozmiar(){return this->przypisana_lista->rozmiar();}
    };

};
#include "../lista_2_kier.cpp"

#endif