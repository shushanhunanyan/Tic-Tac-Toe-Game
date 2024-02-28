#ifndef TICTACTOE_H
#define TICTACTOE_H


#include "Board.h"
#include "Players.h"

#include <string>

class TicTacToe
{
public:
	TicTacToe();
	void startTheGame();
	bool getIfWin() const;
	void userInput();
	bool checkInputedString(std::string);
	void winnerCheck(char);
	void moveElement(std::string);
public:
	Board tictactoeBoard;

private:
	bool playerTurn;
	Player firstPlayer;
	Player secondPlayer;
	bool win;
};

#endif // TICTACTOE_H

