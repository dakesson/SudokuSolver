#pragma once
#include "Puzzle.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdio>

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
public:
	SudokuSolver(Puzzle *puzzle);
	void deepthFirstSearch(Puzzle * puzzle);
	void startTimer();
	void endTimer();	
	~SudokuSolver();
};