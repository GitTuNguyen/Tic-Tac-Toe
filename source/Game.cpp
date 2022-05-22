/*player board play*/
#pragma once
#include "Game.h"
#include "Board.h"
void Game::setIsPlayerWantExit(bool i_isPlayerWantExit)
{
	m_isPlayerWantExit = i_isPlayerWantExit;
}
bool  Game::getIsPlayerWantExit()
{
	return m_isPlayerWantExit;
}
void Game::setBoard(Board* i_board)
{
	m_board = i_board;
}
Board* Game::getBoard()
{
	return m_board;
}
void Game::InitGame()
{
	m_board = new Board();
	char* i_board = new char[9];
	for (int i = 0; i < 9; i++)
	{
		i_board[i] = (char) ('1' + i);
	}
	m_board->setBoardData(i_board);
	m_board->setMovesPlayed(0);
	m_board->setGameResult(GameResult::NONE);	
	Player i_player;
	i_player.setCurrentPlay('X');
	m_board->setPlayer(i_player);
	setIsPlayerWantExit(false);
}
void Game::isPlayAgain()
{
	char inputPlayer;
	cout << k_padding << "Co lam phat nua khong 2 ban? (Nhap Y de choi lai, nhap ky tu khac de thoat game) :  ";
	cin >> inputPlayer;
	if (inputPlayer == 'Y' || inputPlayer == 'y')
	{
		InitGame();
	}
	else {
		setIsPlayerWantExit(true);
	}
}
void Game::UpdateGame()
{
	while (!getIsPlayerWantExit())
	{
		system("CLS");
		Board* i_board = getBoard();
		GameResult i_gameResult = i_board->getGameResult();
		if (i_gameResult == GameResult::NONE)
		{
			i_board->RenderBoard();
			i_board->UpdatePlayerMove();
		}
		else {
			i_board->RenderBoard();
			i_board->RenderGameOver();
			isPlayAgain();
		}
	}
}

void Game::EndGame()
{

}


