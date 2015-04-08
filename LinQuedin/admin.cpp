#include "admin.h"

QString Admin::pswd = "keepahmu";

Admin::Admin(const QString& s){
    if(s==pswd){
        data_ = new Database();
        data_->load();
    }
    else data_ = 0;
}

int Admin::returnUserType() const{
    return 3;
}

int Admin::typeOf(const QString& u) const{
    Utente* user = data_->getUtente(u);
    QString type = typeid(*user).name();
    if(type.contains("Basic"))
        return 0;
    if(type.contains("Business"))
        return 1;
    if(type.contains("Executive"))
        return 2;
}

void Admin::saveDatabase(){
    data_->save();
}

void Admin::sendRicerca(const QString& user,const QString& a,const QString& b,const QString& c,const QString& d,const QString& e,const QString& f){
    risultati = data_->find(user);
}

map<QString,Utente*> Admin::returnRicerca() const{
    return risultati;
}

void Admin::addToNet(const QString&){}

bool Admin::isFriendOf(const QString&) const{}

void Admin::addToDatabase(const QString& s){
    data_->Aggiungi(s,new UBasic(s));
}

void Admin::delFromDatabase(const QString& s){
    data_->Elimina(s);
}

void Admin::modifyPlan(const QString& s){

}

bool Admin::exist(const QString& u){
    risultati = data_->find(u);
    if(risultati.size()==0)
        return false;
    if(risultati.size()==1)
        return true;
}

void Admin::changePlanTo(const QString& u,int t){
    Utente* user = data_->getUtente(u);
    Utente* utente;

    if(t==0){
        std::cout<<"0"<<std::endl;
        utente = new UBasic(u);
        *utente = *user;
    }
    if(t==1){
        std::cout<<"1"<<std::endl;
        utente = new UBusiness(u);
        *utente = *user;
    }
    if(t==2){
        std::cout<<"2"<<std::endl;
        utente = new UExecutive(u);
        *utente = *user;
    }

    data_->Elimina(u);
    map<QString,Nodo> net = utente->net->rete;
    map<QString,Nodo>::const_iterator it = net.begin();
    for(;it!=net.end();++it){
        Utente* p = data_->getUtente((*it).first);
        if((*it).second.flag)
            p->net->rete.insert(std::pair<QString,Nodo>(u,Nodo(utente,false)));
        else p->net->rete.insert(std::pair<QString,Nodo>(u,Nodo(utente,true)));
    }
    data_->Aggiungi(u,utente);

}

Admin::~Admin(){

}
