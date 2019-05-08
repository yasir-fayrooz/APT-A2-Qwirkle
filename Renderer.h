#include "Player.h"
#include "Board.h"

#include <string>

class Renderer {
public:
	void clearConsole();
	void mainMenu();
	void playerName(string player);
	void loadGame();
	void showStudentInfo();

	void playerTurn(bool player1Turn, string player1Name, string player2Name);
	void playerScore(Player player);
	void board(Board board);
	void playerHand(bool player1Turn, Player player1, Player player2);

	string getInput();

	bool getQuit();

private:

   bool quit = false;

};
