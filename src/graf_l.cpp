#ifndef GRAF_L_CPP
#define GRAF_L_CPP

#include "inc/graf_l.hh"

template <typename kraw, typename wierzch>
lista_sasiedztwa<kraw, wierzch>::~lista_sasiedztwa(){
    while(this->lista_wierzcholkow.czy_pusta() == false){
        this->usun_wierzcholek(lista_wierzcholkow.pierwszy()->wartosc);
    }
}

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
    wskaznik_na_krawedz->krawedzie_wierzcholka[0] = wierzch1->krawedzie->ostatni(); // przypisuje wskaznik na pozycje na liscie krawedzi wierzcholka
    wskaznik_na_krawedz->krawedzie_wierzcholka[1] = wierzch2->krawedzie->ostatni(); // przypisuje wskaznik na pozycje na liscie krawedzi wierzcholka
}

template <typename kraw, typename wierzch>
void lista_sasiedztwa<kraw, wierzch>::usun_wierzcholek(wierzcholek_l<kraw, wierzch>* do_usuniecia){
    typename lista_2_kier< krawedz_l<kraw, wierzch>* >::iterator it = do_usuniecia->krawedzie;
    lista_2_kier< krawedz_l<kraw, wierzch>* > *lst_kraw_wierzch = this->przylegle_krawedzie(do_usuniecia);
    while(lst_kraw_wierzch->czy_pusta() == false){ // konczy dzialanie petli gdy lista krawedzi wierzcholka bedzie pusta
        this->usun_krawedz(*(it.zwroc_elem()->wartosc)); // usuwa aktualny element z listy
        it.poczatek(); // za kazdym razem usuwamy pierwszy element
    }
    delete do_usuniecia->krawedzie; // usuwa liste krawedzi werzcholka po oproznieniu jej
    this->lista_wierzcholkow.usun_element(do_usuniecia->miejsce_na_liscie);
}

template <typename kraw, typename wierzch>
void lista_sasiedztwa<kraw, wierzch>::usun_krawedz(krawedz_l<kraw, wierzch>* do_usuniecia){

    // usuwa wskazniki na krawedz z listy wskaznikow na krawedzie wierzcholka
    do_usuniecia->wierzcholki[0]->krawedzie->usun_element(do_usuniecia->krawedzie_wierzcholka[0]);
    do_usuniecia->wierzcholki[1]->krawedzie->usun_element(do_usuniecia->krawedzie_wierzcholka[1]);
    this->lista_krawedzi.usun_element(do_usuniecia->miejsce_na_liscie);
}

template <typename kraw, typename wierzch>
void lista_sasiedztwa<kraw, wierzch>::zamien(wierzcholek_l<kraw, wierzch> *wierzcholek, wierzch nowa_nazwa){
    wierzcholek->nazwa = nowa_nazwa;
}

template <typename kraw, typename wierzch>
void lista_sasiedztwa<kraw, wierzch>::zamien(krawedz_l<kraw, wierzch> *krawedz, kraw nowa_nazwa){
    krawedz->nazwa = nowa_nazwa;
}

template <typename kraw, typename wierzch>
wierzcholek_l<kraw, wierzch> **lista_sasiedztwa<kraw, wierzch>::koncowki_krawedzi(krawedz_l<kraw, wierzch> *krawedz){
    return krawedz->wierzcholki;
}

template <typename kraw, typename wierzch>
wierzcholek_l<kraw, wierzch> *lista_sasiedztwa<kraw, wierzch>::przeciwlegly_wierzch(wierzcholek_l<kraw, wierzch> *moj_wierzcholek, krawedz_l<kraw, wierzch> *krawedz){
    if(krawedz->wierzcholki[0] == moj_wierzcholek){
        return krawedz->wierzcholki[1]; // jesli podano wierzcholek 0 zwroci wskaznik na wierzcholek 1
    }
    if(krawedz->wierzcholki[1] == moj_wierzcholek){
        return krawedz->wierzcholki[0]; // jesli podano wierzcholek 1 zwroci wskaznik na wierzcholek 0
    }
    std::cout << "podany wierzcholek nie nalezy do wskazanej krawedzi" << std::endl;
    return nullptr; // jesli podano wierzcholek, ktory nie nalezy do krawedzi zwroci nullptr
}

template <typename kraw, typename wierzch>
bool lista_sasiedztwa<kraw, wierzch>::czy_sasiednie(wierzcholek_l<kraw,wierzch> *wierzch1, wierzcholek_l<kraw, wierzch> *wierzch2){
    int rozmiar = wierzch1->krawedzie->rozmiar();
    typename lista_2_kier< krawedz_l<kraw, wierzch> *>::iterator it = wierzch1->krawedzie;
    
    // petla przeszukuje liste krawedzi danego wierzcholka
    for(int i=0;i<rozmiar;i++){
        krawedz_l<kraw, wierzch> *pomocnicza = *(it.zwroc_elem()->wartosc);
        // jesli drugi wierzcholek jest w tablicy wierzcholkow krawedzi nastepne 2 IFy to wykryja
        if(pomocnicza->wierzcholki[0] == wierzch2){
            return true;
        }
        if(pomocnicza->wierzcholki[1] == wierzch2){ 
            return true;
        }
    }
    // jesli wierzcholki nie maja wspolnej krawedzi lub drugi wierzcholek nie istnieje zwraca false
    return false;
}

template <typename kraw, typename wierzch>
lista_2_kier< krawedz_l<kraw, wierzch> *> *lista_sasiedztwa<kraw, wierzch>::przylegle_krawedzie(wierzcholek_l<kraw, wierzch> *wierzcholek){
    return wierzcholek->krawedzie;
}

template <typename kraw, typename wierzch>
std::ostream& operator << (std::ostream &strm, lista_sasiedztwa<kraw, wierzch> graf){
    strm << graf.krawedzie()->rozmiar() << "\t" 
        << graf.wierzcholki()->rozmiar() << "\t"
        << graf.wierzcholki()->pierwszy()->wartosc->nazwa << std::endl;

    typename lista_2_kier< krawedz_l<kraw, wierzch> >::iterator it = graf.krawedzie();
    krawedz_l<kraw, wierzch> krawedz;

    for(int i=0;i<graf.krawedzie()->rozmiar();i++){
        krawedz = *(it.wartosc());
        strm << krawedz.wierzcholki[0]->nazwa << "\t"
            << krawedz.wierzcholki[1]->nazwa << "\t"
            << krawedz.nazwa << std::endl;
        it++;
    }
    return strm;
}

template <typename kraw, typename wierzch>
std::istream& operator >> (std::istream &strm, lista_sasiedztwa<kraw, wierzch> &graf){
    int ilosc_krawedzi;
    int ilosc_wierzcholkow;
    wierzch startowy;

    strm >> ilosc_krawedzi;
    strm >> ilosc_wierzcholkow;
    strm >> startowy;
    
    wierzch nazwa_w1;
    wierzch nazwa_w2;
    kraw nazwa_k;

    typename lista_2_kier< wierzcholek_l<kraw, wierzch> >::iterator it = graf.wierzcholki();

 /*    element_2_kier< wierzcholek_m<wierzch> > elem_w1;
    element_2_kier< wierzcholek_m<wierzch> > elem_w2;
    element_2_kier< krawedz_m<kraw, wierzch> > elem_k; */

    wierzcholek_l<kraw, wierzch> w1;
    wierzcholek_l<kraw, wierzch> w2;

    wierzcholek_l<kraw, wierzch> *wsk_w1;
    wierzcholek_l<kraw, wierzch> *wsk_w2;
    wsk_w1 = &w1;
    wsk_w2 = &w2;


    graf.dodaj_wierzcholek(startowy);
    for(int i=0;i<ilosc_krawedzi;i++){
        strm >> nazwa_w1;
        w1.nazwa = nazwa_w1;
        if(it.przeszukaj(w1) != nullptr){ // jesli istnieje wierzcholek o podanej nazwie
            wsk_w1 = it.przeszukaj(w1)->wartosc; //wskazuje na juz istniejacy wierzcholek o podanej nazwie
        } else{ // jesli wierzcholek nie istnieje, dodaje go
            graf.dodaj_wierzcholek(nazwa_w1);
            wsk_w1 = it.wartosc(graf.wierzcholki()->rozmiar()-1); // wskaznik na dodany wierzcholek
        }
        strm >> nazwa_w2;
        w2.nazwa = nazwa_w2;
        if(it.przeszukaj(w2) != nullptr){ // jesli istnieje wierzcholek o podanej nazwie
            wsk_w2 = it.przeszukaj(w2)->wartosc; //wskazuje na juz istniejacy wierzcholek o podanej nazwie
        } else{ // jesli wierzcholek nie istnieje, dodaje go
            graf.dodaj_wierzcholek(nazwa_w2);
            wsk_w2 = it.wartosc(graf.wierzcholki()->rozmiar()-1); // wskaznik na dodany wierzcholek
        }
        strm >> nazwa_k;
        graf.dodaj_krawedz(wsk_w1, wsk_w2, nazwa_k);
    }

    if(graf.wierzcholki()->rozmiar() != ilosc_wierzcholkow){
        std::cout << "ILOSC WIERZCHOLKOW ROZNA OD ZADEKLAROWANEJ PRZEZ UZYTKOWNIKA" << std::endl;
    }

    return strm;

}

#endif