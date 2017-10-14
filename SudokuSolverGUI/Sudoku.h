#include <vector>
#include "Position.h"

#pragma once

class Sudoku
{
private:
	std::vector <int> storage;
	
	std::vector<int> getRowValues(int row);
	std::vector<int> getColValues(int col);
	std::vector<int> getBoxValues(int number);
public:
	Sudoku();
	void setValue(int value, Position pos);
	void removeValue(Position pos);
	int getValueFor(Position pos);
	bool allConstraintsOK();
	bool constraintsForCellOK(Position pos);
	std::vector<Position> getUnFilledPositions();
	std::vector<Position> getFilledPositions();
	int Sudoku::computeConstraintsFor(Position pos);
	void Sudoku::clearValues();
	~Sudoku();
};