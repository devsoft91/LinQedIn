#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

using namespace std;

#include "utente.h"

class Client{
public:
    Utente* u;
    Database* data_;
    Client(const QString&);
    void stampa() const;
    void initialize(const QString&);
    void saveDatabase();
    void sendDatiAnagrafici(const DAnagrafici&);
    void sendTitoliStudio(const TitoliStudio&);
    void sendImpieghi(const Impieghi&);
    DAnagrafici* returnDatiAnagrafici() const;
    TitoliStudio* returnTitoliStudio() const;
    Impieghi* returnImpieghi() const;

};

#endif // CLIENT_H
