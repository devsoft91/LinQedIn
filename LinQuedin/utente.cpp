#include "utente.h"

Utente::Utente(const QString& u) : username(u){
    net = new Rete();
}

Utente::Utente(const Profilo& p,const QString& u) : profile(p),username(u){
    net = new Rete();
}

Profilo& Utente::getProfilo(){
    return profile;
}

QString Utente::getUsername() const{
    return username;
}

Rete* Utente::getRete() const{
    return net;
}

void Utente::setProfilo(const Profilo& p){
    profile = p;
}

void Utente::setUsername(const QString& u){
    username = u;
}

void Utente::setRete(Rete* r){
    net = r;
}

void Utente::add(Utente* u){
    net->addUser(u->username,Nodo(u,true));
    u->net->addUser((*this).username,Nodo(this,false));
}

void Utente::remove(const QString& c){
    net->removeUser(c);
}

Utente& Utente::operator=(const Utente& u){
    profile = u.profile;
    username = u.username;
    *net = *(u.net);
    return *this;
}

Utente::~Utente(){
    std::map<QString,Nodo>::const_iterator iter = net->rete.begin();
    int netsize = net->rete.size();
    for(int i=0;i<netsize;i++){
        (*iter).second.getUtente()->net->rete.erase(username);
        ++iter;
    }
    delete net;
}
