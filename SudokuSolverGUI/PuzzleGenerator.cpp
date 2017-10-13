#include "PuzzleGenerator.h"
#include "SudokuSolver.h"
#include <ctime>


PuzzleGenerator::PuzzleGenerator()
{
	srand(time(0));
}


PuzzleGenerator::~PuzzleGenerator()
{
}

Puzzle* PuzzleGenerator::generate()
{
	Puzzle *puzzle = new Puzzle();
	fillAllCellsWithValues(puzzle);
	removeRandomValuesUntilOneSolution(puzzle);
	
	return puzzle;
}

void PuzzleGenerator::fillAllCellsWithValues(Puzzle * puzzle)
{
	while (true) {
		puzzle->clearValues();
		addRandomInitialValuesTo(puzzle);
		SudokuSolver solver = SudokuSolver(puzzle, false);
		if (solver.solutions.size() > 0)
			break;
	}
}

void PuzzleGenerator::addRandomInitialValuesTo(Puzzle *puzzle)
{
	for (int i = 1; i <= 9; i++) {
		int dataPos = rand() % 80;
		puzzle->setValue(i, Position(dataPos));
	}
}

void PuzzleGenerator::removeRandomValuesUntilOneSolution(Puzzle * puzzle)
{
	std::vector<Position> filledPositions = puzzle->getFilledPositions();
	while (true) {		
		int randomFilledPosition = rand() % (filledPositions.size() - 1);
		Position pos = filledPositions[randomFilledPosition];

		int oldValue = puzzle->getValueFor(pos);
		puzzle->removeValue(Position(pos));
		SudokuSolver solver = SudokuSolver(puzzle, true);

		if (solver.solutions.size() == 0) {
			puzzle->setValue(oldValue, pos);
		}

		if (solver.solutions.size() > 1) {
			puzzle->setValue(oldValue, pos);
			return;
		}

		filledPositions.erase(filledPositions.begin() + randomFilledPosition);
	}
}