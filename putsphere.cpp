#include "putsphere.h"
#include <math.h>
putSphere::putSphere(int xcentro, int ycentro,int zcentro,int raio,float r,float g,float b,float a){

    this->xcentro = xcentro;
    this->ycentro = ycentro;
    this->zcentro = zcentro;
    this->raio = raio;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void putSphere::draw(Sculptor &t){
    for(int i=xcentro-raio;i<=xcentro+raio;i++){
        for(int j=ycentro-raio;j<=ycentro+raio;j++){
            for(int k=zcentro-raio;k<=zcentro+raio;k++){
                if((pow(i-xcentro,2)+pow(j-ycentro,2)+pow(k-zcentro,2))<= pow(raio,2)){
                    t.putVoxel(i,j,k,r,g,b,a);
                }
            }
        }
    }
}
