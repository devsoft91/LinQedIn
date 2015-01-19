#ifndef UTENTE_H
#define UTENTE_H

#include<QString>

#include "profilo.h"
#include "rete.h"

#include "database.h"
class Database;

class Utente
{
public:
    Profilo profile;
    QString username;
    Rete* net;
    Utente();
    Utente(const Profilo&,const QString&);
    virtual void add(const QString&,const Database&);
    //virtual void find() =0;
};

#endif // UTENTE_H
