#include "SudokuWindow.h"
#include "Parser.h"
#include "PuzzleGenerator.h"
#include "SudokuSolver.h"

SudokuWindow::SudokuWindow()
{
	layout = new QGridLayout;

	drawCellLabels();
	drawBoxBorders();
	createMenu();

	QWidget * central = new QWidget();
	
	setCentralWidget(central);
	centralWidget()->setLayout(layout);
		 
	setWindowTitle("Sudoku");
	setFixedSize(cellSize * NUM_COL + 15, cellSize * NUM_ROW + 30 + 10);
	centralWidget()->setContentsMargins(0, 0, 10, 10);
}

void SudokuWindow::createMenu()
{
	QMenuBar* menuBar = new QMenuBar();
	QMenu *fileMenu = new QMenu("File");
	menuBar->addMenu(fileMenu);
	
	QAction *openAction = fileMenu->addAction("Open");
	connect(openAction, &QAction::triggered, this, &SudokuWindow::open);

	QAction *solveAction = fileMenu->addAction("Solve");
	connect(solveAction, &QAction::triggered, this, &SudokuWindow::solve);

	QAction *generateAction = fileMenu->addAction("Generate");
	connect(generateAction, &QAction::triggered, this, &SudokuWindow::generate);

	layout->setMenuBar(menuBar);
}

void SudokuWindow::drawBoxBorders()
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

QLabel * SudokuWindow::getCellLabel(int row, int col)
{
	return cellLabels[row * NUM_COL + col];
}

void SudokuWindow::drawPuzzle(Puzzle *puzzle)
{
	this->puzzle = puzzle;

	for (int row = 0; row < NUM_ROW; row++) {
		for (int col = 0; col < NUM_COL; col++) {
			int value = puzzle->getValueFor(Position(row, col));

			if (value) {
				char asciiNumber = '0' + value;
				QString cellString = QString(asciiNumber);
				getCellLabel(row, col)->setText(cellString);
			}
			else {
				getCellLabel(row, col)->setText(QString(""));
			}
		}
	}
}

void SudokuWindow::open()
{
	QString filename = QFileDialog::getOpenFileName();

	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	Puzzle *puzzle = Parser().parseFile(filename.toStdString());
	
	if (!puzzle->allConstraintsOK()) {
		QMessageBox::warning(this, "Sudoku",
			"This sudoku has contradicting constraints");
	}

	drawPuzzle(puzzle);
}

void SudokuWindow::solve()
{
	if (!this->puzzle)
		return;

	SudokuSolver *solver = new SudokuSolver(this->puzzle, true);

	if (solver->solutions.size() == 1) {
		QMessageBox::information(this, "Solved!", 
			QString::fromStdString(solver->difficultyOfPuzzle()));

		drawPuzzle(&solver->solutions[0]);
	} else {
		QMessageBox::information(this, "Sudoku",
			"This sudoku does not have a unique solution");
	}
}

void SudokuWindow::generate()
{
	PuzzleGenerator *generator = new PuzzleGenerator;
	Puzzle *puzzle = PuzzleGenerator().generate();
	drawPuzzle(puzzle);
}

SudokuWindow::~SudokuWindow()
{
}