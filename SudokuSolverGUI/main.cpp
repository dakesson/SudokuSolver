#include "SudokuWindow.h"
#include <QtWidgets/QApplication>
#include "Parser.h"
#include "SudokuSolver.h"

#include <vector> //REMOVE

int main(int argc, char *argv[])
{
	Parser *parser = new Parser();
	Puzzle *puzzle = parser->parseFile("samurai.txt");
	bool constraints = puzzle->allConstraintsOK();
	//puzzle->runUnitTests();

	SudokuSolver *solver = new SudokuSolver(puzzle);

	QApplication app(argc, argv);
	SudokuWindow sudokuWindow;
	sudokuWindow.drawPuzzle(puzzle);

	sudokuWindow.show();
	
	return app.exec();

}


