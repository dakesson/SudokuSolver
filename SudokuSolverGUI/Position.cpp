#include <math.h>
#include "Position.h"

Position::Position(int row, int col)
{
	this->storagePos = row * NUM_COL + col;
}

Position::Position(int storagePos)
{
	this->storagePos = storagePos;
}

int Position::getRow()
{
	return (storagePos / NUM_ROW);
}

int Position::getCol()
{
	return (storagePos % NUM_ROW);
}

int Position::getStoragePos()
{
	return storagePos;
}

int Position::getBox()
{
	return floor(getRow() / 3) * 3 + floor(getCol() / 3);
}

Position::~Position()
{
}