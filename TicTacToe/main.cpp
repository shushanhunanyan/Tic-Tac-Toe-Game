#include "TicTacToe.h"
#include "Board.h"


#include <iostream>
int main() {
        TicTacToe round1;
	round1.startTheGame();

	int count = 0;
	while (round1.getIfWin() != true && count < 6) {
		++count;
		round1.userInput();
		if (count == 5) {
			 std::cout << "It's a draw! No one wins the game." << std::endl;
			 break;
		}
		round1.userInput();
	}	
}

