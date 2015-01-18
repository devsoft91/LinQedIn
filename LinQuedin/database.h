#ifndef DATABASE_H
#define DATABASE_H

#include <iostream> //solo x test output
#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <map>
#include <algorithm>

#include "utente.h"

using std::map;

class Database
{
private:
    void checkflag() const;
public:
    map<QString,Utente*> db;
    void load();
    void save() const;
    void Aggiungi(const QString&,Utente*);
    void Elimina(const QString&);
    Utente* getUtente(const QString&) const;
};

#endif // DATABASE_H
