#include "ubasic.h"

UBasic::UBasic(const QString& u) : Utente(u){}

UBasic::UBasic(const Profilo& a,const QString& b) : Utente(a,b){

}

void UBasic::add(Utente* u){
    this->Utente::add(u);
}

map<QString,Utente*> UBasic::find(DatiRicerca* d,Database* t){
    QString user = username;
    map<QString,Utente*> risultati;
    map<QString,Utente*>::const_iterator it = t->db.begin();
    for(;it!=t->db.end();++it){
        if((*it).second->username == user)
            continue;
        if(d->getNome()!="" && (*it).second->profile.getDati().getNome() != d->getNome())
            continue;
        if(d->getCognome()!="" && (*it).second->profile.getDati().getCognome() != d->getCognome())
            continue;

        risultati.insert(std::pair<QString,Utente*>((*it).first,(*it).second));
    }
    return risultati;
}

UBasic::~UBasic(){}
