#pragma once

#include <string>
#include "Puzzle.h"

class Parser
{
private:
	Puzzle *puzzle;
public:
	Parser();
	Puzzle* parseFile(std::string filename);
	~Parser();
};