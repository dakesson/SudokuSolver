#pragma once

#include "Puzzle.h"
#include <QVector>
#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QApplication>
#include <QMenuBar>
#include <QtWidgets>

const int cellSize = 40;

class SudokuWindow : public QMainWindow
{
private:
	Puzzle *puzzle;
	QMenu *fileMenu;
	QGridLayout *layout;
	QVector<QLabel*> cellLabels;
	QLabel* cellLabel(int row, int col) const {
		return cellLabels[row * NUM_COL + col];
	}
	void drawBoxBorders();
	void drawCellLabels();
public:
	SudokuWindow();
	void createMenu();
	void drawPuzzle(Puzzle *puzzle);
	void open();
	void solve();
	void generate();
	~SudokuWindow();
};
