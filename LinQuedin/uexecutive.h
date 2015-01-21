#ifndef UEXECUTIVE_H
#define UEXECUTIVE_H

#include "ubusiness.h"

class UExecutive : public UBusiness
{
public:
    UExecutive();
    UExecutive(const Profilo&,const QString&);
    void add(const QString&,const Database&);
    void find();
    ~UExecutive();
};

#endif // UEXECUTIVE_H
