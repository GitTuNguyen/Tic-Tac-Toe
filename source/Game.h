#pragma once
#include "Board.h"
class Game {
public:
	Game();
	void Update();
	~Game();
private:
	void CreateNewMatch();
	void UpdateMove();
	void RenderGameOver();
	void Rematch();
	Board* m_board;
	char m_currentMoveType;
	bool m_isPlayerWantExit;
};