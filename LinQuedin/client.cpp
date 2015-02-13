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
    //data_->save();
}
