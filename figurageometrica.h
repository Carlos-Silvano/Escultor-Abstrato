#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"
class figurageometrica
{
public:
    figurageometrica();
    virtual ~figurageometrica();
    virtual void draw(Sculptor &t)=0;
};

#endif // FIGURAGEOMETRICA_H
