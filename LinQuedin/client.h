#ifndef CLIENT_H
#define CLIENT_H

#include "utente.h"

class Client
{
public:
    Utente* u;
    Database* data_;
    Client(const QString&);
    void stampa() const;
};

#endif // CLIENT_H
