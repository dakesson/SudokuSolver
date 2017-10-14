#pragma once

#include "Sudoku.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdio>


class SudokuSolver
{
private:
	Sudoku *sudoku;
	int numberOfBacktracks;
	
	void deepthFirstSearch(bool findAllSolutions);
public:
	explicit SudokuSolver(Sudoku *sudoku);

	void findAllSolutions();
	void findSolution();
	std::vector<Sudoku> solutions;
	std::string difficultyOfSudoku();
	~SudokuSolver();
};