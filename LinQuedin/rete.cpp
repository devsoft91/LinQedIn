#include "rete.h"

Rete::Rete(){
}

void Rete::addUser(const QString& s,const Nodo& n){
    rete.insert(std::pair<QString,Nodo>(s,n));
}
