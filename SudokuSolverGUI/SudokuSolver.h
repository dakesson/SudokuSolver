#pragma once
#include "Puzzle.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdio>

#define NO_SOLUTION			0;
#define UNIQUE_SOLUTION		1;
#define MULTIPLE_SOLUTIONS_FOUND	2;

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

class SudokuSolver
{
private:
	clock_t sTimer;
	clock_t eTimer;
	Puzzle *puzzle;
	bool findAllSolutions;
	
	void deepthFirstSearch();
	void startTimer();
	void endTimer();
public:
	SudokuSolver(Puzzle *puzzle, bool findAllSolutions);
	int numberOfBacktrack;
	std::vector<Puzzle> solutions;
	~SudokuSolver();
};