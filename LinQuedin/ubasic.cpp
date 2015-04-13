#include "ubasic.h"

UBasic::UBasic(const QString& u) : Utente(u){}

UBasic::UBasic(const Profilo& a,const QString& b) : Utente(a,b){

}

map<QString,Utente*> UBasic::find(DatiRicerca* d,Database* t){
    QString user = getUsername();
    map<QString,Utente*> risultati;
    map<QString,Utente*>::const_iterator it = t->db.begin();
    for(;it!=t->db.end();++it){
        if((*it).second->getUsername() == user)
            continue;
        if(d->getNome()!="" && (*it).second->getProfilo().getDati().getNome() != d->getNome())
            continue;
        if(d->getCognome()!="" && (*it).second->getProfilo().getDati().getCognome() != d->getCognome())
            continue;

        risultati.insert(std::pair<QString,Utente*>((*it).first,(*it).second));
    }
    return risultati;
}

UBasic::~UBasic(){}
