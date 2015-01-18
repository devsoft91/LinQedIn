#include "danagrafici.h"

DAnagrafici::DAnagrafici(){}

DAnagrafici::DAnagrafici(const QString& n,const QString& c,const QString& e,const QDate& d,const QString& ln,const QString& lr) : nome(n),cognome(c),email(e),data_nascita(d),luogo_nascita(ln),luogo_residenza(lr){}

void DAnagrafici::setNome(const QString& z){
    nome = z;
}

void DAnagrafici::setCognome(const QString& z){
    cognome = z;
}

void DAnagrafici::setEmail(const QString& z){
    email = z;
}

void DAnagrafici::setData_nascita(const QDate& z){
    data_nascita = z;
}

void DAnagrafici::setLuogo_nascita(const QString& z){
    luogo_nascita = z;
}

void DAnagrafici::setLuogo_residenza(const QString& z){
    luogo_residenza = z;
}

QString DAnagrafici::getNome() const{
    return nome;
}
QString DAnagrafici::getCognome() const{
    return cognome;
}
QString DAnagrafici::getEmail() const{
    return email;
}
QDate DAnagrafici::getData_nascita() const{
    return data_nascita;
}
QString DAnagrafici::getLuogo_nascita() const{
    return luogo_nascita;
}
QString DAnagrafici::getLuogo_residenza() const{
    return luogo_residenza;
}

void DAnagrafici::operator=(const DAnagrafici& a){
    nome = a.getNome();
    cognome = a.getCognome();
    email = a.getEmail();
    data_nascita = a.getData_nascita();
    luogo_nascita = a.getLuogo_nascita();
    luogo_residenza = a.getLuogo_residenza();
}
