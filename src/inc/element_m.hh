#ifndef ELEMENT_M_HH
#define ELEMENT_M_HH

#include "lista_2_kier.hh"

// wierzcholek wykorzystywany w reprezentacji grafu za pomoca macierzy sasiedztwa
template<typename typ>
struct wierzcholek_m{
    int indeks; // indeks w macierzy
    element_2_kier< wierzcholek_m<typ> > *miejsce_na_liscie; // wskazuje na miejsce na liscie, ktore zajmuje wierzcholek
    typ *nazwa; // wskaznik na nazwe wierzolka, albo element, ktory zawiera, np. 23, abc
    wierzcholek_m();
    wierzcholek_m(typ nowa_nazwa);
};

// krawedz wykorzystywana w reprezentacji grafu za pomoca macierzy sasiedztwa
template <typename kraw, typename wierzch>
struct krawedz_m{
    element_2_kier< krawedz_m<kraw, wierzch> > *miejsce_na_liscie; // wskazuje na miejsce na liscie, ktore zajmuje krawedz
    kraw *nazwa; // wskaznik na nazwe krawedzi albo element, ktory zawiera, np. 23, abc, 7.9
    wierzcholek_m<wierzch> *wierzcholki[2];
    krawedz_m();
    krawedz_m(kraw nowa_nazwa);
};

template<typename typ>
wierzcholek_m<typ>::wierzcholek_m(){
    miejsce_na_liscie = nullptr;
    indeks = -1; // oznacza brak indeksu
    nazwa = nullptr;
}

template<typename typ>
wierzcholek_m<typ>::wierzcholek_m(typ nowa_nazwa){
    miejsce_na_liscie = nullptr;
    indeks = -1; // oznacza brak indeksu
    nazwa = new typ (nowa_nazwa);
}

template<typename kraw, typename wierzch>
krawedz_m<kraw, wierzch>::krawedz_m(){
    this->miejsce_na_liscie = nullptr;
    this->nazwa = nullptr;
    this->wierzcholki[0] = nullptr;
    this->wierzcholki[1] = nullptr;
}

template<typename kraw, typename wierzch>
krawedz_m<kraw, wierzch>::krawedz_m(kraw nowa_nazwa){
    this->miejsce_na_liscie = nullptr;
    kraw *moja_nazwa = new kraw (nowa_nazwa);
    this->nazwa = moja_nazwa;
    this->wierzcholki[0] = nullptr;
    this->wierzcholki[1] = nullptr;
}

#endif