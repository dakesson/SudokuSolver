#pragma once

#include "Sudoku.h"

class SudokuGenerator
{
private:
	void addRandomInitialValuesTo(Sudoku *sudoku);
	void fillSudoku(Sudoku *sudoku);
	void removeRandomValuesUntilOneSolution(Sudoku *sudoku);
public:
	SudokuGenerator();
	~SudokuGenerator();
	Sudoku* generate();
};

