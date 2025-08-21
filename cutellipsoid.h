#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class cutEllipsoid : public figurageometrica
{
private:
    int xcentro,ycentro,zcentro,rx,ry,rz;
public:
    cutEllipsoid(int xcentro,int ycentro,int zcentro,int rx,int ry,int rz);
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
