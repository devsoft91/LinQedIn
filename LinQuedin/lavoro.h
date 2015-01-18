#ifndef LAVORO_H
#define LAVORO_H

#include<QString>
#include<QDate>

class Lavoro
{
private:
    QString azienda;
    QString titolo;
    QString citta;
    QDate inizio;
    QDate fine;
public:
    Lavoro();
    Lavoro(const QString&,const QString&,const QString&,const QDate&,const QDate&);
    QString getAzienda() const;
    QString getTitolo() const;
    QString getCitta() const;
    QDate getInizio() const;
    QDate getFine() const;
};

#endif // LAVORO_H
