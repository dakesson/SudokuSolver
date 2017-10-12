#include "SudokuWindow.h"

SudokuWindow::SudokuWindow()
{
	layout = new QGridLayout;

	drawCellLabels();
	drawQuadrantBorders();

	QWidget * central = new QWidget();
	setCentralWidget(central);
	centralWidget()->setLayout(layout);
	 
	setWindowTitle("Sudoku");
	setFixedSize(cellSize * NUM_COL, cellSize * NUM_ROW);
}

void SudokuWindow::drawCellLabels()
{
	for (int row = 0; row < NUM_ROW; ++row) {
		for (int col = 0; col < NUM_COL; col++) {
			QLabel * const cellLabel = new QLabel();
			cellLabel->setFixedSize(cellSize, cellSize);
			layout->addWidget(cellLabel, row, col);
			cellLabel->setStyleSheet("border: 1px solid grey");
			cellLabel->setAlignment(Qt::AlignCenter);
			cellLabels.append(cellLabel);
		}
	}
}

void SudokuWindow::drawQuadrantBorders()
{
	for (int row = 0; row < 3; ++row) {
		for (int col = 0; col < 3; col++) {
			QLabel * const cellSquare = new QLabel();
			cellSquare->setFixedSize(cellSize * 3, cellSize * 3);
			layout->addWidget(cellSquare, row * 3, col * 3);
			cellSquare->setStyleSheet("border: 2px solid black");
		}
	}
}

void SudokuWindow::drawPuzzle(Puzzle *puzzle)
{
	for (int row = 0; row < NUM_ROW; row++) {
		for (int col = 0; col < NUM_COL; col++) {
			int value = puzzle->getValueFor(Position(row, col));

			if (value) {
				char asciiNumber = '0' + value;
				QString cellString = QString(asciiNumber);
				cellLabel(row, col)->setText(cellString);
			}
		}
	}
}

