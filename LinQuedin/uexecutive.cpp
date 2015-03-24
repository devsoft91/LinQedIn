#include "uexecutive.h"

UExecutive::UExecutive(){}

UExecutive::UExecutive(const Profilo& a,const QString& b) : UBusiness(a,b){}

void UExecutive::add(Utente* u){
    this->Utente::add(u);
}

map<QString,Utente*> UExecutive::find(DatiRicerca* d,Database* t){
    map<QString,Utente*> risultati;
    map<QString,Utente*> map_business = UBusiness::find(d,t);
    map<QString,Utente*>::const_iterator it = map_business.begin();

    list<Lavoro> l_lavori;
    list<Lavoro>::const_iterator iter;

    for(;it!=map_business.end();++it){

        l_lavori = (*it).second->profile.getImpieghi().getLavori();
        iter = l_lavori.begin();

        if(d->getTitolo()!=""){
            bool trovata = false;
            for(;!trovata && iter!=l_lavori.end();++iter){
                if((*iter).getTitolo() != d->getTitolo()){
                    continue;
                }
                else trovata=true;
            }
            if(!trovata) continue;
        }

        iter = l_lavori.begin();

        if(d->getAzienda()!=""){
            bool trovata = false;
            for(;!trovata && iter!=l_lavori.end();++iter){
                if((*iter).getAzienda() != d->getAzienda()){
                    continue;
                }
                else trovata=true;
            }
            if(!trovata) continue;
        }
        risultati.insert(std::pair<QString,Utente*>((*it).first,(*it).second));
    }
    return risultati;
}

UExecutive::~UExecutive(){}
