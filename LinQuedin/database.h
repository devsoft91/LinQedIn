#ifndef DATABASE_H
#define DATABASE_H

#include <iostream> //solo x test output
#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>
#include <map>
#include <algorithm>
#include <typeinfo>
#include <QMessageBox>
#include <QFileDialog>

#include "utente.h"

using std::map;

class Database
{
private:
    void checkflag() const;  //attenzione non usato
public:
    Database();
    map<QString,Utente*> db;
    QString path;
    void load();
    void save() const;
    void Aggiungi(const QString&,Utente*);
    void Elimina(const QString&);
    map<QString,Utente*> find(const QString&) const;
    Utente* getUtente(const QString&) const;
};

#endif // DATABASE_H
