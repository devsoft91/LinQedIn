#ifndef UEXECUTIVE_H
#define UEXECUTIVE_H

#include "ubusiness.h"

class UExecutive : public UBusiness
{
public:
    UExecutive(const QString&);
    UExecutive(const Profilo&,const QString&);
    map<QString,Utente*> find(DatiRicerca*,Database*);
    ~UExecutive();
};

#endif // UEXECUTIVE_H
