#include <vector>
#include "Position.h"

#pragma once

class Puzzle
{
private:
	std::vector <int> storage;
	
	std::vector<int> getRowValues(int row);
	std::vector<int> getColValues(int col);
	std::vector<int> getBoxValues(int number);
public:
	Puzzle();
	void setValue(int value, Position pos);
	void removeValue(Position pos);
	int getValueFor(Position pos);
	bool allConstraintsOK();
	bool constraintsForCellOK(Position pos);
	std::vector<Position> getUnFilledPositions();
	std::vector<Position> getFilledPositions();
	int Puzzle::computeConstraintsFor(Position pos);
	void Puzzle::clearValues();
	~Puzzle();
};