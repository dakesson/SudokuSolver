#include "SudokuSolver.h"
#include <algorithm>

SudokuSolver::SudokuSolver(Puzzle *puzzle)
{
	this->puzzle = puzzle;

	startTimer();
	deepthFirstSearch(puzzle);
	endTimer();	
}

void SudokuSolver::deepthFirstSearch(Puzzle * puzzle)
{
	std::vector<Position> positions = puzzle->getAvailablePositions();

	int level = 0;
	while (level < positions.size())
	{
		DBOUT("LEVEL " << level << std::endl);
		Position pos = positions[level];
		int nextValue = puzzle->getValueFor(pos) + 1;

		if (nextValue == 10)
		{
			puzzle->setValue(0, pos);
			level--;
			continue;
		}

		for (int testValue = nextValue; testValue < 10; testValue++) {
			puzzle->setValue(testValue, pos);
			if (puzzle->constraintsForCellOK(pos))
			{
				level++;
				break;
			}
		}
	} 
}


void SudokuSolver::startTimer()
{
	this->sTimer = clock();
}

void SudokuSolver::endTimer()
{
	this->eTimer = clock();
	unsigned int total_time_ticks = (unsigned int)(sTimer - eTimer);
}

SudokuSolver::~SudokuSolver()
{
}