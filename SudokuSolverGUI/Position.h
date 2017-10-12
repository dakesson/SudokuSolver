#pragma once

const int NUM_ROW = 9;
const int NUM_COL = 9;

class Position
{
private:
	int storagePos;
	Position();
public:
	Position(int row, int col);
	Position(int storagePos);
	int getRow();
	int getCol();
	int getStoragePos();
	int getBox();
	~Position();
};