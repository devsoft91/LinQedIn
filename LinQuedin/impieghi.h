#ifndef IMPIEGHI_H
#define IMPIEGHI_H

#include <vector>

#include "lavoro.h"

using std::list;

class Impieghi
{
private:
    list<Lavoro> impieghi;
public:
    Impieghi();
    Impieghi(const Lavoro&);
    list<Lavoro> getLavori() const;
    void addLavoro(const Lavoro&);
    void addLavoro(const Lavoro&,bool);
    void removeLavoro(const Lavoro&);
    void updateLavoro(const Lavoro&,const Lavoro&);
};

#endif // IMPIEGHI_H
