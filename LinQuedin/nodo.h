#ifndef NODO_H
#define NODO_H

#include <iostream>

class Utente;

class Nodo
{
public:
    Utente* utente;
    bool flag;
    Nodo();
    Nodo(Utente*,bool);
};

#endif // NODO_H
