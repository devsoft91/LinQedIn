#include "lavoro.h"

Lavoro::Lavoro(){}

Lavoro::Lavoro(const QString& a,const QString& t,const QString& c,const QDate& i,const QDate& f):
    azienda(a),titolo(t),citta(c),inizio(i)
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
