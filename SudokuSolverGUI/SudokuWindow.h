#pragma once

#include "Puzzle.h"
#include <QVector>
#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QApplication>

const int cellSize = 40;

class SudokuWindow : public QMainWindow
{
public:
	SudokuWindow();
	void drawQuadrantBorders();
	void drawCellLabels();
	void drawPuzzle(Puzzle *puzzle);
private:
	QGridLayout *layout;
	QVector<QLabel*> cellLabels;
	QLabel* cellLabel(int row, int col) const {
		return cellLabels[row * NUM_COL + col];
	}
};
