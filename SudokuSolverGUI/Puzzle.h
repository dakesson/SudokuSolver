#include <vector>
#include "Position.h"

#pragma once

class Puzzle
{
private:
	std::vector <int> storage;
	
	std::vector<int> getRowValues(int row);
	std::vector<int> getColValues(int col);
	std::vector<int> getQuadrantValues(int number);
public:
	Puzzle();
	~Puzzle();
	void setValue(int value, Position pos);
	int getValueFor(Position pos);

	bool allConstraintsOK();
	bool constraintsForCellOk(Position pos);
	std::vector<Position> getAvailablePositions();

	void runUnitTests();
};