#ifndef IMPIEGHI_H
#define IMPIEGHI_H

#include <vector>

#include "lavoro.h"

using std::vector;

class Impieghi
{
private:
    vector<Lavoro> impieghi;
public:
    Impieghi();
    Impieghi(const Lavoro&);
    vector<Lavoro> getLavoro() const;
    void addLavoro(const Lavoro&);
    void removeLavoro(const Lavoro&);
    void updateLavoro(const Lavoro&,const Lavoro&);
};

#endif // IMPIEGHI_H
