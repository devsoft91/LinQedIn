#include "impieghi.h"

Impieghi::Impieghi(){}

Impieghi::Impieghi(const Lavoro& l){
    addLavoro(l);
}

vector<Lavoro> Impieghi::getLavoro() const{
    return impieghi;
}

void Impieghi::addLavoro(const Lavoro& l){
    impieghi.push_back(l);
}

void Impieghi::removeLavoro(const Lavoro& l){
    vector<Lavoro>::const_iterator it = impieghi.begin();
    bool trovato = false;
    int i=0;
    while(!trovato && it!=impieghi.end()){
        if((*it)==l){
            trovato=true;
            impieghi.erase(impieghi.begin()+i);
        }
        else{++it; ++i;}
    }
}

void Impieghi::updateLavoro(const Lavoro& l, const Lavoro& old){
    vector<Lavoro>::iterator it = impieghi.begin();
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
