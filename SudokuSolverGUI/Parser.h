#pragma once

#include <string>
#include "Sudoku.h"

class Parser
{
private:
	Sudoku *sudoku;
public:
	Parser();
	Sudoku* parseFile(std::string filename);
	~Parser();
};