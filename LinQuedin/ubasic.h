#ifndef UBASIC_H
#define UBASIC_H

#include "utente.h"

class UBasic : public Utente
{
public:
    UBasic(const QString&);
    UBasic(const Profilo&,const QString&);
    map<QString,Utente*> find(DatiRicerca*,Database*);
    ~UBasic();
};

#endif // UBASIC_H
