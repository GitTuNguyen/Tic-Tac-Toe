/* X O */
#pragma once
#include "Player.h"

void Player::setCurrentPlay(char i_currentPlay)
{
	m_currentPlay = i_currentPlay;
}
char Player::getCurrentPlay()
{
	return m_currentPlay;
}