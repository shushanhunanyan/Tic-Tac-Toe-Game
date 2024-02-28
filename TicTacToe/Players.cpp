#include "Players.h"


#include <iostream>

Player::Player() : m_key{}, m_playerName{} {}

void Player::setPlayerName(std::string name)
{
	m_playerName = name;
}

std::string Player::getPlayerName() const
{
	return m_playerName;
}

void Player::setKey(char key)
{
	m_key = key;
}

char Player::getKey() const
{
	return m_key;
}

bool Player::checkInputedString(std::string playerInput)
{
	 if (playerInput.size() == 3) {
                if ((playerInput[0] == m_key) 
				&& (playerInput[1] - 48 >= 0 && playerInput[1] - 48 < 3)
                        	&& (playerInput[2] - 48 >= 0 && playerInput[2] - 48 < 3)) {
						return true;
				}		
			} 
	 return false;
}

