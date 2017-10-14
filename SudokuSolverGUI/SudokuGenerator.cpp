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
	fillAllCellsWithValues(sudoku);
	removeRandomValuesUntilOneSolution(sudoku);
	
	return sudoku;
}

void SudokuGenerator::fillAllCellsWithValues(Sudoku * sudoku)
{
	while (true) {
		sudoku->clearValues();
		addRandomInitialValuesTo(sudoku);
		SudokuSolver solver = SudokuSolver(sudoku, false);
		if (solver.solutions.size() > 0)
			break;
	}
}

void SudokuGenerator::addRandomInitialValuesTo(Sudoku *sudoku)
{
	for (int i = 1; i <= 9; i++) {
		int dataPos = rand() % 80;
		sudoku->setValue(i, Position(dataPos));
	}
}

void SudokuGenerator::removeRandomValuesUntilOneSolution(Sudoku * sudoku)
{
	std::vector<Position> filledPositions = sudoku->getFilledPositions();
	while (true) {		
		int randomFilledPosition = rand() % (filledPositions.size() - 1);
		Position pos = filledPositions[randomFilledPosition];

		int oldValue = sudoku->getValueFor(pos);
		sudoku->removeValue(Position(pos));
		SudokuSolver solver = SudokuSolver(sudoku, true);

		if (solver.solutions.size() == 0) {
			sudoku->setValue(oldValue, pos);
		}

		if (solver.solutions.size() > 1) {
			sudoku->setValue(oldValue, pos);
			return;
		}

		filledPositions.erase(filledPositions.begin() + randomFilledPosition);
	}
}