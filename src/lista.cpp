#ifndef LISTA_CPP
#define LISTA_CPP

#include "inc/lista.hh"

template <typename typ>
lista<typ>::lista(){
    pierwszy_element = nullptr;
    ostatni_element = nullptr;
}

template <typename typ>
element<typ>* lista<typ>::pierwszy(){
    return this->pierwszy_element;
}

template <typename typ>
element<typ>* lista<typ>::ostatni(){
    return this->ostatni_element;
}

template<typename typ>
unsigned int lista<typ>::rozmiar(){
    if(this->czy_pusta() == false){
        unsigned int wielkosc = 1; //lista nie moze byc pusta
        element<typ> *ostatni = this->pierwszy_element;
        while(ostatni->nastepny != nullptr){
            ostatni = ostatni->nastepny;
            ++wielkosc;
        }
        return wielkosc; //zwraca ilosc elementow na liscie
    }
    return 0; // zwraca 0 jesli lista jest pusta
}

template <typename typ>
void lista<typ>::dodaj_na_poczatek(typ dodaj){
    element<typ> *tymczasowe = new element<typ>(dodaj);
    // jesli lista nie jest pusta dodaje element na pierwsze miejsce
    // jesli lista jest pusta pierwszy i ostatni element wskazuja na nowy element
    if(this->czy_pusta() == false){
        tymczasowe->nastepny = this->pierwszy_element;
        this->pierwszy_element = tymczasowe;
    } else{
        this->pierwszy_element = tymczasowe;
        this->ostatni_element = tymczasowe;
    }
}

template <typename typ>
void lista<typ>::dodaj_na_koniec(typ dodaj){
    element<typ> *tymczasowe = new element<typ>(dodaj);
    // jesli lista nie jest pusta dodaje element na ostatnie miejsce
    // jesli lista jest pusta pierwszy i ostatni element wskazuja na nowy element
    if(this->czy_pusta() == false){
        this->ostatni_element->nastepny = tymczasowe;
        this->ostatni_element = tymczasowe;
    } else{
        this->pierwszy_element = tymczasowe;
        this->ostatni_element = tymczasowe;
    }
}

template <typename typ>
void lista<typ>::usun_pierwszy(){
    if(this->czy_pusta() == false){
        element<typ>* tymczasowy;
        tymczasowy = pierwszy_element->nastepny; // tymczasowy zapamietuje adres drugiego elementu
        delete pierwszy_element;
        pierwszy_element = tymczasowy;
    } else{
        std::cout << "nie mozna usunac elementu, lista pusta" << std::endl;
    }
}

template <typename typ>
bool lista<typ>::czy_pusta(){
    if(this->pierwszy_element == nullptr){
        return true; // zwraca true jesli lista jest pusta
    }
    return false; // zwraca false jesli pierwszy element istnieje
}

template <typename typ>
void lista<typ>::usun_element(typ odniesienie){
    if(this->czy_pusta() == false){
        if(*(this->pierwszy_element->wartosc) == odniesienie){ // jesli pierwszy element pasuje usuwa go
            this->usun_pierwszy();
            return; // jesli usunieto element konczy dzialanie funkcji
        } else{
            element<typ>* poprzedzajacy = pierwszy_element; // element przed elementem usuwanym
            element<typ>* do_usuniecia; // ten element bedzie usuwany
            do{
                do_usuniecia = poprzedzajacy->nastepny;
                if(*(do_usuniecia->wartosc) == odniesienie){ // jesli element pasuje do odniesienie usuwa go
                    if(do_usuniecia->nastepny == nullptr){
                        ostatni_element = poprzedzajacy;
                    }
                    poprzedzajacy->nastepny = do_usuniecia->nastepny;
                    delete do_usuniecia;
                    return; // konczy dzialanie funkcji jesli udalo sie usunac element
                }
                poprzedzajacy = poprzedzajacy->nastepny;
            } while(do_usuniecia->nastepny != nullptr);
        }
    }
    std::cout << "nie ma takiego elementu, nic nie usunieto" << std::endl; //jesli nie usunie elementu to wypisze komentarz
}

template <typename typ>
void lista<typ>::wyczysc(){
    if(this->czy_pusta() == false){
        element<typ>* do_usuniecia = this->pierwszy_element;
        element<typ>* kolejny = this->pierwszy_element; // element za elementem usuwanym
        while(do_usuniecia != nullptr){
            kolejny = do_usuniecia->nastepny;
            delete do_usuniecia;
            do_usuniecia = kolejny;
            //std::cout<<"usunieto element"<<std::endl;
        }
        this->pierwszy_element = nullptr;
        this->ostatni_element = nullptr;
    }
}

template <typename typ>
lista<typ>::iterator::iterator(){
    this->aktualny_element = nullptr;
    this->przypisana_lista = nullptr;
}

template <typename typ>
lista<typ>::iterator::iterator(lista<typ> *moja_lista){
    this->aktualny_element = moja_lista->pierwszy(); // przy przypisaniu listy przypisuje jej pierwszy element
    this->przypisana_lista = moja_lista;
}

// numeracja od 0 jak w tablicy
template <typename typ>
element<typ>* lista<typ>::iterator::iteruj(unsigned int numer_elem){
    if(this->przypisana_lista != nullptr){
        if(this->przypisana_lista->czy_pusta() == false){
            element<typ> *wybrany = this->przypisana_lista->pierwszy();
            for(unsigned int i=0;i<numer_elem;i++){
                if (wybrany->nastepny == nullptr){
                    std::cout<<"nie ma takiego elementu"<<std::endl;
                    std::cout<<"zwrocono nullptr"<<std::endl;
                    return nullptr; //w razie przekroczenia zakresu zwraca nullptr
                }
                wybrany = wybrany->nastepny;
            }
            return wybrany; // jesli lista nie bedzie pusta zwroci adres elementu
        }
        std::cout << "lista pusta, zwrocono nulptr" << std::endl;
        return nullptr; // w razie pustej listy zwraca nullptr
    }
    std::cout << "nie przypisano listy, zwrocono nullptr" << std::endl;
    return nullptr;
}

template<typename typ>
element<typ>* lista<typ>::iterator::iteruj(element<typ> *wskazany_elem, unsigned int numer_elem){
    element<typ> *wybrany;
    wybrany = wskazany_elem;
    for(unsigned int i=0;i<numer_elem;i++){
        if (wybrany->nastepny == nullptr){
            std::cout<<"nie ma takiego elementu"<<std::endl;
            std::cout<<"zwrocono nullptr"<<std::endl;
            return nullptr; //w razie przekroczenia zakresu zwraca nullptr
        }
        wybrany = wybrany->nastepny;
    }
    return wybrany;
}

template <typename typ>
element<typ>* lista<typ>::iterator::operator ++(){
    if(this->aktualny_element != nullptr){
        this->aktualny_element = this->aktualny_element->nastepny;
    }
    return this->aktualny_element;
}

template <typename typ>
element<typ>* lista<typ>::iterator::operator ++(int){
    if(this->aktualny_element != nullptr){
        this->aktualny_element = this->aktualny_element->nastepny;
    }
    return this->aktualny_element;
}

template <typename typ>
void lista<typ>::iterator::operator =(lista<typ> &moja_lista){
    this->przypisana_lista = moja_lista;
    this->aktualny_element = moja_lista->pierwszy();
}

template <typename typ>
void lista<typ>::iterator::operator =(iterator moj_iter){
    this->aktualny_element = moj_iter.aktualny_element;
    this->przypisana_lista = moj_iter.przypisana_lista;
}

template <typename typ>
element<typ>* lista<typ>::iterator::przeszukaj(typ szukany){
    if(this->przypisana_lista != nullptr){
        if(this->przypisana_lista->pierwszy() != nullptr){
            this->aktualny_element = przypisana_lista->pierwszy();
            for(element<typ>* ostatni = this->przypisana_lista->ostatni(); //petla skonczy dzialanie gdy dojdzie do ostatniego elementu
                    this->aktualny_element != ostatni;
                    (*this)++){
                if(*(this->aktualny_element->wartosc) == szukany){
                    return this->aktualny_element;
                }
            }
            if(szukany == *(this->przypisana_lista->ostatni()->wartosc)){ //sprawdza jeszcze ostatni element pominiety przez petle
                return this->przypisana_lista->ostatni();
            }
            std::cout << "nie znaleziono elementu" << std::endl;
            return nullptr; //gdy cos pojdzie nie tak zwraca nullptr
        }
        std::cout << "lista pusta" << std::endl;
        return nullptr; //gdy cos pojdzie nie tak zwraca nullptr
    }
    std::cout << "nie przypisano listy do iteratora" << std::endl;
    return nullptr; //gdy cos pojdzie nie tak zwraca nullptr
}

template <typename typ>
element<typ>* lista<typ>::iterator::wartosc(){
    return this->aktualny_element;
}

template <typename typ>
void lista<typ>::iterator::poczatek(){
    this->aktualny_element = this->przypisana_lista->pierwszy();
}

#endif