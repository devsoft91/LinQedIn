#ifndef CLIENT_H
#define CLIENT_H

#include "utente.h"
#include "mainwindow.h"

class Client
{
public:
    Utente* u;
    Database* data_;
    MainWindow* window;
    Client(const QString&);
    void stampa() const;
};

#endif // CLIENT_H
