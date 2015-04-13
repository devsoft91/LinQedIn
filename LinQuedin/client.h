#ifndef CLIENT_H
#define CLIENT_H

using namespace std;

#include "controller.h"
#include "utente.h"
class DatiRicerca;

class Client : public virtual Controller
{
public:
    Utente* u;
    Database* data_;
    map<QString,Utente*> risultati;
    void stampa() const;
    void initialize(const QString&);
    void saveDatabase();
    void sendDatiAnagrafici(const DAnagrafici&);
    void sendTitoliStudio(const TitoliStudio&);
    void sendDiploma(const QString&,int);
    void sendImpiego(const Impieghi&);
    void sendLavoro(const Lavoro&);
    void sendLavoro(const Lavoro&,bool);
    void sendLaurea(const Laurea&);
    void sendLaurea(const QString&,const Laurea&);
    void sendRicerca(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&,const QString&);
    void addToNet(const QString&);
    DAnagrafici* returnDatiAnagrafici() const;
    TitoliStudio* returnTitoliStudio() const;
    Impieghi* returnImpieghi() const;
    map<QString,Nodo> returnRete() const;
    int returnUserType() const;
    map<QString,Utente*> returnRicerca() const;
    bool isFriendOf(const QString&) const;

    void removeFromNet(const QString&);

    Client(const QString&,Database* = 0);
    ~Client();

};

#endif // CLIENT_H
