#pragma once
#include "Puzzle.h"

class PuzzleGenerator
{
private:
	void addRandomInitialValuesTo(Puzzle *puzzle);
	void fillAllCellsWithValues(Puzzle *puzzle);
	void removeRandomValuesUntilOneSolution(Puzzle *puzzle);
public:
	PuzzleGenerator();
	~PuzzleGenerator();
	Puzzle* generate();
};

