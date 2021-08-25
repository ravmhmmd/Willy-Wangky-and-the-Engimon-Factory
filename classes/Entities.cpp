#include "Entities.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
// #include "Map.h"

Entities::Entities()
{
	this->posX = 0;
	this->posY = 0;
}

Entities::Entities(int x, int y)
{
	this->posX = x;
	this->posY = y;
}

Entities::Entities(const Entities &other)
{
	this->posX = other.posX;
	this->posY = other.posY;
}

Entities::~Entities()
{
}

Entities &Entities::operator=(const Entities &other)
{
	this->posX = other.posX;
	this->posY = other.posY;
	return *this;
}

int Entities::getX() const
{
	return posX;
}

int Entities::getY() const
{
	return posY;
}

void Entities::setX(int x)
{
	posX = x;
}

void Entities::setY(int y)
{
	posY = y;
}

// move2an nunggu map

void Entities::move(int x, int y)
{
	int deltaX = x - posX, deltaY = y - posY;
	int tempx = posX, tempy = posY;

	if (!((deltaX == 0 && deltaY == 1)		// N
		  || (deltaX == 1 && deltaY == 1)	// NE
		  || (deltaX == 1 && deltaY == 0)	// E
		  || (deltaX == 1 && deltaY == -1)	// SE
		  || (deltaX == 0 && deltaY == -1)	// S
		  || (deltaX == -1 && deltaY == -1) // SW
		  || (deltaX == -1 && deltaY == 0)	// W
		  || (deltaX == -1 && deltaY == 1)))
	{ // NW
		throw "invalid direction";
	}

	posX = x;
	posY = y;

	//map->pseudomovePlayer(tempx, tempy, this);
}