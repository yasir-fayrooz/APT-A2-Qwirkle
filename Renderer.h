#include <string>
#include <Player>
#include <Board>

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
	
	string getInput();
	
	bool getQuit();

private:

   bool quit = false;
   
};