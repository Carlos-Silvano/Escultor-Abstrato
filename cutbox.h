#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"

class cutBox : public figurageometrica
{
private:
    int x0,y0,z0,x1,y1,z1;
public:
    cutBox(int x0,int y0,int z0,int x1,int y1,int z1);
    void draw(Sculptor &t);
};

#endif // CUTBOX_H
