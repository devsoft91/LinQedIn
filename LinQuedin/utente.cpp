#include "utente.h"

Utente::Utente(){}

Utente::Utente(const Profilo& p,const QString& u) : profile(p),username(u){
    net = new Rete();
}

void Utente::add(const QString& c,const Database& d){
    Utente* tmp = d.getUtente(c);
    net->addUser(c,Nodo(tmp,true));
    tmp->net->addUser((*this).username,Nodo(this,false));
}

//void Utente::find(){}
