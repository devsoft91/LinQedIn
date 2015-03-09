#ifndef LAVORO_H
#define LAVORO_H

#include<QString>
#include<QDate>

class Lavoro
{
private:
    QString titolo;
    QString azienda;
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
    void setAzienda(const QString&);
    void setTitolo(const QString&);
    void setCitta(const QString&);
    void setInizio(const QDate&);
    void setFine(const QDate&);
    bool operator==(const Lavoro&) const;
};

#endif // LAVORO_H
