#ifndef GRAF_M_CPP
#define GRAF_M_CPP

#include "inc/graf_m.hh"


template <typename kraw, typename wierzch>
mac_sasiedztwa<kraw, wierzch>::mac_sasiedztwa(){
    this->macierz = nullptr;
}

template <typename kraw, typename wierzch>
void mac_sasiedztwa<kraw, wierzch>::dodaj_wierzcholek(wierzch nazwa){
    int wielkosc = this->lista_wierzcholkow.rozmiar();
    if(this->lista_wierzcholkow.czy_pusta() == false){ // jesli graf ma jakis wierzcholek
        krawedz_m<kraw, wierzch> ***pomocnicza = new krawedz_m<kraw, wierzch>** [wielkosc+1];
        for(int i=0;i<wielkosc+1;i++){
            pomocnicza[i] = new krawedz_m<kraw, wierzch>* [wielkosc+1];
        }
        // przepisuje stara tablice do nowej
        for(int i=0;i<wielkosc;i++){
            for(int j=0;j<wielkosc;j++){
                pomocnicza[i][j] = this->macierz[i][j];
            }
            pomocnicza[i][wielkosc] = nullptr; // w ostatniej kolumnie nie ma krawedzi, wiec ma wszedzie nullptr
        }
        // ostatni wiersz jest wypelniony nullptr
        // poniewaz nowy wierzcholek nie ma krawedzi
        for(int i=0;i<wielkosc+1;i++){
            pomocnicza[wielkosc][i] = nullptr;
        }
        // usuniecie tablicy dwuwymiarowej
        for(int i=0;i<wielkosc;i++){
            delete [] this->macierz[i];
        }
        delete [] this->macierz;
        // przypisanie do macierzy nowej tablicy
        this->macierz = pomocnicza;
    } else{ // jesli nie bylo zadnego wierzcholka
        // tworzy dynamiczna dwuwymiarowa tablice wskaznikow 1x1 i przypisuje jej nullptr
        this->macierz = new krawedz_m<kraw, wierzch>** [1];
        this->macierz[0] = new krawedz_m<kraw,wierzch>* [1];
        this->macierz[0][0] = nullptr;
    }
    wierzcholek_m<wierzch> nowy_wierzcholek(nazwa); // tworzy wierzcholek o podanej nazwie
    // wpisuje indeks do wierzcholka
    // indeksy od 0 (wielkosc to rozmiar przed dodaniem)
    nowy_wierzcholek.indeks = wielkosc;
    this->lista_wierzcholkow.dodaj_na_koniec(nowy_wierzcholek); // dodaje wierzcholek na koniec listy wierzcholkow
    // dodaje do nowego wierzcholka jego adres na liscie
    this->lista_wierzcholkow.ostatni()->wartosc->miejsce_na_liscie = this->lista_wierzcholkow.ostatni();
}

template <typename kraw, typename wierzch>
void mac_sasiedztwa<kraw, wierzch>::dodaj_krawedz(wierzcholek_m<wierzch> *wierzch1, wierzcholek_m<wierzch> *wierzch2, kraw nazwa_kraw){
    krawedz_m<kraw,wierzch> nowa_krawedz(nazwa_kraw);
    nowa_krawedz.wierzcholki[0] = wierzch1; // wskaznik na 1 wierzcholek
    nowa_krawedz.wierzcholki[1] = wierzch2; // wskaznik na 2gi wierzcholek
    this->lista_krawedzi.dodaj_na_koniec(nowa_krawedz);
    this->lista_krawedzi.ostatni()->wartosc->miejsce_na_liscie = this->lista_krawedzi.ostatni();
    
    // wpisuje do macierzy wskaznik na krawedz w odpowiednich miejscach
    int indeks1 = wierzch1->indeks;
    int indeks2 = wierzch2->indeks;
    this->macierz[indeks1][indeks2] = this->lista_krawedzi.ostatni()->wartosc;
    this->macierz[indeks2][indeks1] = this->lista_krawedzi.ostatni()->wartosc;
}

template <typename kraw, typename wierzch>
void mac_sasiedztwa<kraw, wierzch>::usun_wierzcholek(wierzcholek_m<wierzch> *do_usuniecia){
    

    int indeks = do_usuniecia->indeks;
    int rozmiar = this->lista_wierzcholkow.rozmiar();
    for(int i=0;i<rozmiar;i++){
        if(this->macierz[indeks][i] != nullptr){
            usun_krawedz(macierz[indeks][i]);
        }
    }

    if(rozmiar>1){ // jesli mamy conajmniej 2 wierzcholki
        // tworzy mniejsza tablice do ktorej beda przepisane wierzcholki
        krawedz_m<kraw, wierzch> ***pomocnicza = new krawedz_m<kraw, wierzch>** [rozmiar-1];
        for(int i=0;i<rozmiar-1;i++){
            pomocnicza[i] = new krawedz_m<kraw, wierzch>* [rozmiar-1];
        }

        // przepisuje macierz do pomocniczej bez odpowiedniego wiersza
        for(int i=0;i<rozmiar-1;i++){
            if(i<indeks){
                for(int j=0;j<rozmiar-1;j++){
                    if(j<indeks){
                        pomocnicza[i][j] = this->macierz[i][j];
                    } else{ // pomijamy usuwana kolumne
                        pomocnicza[i][j] = this->macierz[i][j+1];
                    }
                }
            } else{ // pomijamy odpowiedni wiersz
                for(int j=0;j<rozmiar-1;j++){
                    if(j<indeks){
                        pomocnicza[i][j] = this->macierz[i+1][j];
                    } else{
                        pomocnicza[i][j] = this->macierz[i+1][j+1]; // pomijamy usuwana kolumne
                    }
                }
            }
        }
        // usuwamy stara tablice i wskazujemy macierza na nowa
        for(int i=0;i<rozmiar;i++){
            delete [] this->macierz[i];
        }
        delete [] this->macierz;
        this->macierz = pomocnicza;
    } else{ //jesli usuwamy jedyny wierzcholek
        delete [] this->macierz[0];
        delete [] this->macierz;
        this->macierz = nullptr;
    }

    // usuwa wierzcholek z listy wierzcholkow
    this->lista_wierzcholkow.usun_element(do_usuniecia->miejsce_na_liscie);

    // nadanie od nowa indeksow wierzcholkom
    typename lista_2_kier< wierzcholek_m<wierzch> >::iterator it = &this->lista_wierzcholkow;
    rozmiar = this->lista_wierzcholkow.rozmiar();
    for(int i=indeks;i<rozmiar;i++){ // zaczynamy od indeksu wierzcholka, ktory usunelismy
        it.iteruj(indeks);
        it.wartosc()->indeks = indeks;
        it++;
    }
}

template <typename kraw, typename wierzch>
void mac_sasiedztwa<kraw, wierzch>::usun_krawedz(krawedz_m<kraw,wierzch> *do_usuniecia){
    

    int indeks1 = do_usuniecia->wierzcholki[0]->indeks;
    int indeks2 = do_usuniecia->wierzcholki[1]->indeks;
    this->macierz[indeks1][indeks2] = nullptr;
    this->macierz[indeks2][indeks1] = nullptr;
    this->lista_krawedzi.usun_element(do_usuniecia->miejsce_na_liscie);
}

template <typename kraw, typename wierzch>
void mac_sasiedztwa<kraw, wierzch>::zamien(wierzcholek_m<wierzch> *wierzcholek, wierzch nowa_nazwa){
    wierzcholek->nazwa = nowa_nazwa;
}

template <typename kraw, typename wierzch>
void mac_sasiedztwa<kraw, wierzch>::zamien(krawedz_m<kraw, wierzch> *krawedz, kraw nowa_nazwa){
    krawedz->nazwa = nowa_nazwa;
}

template <typename kraw, typename wierzch>
wierzcholek_m<wierzch> **mac_sasiedztwa<kraw, wierzch>::koncowki_krawedzi(krawedz_m<kraw, wierzch> *krawedz){
    return krawedz->wierzcholki;
}

template <typename kraw, typename wierzch>
wierzcholek_m<wierzch> *mac_sasiedztwa<kraw, wierzch>::przeciwlegly_wierzch(wierzcholek_m<wierzch> *moj_wierzcholek, krawedz_m<kraw, wierzch> *krawedz){
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
bool mac_sasiedztwa<kraw, wierzch>::czy_sasiednie(wierzcholek_m<wierzch> *wierzch1, wierzcholek_m<wierzch> *wierzch2){
    int indeks1 = wierzch1->indeks;
    int indeks2 = wierzch2->indeks;
    if(this->macierz[indeks1][indeks2] != nullptr){
        return true; // zwraca true jesli wierzcholki maja wspolna krawedz
    }
    return false; // zwraca false, jesli wierzcholki nie maja wspolnej krawedzi
}

template <typename kraw, typename wierzch>
krawedz_m<kraw, wierzch> **mac_sasiedztwa<kraw, wierzch>::przylegle_krawedzie(wierzcholek_m<wierzch> *wierzcholek){
    int indeks = wierzcholek->indeks;
    return this->macierz[indeks];
}

template <typename kraw, typename wierzch>
std::ostream& operator << (std::ostream &strm, mac_sasiedztwa<kraw, wierzch> graf){
    strm << graf.krawedzie()->rozmiar() << "\t" 
        << graf.wierzcholki()->rozmiar() << "\t"
        << graf.wierzcholki()->pierwszy()->wartosc->nazwa << std::endl;

    typename lista_2_kier< krawedz_m<kraw, wierzch> >::iterator it = graf.krawedzie();
    krawedz_m<kraw, wierzch> krawedz;

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
std::istream& operator >> (std::istream &strm, mac_sasiedztwa<kraw, wierzch> &graf){
    int ilosc_krawedzi;
    int ilosc_wierzcholkow;
    wierzch startowy;

    strm >> ilosc_krawedzi;
    strm >> ilosc_wierzcholkow;
    strm >> startowy;
    
    wierzch nazwa_w1;
    wierzch nazwa_w2;
    kraw nazwa_k;

    typename lista_2_kier< wierzcholek_m<wierzch> >::iterator it = graf.wierzcholki();

 /*    element_2_kier< wierzcholek_m<wierzch> > elem_w1;
    element_2_kier< wierzcholek_m<wierzch> > elem_w2;
    element_2_kier< krawedz_m<kraw, wierzch> > elem_k; */

    wierzcholek_m<wierzch> w1;
    wierzcholek_m<wierzch> w2;

    wierzcholek_m<wierzch> *wsk_w1;
    wierzcholek_m<wierzch> *wsk_w2;
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