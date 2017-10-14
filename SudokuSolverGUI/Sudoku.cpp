#include "Sudoku.h"
#include "Utility.h"


Sudoku::Sudoku()
{
	storage = std::vector<int>(NUM_ROW * NUM_COL);
}

void Sudoku::setValue(int value, Position pos)
{
	storage[pos.getStoragePos()] = value;
}

void Sudoku::removeValue(Position pos)
{
	setValue(NULL, pos);
}

int Sudoku::getValueFor(Position pos)
{
	return storage[pos.getStoragePos()];
}

std::vector<int>Sudoku::getRowValues(int row) 
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

std::vector<int> Sudoku::getColValues(int col)
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

std::vector<int> Sudoku::getBoxValues(int number)
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

bool Sudoku::allConstraintsOK()
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

bool Sudoku::constraintsForCellOK(Position pos)
{
	if (utility::containsDuplicates(getRowValues(pos.getRow())))
		return false;

	if (utility::containsDuplicates(getColValues(pos.getCol())))
		return false;

	if (utility::containsDuplicates(getBoxValues(pos.getBox())))
		return false;

	return true;
}

std::vector<Position> Sudoku::getUnFilledPositions()
{
	std::vector<Position> result;
	for (int i = 0; i < this->storage.size(); i++) {
		if (!storage[i])
			result.push_back(Position(i));		
	}
	return result;
}

std::vector<Position> Sudoku::getFilledPositions()
{
	std::vector<Position> result;
	for (int i = 0; i < this->storage.size(); i++) {
		if (storage[i])
			result.push_back(Position(i));
	}
	return result;
}

int Sudoku::computeConstraintsFor(Position pos)
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

void Sudoku::clearValues()
{
	this->storage = std::vector<int>(NUM_ROW * NUM_COL);
}

Sudoku::~Sudoku()
{
}