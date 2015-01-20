#ifndef UBUSINESS_H
#define UBUSINESS_H

#include "ubasic.h"

class UBusiness : public UBasic
{
public:
    UBusiness();
    UBusiness(const Profilo&,const QString&);
    void add(const QString&,const Database&);
    void find();
    ~UBusiness();
};

#endif // UBUSINESS_H
