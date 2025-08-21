#include "cutellipsoid.h"
#include <math.h>
cutEllipsoid::cutEllipsoid(int xcentro,int ycentro,int zcentro,int rx,int ry,int rz){
    this->xcentro=xcentro;
    this->ycentro=ycentro;
    this->zcentro=zcentro;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
}

void cutEllipsoid::draw(Sculptor &t){
    for(int i=xcentro-rx;i<xcentro+rx;i++){
        for(int j=ycentro-ry;j<ycentro+ry;j++){
            for(int k=zcentro-rz;k<zcentro+rz;k++){
                if((pow((i-xcentro)*ry*rz,2)+pow((j-ycentro)*rx*rz,2)+pow((k-zcentro)*rx*ry,2))<=pow(rx*ry*rz,2)){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
