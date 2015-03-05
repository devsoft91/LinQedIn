#ifndef TITOLISTUDIO_H
#define TITOLISTUDIO_H

#include "laurea.h"

#include <QString>
#include <vector>

using std::vector;

class TitoliStudio
{
private:
    QString diploma;
    int anno;
    vector<Laurea> lauree;
public:
    TitoliStudio();
    TitoliStudio(const QString&,int); // da completareeeeeee
    TitoliStudio(const QString&,int,const Laurea&); // da completareeeeeee
    QString getDiploma() const;
    int getAnno() const;
    vector<Laurea> getLaurea() const;
    void setDiploma(const QString&);
    void setAnno(const int&);
    void addLaurea(const Laurea&);
    void updateLaurea(const QString&,const Laurea&);
    void removeLaurea(const QString&);
    //elimina un elemento
    //distruttore di default

};

#endif // TITOLISTUDIO_H
