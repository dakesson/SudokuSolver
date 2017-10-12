#include "Puzzle.h"
#include "Utility.h"


Puzzle::Puzzle()
{
	this->storage = std::vector<int>(NUM_ROW * NUM_COL);
}

Puzzle::~Puzzle()
{
}

void Puzzle::setValue(int value, Position pos)
{
	storage[pos.getStoragePos()] = value;
}

int Puzzle::getValueFor(Position pos)
{
	return storage[pos.getStoragePos()];
}

std::vector<int>Puzzle::getRowValues(int row) 
{
	std::vector<int> rowValues;
	for (int col = 0; col < NUM_COL; col++)
	{
		int value = getValueFor(Position(row,col));
		if (value)
			rowValues.push_back(value);
	}
	return rowValues;
}

std::vector<int> Puzzle::getColValues(int col)
{
	std::vector<int> colValues; // INHERIT VECTOR AND CUSTOM FUNC FOR NULL ADDING?
	for (int row = 0; row < NUM_ROW; row++)
	{
		int value = getValueFor(Position(row, col));
		if (value)
			colValues.push_back(value);
	}
		

	return colValues;
}

std::vector<int> Puzzle::getQuadrantValues(int number)
{
	//Counting number row wise from top left (0-8)
	std::vector<int> quadrantValues;
	
	int startRow = floor(number / 3) * 3;
	for (int row = startRow; row < startRow + 3; row++)
	{
		int startCol = (number % 3) * 3;
		for (int col = startCol; col < startCol + 3; col++)
		{
			int value = getValueFor(Position(row, col));
			if (value)
				quadrantValues.push_back(value);
		}
	}

	return quadrantValues;
}

bool Puzzle::allConstraintsOK()
{
	for (int i = 0; i < 9; i++)
	{
		if (utility::containsDuplicates(getRowValues(i)))
			return false;

		if (utility::containsDuplicates(getColValues(i)))
			return false;

		std::vector<int> t = getQuadrantValues(i);
		if (utility::containsDuplicates(getQuadrantValues(i)))
			return false;
	}
	
	return true;
}

bool Puzzle::constraintsForCellOk(Position pos)
{
	if (utility::containsDuplicates(getRowValues(pos.getRow())))
		return false;

	if (utility::containsDuplicates(getColValues(pos.getCol())))
		return false;

	if (utility::containsDuplicates(getQuadrantValues(pos.getQuadrant())))
		return false;

	return true;
}

std::vector<Position> Puzzle::getAvailablePositions()
{
	std::vector<Position> result;
	for (int i = 0; i < this->storage.size(); i++) {
		if (!storage[i])
			result.push_back(Position(i));
	}
	return result;
}

void Puzzle::runUnitTests() 
{	
	/*
	bool test1 = (squareNumberForCell(0, 0) == 0);
	bool test2 = (squareNumberForCell(8, 0) == 6);
	bool test3 = (squareNumberForCell(0, 7) == 2);
	bool test4 = (squareNumberForCell(7, 7) == 8);

	std::vector<int> vtest1 = getQuadrantValues(2);
	std::vector<int> vtest2 = getQuadrantValues(3);
	std::vector<int> vtest3 = getQuadrantValues(8);
	*/

}

