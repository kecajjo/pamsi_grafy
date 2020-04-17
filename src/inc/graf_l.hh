#ifndef GRAF_HH
#define GRAF_HH

#include "lista.hh"
#include "element_l.hh"

// TODO 3ostatnie funkcje z prezentacji (te od iteracji)
// graf realizowany za pomoca listy sasiedztwa
template <typename kraw, typename wierzch>
class lista_sasiedztwa{

    public: // na chwile tylko public pamietac zeby usunac
    lista< wierzcholek_l<kraw, wierzch> > lista_wierzcholkow; // lista wierzcholkow grafu
    lista_2_kier< krawedz_l<kraw, wierzch> > lista_krawedzi; // lista krawedzi grafu dwukierunkowa do szybszego usuwania wierzcholkow

    public:
    wierzcholek_l<kraw, wierzch>* koncowki_krawedzi(krawedz_l<kraw, wierzch>* krawedz); // zwraca wskaznik na 2elementowa tablice wierzcholkow
    wierzcholek_l<kraw, wierzch>* przeciwlegly_wierzch(wierzcholek_l<kraw, wierzch>* moj_wierzcholek, krawedz_l<kraw, wierzch>* krawedz);
    bool czy_sasiednie(wierzcholek_l<kraw, wierzch>* wierzch1, wierzcholek_l<kraw, wierzch>* wierzch2);
    void zamien(wierzcholek_l<kraw, wierzch>* wierzcholek, wierzch nazwa);
    void zamien(krawedz_l<kraw, wierzch>* krawedz, kraw nazwa);
    void dodaj_wierzcholek(wierzch nazwa); // dodaje wierzcholek o nazwie
    void dodaj_krawedz(wierzcholek_l<kraw, wierzch>* wierzch1, wierzcholek_l<kraw, wierzch>* wierzch2, kraw nazwa_kraw); // dodaj krawedz o nazwie
    void usun_wierzcholek(wierzcholek_l<kraw, wierzch>* do_usuniecia); // usuwa wierzcholek i przylegajace krawedzie
    void usun_krawedz(krawedz_l<kraw, wierzch>* do_usuniecia);

};

#include "../graf_l.cpp"

#endif