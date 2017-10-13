#pragma once
#include "Puzzle.h"
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
	Puzzle *puzzle;
	int numberOfBacktrack;
	bool findAllSolutions;
	
	void deepthFirstSearch();
	void startTimer();
	void endTimer();
public:
	SudokuSolver(Puzzle *puzzle, bool findAllSolutions);
	std::vector<Puzzle> solutions;

	std::string difficultyOfPuzzle();
	~SudokuSolver();
};