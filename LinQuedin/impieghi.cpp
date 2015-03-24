#include "impieghi.h"

Impieghi::Impieghi(){}

Impieghi::Impieghi(const Lavoro& l){
    addLavoro(l);
}

list<Lavoro> Impieghi::getLavori() const{
    return impieghi;
}

void Impieghi::addLavoro(const Lavoro& l){
    impieghi.push_back(l);
}

void Impieghi::addLavoro(const Lavoro& l, bool f){
    if(f) impieghi.push_front(l);
    else impieghi.push_back(l);
}

void Impieghi::removeLavoro(const Lavoro& l){
    list<Lavoro>::iterator it = impieghi.begin();
    bool trovato = false;
    int i=0;
    while(!trovato && it!=impieghi.end()){
        if((*it)==l){
            trovato=true;
            impieghi.erase(it);
        }
        else{++it; ++i;}
    }
}

void Impieghi::updateLavoro(const Lavoro& l, const Lavoro& old){
    list<Lavoro>::iterator it = impieghi.begin();
    bool trovato = false;
    int i=0;
    while(!trovato && it!=impieghi.end()){
        if((*it)==old){
            trovato=true;
            (*it).setTitolo(l.getTitolo());
            (*it).setAzienda(l.getAzienda());
            (*it).setCitta(l.getCitta());
            (*it).setInizio(l.getInizio());
            (*it).setFine(l.getFine());
        }
        else{++it; ++i;}
    }
}
