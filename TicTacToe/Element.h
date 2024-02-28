#include <string>

class Element
{
public:
	Element();
	char getPlayer1() const;
	char getPlayer2() const;
	char getStart() const;
        bool isValid(std::string);

private:
	char player1;
	char player2;
	char start;
};
	
