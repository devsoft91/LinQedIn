#include "ubusiness.h"

UBusiness::UBusiness(){}

UBusiness::UBusiness(const Profilo& a,const QString& b) : UBasic(a,b){
    std::cout<<"costruttore di UBusiness\n";
}

void UBusiness::add(const QString& c, const Database& d){
    this->Utente::add(c,d);
}

void UBusiness::find(){
    std::cout<<"Sono un Profilo Business\n\n";
}

UBusiness::~UBusiness(){}
