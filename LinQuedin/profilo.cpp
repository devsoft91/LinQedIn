#include "profilo.h"

Profilo::Profilo(){}

Profilo::Profilo(const DAnagrafici& a,const TitoliStudio& b) : dati(a),titoli(b){}

Profilo::Profilo(const DAnagrafici& a,const TitoliStudio& b,const Impieghi& c) : dati(a),titoli(b),impieghi(c){}

void Profilo::setDati(const DAnagrafici& d){
    dati = d;
}

void Profilo::setTitoli(const TitoliStudio& t){
    titoli = t;
}

void Profilo::setImpieghi(const Impieghi& i){
    impieghi = i;
}

DAnagrafici Profilo::getDati() const{
    return dati;
}
TitoliStudio Profilo::getTitoli() const{
    return titoli;
}
Impieghi Profilo::getImpieghi() const{
    return impieghi;
}
