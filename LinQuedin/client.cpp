#include "client.h"

Client::Client(const QString& s,Database* d){
    if(d==0){
        data_ = new Database();
        data_->load();
    }
    else data_ = d;
    initialize(s);
}

void Client::stampa() const{

}

void Client::initialize(const QString& s){
    u = data_->getUtente(s);
}

void Client::saveDatabase(){
    data_->save();
}

void Client::sendDatiAnagrafici(const DAnagrafici& d){
    u->profile.setDati(d);
}

void Client::sendTitoliStudio(const TitoliStudio& t){
    u->profile.setTitoli(t);
}

void Client::sendDiploma(const QString& s, int i){
    u->profile.setDiploma(s,i);
}

void Client::sendImpiego(const Impieghi& i){
    u->profile.setImpieghi(i);
}

void Client::sendLavoro(const Lavoro& l){
    u->profile.setLavoro(l);
}

void Client::sendLavoro(const Lavoro& l, bool f){
    u->profile.setLavoro(l,f);
}

void Client::sendLaurea(const Laurea& l){
    u->profile.setLaurea(l);
}

void Client::sendLaurea(const QString& s,const Laurea& l){
    u->profile.setLaurea(s,l);
}

void Client::sendRicerca(const QString&,const QString& a,const QString& b,const QString& c,const QString& d,const QString& e,const QString& f){
    DatiRicerca* dati = new DatiRicerca();
    if(a!=""){
        dati->setNome(a);
    }
    if(b!=""){
        dati->setCognome(b);
    }
    if(c!=""){
        dati->setDiploma(c);
    }
    if(d!=""){
        dati->setLaurea(d);
    }
    if(e!=""){
        dati->setTitolo(e);
    }
    if(f!=""){
        dati->setAzienda(f);
    }

    risultati = u->find(dati,data_);
}

void Client::addToNet(const QString& s){
    Utente* utente = data_->getUtente(s);
    u->add(utente);
}

DAnagrafici* Client::returnDatiAnagrafici() const{
    return new DAnagrafici(u->profile.getDati());
}

TitoliStudio* Client::returnTitoliStudio() const{
    return new TitoliStudio(u->profile.getTitoli());
}

Impieghi* Client::returnImpieghi() const{
    return new Impieghi(u->profile.getImpieghi());
}

map<QString,Nodo> Client::returnRete() const{
    return u->net->rete;
}

void Client::removeFromNet(const QString& s){
    u->remove(s);
}

int Client::returnUserType() const{
    QString typo = typeid(*u).name();
    int r;
    if(typo.contains("Basic"))
        r = 0;
    if(typo.contains("Business"))
        r = 1;
    if(typo.contains("Executive"))
        r = 2;
    return r;
}

map<QString,Utente*> Client::returnRicerca() const{
    return risultati;
}

bool Client::isFriendOf(const QString& s) const{
    map<QString,Nodo>::const_iterator it = u->net->rete.end();
    if(u->net->rete.find(s)!=it)
        return true;
    return false;
}

Client::~Client(){

}
