#pragma once

#include <string>
#include "Sudoku.h"

namespace Parser
{
	Sudoku* parseFile(std::string filename);
};