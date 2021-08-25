#ifndef CELL_H
#define CELL_H


#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Cell {
    private:
        int x;
        int y;
        string symbol;
        /* list symbol :
           W = water hi level
           w = water low level
           I = ice hi level
           i = ice low level
           F = fire hi level
           f = fire low level
           G = ground hi level
           g = ground low level
           E = electric hi level
           e = electric low level
           L = fire electric hi level
           l = fire electric low level
           S = water ice hi level
           s = water ice low level
           N = water ground hi level
           n = water ground low level
           P = player
           X = active engimon
           - = grassland
           o = sea
        */

    public:
        Cell();
        Cell(int xc, int yc,string sc);
        int getX();
        int getY();
        string getSymbol();
        void setX(int xc);
        void setY(int yc);
        void setSymbol(string sc);
};

class Tile : public Cell {
    protected :
        bool isAdaEntity;
    public :
        Tile(int xc, int yc, string sc, bool entityc):Cell(xc,yc,sc){
            this->isAdaEntity = entityc;
        }
        bool getIsAdaEntity(){
            return isAdaEntity;
        }
        void setIsAdaEntity(bool entityc){
            this->isAdaEntity = entityc;
        }
};

class Grassland : public Tile {
    public :
        Grassland(int xc, int yc, string sc, bool entityc):Tile(xc,yc,sc,entityc){}
};

class Sea : public Tile {
    public :
        Sea(int xc, int yc, string sc, bool entityc):Tile(xc,yc,sc,entityc){}
};

class EntityInMap : public Cell {
    protected :
        string tipeEntity;
        /* player   = player
           engaktif = engimon aktif
           engliar  = engimon liar
           empty    = kosong */
    public :
        EntityInMap(int xc, int yc, string sc, string tipe):Cell(xc,yc,sc){
            this->tipeEntity = tipe;
        }
        string getTipeEntity(){
            return this->tipeEntity;
        }
        void setTipeEntity(string tipe){
            this->tipeEntity = tipe;
        }
};

#endif
