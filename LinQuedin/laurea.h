#ifndef LAUREA_H
#define LAUREA_H

#include<QString>

class Laurea
{
private:
    QString nome;
    int anno;
public:
    Laurea(const QString& ="",int =0);
    QString getNome() const;
    int getAnno() const;
    void setNome(const QString&);
    void setAnno(const int&);
};

#endif // LAUREA_H
