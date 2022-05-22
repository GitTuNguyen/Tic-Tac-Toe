#pragma once
#include "Player.h"
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
class Board {
private:
	char* m_boardData;
	Player m_player; 
	GameResult m_gameResult;
	size_t m_movesPlayed;
	size_t m_playerMove;
public:
	void setPlayer(Player i_player);
	Player getPlayer();
	void setGameResult(GameResult i_gameResult);
	GameResult getGameResult();
	void setBoardData(char* i_Board);
	char* getBoardData();
	void setPlayerMove(size_t i_playerMove);
	size_t getPlayerMove();
	void setMovesPlayed(size_t i_movesPlayed);
	size_t getMovesPlayed();
	void RenderBoard();
	void UpdateBoard(size_t i_playerMove);
	GameResult CheckGameResult();
	bool ValidateMove(size_t i_playerMove);
	void UpdatePlayerMove();
	void RenderGameOver();
};