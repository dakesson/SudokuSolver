#include "Puzzle.h"
#include "Utility.h"


Puzzle::Puzzle()
{
	this->storage = std::vector<int>(NUM_ROW * NUM_COL);
}

void Puzzle::setValue(int value, Position pos)
{
	storage[pos.getStoragePos()] = value;
}

void Puzzle::removeValue(Position pos)
{
	setValue(NULL, pos);
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
	std::vector<int> colValues;
	for (int row = 0; row < NUM_ROW; row++)
	{
		int value = getValueFor(Position(row, col));
		if (value)
			colValues.push_back(value);
	}
	return colValues;
}

std::vector<int> Puzzle::getBoxValues(int number)
{
	std::vector<int> BoxValues;
	
	int startRow = floor(number / 3) * 3;
	for (int row = startRow; row < startRow + 3; row++)
	{
		int startCol = (number % 3) * 3;
		for (int col = startCol; col < startCol + 3; col++)
		{
			int value = getValueFor(Position(row, col));
			if (value)
				BoxValues.push_back(value);
		}
	}
	return BoxValues;
}

bool Puzzle::allConstraintsOK()
{
	for (int i = 0; i < 9; i++)
	{
		if (utility::containsDuplicates(getRowValues(i)))
			return false;

		if (utility::containsDuplicates(getColValues(i)))
			return false;

		std::vector<int> t = getBoxValues(i);
		if (utility::containsDuplicates(getBoxValues(i)))
			return false;
	}	
	return true;
}

bool Puzzle::constraintsForCellOK(Position pos)
{
	if (utility::containsDuplicates(getRowValues(pos.getRow())))
		return false;

	if (utility::containsDuplicates(getColValues(pos.getCol())))
		return false;

	if (utility::containsDuplicates(getBoxValues(pos.getBox())))
		return false;

	return true;
}

std::vector<Position> Puzzle::getUnFilledPositions()
{
	std::vector<Position> result;
	for (int i = 0; i < this->storage.size(); i++) {
		if (!storage[i])
			result.push_back(Position(i));		
	}
	return result;
}

std::vector<Position> Puzzle::getFilledPositions()
{
	std::vector<Position> result;
	for (int i = 0; i < this->storage.size(); i++) {
		if (storage[i])
			result.push_back(Position(i));
	}
	return result;
}

int Puzzle::computeConstraintsFor(Position pos)
{
	std::vector<int> constraints;

	std::vector<int> rowValues = getRowValues(pos.getRow());
	constraints.insert(constraints.end(), rowValues.begin(), rowValues.end());

	std::vector<int> colValues = getColValues(pos.getCol());
	constraints.insert(constraints.end(), colValues.begin(), colValues.end());

	std::vector<int> boxValues = getBoxValues(pos.getBox());
	constraints.insert(constraints.end(), boxValues.begin(), boxValues.end());

	return utility::countUniqueValues(constraints);
}

void Puzzle::clearValues()
{
	this->storage = std::vector<int>(NUM_ROW * NUM_COL);
}

Puzzle::~Puzzle()
{
}