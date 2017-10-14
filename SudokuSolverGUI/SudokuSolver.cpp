#include "SudokuSolver.h"
#include <algorithm>

SudokuSolver::SudokuSolver(Sudoku *sudoku, bool findAllSolutions)
{
	this->sudoku = sudoku;
	this->findAllSolutions = findAllSolutions;
	deepthFirstSearch();
}

void SudokuSolver::deepthFirstSearch()
{
	std::vector<Position> positions = sudoku->getUnFilledPositions();

	int level = 0;
	this->numberOfBacktrack = 0;
	
	while (level < positions.size())
	{
		if (level == -1)
			return;

		Position pos = positions[positions.size() - 1 - level];
		int nextValue = sudoku->getValueFor(pos) + 1;

		if (nextValue == 10) {
			sudoku->setValue(0, pos);
			level--;
			numberOfBacktrack++;
			continue;
		}

		for (int testValue = nextValue; testValue < 10; testValue++) {
			sudoku->setValue(testValue, pos);
			if (sudoku->constraintsForCellOK(pos)) {

				bool solutionFound = (level == positions.size() - 1);
				if (solutionFound) {
					solutions.push_back(*sudoku);
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

std::string SudokuSolver::difficultyOfSudoku()
{
	if (numberOfBacktrack == 0) {
		return "No sudoku solved";
	}
	else if (numberOfBacktrack < 1000) {
		return "Sudoku was easy!";
	}
	else if (numberOfBacktrack < 15000) {
		return "Sudoku  was medium";
	}
	else if (numberOfBacktrack < 35000) {
		return "Sudoku  was hard";
	}
	else if (numberOfBacktrack >= 35000) {
		return "Sudoku  was level SAMURAI!";
	}
}

SudokuSolver::~SudokuSolver()
{
}