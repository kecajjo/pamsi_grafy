#ifndef ELEMENT_M_HH
#define ELEMENT_M_HH

#include "lista_2_kier.hh"

// wierzcholek wykorzystywany w reprezentacji grafu za pomoca macierzy sasiedztwa
template<typename typ>
struct wierzcholek_m{
    int indeks; // indeks w macierzy
    element_2_kier< wierzcholek_m<typ> > *miejsce_na_liscie; // wskazuje na miejsce na liscie, ktore zajmuje wierzcholek
    typ nazwa; // nazwa wierzolka, albo element, ktory zawiera, np. 23, abc
    wierzcholek_m();
    wierzcholek_m(typ nowa_nazwa);
    bool operator ==(wierzcholek_m<typ> por){if(this->nazwa == por.nazwa){return true;} return false;}
    bool operator >(wierzcholek_m<typ> por){if(this->nazwa > por.nazwa){return true;} return false;}
    bool operator >=(wierzcholek_m<typ> por){if(this->nazwa >= por.nazwa){return true;} return false;}
    bool operator <(wierzcholek_m<typ> por){if(this->nazwa < por.nazwa){return true;} return false;}
    bool operator <=(wierzcholek_m<typ> por){if(this->nazwa <= por.nazwa){return true;} return false;}
};

// krawedz wykorzystywana w reprezentacji grafu za pomoca macierzy sasiedztwa
template <typename kraw, typename wierzch>
struct krawedz_m{
    element_2_kier< krawedz_m<kraw, wierzch> > *miejsce_na_liscie; // wskazuje na miejsce na liscie, ktore zajmuje krawedz
    kraw nazwa; // nazwa krawedzi albo element, ktory zawiera, np. 23, abc, 7.9
    wierzcholek_m<wierzch> *wierzcholki[2];
    krawedz_m();
    krawedz_m(kraw nowa_nazwa);
    bool operator ==(krawedz_m<kraw, wierzch> por){if(this->nazwa == por.nazwa){return true;} return false;}
    bool operator >(krawedz_m<kraw, wierzch> por){if(this->nazwa > por.nazwa){return true;} return false;}
    bool operator >=(krawedz_m<kraw, wierzch> por){if(this->nazwa >= por.nazwa){return true;} return false;}
    bool operator <(krawedz_m<kraw, wierzch> por){if(this->nazwa < por.nazwa){return true;} return false;}
    bool operator <=(krawedz_m<kraw, wierzch> por){if(this->nazwa <= por.nazwa){return true;} return false;}

};

template<typename typ>
wierzcholek_m<typ>::wierzcholek_m(){
    this->miejsce_na_liscie = nullptr;
    this->indeks = -1; // oznacza brak indeksu
}

template<typename typ>
wierzcholek_m<typ>::wierzcholek_m(typ nowa_nazwa){
    this->miejsce_na_liscie = nullptr;
    this->indeks = -1; // oznacza brak indeksu
    this->nazwa = nowa_nazwa;
}

template<typename kraw, typename wierzch>
krawedz_m<kraw, wierzch>::krawedz_m(){
    this->miejsce_na_liscie = nullptr;
    this->wierzcholki[0] = nullptr;
    this->wierzcholki[1] = nullptr;
}

template<typename kraw, typename wierzch>
krawedz_m<kraw, wierzch>::krawedz_m(kraw nowa_nazwa){
    this->miejsce_na_liscie = nullptr;
    this->nazwa = nowa_nazwa;
    this->wierzcholki[0] = nullptr;
    this->wierzcholki[1] = nullptr;
}

#endif