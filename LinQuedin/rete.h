#ifndef RETE_H
#define RETE_H

#include <QString>
#include <map>

#include "nodo.h"

using std::map;

class Rete
{
public:
    map<QString,Nodo> rete;
    Rete();
    void addUser(const QString&,const Nodo&);
    void removeUser(const QString&);
    Rete* operator=(Rete*);
};

#endif // RETE_H
