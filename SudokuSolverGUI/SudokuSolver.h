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
	clock_t sTimer;
	clock_t eTimer;
	Sudoku *sudoku;
	int numberOfBacktrack;
	bool findAllSolutions;
	
	void deepthFirstSearch();
	void startTimer();
	void endTimer();
public:
	SudokuSolver(Sudoku *sudoku, bool findAllSolutions);
	std::vector<Sudoku> solutions;

	std::string difficultyOfSudoku();
	~SudokuSolver();
};