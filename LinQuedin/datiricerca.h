#ifndef DATIRICERCA_H
#define DATIRICERCA_H

#include <QString>

class DatiRicerca
{
private:
    QString username;
    QString nome;
    QString cognome;
    QString diploma;
    QString laurea;
    QString titolo;
    QString azienda;
public:
    void setUsername(const QString&);
    void setNome(const QString&);
    void setCognome(const QString&);
    void setDiploma(const QString&);
    void setLaurea(const QString&);
    void setTitolo(const QString&);
    void setAzienda(const QString&);
    QString getNome() const;
    QString getCognome() const;
    QString getDiploma() const;
    QString getLauree() const;
    QString getTitolo() const;
    QString getAzienda() const;
    DatiRicerca(const QString& user = "",const QString& a = "",const QString& b = "",const QString& c = "",const QString& d = "",const QString& e = "",const QString& f = "");
};

#endif // DATIRICERCA_H
