#include "client.h"

Client::Client(const QString& s){
    data_ = new Database();
    data_->load();
    u = data_->getUtente(s);
    data_->save();
}

void Client::stampa() const{

}
