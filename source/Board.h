#pragma once
#include "GameConst.h"
#include <iostream>
using namespace std;
enum GameResult
{
	NONE,
	X_WIN,
	O_WIN,
	DRAW
};
#define TABLE_ROW 3
#define TABLE_COL 3
#define TABLE_SIZE (TABLE_ROW * TABLE_COL)
class Board {
private:
	char* m_boardData;
	GameResult m_gameResult;
	size_t m_movesPlayed;
public:
	Board();
	void Reset();
	GameResult GetGameResult();
	void Render();
	void Update(size_t i_position, char i_moveType);
	void UpdateGameResult(size_t i_position, char i_moveType);
	bool ValidateMove(size_t i_playerMove);
};