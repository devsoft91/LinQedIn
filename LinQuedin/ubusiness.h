#ifndef UBUSINESS_H
#define UBUSINESS_H

#include "ubasic.h"

class UBusiness : public UBasic
{
public:
    UBusiness();
    UBusiness(const Profilo&,const QString&);
    void add(Utente*);
    map<QString,Utente*> find(DatiRicerca*,Database*);
    ~UBusiness();
};

#endif // UBUSINESS_H
