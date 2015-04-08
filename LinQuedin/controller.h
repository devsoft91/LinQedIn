#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utente.h"

class Controller
{
public:
    virtual int returnUserType() const = 0;
    virtual void saveDatabase() = 0;
    virtual void sendRicerca(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&,const QString&) = 0;
    virtual map<QString,Utente*> returnRicerca() const = 0;
    virtual bool isFriendOf(const QString&) const = 0;
    virtual void addToNet(const QString&) = 0;
    Controller();
    virtual ~Controller();
};

#endif // CONTROLLER_H
