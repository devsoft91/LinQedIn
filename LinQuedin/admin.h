#ifndef ADMIN_H
#define ADMIN_H

#include <QString>

#include "database.h"
#include "controller.h"
#include "ubasic.h"
#include "ubusiness.h"
#include "uexecutive.h"

class Admin : public virtual Controller
{
public:
    static QString pswd;
    Database* data_;
    map<QString,Utente*> risultati;
    int returnUserType() const;
    int typeOf(const QString&) const;
    void saveDatabase();
    void sendRicerca(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&,const QString&);
    map<QString,Utente*> returnRicerca() const;
    bool isFriendOf(const QString&) const;
    void addToNet(const QString&);
    void addToDatabase(const QString&);
    void delFromDatabase(const QString&);
    void modifyPlan(const QString&);
    bool exist(const QString&);
    void changePlanTo(const QString&,int);
    Admin(const QString&);
    ~Admin();
};

#endif // ADMIN_H
