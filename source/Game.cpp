/*player board play*/
#pragma once
#include "Game.h"
#include "Board.h"

Game::Game()
{
	m_board = new Board();
	m_currentMoveType = 'X';
	m_isPlayerWantExit = false;	
}

void Game::CreateNewMatch()
{
	m_board->Reset();
	
}
void Game::Rematch()
{
	char inputPlayer;
	cout << k_padding << "Play again? (Y to play again, another key to quit): ";
	cin >> inputPlayer;
	if (inputPlayer == 'Y' || inputPlayer == 'y')
	{
		CreateNewMatch();
	}
	else {
		m_isPlayerWantExit = true;
	}
}
void Game::Update()
{
	while (!m_isPlayerWantExit)
	{
		system("CLS");

		m_board->Render();

		GameResult gameResult = m_board->GetGameResult();
		if (gameResult == GameResult::NONE)
		{
			UpdateMove();
		}
		else {
			RenderGameOver();
			Rematch();
		}
	}
}

void Game::UpdateMove()
{
	bool isValidMove = false;
	size_t movePosition;
	while (!isValidMove)
	{
		cout << k_padding << "Player " << m_currentMoveType << " turn : ";
		cin >> movePosition;
		isValidMove = m_board->ValidateMove(movePosition);
	}
	m_board->Update(movePosition, m_currentMoveType);
	m_currentMoveType = m_currentMoveType == 'X' ? 'O' : 'X';
}


void Game::RenderGameOver()
{
	cout << k_padding << "\t       ---Game---+---OVER--- \n";
	GameResult gameResult = m_board->GetGameResult();
	switch (gameResult)
	{
	case NONE:
		break;
	case X_WIN:
		cout << k_padding << "\t+--- Player 1 [X] WIN! Conratulation ---+\n";
		break;
	case O_WIN:
		cout << k_padding << "+--- Player 2 [O] WIN! Conratulation ---+\n";
		break;
	case DRAW:
		cout << k_padding << "+--- Game draw! ---+\n";
		break;
	default:
		break;
	}
}


Game::~Game()
{
	delete m_board;
}