#include "impieghi.h"

Impieghi::Impieghi(){}

Impieghi::Impieghi(const Lavoro& l){
    addLavoro(l);
}

vector<Lavoro> Impieghi::getLavoro() const{
    return impieghi;
}

void Impieghi::addLavoro(const Lavoro& l){
    impieghi.push_back(l);
}
