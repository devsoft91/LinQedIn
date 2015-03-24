#ifndef UEXECUTIVE_H
#define UEXECUTIVE_H

#include "ubusiness.h"

class UExecutive : public UBusiness
{
public:
    UExecutive();
    UExecutive(const Profilo&,const QString&);
    void add(Utente*);
    map<QString,Utente*> find(DatiRicerca*,Database*);
    ~UExecutive();
};

#endif // UEXECUTIVE_H
