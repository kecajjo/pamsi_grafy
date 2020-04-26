#ifndef GRAF_M_HH
#define GRAF_M_HH

#include "lista_2_kier.hh"
#include "element_m.hh"

// graf realizowany za pomoca macierzy sasiedztwa
template<typename kraw, typename wierzch>
class mac_sasiedztwa{
    lista_2_kier< wierzcholek_m<wierzch> > lista_wierzcholkow; // lista wierzcholkow grafu
    lista_2_kier< krawedz_m<kraw, wierzch> > lista_krawedzi; // lista krawedzi grafu
    krawedz_m<kraw, wierzch> ***macierz; // wskaznik na dwuwymiarowa tablice wskaznikow

    public:
    mac_sasiedztwa();
    void dodaj_wierzcholek(wierzch nazwa); // dodaje wierzcholek o nazwie
    void dodaj_krawedz(wierzcholek_m<wierzch> *wierzch1, wierzcholek_m<wierzch> *wierzch2, kraw nazwa_kraw); // dodaj krawedz o nazwie
    void usun_wierzcholek(wierzcholek_m<wierzch> *do_usuniecia); // usuwa wierzcholek i przylegajace krawedzie
    void usun_krawedz(krawedz_m<kraw, wierzch> *do_usuniecia);
    void zamien(wierzcholek_m<wierzch> *wierzcholek, wierzch nowa_nazwa);
    void zamien(krawedz_m<kraw, wierzch> *krawedz, kraw nowa_nazwa);
    wierzcholek_m<wierzch> **koncowki_krawedzi(krawedz_m<kraw, wierzch> *krawedz); // zwraca wskaznik na tablice wierzcholkow krawedzi
    wierzcholek_m<wierzch> *przeciwlegly_wierzch(wierzcholek_m<wierzch> *moj_wierzcholek, krawedz_m<kraw, wierzch> *krawedz);
    bool czy_sasiednie(wierzcholek_m<wierzch> *wierzch1, wierzcholek_m<wierzch> *wierzch2);
    lista_2_kier< wierzcholek_m<wierzch> > *wierzcholki(){return &this->lista_wierzcholkow;}
    lista_2_kier< krawedz_m<kraw, wierzch> > *krawedzie(){return &this->lista_krawedzi;}
    krawedz_m<kraw, wierzch> **przylegle_krawedzie(wierzcholek_m<wierzch> *wierzcholek); // zwraca wskaznik na wiersz w macierzy

};

template <typename kraw, typename wierzch>
std::ostream& operator << (std::ostream &strm, mac_sasiedztwa<kraw, wierzch> graf);

template <typename kraw, typename wierzch>
std::istream& operator >> (std::istream &strm, mac_sasiedztwa<kraw, wierzch> &graf);

#include "../graf_m.cpp"

#endif