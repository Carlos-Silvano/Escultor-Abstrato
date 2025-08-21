#include "putellipsoid.h"
#include <math.h>
putEllipsoid::putEllipsoid(int xcentro,int ycentro,int zcentro, int rx,int ry,int rz,float r,float g,float b,float a){
    this->xcentro=xcentro;
    this->ycentro=ycentro;
    this->zcentro=zcentro;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

void putEllipsoid::draw(Sculptor &t){
    for(int i=xcentro-rx;i<=xcentro+rx;i++){
        for(int j=ycentro-ry;j<=ycentro+ry;j++){
            for(int k=zcentro-rz;k<=zcentro+rz;k++){
                if((pow((i-xcentro)*ry*rz,2)+pow((j-ycentro)*rx*rz,2)+pow((k-zcentro)*rx*ry,2))<=pow(rx*ry*rz,2)){
                    t.putVoxel(i,j,k,r,g,b,a);
                }
            }
        }
    }
}
