#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include "Board.h"
#include "Player.h"
#include "TileBag.h"

using std::string;

class Renderer {
public:
	void clearConsole();
	void mainMenu();
	void playerName(string player);
	void loadGame();
	void showStudentInfo();
	
	void playerTurn(bool player1Turn, string player1Name, string player2Name);
	void playerScore(Player* player);
	void tileBagCount(TileBag* tileBag);
	void board(Board* board);
	void playerHand(bool player1Turn, Player* player1, Player* player2);
	void saveGame();
	void inputValidationError();
	void renderMenuError();
	void qwirkle();
	void gameOver(Player* player1, Player* player2);
	void AIInput(string input);
	void sleep(unsigned milliseconds);

	string getInput();

	bool getQuit();

private:

   bool quit = false;

};

#endif //RENDERER_H