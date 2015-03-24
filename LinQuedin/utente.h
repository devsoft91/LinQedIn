#ifndef UTENTE_H
#define UTENTE_H

#include<QString>

#include "profilo.h"
#include "rete.h"
#include "datiricerca.h"

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
    virtual void add(Utente*);
    virtual void remove(const QString&);
    virtual map<QString,Utente*> find(DatiRicerca*,Database*) =0;
    virtual ~Utente();
};

#endif // UTENTE_H
