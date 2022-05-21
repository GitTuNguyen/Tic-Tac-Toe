#include "Board.h"

void Board::setPlayer(Player i_player)
{
	m_player = i_player;
}
Player Board::getPlayer()
{
	return m_player;
}
void  Board::setGameResult(GameResult i_gameResult)
{
	m_gameResult = i_gameResult;
}
GameResult  Board::getGameResult()
{
	return m_gameResult;
}
void Board::setBoardData(char* i_board)
{
	m_boardData = i_board;
}
char* Board::getBoardData()
{
	return m_boardData;
}
void Board::setPlayerMove(size_t i_playerMove)
{
	m_playerMove = i_playerMove;
}
size_t Board::getPlayerMove()
{
	return m_playerMove;
}
void Board::setMovesPlayed(size_t i_movesPlayed)
{
	m_movesPlayed = i_movesPlayed;
}
size_t Board::getMovesPlayed()
{
	return m_movesPlayed;
}
void Board::RenderBoard()
{
	const char* gameName1 = "\t\t\t\t GAME---TIC---TAC---TOE \n";
	const char* gameName2 = "\t\t\t FOR\t 2\t Player\n\n";
	const char* guideGame = "\t\t PLAYER - 1 [X] \t-\t PLAYER - 2 [O]\n\n";
	cout << gameName1 << gameName2 << guideGame;
	cout << k_padding << "+---+---+---+\n";
	cout << k_padding << "| " << m_boardData[0] << " | " << m_boardData[1] << " | " << m_boardData[2] << " |\n";
	cout << k_padding << "+---+---+---+\n";
	cout << k_padding << "| " << m_boardData[3] << " | " << m_boardData[4] << " | " << m_boardData[5] << " |\n";
	cout << k_padding << "+---+---+---+\n";
	cout << k_padding << "| " << m_boardData[6] << " | " << m_boardData[7] << " | " << m_boardData[8] << " |\n";
	cout << k_padding << "+---+---+---+\n\n";
}
GameResult Board::CheckGameResult()
{
	bool isLastPlayerWin = false;
	char* i_board = getBoardData();
	if ((i_board[0] == i_board[1] && i_board[0] == i_board[2]) ||
		(i_board[3] == i_board[4] && i_board[3] == i_board[5]) ||
		(i_board[6] == i_board[7] && i_board[6] == i_board[8]) ||
		(i_board[0] == i_board[3] && i_board[0] == i_board[6]) ||
		(i_board[1] == i_board[4] && i_board[1] == i_board[7]) ||
		(i_board[2] == i_board[5] && i_board[2] == i_board[8]) ||
		(i_board[0] == i_board[4] && i_board[0] == i_board[8]) ||
		(i_board[2] == i_board[5] && i_board[1] == i_board[6]))
	{
		isLastPlayerWin = true;
	}
	if (isLastPlayerWin)
	{
		if (m_player.getCurrentPlay() == 'X')
		{
			return GameResult::X_WIN;
		}
		else {
			return GameResult::O_WIN;
		}
	}
	else if (getMovesPlayed() == 9)
	{
		return GameResult::DRAW;
	}
	return GameResult::NONE;
}
void Board::UpdateBoard(size_t i_playerMove)
{
	char* i_boardData = getBoardData();
	i_boardData[i_playerMove - 1] = m_player.getCurrentPlay();
	setBoardData(i_boardData);

	setMovesPlayed(getMovesPlayed() + 1);

	setGameResult(CheckGameResult());

	char i_currentPlay = m_player.getCurrentPlay();
	i_currentPlay = i_currentPlay == 'X' ? 'O' : 'X';
	m_player.setCurrentPlay(i_currentPlay);
}
bool Board::ValidateMove(size_t i_playerMove)
{
	if (i_playerMove < 1 || i_playerMove > 9)
	{
		cout << k_padding << "Chon sai roi, chon lai di khong t dam cho gio >.< \n";
		return false;
	}
	char* i_boardData = getBoardData();
	char valueCurrentPlay = i_boardData[i_playerMove - 1];
	if (valueCurrentPlay == 'X' || valueCurrentPlay == 'O')
	{
		cout << k_padding << "Cho nay co nguoi roi, di cho khac di =.= \n";
		return false;
	}
	return true;
}
void Board::UpdatePlayerMove()
{
	bool isValidMove = false;
	size_t i_playerMove;
	while (!isValidMove)
	{

		
		if (m_player.getCurrentPlay() == 'X')
		{
			cout << k_padding << "Den luot m di roi day, so 1 [X]: ";
		}
		else {
			cout << k_padding << "Gio thi den luot m, so 2 [O]: ";
		}
		cin >> i_playerMove;
		isValidMove = Board::ValidateMove(i_playerMove);
		UpdateBoard(i_playerMove);
	}
}
void Board::RenderGameOver()
{
	cout << k_padding << "\t ---Game---+---OVER--- \n";
	GameResult m_gameResult = getGameResult();
	switch (m_gameResult)
	{
	case NONE:
		break;
	case X_WIN:
		cout << k_padding << "Chuc mung m da thang, so 1 [X]!!!\n";
		break;
	case O_WIN:
		cout << k_padding << "Chuc mung m da thang, so 2 [O]!!!\n";
		break;
	case DRAW:
		cout << k_padding << "Danh mai cha co ai thang ca, sida!!!\n";
		break;
	default:
		break;
	}
}
