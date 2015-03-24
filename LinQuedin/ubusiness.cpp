#include "ubusiness.h"

UBusiness::UBusiness(){}

UBusiness::UBusiness(const Profilo& a,const QString& b) : UBasic(a,b){

}

void UBusiness::add(Utente* u){
    this->Utente::add(u);
}

map<QString,Utente*> UBusiness::find(DatiRicerca* d,Database* t){
    map<QString,Utente*> risultati;
    map<QString,Utente*> map_basic = UBasic::find(d,t);
    map<QString,Utente*>::const_iterator it = map_basic.begin();
    for(;it!=map_basic.end();++it){
        if(d->getDiploma()!="")
            if((*it).second->profile.getTitoli().getDiploma() != d->getDiploma()){
                continue;
            }
        if(d->getLaurea()!=""){
            bool trovata = false;
            vector<Laurea> v_lauree = (*it).second->profile.getTitoli().getLaurea();
            vector<Laurea>::const_iterator iter = v_lauree.begin();
            for(;!trovata && iter!=v_lauree.end();++iter){
                if((*iter).getNome() != d->getLaurea()){
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

UBusiness::~UBusiness(){}
