#ifndef UBASIC_H
#define UBASIC_H

#include "utente.h"

class UBasic : public Utente
{
public:
    UBasic();
    UBasic(const Profilo&,const QString&);
    void add(const QString&,const Database&);
    void find();
    ~UBasic();
};

#endif // UBASIC_H
