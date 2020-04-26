#ifndef ELEMENT_L_HH
#define ELEMENT_L_HH

#include "lista_2_kier.hh"

template <typename kraw, typename wierzch> struct krawedz_l;
template <typename kraw, typename wierzch> struct wierzcholek_l;

// wierzcholek wykorzystywany w reprezentacji grafu za pomoca listy sasiedztwa
// musimy znac typ danych jakie przechowuje krawedz i wierzcholek
template <typename kraw, typename wierzch>
struct wierzcholek_l{
    element_2_kier< wierzcholek_l<kraw, wierzch> > *miejsce_na_liscie; // wskazuje na miejsce na liscie, ktore zajmuje wierzcholek
    wierzch nazwa; // nazwa wierzcholka albo element, ktory zawiera, np. 23, abc, 7.9
    lista_2_kier< krawedz_l<kraw, wierzch>* > *krawedzie; // wskazniki na krawedzie wychodzace z wierzcholka
    wierzcholek_l();
    wierzcholek_l(wierzch nowa_nazwa);
    //wierzch operator*() const {return this->nazwa;}
    bool operator ==(wierzcholek_l<kraw, wierzch> por){if(this->nazwa == por.nazwa){return true;} return false;}
    bool operator >(wierzcholek_l<kraw, wierzch> por){if(this->nazwa > por.nazwa){return true;} return false;}
    bool operator >=(wierzcholek_l<kraw, wierzch> por){if(this->nazwa >= por.nazwa){return true;} return false;}
    bool operator <(wierzcholek_l<kraw, wierzch> por){if(this->nazwa < por.nazwa){return true;} return false;}
    bool operator <=(wierzcholek_l<kraw, wierzch> por){if(this->nazwa <= por.nazwa){return true;} return false;}

};

// krawedz wykorzystywana w reprezentacji grafu za pomoca listy sasiedztwa
// musimy znac typ danych jakie przechowuje krawedz i wierzcholek
template <typename kraw, typename wierzch>
struct krawedz_l{
    element_2_kier< krawedz_l<kraw, wierzch> > *miejsce_na_liscie; // wskazuje na miejsce na liscie, ktore zajmuje krawedz
    kraw nazwa; // nazwa krawedzi albo element, ktory zawiera, np. 23, abc, 7.9
    wierzcholek_l<kraw, wierzch> *wierzcholki[2];
    // wskaznik na pozycje wskaznika na krawedz (tego z listy krawedzi danego wierzcholka)
    element_2_kier< krawedz_l<kraw, wierzch>* > *krawedzie_wierzcholka[2];
    krawedz_l();
    krawedz_l(kraw nowa_nazwa);
    //kraw operator*() const{ return this->nazwa;}
    bool operator ==(krawedz_l<kraw, wierzch> por){if(this->nazwa == por.nazwa){return true;} return false;}
    bool operator >(krawedz_l<kraw, wierzch> por){if(this->nazwa > por.nazwa){return true;} return false;}
    bool operator >=(krawedz_l<kraw, wierzch> por){if(this->nazwa >= por.nazwa){return true;} return false;}
    bool operator <(krawedz_l<kraw, wierzch> por){if(this->nazwa < por.nazwa){return true;} return false;}
    bool operator <=(krawedz_l<kraw, wierzch> por){if(this->nazwa <= por.nazwa){return true;} return false;}
};

template <typename kraw, typename wierzch>
wierzcholek_l<kraw, wierzch>::wierzcholek_l(){
    this->krawedzie = new lista_2_kier< krawedz_l<kraw, wierzch>* >; // lista wskaznikow na krawedz
    this->miejsce_na_liscie = nullptr;
}

template <typename kraw, typename wierzch>
wierzcholek_l<kraw, wierzch>::wierzcholek_l(wierzch nowa_nazwa){
    this->krawedzie = new lista_2_kier< krawedz_l<kraw, wierzch>* >; //lista wskaznikow na krawedz
    this->miejsce_na_liscie = nullptr;
    this->nazwa = nowa_nazwa;
}

template <typename kraw, typename wierzch>
krawedz_l<kraw, wierzch>::krawedz_l(){
    this->krawedzie_wierzcholka[0] = nullptr;
    this->krawedzie_wierzcholka[1] = nullptr;
    this->miejsce_na_liscie = nullptr;
    this->wierzcholki[0] = nullptr;
    this->wierzcholki[1] = nullptr;
}

template <typename kraw, typename wierzch>
krawedz_l<kraw, wierzch>::krawedz_l(kraw nowa_nazwa){
    this->krawedzie_wierzcholka[0] = nullptr;
    this->krawedzie_wierzcholka[1] = nullptr;
    this->miejsce_na_liscie = nullptr;
    this->nazwa = nowa_nazwa;
    this->wierzcholki[0] = nullptr;
    this->wierzcholki[1] = nullptr;
}

#endif