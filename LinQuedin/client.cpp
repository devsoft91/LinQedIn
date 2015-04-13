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
    u->getProfilo().setDati(d);
}

void Client::sendTitoliStudio(const TitoliStudio& t){
    u->getProfilo().setTitoli(t);
}

void Client::sendDiploma(const QString& s, int i){
    u->getProfilo().setDiploma(s,i);
}

void Client::sendImpiego(const Impieghi& i){
    u->getProfilo().setImpieghi(i);
}

void Client::sendLavoro(const Lavoro& l){
    u->getProfilo().setLavoro(l);
}

void Client::sendLavoro(const Lavoro& l, bool f){
    u->getProfilo().setLavoro(l,f);
}

void Client::sendLaurea(const Laurea& l){
    u->getProfilo().setLaurea(l);
}

void Client::sendLaurea(const QString& s,const Laurea& l){
    u->getProfilo().setLaurea(s,l);
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
    return new DAnagrafici(u->getProfilo().getDati());
}

TitoliStudio* Client::returnTitoliStudio() const{
    return new TitoliStudio(u->getProfilo().getTitoli());
}

Impieghi* Client::returnImpieghi() const{
    return new Impieghi(u->getProfilo().getImpieghi());
}

map<QString,Nodo> Client::returnRete() const{
    return u->getRete()->rete;
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
    map<QString,Nodo>::const_iterator it = u->getRete()->rete.end();
    if(u->getRete()->rete.find(s)!=it)
        return true;
    return false;
}

Client::~Client(){

}
