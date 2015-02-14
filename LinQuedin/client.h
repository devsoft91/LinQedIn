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
    void sendDatiAnagrafici(const DAnagrafici&);
    void saveDatabase();
    DAnagrafici* returnDatiAnagrafici() const;

};

#endif // CLIENT_H
