#ifndef LISTA_2_KIER_CPP
#define LISTA_2_KIER_CPP

#include "inc/lista_2_kier.hh"

template <typename typ>
lista_2_kier<typ>::lista_2_kier(){
    pierwszy_element = nullptr;
    ostatni_element = nullptr;
}

template<typename typ>
unsigned int lista_2_kier<typ>::rozmiar(){
    if(this->czy_pusta() == false){
        unsigned int wielkosc = 1; //lista_2_kier nie moze byc pusta
        element_2_kier<typ> *ostatni = this->pierwszy_element;
        while(ostatni->nastepny != nullptr){
            ostatni = ostatni->nastepny;
            ++wielkosc;
        }
        return wielkosc;
    }
    return 0; // zwraca 0 jesli lista_2_kier jest pusta
}

template <typename typ>
void lista_2_kier<typ>::dodaj_na_poczatek(typ dodaj){
    element_2_kier<typ> *tymczasowe = new element_2_kier<typ>(dodaj);
    // jesli lista_2_kier nie jest pusta dodaje element_2_kier na pierwsze miejsce
    // jesli lista_2_kier jest pusta pierwszy i ostatni element_2_kier wskazuja na nowy element_2_kier
    if(this->czy_pusta() == false){
        tymczasowe->nastepny = this->pierwszy_element;
        this->pierwszy_element->poprzedni = tymczasowe;
        this->pierwszy_element = tymczasowe;
    } else{
        this->pierwszy_element = tymczasowe;
        this->ostatni_element = tymczasowe;
    }
}

template <typename typ>
void lista_2_kier<typ>::dodaj_na_koniec(typ dodaj){
    element_2_kier<typ> *tymczasowe = new element_2_kier<typ>(dodaj);
    // jesli lista_2_kier nie jest pusta dodaje element_2_kier na ostatnie miejsce
    // jesli lista_2_kier jest pusta pierwszy i ostatni element_2_kier wskazuja na nowy element_2_kier
    if(this->czy_pusta() == false){
        tymczasowe->poprzedni = this->ostatni_element;
        this->ostatni_element->nastepny = tymczasowe;
        this->ostatni_element = tymczasowe;

    } else{
        this->pierwszy_element = tymczasowe;
        this->ostatni_element = tymczasowe;
    }
}

template <typename typ>
void lista_2_kier<typ>::usun_pierwszy(){
    if(this->czy_pusta() == false){
        element_2_kier<typ>* tymczasowy;
        tymczasowy = pierwszy_element->nastepny; // tymczasowy zapamietuje adres drugiego elementu
        delete pierwszy_element;
        pierwszy_element = tymczasowy;
        pierwszy_element->poprzedni = nullptr;
    } else{
        std::cout << "nie mozna usunac elementu, lista_2_kier pusta" << std::endl;
    }
}

template <typename typ>
void lista_2_kier<typ>::usun_ostatni(){
    if(this->czy_pusta() == false){
        element_2_kier<typ>* tymczasowy;
        tymczasowy = ostatni_element->poprzedni; // tymczasowy zapamietuje adres przedostatniego elementu
        delete ostatni_element;
        ostatni_element = tymczasowy;
        ostatni_element->nastepny = nullptr;
    } else{
        std::cout << "nie mozna usunac elementu, lista_2_kier pusta" << std::endl;
    }
}

template <typename typ>
void lista_2_kier<typ>::usun_element(typ odniesienie){
    if(this->czy_pusta() == false){
        element_2_kier<typ>* do_usuniecia = pierwszy_element;
        if(*(do_usuniecia->wartosc) == odniesienie){ // jesli pierwszy element_2_kier pasuje do odniesienia
            this->usun_pierwszy();
            return;
        } else{
            do_usuniecia = do_usuniecia->nastepny;
            while(do_usuniecia->nastepny != nullptr){
                if(*(do_usuniecia->wartosc) == odniesienie){
                    do_usuniecia->poprzedni->nastepny = do_usuniecia->nastepny; // poprzedni element_2_kier bedzie wskazywal na nastepny po usunietym
                    do_usuniecia->nastepny->poprzedni = do_usuniecia->poprzedni; // nastepny element_2_kier bedzie wskazywal na poprzedni przed usunietym;
                    delete do_usuniecia;
                    return;
                }
                do_usuniecia = do_usuniecia->nastepny;
            }
            if(*(ostatni_element->wartosc) == odniesienie){
                this->usun_ostatni();
                return;
            }
        }
    } else{
        std::cout << "nie mozna usunac elementu, lista_2_kier pusta" << std::endl;
    }
}

template <typename typ>
void lista_2_kier<typ>::usun_element(element_2_kier<typ>* do_usuniecia){
    //przypadek kiedy usuwamy jedyny element_2_kier na liscie
    if(do_usuniecia->poprzedni == nullptr && do_usuniecia->nastepny == nullptr){
        pierwszy_element = nullptr;
        ostatni_element = nullptr;
        delete do_usuniecia;
    } else{
        // jesli pierwszy element na liscie
        if(do_usuniecia->poprzedni == nullptr && do_usuniecia->nastepny != nullptr){
            // jesli usuwamy pierwszy element_2_kier na liscie
            // musimy nastepny uznac jako pierwszy
            this->pierwszy_element = do_usuniecia->nastepny;
            do_usuniecia->nastepny->poprzedni = nullptr;
            delete do_usuniecia;
        } else{
            // jesli ostatni na liscie
            if(do_usuniecia->nastepny == nullptr && do_usuniecia->poprzedni != nullptr){
                // jesli usuwamy ostatni element_2_kier na liscie
                // musimy poprzedni uznac za ostatni
                this->ostatni_element = do_usuniecia->poprzedni;
                do_usuniecia->poprzedni->nastepny = nullptr;
                delete do_usuniecia;
            } else{ // srodkowy element
                do_usuniecia->poprzedni->nastepny = do_usuniecia->nastepny;
                do_usuniecia->nastepny->poprzedni = do_usuniecia->poprzedni;
                delete do_usuniecia;
            }
        }
    }
}

template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::pierwszy(){
    return this->pierwszy_element;
}

template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::ostatni(){
    return this->ostatni_element;
}

template <typename typ>
bool lista_2_kier<typ>::czy_pusta(){
    if(this->pierwszy_element == nullptr){
        return true; // zwraca true jesli lista_2_kier jest pusta
    }
    return false; // zwraca false jesli pierwszy element_2_kier istnieje
}

template <typename typ>
void lista_2_kier<typ>::wyczysc(){
    if(this->czy_pusta() == false){
        element_2_kier<typ>* do_usuniecia = pierwszy_element;
        element_2_kier<typ>* kolejny = pierwszy_element; // element_2_kier za elementem usuwanym
        while(do_usuniecia != nullptr){
            kolejny = do_usuniecia->nastepny;
            delete do_usuniecia;
            do_usuniecia = kolejny;
        }
        this->pierwszy_element = nullptr;
        this->ostatni_element = nullptr;
    }
}

template <typename typ>
lista_2_kier<typ>::iterator::iterator(){
    this->aktualny_element = nullptr;
    this->przypisana_lista = nullptr;
}

template <typename typ>
lista_2_kier<typ>::iterator::iterator(lista_2_kier<typ> *moja_lista){
    this->aktualny_element = moja_lista->pierwszy(); // przy przypisaniu listy przypisuje jej pierwszy element_2_kier
    this->przypisana_lista = moja_lista;
}

// numeracja od 0 jak w tablicy
template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::iteruj(unsigned int numer_elem){
    if(this->przypisana_lista != nullptr){
        if(this->przypisana_lista->czy_pusta() == false){
            element_2_kier<typ> *wybrany = this->przypisana_lista->pierwszy();
            for(unsigned int i=0;i<numer_elem;i++){
                if (wybrany->nastepny == nullptr){
                    std::cout<<"nie ma takiego elementu"<<std::endl;
                    std::cout<<"zwrocono nullptr"<<std::endl;
                    return nullptr; //w razie przekroczenia zakresu zwraca nullptr
                }
                wybrany = wybrany->nastepny;
            }
            return wybrany; // jesli lista_2_kier nie bedzie pusta zwroci adres elementu
        }
        std::cout << "lista_2_kier pusta, zwrocono nulptr" << std::endl;
        return nullptr; // w razie pustej listy zwraca nullptr
    }
    std::cout << "nie przypisano listy, zwrocono nullptr" << std::endl;
    return nullptr;
}

template<typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::iteruj(element_2_kier<typ> *wskazany_elem, unsigned int numer_elem){
    element_2_kier<typ> *wybrany;
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

// numeracja od 0 jak w tablicy
template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::iteruj_wstecz(unsigned int numer_elem){
    if(this->przypisana_lista != nullptr){
        if(this->przypisana_lista->czy_pusta() == false){
            element_2_kier<typ> *wybrany = this->przypisana_lista->ostatni();
            for(unsigned int i=0;i<numer_elem;i++){
                if (wybrany->poprzedni == nullptr){
                    std::cout<<"nie ma takiego elementu"<<std::endl;
                    std::cout<<"zwrocono nullptr"<<std::endl;
                    return nullptr; //w razie przekroczenia zakresu zwraca nullptr
                }
                wybrany = wybrany->poprzedni;
            }
            return wybrany; // jesli lista_2_kier nie bedzie pusta zwroci adres elementu
        }
        std::cout << "lista_2_kier pusta, zwrocono nulptr" << std::endl;
        return nullptr; // w razie pustej listy zwraca nullptr
    }
    std::cout << "nie przypisano listy, zwrocono nullptr" << std::endl;
    return nullptr;
}

template<typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::iteruj_wstecz(element_2_kier<typ> *wskazany_elem, unsigned int numer_elem){
    element_2_kier<typ> *wybrany;
    wybrany = wskazany_elem;
    for(unsigned int i=0;i<numer_elem;i++){
        if (wybrany->poprzedni == nullptr){
            std::cout<<"nie ma takiego elementu"<<std::endl;
            std::cout<<"zwrocono nullptr"<<std::endl;
            return nullptr; //w razie przekroczenia zakresu zwraca nullptr
        }
        wybrany = wybrany->poprzedni;
    }
    return wybrany;
}

template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::operator ++(){
    if(this->aktualny_element != nullptr){
        this->aktualny_element = this->aktualny_element->nastepny;
    }
    return this->aktualny_element;
}

template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::operator ++(int){
    if(this->aktualny_element != nullptr){
        this->aktualny_element = this->aktualny_element->nastepny;
    }
    return this->aktualny_element;
}

template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::operator --(){
    if(this->aktualny_element != nullptr){
        this->aktualny_element = this->aktualny_element->poprzedni;
    }
    return this->aktualny_element;
}

template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::operator --(int){
    if(this->aktualny_element != nullptr){
        this->aktualny_element = this->aktualny_element->poprzedni;
    }
    return this->aktualny_element;
}

template <typename typ>
void lista_2_kier<typ>::iterator::operator =(lista_2_kier<typ> &moja_lista){
    this->przypisana_lista = moja_lista;
    this->aktualny_element = moja_lista->pierwszy();
}

template <typename typ>
void lista_2_kier<typ>::iterator::operator =(iterator moj_iter){
    this->aktualny_element = moj_iter.aktualny_element;
    this->przypisana_lista = moj_iter.przypisana_lista;
}

template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::przeszukaj(typ szukany){
    if(this->przypisana_lista != nullptr){
        if(this->przypisana_lista->pierwszy() != nullptr){
            this->aktualny_element = przypisana_lista->pierwszy();
            for(element_2_kier<typ>* ostatni = this->przypisana_lista->ostatni(); //petla skonczy dzialanie gdy dojdzie do ostatniego elementu
                    this->aktualny_element != ostatni;
                    (*this)++){
                if(*(this->aktualny_element->wartosc) == szukany){
                    return this->aktualny_element;
                }
            }
            if(szukany == *(this->przypisana_lista->ostatni()->wartosc)){ //sprawdza jeszcze ostatni element_2_kier pominiety przez petle
                return this->przypisana_lista->ostatni();
            }
            std::cout << "nie znaleziono elementu" << std::endl;
            return nullptr; //gdy cos pojdzie nie tak zwraca nullptr
        }
        std::cout << "lista_2_kier pusta" << std::endl;
        return nullptr; //gdy cos pojdzie nie tak zwraca nullptr
    }
    std::cout << "nie przypisano listy do iteratora" << std::endl;
    return nullptr; //gdy cos pojdzie nie tak zwraca nullptr
}

template <typename typ>
element_2_kier<typ>* lista_2_kier<typ>::iterator::wartosc(){
    return this->aktualny_element;
}

template <typename typ>
void lista_2_kier<typ>::iterator::poczatek(){
    this->aktualny_element = this->przypisana_lista->pierwszy();
}

template <typename typ>
void lista_2_kier<typ>::iterator::koniec(){
    this->aktualny_element = this->przypisana_lista->ostatni();
}

#endif