#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{
public:
	Player();
	void setPlayerName(std::string);
	std::string getPlayerName() const;
	void setKey(char);
	char getKey() const;

	bool checkInputedString(std::string);

private:
	char m_key;
        std::string m_playerName;
};
#endif // PLAYER_H
