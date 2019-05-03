#include <string>
#include <Renderer>
#include <Player>
#include <Board>

class GameEngine {
public:
   GameEngine(string player1name, string player2name);
   GameEngine(string fileName);
   
   void startGame(Renderer render);

private:
   Board board;
   Player players[2]; //2 players
   bool player1Turn = true; //if true, player 1's turn, if false, player 2's turn...
   
   bool endGame = false; //checks for win conditions and sets to true when game ends
};