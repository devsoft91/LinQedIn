#ifndef IMPIEGHI_H
#define IMPIEGHI_H

#include "lavoro.h"

#include <vector>

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
};

#endif // IMPIEGHI_H
