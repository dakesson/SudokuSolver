#include "Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctype.h>

Parser::Parser()
{
	sudoku = new Sudoku();
}

Sudoku* Parser::parseFile(std::string filename)
{
	std::ifstream infile(filename);
	if (!infile.is_open())
		throw std::invalid_argument("Could not open file: " + filename);
	
	std::string line;
	int row = 0;
	while (getline(infile, line))
	{
		for (std::string::size_type col = 0; col < line.size(); col++) 
		{
			char s = line[col];
			if (isdigit(s))
			{
				int number = s - '0';
				sudoku->setValue(number, Position(row, col));
			}
		}
		row++;
	}

	return sudoku;
}

Parser::~Parser()
{
}
