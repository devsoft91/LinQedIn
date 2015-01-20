#include "utente.h"

Utente::Utente(){}

Utente::Utente(const Profilo& p,const QString& u) : profile(p),username(u){
    net = new Rete();
    std::cout<<"costruttore di Utente\n";
}

void Utente::add(const QString& c,const Database& d){
    Utente* tmp = d.getUtente(c);
    net->addUser(c,Nodo(tmp,true));
    tmp->net->addUser((*this).username,Nodo(this,false));
}

Utente::~Utente(){  //ATTENZIONE
    std::cout<<"Distruttore Utente\n";
    std::map<QString,Nodo>::const_iterator iter = net->rete.begin();
    int netsize = net->rete.size();
    QString user = username;
    for(int i=0;i<netsize;i++){
        (*iter).second.utente->net->rete.erase(user);
        ++iter;
    }
    delete net;
}
