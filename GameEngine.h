#include <string>
#include <Renderer>
#include <Player>
#include <Board>
#include <TileBag>

class GameEngine {
public:
   GameEngine(string player1name, string player2name);
   GameEngine(string fileName);
   
   void startGame(Renderer render);

private:
//instance variables

   Board board;
   TileBag tileBag;
   
   Player players[2]; //2 players
   bool player1Turn = true; //if true, player 1's turn, if false, player 2's turn...
   
   bool endGame = false; //checks for win conditions and sets to true when game ends
   
//methods
   void renderGame();
   bool validation(string input);
   void replace(string input);
   void place(string input);
   void calculatePointsScored();
   bool endGameChecker();
   bool inputValidation(string input);
   bool playerHandValidation(string inputType, string input);
   bool boardPosValidation(string inputType, string input);
};