#include "SudokuGenerator.h"
#include "SudokuSolver.h"
#include <ctime>


SudokuGenerator::SudokuGenerator()
{
	srand(time(0));
}


SudokuGenerator::~SudokuGenerator()
{
}

Sudoku* SudokuGenerator::generate()
{
	Sudoku *sudoku = new Sudoku();
	fillSudoku(sudoku);
	removeRandomValuesUntilOneSolution(sudoku);
	
	return sudoku;
}

void SudokuGenerator::fillSudoku(Sudoku * sudoku)
{
	while (true) {
		sudoku->clearValues();
		addRandomInitialValuesTo(sudoku);
		SudokuSolver solver = SudokuSolver(sudoku);
		solver.findSolution();
		if (solver.solutions.size() > 0) {
			sudoku = &solver.solutions[0];
			break;
		}
			
	}
}

void SudokuGenerator::addRandomInitialValuesTo(Sudoku *sudoku)
{
	for (int i = 1; i <= 9; i++) {
		int storagePos = rand() % 80;
		sudoku->setValue(i, Position(storagePos));
	}
}

void SudokuGenerator::removeRandomValuesUntilOneSolution(Sudoku * sudoku)
{
	std::vector<Position> removablePositions = sudoku->getFilledPositions();
	while (true) {		
		int randomRemovablePosition = rand() % (removablePositions.size() - 1);
		Position pos = removablePositions[randomRemovablePosition];

		int oldValue = sudoku->getValueFor(pos);
		sudoku->removeValue(Position(pos));
		SudokuSolver solver = SudokuSolver(sudoku);
		solver.findAllSolutions();

		if (solver.solutions.size() == 0) {
			sudoku->setValue(oldValue, pos);
		}

		if (solver.solutions.size() > 1) {
			sudoku->setValue(oldValue, pos);
			return;
		}

		removablePositions.erase(removablePositions.begin() + randomRemovablePosition);
	}
}