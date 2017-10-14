#pragma once

#include <QtWidgets>
#include "Puzzle.h"

class SudokuWindow : public QMainWindow
{
private:
	Puzzle *puzzle;
	QMenu *fileMenu;
	QGridLayout *layout;
	QVector<QLabel*> cellLabels;
	const int cellSize = 40;

	void createMenu();
	void drawBoxBorders();
	void drawCellLabels();
	QLabel* getCellLabel(int row, int col);
public:
	SudokuWindow();
	void drawPuzzle(Puzzle *puzzle);
	void open();
	void solve();
	void generate();
	~SudokuWindow();
};