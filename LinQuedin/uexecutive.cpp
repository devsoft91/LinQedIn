#include "uexecutive.h"

UExecutive::UExecutive(){}

UExecutive::UExecutive(const Profilo& a,const QString& b) : UBusiness(a,b){
    std::cout<<"costruttore di UExecutive\n";
}

void UExecutive::add(const QString& c, const Database& d){
    this->Utente::add(c,d);
}

void UExecutive::find(){
    std::cout<<"Sono un Profilo Executive\n\n";
}

UExecutive::~UExecutive(){}
