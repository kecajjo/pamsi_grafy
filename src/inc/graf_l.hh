#ifndef GRAF_L_HH
#define GRAF_L_HH

#include "element_l.hh"
#include "lista_2_kier.hh"

// graf realizowany za pomoca listy sasiedztwa
template <typename kraw, typename wierzch>
class lista_sasiedztwa{

    lista_2_kier< wierzcholek_l<kraw, wierzch> > lista_wierzcholkow; // lista wierzcholkow grafu
    lista_2_kier< krawedz_l<kraw, wierzch> > lista_krawedzi; // lista krawedzi grafu 

    public:
    ~lista_sasiedztwa();
    void dodaj_wierzcholek(wierzch nazwa); // dodaje wierzcholek o nazwie
    void dodaj_krawedz(wierzcholek_l<kraw, wierzch> *wierzch1, wierzcholek_l<kraw, wierzch> *wierzch2, kraw nazwa_kraw); // dodaj krawedz o nazwie
    void usun_wierzcholek(wierzcholek_l<kraw, wierzch> *do_usuniecia); // usuwa wierzcholek i przylegajace krawedzie
    void usun_krawedz(krawedz_l<kraw, wierzch> *do_usuniecia);
    void zamien(wierzcholek_l<kraw, wierzch> *wierzcholek, wierzch nowa_nazwa);
    void zamien(krawedz_l<kraw, wierzch> *krawedz, kraw nowa_nazwa);
    wierzcholek_l<kraw, wierzch> **koncowki_krawedzi(krawedz_l<kraw, wierzch> *krawedz); // zwraca wskaznik na tablice wierzcholkow krawedzi
    wierzcholek_l<kraw, wierzch> *przeciwlegly_wierzch(wierzcholek_l<kraw, wierzch> *moj_wierzcholek, krawedz_l<kraw, wierzch> *krawedz);
    bool czy_sasiednie(wierzcholek_l<kraw, wierzch> *wierzch1, wierzcholek_l<kraw, wierzch> *wierzch2);
    lista_2_kier< wierzcholek_l<kraw, wierzch> > *wierzcholki(){return &this->lista_wierzcholkow;}
    lista_2_kier< krawedz_l<kraw, wierzch> > *krawedzie(){return &this->lista_krawedzi;}
    lista_2_kier< krawedz_l<kraw, wierzch> *> *przylegle_krawedzie(wierzcholek_l<kraw, wierzch> *wierzcholek); // zwraca liste wskaznikow na krawedzie wierzcholka

};

template <typename kraw, typename wierzch>
std::ostream& operator << (std::ostream &strm, lista_sasiedztwa<kraw, wierzch> graf);

template <typename kraw, typename wierzch>
std::istream& operator >> (std::istream &strm, lista_sasiedztwa<kraw, wierzch> &graf);

#include "../graf_l.cpp"

#endif