#ifndef BOARD_H
#define BOARD_H

#include "Element.h"


#include <string>

class Board
{
public:
	Board();
	void printBoard();
	char getCell(int, int) const;
	void setCell(int, int, char);

private:
	Element elements;
	char cells[3][3];
};

#endif // BOARD_H
