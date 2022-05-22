/*luot di, vi tri di, game ket thuc hay chua, */
#pragma once
#include <iostream>
using namespace std;

class Play {
private:	
	enum GameResult
	{
		NONE,
		X_WIN,
		O_WIN,
		DRAW
	};
	bool isPlayerWantExit;
	GameResult gameResult;
public:
	void setGameResult(GameResult gameResult)
	{
		this->gameResult = gameResult;
	}
	GameResult getGameResult()
	{
		return gameResult;
	}
	void setIsPlayerWantExit(bool isPlayerWantExit)
	{
		this->isPlayerWantExit = isPlayerWantExit;
	}
	bool getIsPlayerWantExit()
	{
		return isPlayerWantExit;
	}
};