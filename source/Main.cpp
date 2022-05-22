#include "Game.h"


void main()
{
	Game* game = new Game();
	game->InitGame();

	game->UpdateGame();

	game->EndGame();

	getchar();
}