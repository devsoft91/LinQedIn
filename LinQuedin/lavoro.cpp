#include "lavoro.h"

Lavoro::Lavoro(){}

Lavoro::Lavoro(const QString& a,const QString& t,const QString& c,const QDate& i,const QDate& f):
    titolo(a),azienda(t),citta(c),inizio(i)
{
    if(!f.isNull())
        fine=f;
}

QString Lavoro::getAzienda() const{
    return azienda;
}
QString Lavoro::getTitolo() const{
    return titolo;
}
QString Lavoro::getCitta() const{
    return citta;
}
QDate Lavoro::getInizio() const{
    return inizio;
}
QDate Lavoro::getFine() const{
    return fine;
}

void Lavoro::setTitolo(const QString& s){
    titolo = s;
}

void Lavoro::setAzienda(const QString& s){
    azienda = s;
}

void Lavoro::setCitta(const QString& s){
    citta = s;
}

void Lavoro::setInizio(const QDate& d){
    inizio = d;
}

void Lavoro::setFine(const QDate& d){
    fine = d;
}

bool Lavoro::operator==(const Lavoro& l) const{
    return getTitolo()==l.getTitolo() && getAzienda()==l.getAzienda() && getCitta()==l.getCitta() && getInizio()==l.getInizio() && getFine()==l.getFine();
}
