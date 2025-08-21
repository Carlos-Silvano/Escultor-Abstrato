#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

class putEllipsoid : public figurageometrica
{
private:
    int xcentro,ycentro,zcentro,rx,ry,rz;
    float r,g,b,a;
public:
    putEllipsoid(int xcentro,int ycentro,int zcentro,int rx,int ry,int rz,float r,float g,float b,float a);

    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
