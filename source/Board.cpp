#include "Board.h"

Board::Board()
{
	m_boardData = new char[TABLE_SIZE];
	Reset();
}

void Board::Reset()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		m_boardData[i] = (char)('1' + i);
	}
	m_movesPlayed = 0;
	m_gameResult = GameResult::NONE;
}

GameResult  Board::GetGameResult()
{
	return m_gameResult;
}

void Board::Render()
{
	const char* gameName1 = "\t\t\t      GAME---TIC---TAC---TOE \n";
	const char* gameName2 = "\t\t\t\t FOR\t 2    Player\n\n";
	const char* guideGame = "\t\t PLAYER - 1 [X] \t - \tPLAYER - 2 [O]\n\n";
	cout << gameName1 << gameName2 << guideGame;
	cout << k_padding << k_padding << "   +---+---+---+\n";
	cout << k_padding << k_padding << "   | " << m_boardData[0] << " | " << m_boardData[1] << " | " << m_boardData[2] << " |\n";
	cout << k_padding << k_padding << "   +---+---+---+\n";
	cout << k_padding << k_padding << "   | " << m_boardData[3] << " | " << m_boardData[4] << " | " << m_boardData[5] << " |\n";
	cout << k_padding << k_padding << "   +---+---+---+\n";
	cout << k_padding << k_padding << "   | " << m_boardData[6] << " | " << m_boardData[7] << " | " << m_boardData[8] << " |\n";
	cout << k_padding << k_padding << "   +---+---+---+\n\n";
}
void Board::UpdateGameResult(size_t i_position, char i_moveType)
{
	bool isLastPlayerWin = false;
	size_t row = i_position / TABLE_ROW;
	size_t collum = i_position % TABLE_COL;
	size_t fistPositionInRow = TABLE_ROW * row;
	isLastPlayerWin = (m_boardData[fistPositionInRow] == m_boardData[fistPositionInRow + 1] &&
		m_boardData[fistPositionInRow + 1] == m_boardData[fistPositionInRow + 2]) //Row
		|| (m_boardData[collum] == m_boardData[collum + TABLE_COL] &&
			m_boardData[collum + TABLE_COL] == m_boardData[collum + TABLE_COL * 2]); //Column

	if (!isLastPlayerWin) //Not win by row or column
	{
		//Check diagonal
		if (row == collum)
		{
			for (int i = 0; i < TABLE_ROW; i++)
			{
				if (m_boardData[i * TABLE_ROW + i] != i_moveType)
				{
					break;
				}
				else if (i == TABLE_ROW - 1)
				{
					isLastPlayerWin = true;
				}
			}
		}
		else if (row == (TABLE_COL - collum - 1))
		{
			for (int i = 0; i < TABLE_ROW; i++)
			{
				if (m_boardData[i * TABLE_ROW + (TABLE_COL - i - 1)] != i_moveType)
				{
					break;
				}
				else if (i == TABLE_ROW - 1)
				{
					isLastPlayerWin = true;
				}
			}
		}
	}

	if (isLastPlayerWin)
	{
		if (i_moveType == 'X')
		{
			m_gameResult = GameResult::X_WIN;
		}
		else {
			m_gameResult = GameResult::O_WIN;
		}
	}
	else if (m_movesPlayed == 9)
	{
		m_gameResult = GameResult::DRAW;
	}
	else
	{
		m_gameResult = GameResult::NONE;
	}
}
void Board::Update(size_t i_position, char i_moveType)
{
	m_boardData[i_position - 1] = i_moveType;
	++m_movesPlayed;

	UpdateGameResult(i_position - 1, i_moveType);
}
bool Board::ValidateMove(size_t i_playerMove)
{
	if (i_playerMove < 1 || i_playerMove > 9)
	{
		cout << k_padding << "Invalid input! \n";
		return false;
	}
	char valueCurrentPlay = m_boardData[i_playerMove - 1];
	if (valueCurrentPlay == 'X' || valueCurrentPlay == 'O')
	{
		cout << k_padding << "Can not play here. Please choose another position. \n";
		return false;
	}
	return true;
}
