#include "SudokuWindow.h"
#include <QtWidgets/QApplication>
#include "Parser.h"
#include "SudokuSolver.h"
#include "PuzzleGenerator.h"

#include <vector> //REMOVE

int main(int argc, char *argv[])
{
/*	Parser *parser = new Parser();
	Puzzle *puzzle = parser->parseFile("medium.txt");
	bool constraints = puzzle->allConstraintsOK();
	//puzzle->runUnitTests();

	SudokuSolver *solver = SudokuSolver(puzzle);
	solver->findSolutions();
	*/

	PuzzleGenerator *generator = new PuzzleGenerator;
	Puzzle *puzzle = PuzzleGenerator().generate();
	
	QApplication app(argc, argv);
	SudokuWindow sudokuWindow;
	sudokuWindow.drawPuzzle(puzzle);
	sudokuWindow.show();

	return app.exec();

}


