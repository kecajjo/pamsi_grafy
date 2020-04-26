#ifndef WEKTOR_CPP
#define WEKTOR_CPP

#include "inc/wektor.hh"

template <typename typ>
wektor<typ>::wektor(){
    this->pojemnosc = 1;
    this->rozmiar = 0;
    this->tablica = new typ[this->pojemnosc];
}

template <typename typ>
wektor<typ>::wektor(typ do_dodania){
    this->pojemnosc = 2;
    this->rozmiar = 1;
    this->tablica = new typ[this->pojemnosc];
    this->tablica[0] = do_dodania;
}

template <typename typ>
wektor<typ>::~wektor(){
    delete [] this->tablica;
}

template <typename typ>
void wektor<typ>::dodaj(typ dodano){
    if(this->pojemnosc<this->rozmiar+2){ // jesli wektor bedzie za maly
        this->pojemnosc *=2;
        typ *pomocnicza = new typ[this->pojemnosc];
        for(int i=0;i<rozmiar;i++){ // przepisuje do mniejszej tablicy
            pomocnicza[i] = this->tablica[i];
        }
        delete [] this->tablica;
        this->tablica = pomocnicza;
    }
    this->tablica[this->rozmiar] = dodano;
    this->rozmiar++;
}

template <typename typ>
void wektor<typ>::usun(){
    if(rozmiar>0){
        if(this->pojemnosc>2*(this->rozmiar+2)){ //jesli wektor bedzie za duzy
            this->pojemnosc /= 2;
            typ *pomocnicza = new typ[this->pojemnosc];
            for(int i=0;i<rozmiar;i++){ // przepisuje do mniejszej tablicy
                pomocnicza[i] = this->tablica[i];
            }
            delete [] this->tablica;
            this->tablica = pomocnicza;
        }
        this->rozmiar--;
    } else{
        std::cout << "proba usuniecia elementu z pustego wektora" << std::endl;
    }
}

template <typename typ>
void wektor<typ>::usun(int indeks){
    if(rozmiar>indeks){
        if(this->pojemnosc>2*this->rozmiar){ // jesli wektor bedzie za duzy
            this->pojemnosc /= 2;
            typ *pomocnicza = new typ[this->pojemnosc];
            for(int i=0;i<rozmiar;i++){ // przepisuje do mniejszej tablicy
                pomocnicza[i] = this->tablica[i];
            }
            delete [] this->tablica;
            this->tablica = pomocnicza;
        }
        this->rozmiar--;
        for(int i=indeks;i<rozmiar;i++){
            this->tablica[i] = tablica[i+1];
        }
    } else{
        std::cout << "proba usuniecia elementu spoza tablicy" << std::endl;
    }
}

template<typename typ>
void wektor<typ>::wyczysc(){
    this->pojemnosc = 1;
    this->rozmiar = 0;
    delete [] this->tablica;
    this->tablica = new typ[1];
}

template<typename typ>
typ wektor<typ>::operator[](int indeks) const{
    if(indeks<rozmiar){
        return this->tablica[indeks];
    }
    // w razie proby odwolania do nieistniejacego elementu zwraca pierwszy element
    std::cout << "nie ma takiego elementu, zwrocono pierwszy element" << std::endl;
    return this->tablica[0];
}

template<typename typ>
typ& wektor<typ>::operator[](int indeks){
    if(indeks<rozmiar){
        return this->tablica[indeks];
    }
    // w razie proby odwolania do nieistniejacego elementu zwraca pierwszy element
    std::cout << "nie ma takiego elementu, zwrocono pierwszy element" << std::endl;
    return this->tablica[0];
}

#endif