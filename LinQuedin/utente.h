#ifndef UTENTE_H
#define UTENTE_H

#include<QString>
#include <iostream>

using std::cout;

#include "profilo.h"
#include "rete.h"
#include "datiricerca.h"

#include "database.h"
class Database;

class Utente
{
private:
    Profilo profile;
    QString username;
    Rete* net;
public:
    Utente(const QString&);
    Utente(const Profilo&,const QString&);
    Profilo& getProfilo();
    QString getUsername() const;
    Rete* getRete() const;
    void setProfilo(const Profilo&);
    void setUsername(const QString&);
    void setRete(Rete*);
    virtual void add(Utente*);
    virtual void remove(const QString&);
    virtual map<QString,Utente*> find(DatiRicerca*,Database*) = 0;
    Utente& operator=(const Utente&);
    virtual ~Utente();
};

#endif // UTENTE_H
