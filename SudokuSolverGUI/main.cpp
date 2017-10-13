#include "SudokuWindow.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	SudokuWindow sudokuWindow;
	sudokuWindow.show();

	return app.exec();

}


