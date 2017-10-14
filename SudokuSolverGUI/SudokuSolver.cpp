#include "SudokuSolver.h"
#include <algorithm>

SudokuSolver::SudokuSolver(Sudoku *sudoku)
{
	this->sudoku = sudoku;
}

void SudokuSolver::findAllSolutions()
{
	deepthFirstSearch(true);
}

void SudokuSolver::findSolution()
{
	deepthFirstSearch(false);
}

void SudokuSolver::deepthFirstSearch(bool findAllSolutions)
{
	std::vector<Position> unfilledPositions = sudoku->getUnFilledPositions();

	int level = 0;
	numberOfBacktracks = 0;
		
	while (level < unfilledPositions.size())
	{
		if (level == -1)
			return;

		Position pos = unfilledPositions[unfilledPositions.size() - level - 1];
		int nextValue = sudoku->getValueFor(pos) + 1;

		if (nextValue == 10) {
			sudoku->setValue(0, pos);
			level--;
			numberOfBacktracks++;
			continue;
		}

		for (int testValue = nextValue; testValue < 10; testValue++) {
			sudoku->setValue(testValue, pos);
			if (sudoku->constraintsForCellOK(pos)) {

				bool solutionFound = (level == unfilledPositions.size() - 1);
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

std::string SudokuSolver::difficultyOfSudoku()
{
	if (numberOfBacktracks == 0) {
		return "No sudoku solved";
	}
	else if (numberOfBacktracks < 1000) {
		return "Sudoku was easy!";
	}
	else if (numberOfBacktracks < 15000) {
		return "Sudoku  was medium";
	}
	else if (numberOfBacktracks < 35000) {
		return "Sudoku  was hard";
	}
	else {
		return "Sudoku  was level SAMURAI!";
	}
}

SudokuSolver::~SudokuSolver()
{
}