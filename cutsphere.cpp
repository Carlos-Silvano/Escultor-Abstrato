#include "cutsphere.h"
#include <math.h>
cutSphere::cutSphere(int xcentro,int ycentro,int zcentro,int raio){
    this->xcentro=xcentro;
    this->ycentro=ycentro;
    this->zcentro=zcentro;
    this->raio=raio;
}

void cutSphere::draw(Sculptor &t){
    for(int i=xcentro-raio;i<xcentro+raio;i++){
        for(int j=ycentro-raio;j<ycentro+raio;j++){
            for(int k=zcentro-raio;k<zcentro+raio;k++){
                if((pow(i-xcentro,2)+pow(j-ycentro,2)+pow(k-zcentro,2))<= pow(raio,2)){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
