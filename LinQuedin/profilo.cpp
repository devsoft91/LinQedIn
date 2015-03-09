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

void Profilo::setDiploma(const QString& s, int i){
    titoli.setDiploma(s);
    titoli.setAnno(i);
}

void Profilo::setImpieghi(const Impieghi& i){
    impieghi = i;
}

void Profilo::setLaurea(const Laurea& l){
    titoli.addLaurea(l);
}

void Profilo::setLaurea(const QString& s,const Laurea& l){
    titoli.updateLaurea(s,l);
}

void Profilo::setLavoro(const Lavoro& l){
    impieghi.addLavoro(l);
}

void Profilo::removeLaurea(const QString& s){
    titoli.removeLaurea(s);
}

void Profilo::removeImpiego(const Lavoro& l){
    impieghi.removeLavoro(l);
}

void Profilo::updateImpiego(const Lavoro& l,const Lavoro& old){
    impieghi.updateLavoro(l,old);
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
