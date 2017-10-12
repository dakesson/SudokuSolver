#include "SudokuSolver.h"
#include <algorithm>
#include <ctime>
#include <cstdio>

SudokuSolver::SudokuSolver(Puzzle *puzzle)
{
	clock_t time_a = clock();

	this->puzzle = puzzle;

	std::vector<Position> positions = puzzle->getAvailablePositions();
	//for (int i = 0; i < positions.size(); i++) {

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

		for (int j = nextValue; j <= 9; j++) {
			puzzle->setValue(j, pos);
			if (puzzle->constraintsForCellOk(pos))
			{
				level++;
				break;
			}
			else if (j == 9) 
			{
				puzzle->setValue(0, pos);
				level--;
				break;
			}				
		}
	}
	
	clock_t time_b = clock();
	unsigned int total_time_ticks = (unsigned int)(time_b - time_a);
	
}


SudokuSolver::~SudokuSolver()
{
}
