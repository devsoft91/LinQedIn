#include "ubasic.h"

UBasic::UBasic(){}

UBasic::UBasic(const Profilo& a,const QString& b) : Utente(a,b){
    std::cout<<"costruttore di UBasic\n";
}

void UBasic::add(const QString& c, const Database& d){
    this->Utente::add(c,d);
}

void UBasic::find(){
    std::cout<<"Sono un Profilo Basic\n\n";
}

UBasic::~UBasic(){}
