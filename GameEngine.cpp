#include GameEngine.h


GameEngine::GameEngine(string player1name, string player2name)
{
	//creates 2 new players in the player array, initialises new things such as board etc.
}

GameEngine::GameEngine(string fileName)
{
	//loads from file and stores into instance variables in .h file
}

void GameEngine::startGame(Renderer render)
{
	//This will be our game loop
}

/* INSTANCE VARIABLES / FIELDS

Board board;
Player players[2];
bool player1Turn = true;

bool endGame = false;

*/

/* startGame(Renderer render) pseudocode implementation:

WHILE(endGame == false && render.getQuit == false)
	render.clearConsole();
	render.playerTurn(player1Turn, players[0].getName(), players[1].getName());
	render.playerScore(players[0]);
	render.playerScore(players[1]);
	render.board(board);
*/