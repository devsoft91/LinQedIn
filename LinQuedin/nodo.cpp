#include "nodo.h"

Nodo::Nodo(){
    utente = 0;
    flag = false;
}

Nodo::Nodo(Utente* u,bool f) : utente(u),flag(f){}

void Nodo::setUtente(Utente* u){
    utente = u;
}

void Nodo::setFlag(bool b){
    flag = b;
}

Utente* Nodo::getUtente() const{
    return utente;
}

bool Nodo::getFlag() const{
    return flag;
}
