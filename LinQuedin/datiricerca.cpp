#include "datiricerca.h"

DatiRicerca::DatiRicerca(const QString& user,const QString& a,const QString& b,const QString& c,const QString& d,const QString& e,const QString& f) : username(user),nome(a),cognome(b),diploma(c),laurea(d),titolo(e),azienda(f){}

void DatiRicerca::setUsername(const QString& user){
    username = user;
}

void DatiRicerca::setNome(const QString& s){
    nome = s;
}

void DatiRicerca::setCognome(const QString& s){
    cognome = s;
}

void DatiRicerca::setDiploma(const QString& s){
    diploma = s;
}

void DatiRicerca::setLaurea(const QString& s){
    laurea = s;
}

void DatiRicerca::setTitolo(const QString& s){
    titolo = s;
}

void DatiRicerca::setAzienda(const QString& s){
    azienda = s;
}

QString DatiRicerca::getNome() const{
    return nome;
}

QString DatiRicerca::getCognome() const{
    return cognome;
}

QString DatiRicerca::getDiploma() const{
    return diploma;
}

QString DatiRicerca::getLauree() const{
    return laurea;
}

QString DatiRicerca::getTitolo() const{
    return titolo;
}

QString DatiRicerca::getAzienda() const{
    return azienda;
}
