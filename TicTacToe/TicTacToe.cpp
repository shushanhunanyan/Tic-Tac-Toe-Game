#include "TicTacToe.h"
#include "Players.h"        

#include <iostream>
#include <string>

TicTacToe::TicTacToe() : tictactoeBoard{}, firstPlayer{}, secondPlayer{}, playerTurn{false}, win{false} {}

void TicTacToe::startTheGame()
{
	std::cout << "WELCOME TO THE TIC-TAC-TOE GAME ^~^" << std::endl << std::endl;
	std::cout << "Pls select the first players name(will play with 'X'):";

	std::string name;
	std::cin >> name;
	firstPlayer.setPlayerName(name);
	firstPlayer.setKey('X');

	std::cout << "Pls select the second players name('O'):";
	std::cin >> name;
	secondPlayer.setPlayerName(name);
	secondPlayer.setKey('O');
	std::cout << std::endl;
	std::cout << "Move example: X01, where 0 is a row and 1 is a column." << std::endl;
	
}

bool TicTacToe::getIfWin() const
{
        return win;
}


void TicTacToe::userInput()
{
	tictactoeBoard.printBoard();
	if (playerTurn == false && win != true) {
        	std::cout << firstPlayer.getPlayerName() << "'s turn: ";
		playerTurn = true;
		std::string input;
		std::cin >> input;

		if (firstPlayer.checkInputedString(input) == false) {
			std::cerr << "INVALID USAGE" << std::endl;
	                return;

		} else {
                	moveElement(input);
        	}

	} else if (playerTurn == true && win != true) {
		std::cout << secondPlayer.getPlayerName() << "'s turn: ";
		playerTurn = false;
		std::string input;
		std::cin >> input;

        	if (secondPlayer.checkInputedString(input) == false) {
                	std::cerr << "INVALID USAGE" << std::endl;
                	return;
        	} else {
                	moveElement(input);
        	}
	}
}

void TicTacToe::moveElement(std::string playerInput)
{
        char s = playerInput[0];
        int dest1 = playerInput[1] - 48;
        int dest2 = playerInput[2] - 48;

        if (tictactoeBoard.getCell(dest1, dest2) == ' ') {
                tictactoeBoard.setCell(dest1, dest2, s);
                winnerCheck(s);
                if (win == true) {
                        std::cout << s << "IS THE WINNER" << std::endl;
			return;

                } else {
                       return;
                }
	}
        else {
                std::cerr << "this index is already used." << std::endl;
        }
}


void TicTacToe::winnerCheck(char el)
{
	//-----brute-force solution----
	//
	//row
        int count = 0;
        for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                        if (tictactoeBoard.getCell(i, j) == el) {
                                ++count;
                        }
                }
                if (count == 3) {
                        win = true;
                } else {
                        count = 0;
                }
        }

        //calumn
        for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                        if (tictactoeBoard.getCell(i, j) == el) {
                                ++count;
                        }
                }
                if (count == 3) {
                        win = true;
                } else {
                        count = 0;
                }
        }


        for (int i = 0; i < 3; ++i) {
                int j = i;

                if (tictactoeBoard.getCell(i, j) == el) {
                        ++count;
                }
        }

        if (count == 3) {
                win = true;

        } else {
                count = 0;
        }
	
	for (int i = 0; i < 3; ++i) {
                int j = 2;
                if (tictactoeBoard.getCell(i, j) == el) {
                        ++count;
                }
                --j;
        }
        if (count == 3) {
                win = true;
        }

//other solution
/*	int counti = 0;
        int countj = 0;
        for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                        if (tictactoeBoard.getCell(i, j) == el) {
                                ++counti;
                        } else if (tictactoeBoard.getCell(j, i) == el) {
                                ++countj;
                        }
                }
        }
        if (counti == 3 || countj == 3) {
                win = true;
                return;
        } else {
                counti = 0;
                countj = 0;
        }
        

        for (int i = 0; i < 3; ++i) {
                int j = i;
                int k = 2;

                if (tictactoeBoard.getCell(i, j) == el) {
                        ++counti;

                } else if (tictactoeBoard.getCell(i, k) == el) {
                        ++countj;
                }
                ++k;
        }
                if (counti == 3 || countj == 3) {
                        win = true;
                        return;

               } else {
                        counti = 0;
                        countj = 0;
               }
*/
}
