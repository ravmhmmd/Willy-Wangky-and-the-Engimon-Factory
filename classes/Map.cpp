// File : Map.cpp

#include <iostream>
#include "Map.h"

using namespace std;

Map::Map(){
    //Matriks <Cell> maps(x,y)
    // input map
    ifstream inputMap;
    inputMap.open("mapFile.txt");

    // inisiasi matriks ukuran
    inputMap >> y;
    inputMap >> x;
    maps = new Tile**[y];
    entityMaps = new Tile**[y];
    for (int i = 0; i < y; i++){
        maps[i] = new Tile*[x];
        entityMaps[i] = new Tile*[x];
    }

    // inisiasi matriks isi
    for (int i = 0; i < y; i++){
        string symb;
        inputMap >> symb;
        for (int j = 0; j < x; j++){
            entityMaps[i][j] = new Tile(j,i,"#",false);
            if (symb[j] == '-'){
                maps[i][j] = new Tile(j,i,"-",false);
            }
            else if (symb[j] == 'o'){
                maps[i][j] = new Tile(j,i,"o",false);
            }
        }
    }

    this->maxEngimonLiar = 10;
    this->countEngimonLiar = 0;
}

bool Map::isGrassLand(int xc, int yc){
    if (maps[yc][xc]->getSymbol() == "-"){
        return true;
    }
    return false;
}

bool Map::isSea(int xc, int yc){
    if (maps[yc][xc]->getSymbol() == "o"){
        return true;
    }
    return false;
}

void Map::spawnEngimonLiar(Engimon e){
    if (countEngimonLiar < 10){
        int xEngLi = rand() % 12;
        int yEngLi = rand() % 10;
        countEngimonLiar = countEngimonLiar + 1;
        if (entityMaps[yEngLi][xEngLi]->getSymbol()=="#"){
            engimonInMap(e);
        }
    }
}

void Map::playerInMap(Player p){
    int xPosinMap = p.getX();
    int yPosinMap = p.getY();
    entityMaps[yPosinMap][xPosinMap]->setX(xPosinMap);
    entityMaps[yPosinMap][xPosinMap]->setY(yPosinMap);
    entityMaps[yPosinMap][xPosinMap]->setSymbol("P");
    entityMaps[yPosinMap][xPosinMap]->setIsAdaEntity(true);
    maps[yPosinMap][xPosinMap]->setIsAdaEntity(true);
}

void Map::engimonInMap(Engimon e){
    int minLeveltoCaps;
    int xPosinMap = e.getX();
    int yPosinMap = e.getY();
    int levEng = e.getLevel();
    string specEng = e.getSpecies();
    entityMaps[yPosinMap][xPosinMap]->setIsAdaEntity(true);
    if (e.getisActive() == true){
        entityMaps[yPosinMap][xPosinMap]->setSymbol("X");
    }
    else if (e.getisLiar() == true){
        if(levEng >= minLeveltoCaps){
            if(specEng == "watermon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("W");
            }
            else if(specEng == "watericemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("S");
            }
            else if(specEng == "watergroundmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("N");
            }
            else if(specEng == "icemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("I");
            }
            else if(specEng == "groundmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("G");
            }
            else if(specEng == "Firemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("F");
            }
            else if(specEng == "fireelectricmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("L");
            }
            else if(specEng == "electricmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("E");
            }
        }
        else if(levEng < minLeveltoCaps){
            if(specEng == "watermon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("w");
            }
            else if(specEng == "watericemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("s");
            }
            else if(specEng == "watergroundmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("n");
            }
            else if(specEng == "icemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("i");
            }
            else if(specEng == "groundmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("g");
            }
            else if(specEng == "Firemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("f");
            }
            else if(specEng == "fireelectricmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("l");
            }
            else if(specEng == "electricmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("e");
            }
        }
    }
}

void Map::printMap(){
    for(int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            if (entityMaps[i][j]->getSymbol() == "#"){
                cout<<maps[i][j]->getSymbol();
            }
            else{
                cout<<entityMaps[i][j]->getSymbol();
            }
        }
        cout<<endl;
    }
}

bool Map::isAdaPlayer(int xc, int yc){
    if (entityMaps[yc][xc]->getSymbol() == "P"){
        return true;
    }
    return false;
}

void Map::pseudomovePlayer(int beforeX, int beforeY, Player p){
    int afterX = p.getX();
    int afterY = p.getY();
    entityMaps[afterY][afterX]->setX(afterX);
    entityMaps[afterY][afterX]->setY(afterY);
    entityMaps[afterY][afterX]->setSymbol("P");
    entityMaps[afterY][afterX]->setIsAdaEntity(true);
    maps[afterY][afterX]->setIsAdaEntity(true);
    entityMaps[beforeY][beforeX]->setX(beforeX);
    entityMaps[beforeY][beforeX]->setY(beforeY);
    entityMaps[beforeY][beforeX]->setSymbol("#");
    entityMaps[beforeY][beforeX]->setIsAdaEntity(false);
    maps[beforeY][beforeX]->setIsAdaEntity(false);
}

void Map::pseudomoveEngimon(int beforeX, int beforeY, Engimon e){
    int minLeveltoCaps = 30;
    int xPosinMap = e.getX();
    int yPosinMap = e.getY();
    int levEng = e.getLevel();
    string specEng = e.getSpecies();
    entityMaps[yPosinMap][xPosinMap]->setIsAdaEntity(true);
    if (e.getisActive() == true){
        entityMaps[yPosinMap][xPosinMap]->setSymbol("X");
    }
    else if (e.getisLiar() == true){
        if(levEng >= minLeveltoCaps){
            if(specEng == "watermon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("W");
            }
            else if(specEng == "watericemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("S");
            }
            else if(specEng == "watergroundmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("N");
            }
            else if(specEng == "icemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("I");
            }
            else if(specEng == "groundmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("G");
            }
            else if(specEng == "Firemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("F");
            }
            else if(specEng == "fireelectricmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("L");
            }
            else if(specEng == "electricmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("E");
            }
        }
        else if(levEng < minLeveltoCaps){
            if(specEng == "watermon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("w");
            }
            else if(specEng == "watericemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("s");
            }
            else if(specEng == "watergroundmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("n");
            }
            else if(specEng == "icemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("i");
            }
            else if(specEng == "groundmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("g");
            }
            else if(specEng == "Firemon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("f");
            }
            else if(specEng == "fireelectricmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("l");
            }
            else if(specEng == "electricmon"){
                entityMaps[yPosinMap][xPosinMap]->setSymbol("e");
            }
        }
    }
    maps[yPosinMap][xPosinMap]->setIsAdaEntity(true);
    entityMaps[beforeY][beforeX]->setSymbol("#");
    entityMaps[yPosinMap][xPosinMap]->setIsAdaEntity(false);
    maps[beforeY][beforeX]->setIsAdaEntity(false);
}
