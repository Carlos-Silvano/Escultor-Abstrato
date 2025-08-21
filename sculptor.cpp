#include "sculptor.h"
#include <fstream>
#include <cmath>
#include <iostream>
#include <iomanip>
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    v = new Voxel**[nx];
    for(int i = 0; i <nx;i++){
        v[i] = new Voxel*[ny];
        for(int j = 0;j<ny;j++){
            v[i][j] = new Voxel[nz];
            for(int k = 0;k<nz;k++){
                v[i][j][k].show = false;
            }
        }

    }
}

Sculptor::~Sculptor(){
    for(int i = 0;i<nx;i++){
        for(int j = 0;j<ny;j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}
void Sculptor::putVoxel(int x, int y, int z, float r, float g, float b, float a){

        v[x][y][z].show=true;
        v[x][y][z].r=r;
        v[x][y][z].g=g;
        v[x][y][z].b=b;
        v[x][y][z].a=a;

}
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false;
}

void Sculptor::writeOFF(const char* filename){
    std::ofstream fout;
    fout << std::fixed << std::setprecision(2);
    int nvoxels = 0;

    fout.open(filename);
    if (!fout.is_open()) {
        std::cerr<<"ERRO AO ABRIR"<<std::endl;
        exit(1);
    }
    for(int i=0;i<nx;i++){
        for(int j = 0;j<ny;j++){
            for(int k = 0;k<nz;k++){
                if(v[i][j][k].show){
                    nvoxels++;
                }
            }
        }
    }
    int nvertices = nvoxels * 8;
    int nfaces = nvoxels * 6;
    fout << "OFF\n";
    fout << nvoxels * 8 << " " << nvoxels * 6 << " 0\n";
    // escrever os vertices
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].show ){
                    for(int i0=i;i0<=i+1;i0++){
                        for(int j0=j;j0<=j+1;j0++){
                            for(int k0=k;k0<=k+1;k0++){
                                fout << i0 << " " << j0 << " " << k0 << " \n";
                            }
                        }
                    }
                }
            }
        }
    }
    int v1 = 0;
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].show ){

                    fout << "4 "<< v1+0 << " " << v1+1 << " " << v1+3 << " " << v1+2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+4 << " " << v1+5 << " " << v1+7 << " " << v1+6 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+0 << " " << v1+2 << " " << v1+6 << " " << v1+4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+1 << " " << v1+5 << " " << v1+7 << " " << v1+3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+2 << " " << v1+3 << " " << v1+7 << " " << v1+6 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+0 << " " << v1+1 << " " << v1+5 << " " << v1+4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    v1+=8;
                }
            }
        }
    }
    // escrever as faces
    fout.close();

}
