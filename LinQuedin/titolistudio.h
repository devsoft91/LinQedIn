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
    TitoliStudio(const QString&,int);
    TitoliStudio(const QString&,int,const Laurea&);
    QString getDiploma() const;
    int getAnno() const;
    vector<Laurea> getLauree() const;
    void setDiploma(const QString&);
    void setAnno(const int&);
    void addLaurea(const Laurea&);
    void updateLaurea(const QString&,const Laurea&);
    void removeLaurea(const QString&);

};

#endif // TITOLISTUDIO_H
