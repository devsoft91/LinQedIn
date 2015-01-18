#include "laurea.h"

Laurea::Laurea(const QString& a,int b) : nome(a),anno(b)
{
// da completareeeeeeeeee
}

QString Laurea::getNome() const{
    return nome;
}

int Laurea::getAnno() const{
    return anno;
}

void Laurea::setNome(const QString& n){
    nome = n;
}

void Laurea::setAnno(const int& a){
    anno = a;
}
