#pragma once

#include "Sudoku.h"

class SudokuGenerator
{
private:
	void addRandomInitialValuesTo(Sudoku *sudoku);
	void fillAllCellsWithValues(Sudoku *sudoku);
	void removeRandomValuesUntilOneSolution(Sudoku *sudoku);
public:
	SudokuGenerator();
	~SudokuGenerator();
	Sudoku* generate();
};

