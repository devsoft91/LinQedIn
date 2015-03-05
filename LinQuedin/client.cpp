#include "client.h"

Client::Client(const QString& s){
    data_ = new Database();
    data_->load();
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

void Client::sendImpieghi(const Impieghi& i){
    u->profile.setImpieghi(i);
}

void Client::sendLaurea(const Laurea& l){
    u->profile.setLaurea(l);
}

void Client::sendLaurea(const QString& s,const Laurea& l){
    u->profile.setLaurea(s,l);
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
