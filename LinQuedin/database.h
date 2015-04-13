#ifndef DATABASE_H
#define DATABASE_H

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
public:
    map<QString,Utente*> db;
    QString path;
    Database();
    void load();
    void save() const;
    void Aggiungi(const QString&,Utente*);
    void Elimina(const QString&);
    map<QString,Utente*> find(const QString&) const;
    Utente* getUtente(const QString&) const;
};

#endif // DATABASE_H
