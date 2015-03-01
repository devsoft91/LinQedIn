#include "titolistudio.h"

TitoliStudio::TitoliStudio(){}

TitoliStudio::TitoliStudio(const QString& a,int b){
    diploma = a;
    anno = b;
}

TitoliStudio::TitoliStudio(const QString& a,int b,const Laurea& c) {
    diploma = a;
    anno = b;
    lauree.push_back(c);
} // da completareeeeeee

QString TitoliStudio::getDiploma() const{
    return diploma;
}

int TitoliStudio::getAnno() const{
    return anno;
}

vector<Laurea> TitoliStudio::getLaurea() const{
    if(lauree.size()!=0)
        return lauree;
    return vector<Laurea>();
}

void TitoliStudio::setDiploma(const QString& d){
    diploma = d;
}

void TitoliStudio::setAnno(const int& a){
    anno = a;
}

void TitoliStudio::addLaurea(const Laurea& l) {
    lauree.push_back(l);
}
