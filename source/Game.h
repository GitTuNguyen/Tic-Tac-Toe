#pragma once
#include "Board.h"
class Game {
private:	
	bool m_isPlayerWantExit;
	Board* m_board;
public:
	void setIsPlayerWantExit(bool i_isPlayerWantExit);
	bool getIsPlayerWantExit();
	void setBoard(Board* i_board);
	Board* getBoard();
	void InitGame();
	void isPlayAgain();
	void UpdateGame();
	void EndGame();
};