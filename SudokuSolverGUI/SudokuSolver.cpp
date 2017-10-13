#include "SudokuSolver.h"
#include <algorithm>

SudokuSolver::SudokuSolver(Puzzle *puzzle, bool findAllSolutions)
{
	this->puzzle = puzzle;
	this->findAllSolutions = findAllSolutions;
	deepthFirstSearch();
}

void SudokuSolver::deepthFirstSearch()
{
	std::vector<Position> positions = puzzle->getUnFilledPositions();

	int level = 0;
	this->numberOfBacktrack = 0;
	
	while (level < positions.size())
	{
		if (level == -1)
			return;

		Position pos = positions[positions.size() - 1 - level];
		int nextValue = puzzle->getValueFor(pos) + 1;

		if (nextValue == 10) {
			puzzle->setValue(0, pos);
			level--;
			numberOfBacktrack++;
			continue;
		}

		for (int testValue = nextValue; testValue < 10; testValue++) {
			puzzle->setValue(testValue, pos);
			if (puzzle->constraintsForCellOK(pos)) {

				bool solutionFound = (level == positions.size() - 1);
				if (solutionFound) {
					solutions.push_back(*puzzle);
					if (!findAllSolutions) {
						return;
					}
				} else {
					level++;
					break;
				}

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