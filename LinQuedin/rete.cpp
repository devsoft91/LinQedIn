#include "rete.h"

Rete::Rete(){}

void Rete::addUser(const QString& s,const Nodo& n){
    rete.insert(std::pair<QString,Nodo>(s,n));
}

void Rete::removeUser(const QString& s){
    rete.erase(s);
}

Rete* Rete::operator=(Rete*){
    Rete* tmp = new Rete();
    map<QString,Nodo>::const_iterator it = rete.begin();
    for(;it!=rete.end();++it){
        tmp->addUser((*it).first,(*it).second);
    }
    return tmp;
}
