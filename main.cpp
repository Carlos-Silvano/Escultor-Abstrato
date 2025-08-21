#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "sculptor.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"
int main(){
    std::string s;
    std::ifstream fin;
    std::vector<figurageometrica *> fig;
    int largura=0, altura=0, profundidade=0;

    fin.open("robo2.txt");
    if(!fin.is_open()){
        exit(0);
    }
    while(fin.good()){
        fin >> s;
        if(fin.good()){
            if (s.compare("dim") == 0){
                fin >> largura >> altura >> profundidade;
            }

            else if(s.compare("putvoxel") == 0){
                int x,y,z;
                float r,g,b,a;
                fin >> x >> y >> z >> r >> g >> b >> a;
                fig.push_back(new putVoxel(x,y,z,r,g,b,a));
            }
            else if(s.compare("cutvoxel") == 0){
                int x,y,z;
                fin >> x >> y >> z;
                fig.push_back(new cutVoxel(x,y,z));
            }


            else if(s.compare("putbox") == 0){
                int x0,x1,y0,y1,z0,z1;
                float r,g,b,a;
                fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1 >> r >> g >> b >> a;
                fig.push_back(new putBox(x0,y0,z0,x1,y1,z1,r,g,b,a));
            }
            else if(s.compare("cutbox") == 0){
                int x0,x1,y0,y1,z0,z1;
                fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
                fig.push_back(new cutBox(x0,y0,z0,x1,y1,z1));
            }


            else if(s.compare("putsphere") == 0){
                int xcentro,ycentro,zcentro,raio;
                float r,g,b,a;
                fin >> xcentro >> ycentro >> zcentro >> raio >> r >> g >> b >> a;
                fig.push_back(new putSphere(xcentro,ycentro,zcentro,raio,r,g,b,a));
            }
            else if(s.compare("cutsphere") == 0){
                int xcentro,ycentro,zcentro,raio;
                fin >> xcentro >> ycentro >> zcentro >> raio;
                fig.push_back(new cutSphere(xcentro,ycentro,zcentro,raio));
            }


            else if(s.compare("putellipsoid") == 0){
                int xcentro,ycentro,zcentro,rx,ry,rz;
                float r,g,b,a;
                fin >> xcentro >> ycentro >> zcentro >> rx >> ry >> rz >> r >> g >> b >> a;
                fig.push_back(new putEllipsoid(xcentro,ycentro,zcentro,rx,ry,rz,r,g,b,a));
            }
            else if(s.compare("cutellipsoid") == 0){
                int xcentro,ycentro,zcentro,rx,ry,rz;
                fin >> xcentro >> ycentro >> zcentro >> rx >> ry >> rz;
                fig.push_back(new cutEllipsoid(xcentro,ycentro,zcentro,rx,ry,rz));
            }

        }
    }

    Sculptor vox(largura,altura,profundidade);
    for(auto i : fig){
        i->draw(vox);
    }

    vox.writeOFF("robo2.OFF");

    for(auto i : fig){
        delete i;
    }

    return 0;
}
