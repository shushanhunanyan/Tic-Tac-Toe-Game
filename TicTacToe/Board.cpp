#include "Board.h"
#include "SaveAsString.h"


#include <string>
#include <iostream>


Board::Board() : elements{} 
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cells[i][j] = elements.getStart();
		}
	}
}


char Board::getCell(int i, int j) const
{
	return cells[i][j];
}


void Board::printBoard()
{
	SaveOnFile onfile("data.txt");

	std::string save;
	for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
			save += cells[i][j];
			if (j == 2) {
				std::cout << "|  " << cells[i][j] << " |";

			} else {
				std::cout << "|  " << cells[i][j] << " ";

			}
                }
                std::cout << std::endl;
		if (i != 2) {
			std::cout << "_______________" << std::endl;
		}
		
        }
	if (onfile.writeToFile(save) == false) {
		std::cerr << "error from file system." << std::endl;
	}
}


void Board::setCell(int i, int j, char v) 
{
	cells[i][j] = v;
}


