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

void Client::sendDatiAnagrafici(const DAnagrafici& d){
    u->profile.setDati(d);
}

void Client::saveDatabase(){
    data_->save();
}

DAnagrafici* Client::returnDatiAnagrafici() const{
    return new DAnagrafici(u->profile.getDati());
}
