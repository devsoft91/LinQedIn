#ifndef NODO_H
#define NODO_H

class Utente;

class Nodo
{
private:
    Utente* utente;
    bool flag;
public:
    Nodo();
    Nodo(Utente*,bool);
    void setUtente(Utente*);
    void setFlag(bool);
    Utente* getUtente() const;
    bool getFlag() const;
};

#endif // NODO_H
