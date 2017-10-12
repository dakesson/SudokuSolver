#pragma once
#include "Puzzle.h"
#include <Windows.h>
#include <iostream>
#include <sstream>

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

class SudokuSolver
{
private:
	Puzzle *puzzle;
public:
	SudokuSolver(Puzzle *puzzle);
	~SudokuSolver();
};