#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class cutSphere : public figurageometrica
{
private:
    int xcentro,ycentro,zcentro,raio;
public:
    cutSphere(int xcentro,int ycentro,int zcentro,int raio);
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
