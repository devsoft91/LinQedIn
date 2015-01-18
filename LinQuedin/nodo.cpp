#include "nodo.h"

Nodo::Nodo(){
    std::cout<<"test";
    utente = 0;
    flag = false;
}

Nodo::Nodo(Utente* u,bool f) : utente(u),flag(f){}
