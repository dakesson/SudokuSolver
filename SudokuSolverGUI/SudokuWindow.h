#pragma once

#include <QtWidgets>
#include "Sudoku.h"

class SudokuWindow : public QMainWindow
{
private:
	Sudoku *sudoku;
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
	void draw(Sudoku *sudoku);
	void open();
	void solve();
	void generate();
	~SudokuWindow();
};