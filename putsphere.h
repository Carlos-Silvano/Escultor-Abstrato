#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

class putSphere : public figurageometrica
{
private:
    int xcentro,ycentro,zcentro,raio;
    float r,g,b,a;
public:
    putSphere(int xcentro,int ycentro,int zcentro,int raio,float r,float g,float b,float a);

    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
