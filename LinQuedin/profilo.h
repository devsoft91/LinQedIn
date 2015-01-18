#ifndef PROFILO_H
#define PROFILO_H

#include "danagrafici.h"
#include "titolistudio.h"
#include "impieghi.h"

class Profilo
{
private:
    DAnagrafici dati;
    TitoliStudio titoli;
    Impieghi impieghi;
public:
    Profilo();
    Profilo(const DAnagrafici&,const TitoliStudio&);
    Profilo(const DAnagrafici&,const TitoliStudio&,const Impieghi&);
    void setDati(const DAnagrafici&);
    void setTitoli(const TitoliStudio&);
    void setImpieghi(const Impieghi&);
    DAnagrafici getDati() const;
    TitoliStudio getTitoli() const;
    Impieghi getImpieghi() const;
};

#endif // PROFILO_H
