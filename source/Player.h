#pragma once
enum MoveType
{
	X,
	O
};
class Player {
private:
	char m_currentPlay;
	MoveType m_moveType;
public:
	void setCurrentPlay(char i_currentPlay);
	char getCurrentPlay();
};