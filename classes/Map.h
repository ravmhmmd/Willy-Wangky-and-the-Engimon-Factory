// File : map.h

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "Cell.h"
#include "Entities.h"
#include "Player.h"
#include "Engimon.h"

using namespace std;

class Map {
    private :
        int x, y;
        Tile ***maps;
        Tile ***entityMaps;
        int maxEngimonLiar;
        int countEngimonLiar;

    public :
        Map();
        bool isGrassLand(int xc, int yc);
        bool isSea(int xc, int yc);
        void spawnEngimonLiar(Engimon e);
        //void entityInMap(int x, int y);
        void playerInMap(Player p);
        void engimonInMap(Engimon e);
        //void loadMap(Matriks M, int xMapSize, int yMapSize, char fileName);
        void printMap();
        void printEntity();
        //void setCell();
        bool isAdaPlayer(int xc, int yc);
        void pseudomovePlayer(int beforeX, int beforeY, Player p);
        void pseudomoveEngimon(int beforeX, int beforeY, Engimon e);
};

#endif
