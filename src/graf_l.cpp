#ifndef GRAF_L_CPP
#define GRAF_L_CPP

#include "inc/graf_l.hh"

template <typename kraw, typename wierzch>
void lista_sasiedztwa<kraw, wierzch>::dodaj_wierzcholek(wierzch nazwa){
    wierzcholek_l<kraw, wierzch> nowy_wierzcholek(nazwa); // tworzy wierzcholek o nazwie
    this->lista_wierzcholkow.dodaj_na_koniec(nowy_wierzcholek); //dodaje wierzcholek na koniec listy
    // dodaje do nowego wierzcholka jego adres na liscie
    this->lista_wierzcholkow.ostatni()->wartosc->miejsce_na_liscie = this->lista_wierzcholkow.ostatni();
}

template <typename kraw, typename wierzch>
void lista_sasiedztwa<kraw, wierzch>::dodaj_krawedz(wierzcholek_l<kraw, wierzch> *wierzch1, wierzcholek_l<kraw, wierzch> *wierzch2, kraw nazwa_kraw){
    krawedz_l<kraw,wierzch> nowa_krawedz(nazwa_kraw);
    nowa_krawedz.wierzcholki[0] = wierzch1; // wskaznik na 1 wierzcholek
    nowa_krawedz.wierzcholki[1] = wierzch2; // wskaznik na 2gi wierzcholek
    this->lista_krawedzi.dodaj_na_koniec(nowa_krawedz);
    this->lista_krawedzi.ostatni()->wartosc->miejsce_na_liscie = this->lista_krawedzi.ostatni();
    // dodaje krawedz do listy wskaznikow na krawedzie na ktora wskazuje wierzcholek
    krawedz_l<kraw, wierzch> *wskaznik_na_krawedz = this->lista_krawedzi.ostatni()->wartosc;
    wskaznik_na_krawedz->wierzcholki[0]->krawedzie->dodaj_na_koniec(wskaznik_na_krawedz);
    wskaznik_na_krawedz->wierzcholki[1]->krawedzie->dodaj_na_koniec(wskaznik_na_krawedz);
    wskaznik_na_krawedz->krawedzie_wierzcholka[0] = wierzch1->krawedzie->ostatni(); // przypisuje wskazznik na pozycje na liscie krawedzi wierzcholka
    wskaznik_na_krawedz->krawedzie_wierzcholka[1] = wierzch2->krawedzie->ostatni(); // przypisuje wskazznik na pozycje na liscie krawedzi wierzcholka
}

template <typename kraw, typename wierzch>
void lista_sasiedztwa<kraw, wierzch>::usun_wierzcholek(wierzcholek_l<kraw, wierzch>* do_usuniecia){
    typename lista_2_kier< krawedz_l<kraw, wierzch>* >::iterator it = do_usuniecia->krawedzie;
    while(it.wartosc() != nullptr){
        this->usun_krawedz(*(it.wartosc()->wartosc));
        it++;
    }
}

template <typename kraw, typename wierzch>
void lista_sasiedztwa<kraw, wierzch>::usun_krawedz(krawedz_l<kraw, wierzch>* do_usuniecia){
    delete do_usuniecia->nazwa; // usuwa nazwe/wartosc krawedzi
    // usuwa wskazniki na krawedz z listy wskaznikow na krawedzie wierzcholka
    do_usuniecia->wierzcholki[0]->krawedzie->usun_element(do_usuniecia->krawedzie_wierzcholka[0]);
    do_usuniecia->wierzcholki[1]->krawedzie->usun_element(do_usuniecia->krawedzie_wierzcholka[1]);
    this->lista_krawedzi.usun_element(do_usuniecia->miejsce_na_liscie);
}
#endif