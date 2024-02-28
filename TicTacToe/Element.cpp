#include "Element.h"

Element::Element() : player1{'X'}, player2{'O'}, start{' '} {}

char Element::getPlayer1() const
{
	return player1;
}

char Element::getPlayer2() const
{
        return player2;
}

char Element::getStart() const
{
        return start;
}

bool Element::isValid(std::string userInput) 
{
        if (userInput.size() == 3) {
		if ((userInput[0] == player1 || userInput[0] == player2)
                        && (userInput[1] - 48 >= 0 && userInput[1] - 48 < 3)
                        && (userInput[2] - 48 >= 0 && userInput[2] - 48 < 3) ) {

			return true;
		}

        }
        return false;
}

