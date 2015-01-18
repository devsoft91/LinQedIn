#ifndef DANAGRAFICI_H
#define DANAGRAFICI_H

#include <QString>
#include <QDate>

class DAnagrafici
{
private:
    QString nome;
    QString cognome;
    QString email;
    QDate data_nascita;
    QString luogo_nascita;
    QString luogo_residenza;

public:
    DAnagrafici();
    DAnagrafici(const QString&,const QString&,const QString&,const QDate&,const QString&,const QString&);
    //distruttore standard

    void setNome(const QString&);
    void setCognome(const QString&);
    void setEmail(const QString&);
    void setData_nascita(const QDate&);
    void setLuogo_nascita(const QString&);
    void setLuogo_residenza(const QString&);

    QString getNome() const;
    QString getCognome() const;
    QString getEmail() const;
    QDate getData_nascita() const;
    QString getLuogo_nascita() const;
    QString getLuogo_residenza() const;

    void operator=(const DAnagrafici&);
};

#endif // DANAGRAFICI_H
