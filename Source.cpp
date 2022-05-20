#include <stdio.h>
#include <iostream>

using namespace std;

char board[3][3];
enum GameResult
{
	NONE,
	X_WIN,
	O_WIN,
	DRAW
};
size_t playerMove;
size_t movesPlayed;
char currentPlayer;
bool isPlayerWantExit;
GameResult gameResult;
const char* k_padding = "\t\t";
void InitGame()
{
	for (int i = 0; i < 9; i++)
	{
		board[i / 3][i % 3] = '1' + i;
	}
	gameResult = GameResult::NONE;
	movesPlayed = 0;
	currentPlayer = 'X';
	isPlayerWantExit = false;
}

void RenderBoard()
{
	const char* gameName1 = "\t\t\t\t GAME---TIC---TAC---TOE \n";
	const char* gameName2 = "\t\t\t FOR\t 2\t Player\n\n";
	const char* guideGame = "\t\t PLAYER - 1 [X] \t-\t PLAYER - 2 [O]\n\n";
	cout << gameName1 << gameName2 << guideGame;
	cout << k_padding << "+---+---+---+\n";
	cout << k_padding << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |\n";
	cout << k_padding << "+---+---+---+\n";
	cout << k_padding << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |\n";
	cout << k_padding << "+---+---+---+\n";
	cout << k_padding << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |\n";
	cout << k_padding << "+---+---+---+\n\n";
}
GameResult CheckGameResult()
{
	bool isLastPlayerWin = false;
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
			board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			isLastPlayerWin = true;
			break;
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
		board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		isLastPlayerWin = true;
	}
	if (isLastPlayerWin)
	{
		if (currentPlayer == 'X')
		{
			return GameResult::X_WIN;
		}
		else {
			return GameResult::O_WIN;
		}
	}
	else if (movesPlayed == 9)
	{
		return GameResult::DRAW;
	}
		return GameResult::NONE;
}
void UpdateBoard(size_t i_playerMove)
{
	board[(i_playerMove - 1) / 3][(i_playerMove - 1) % 3] = currentPlayer;
	++movesPlayed;
	gameResult = CheckGameResult();
	currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
}
bool ValidateMove(size_t i_playerMove)
{
	if (i_playerMove < 1 || i_playerMove > 9)
	{
		cout << k_padding << "Chon sai roi, chon lai di khong t dam cho gio >.< \n";
		return false;
	}
	char valueCurrentPlay = board[(i_playerMove - 1) / 3][(i_playerMove - 1) % 3];
	if (valueCurrentPlay == 'X' || valueCurrentPlay == 'O')
	{
		cout << k_padding << "Cho nay co nguoi roi, di cho khac di =.= \n";
		return false;
	}
	return true;
}

void UpdatePlayerMove()
{
	bool isValidMove = false;
	while (!isValidMove)
	{
		if (currentPlayer == 'X')
		{
			cout << k_padding << "Den luot m di roi day, so 1 [X]: ";
		}
		else {
			cout << k_padding << "Gio thi den luot m, so 2 [O]: ";
		}
		cin >> playerMove;
		isValidMove = ValidateMove(playerMove);
	}
	UpdateBoard(playerMove);
}
void RenderGameOver()
{
	cout << k_padding << "\t ---Game---+---OVER--- \n";
	switch (gameResult)
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
	char inputPlayer;
	cout << k_padding << "Co lam phat nua khong 2 ban? (Nhap Y de choi lai, nhap ky tu khac de thoat game) :  ";
	cin >> inputPlayer;
	if (inputPlayer == 'Y' || inputPlayer == 'y')
	{
		InitGame();
	}
	else {
		isPlayerWantExit = true;
	}
}
void UpdateGame()
{
	while (!isPlayerWantExit)
	{
		system("CLS");
		if (gameResult == GameResult::NONE)
		{
			RenderBoard();
			UpdatePlayerMove();
		}
		else {
			RenderBoard();
			RenderGameOver();
		}
	}
}

void EndGame()
{

}

void main()
{
	InitGame();

	UpdateGame();

	EndGame();

	getchar();
}