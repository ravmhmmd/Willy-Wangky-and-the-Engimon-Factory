#include "Cell.h"

Cell::Cell(){
    this->x = 0;
    this->y = 0;
    this->symbol = "#";
}

Cell::Cell(int xc, int yc, string sc){
    this->x = xc;
    this->y = yc;
    this->symbol = sc;
}

int Cell::getX(){
    return x;
}

int Cell::getY(){
    return y;
}

string Cell::getSymbol(){
    return symbol;
}

void Cell::setX(int xc){
    this->x = xc;
}

void Cell::setY(int yc){
    this->y = yc;
}

void Cell::setSymbol(string sc){
    this->symbol = sc;
}
