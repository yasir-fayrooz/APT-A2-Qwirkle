#include <string>
#include "TileBag.h"
#include "TileCodes.h"
#include "Board.h"
#include "Player.h"
#include "Renderer.h"

using std::string;

class GameEngine {
public:
   GameEngine(string player1name, string player2name);
   GameEngine(string fileName);
   
   void startGame(Renderer* render);

private:
//instance variables

   Board* board;
   TileBag* tileBag;
   
   Player* players[2]; //2 players
   bool player1Turn = true; //if true, player 1's turn, if false, player 2's turn...
   
   bool endGame = false; //checks for win conditions and sets to true when game ends
   bool qwirkle = false;
   
//methods
   void renderGame(Renderer* render);
   bool validation(string input);
   void replace(string input);
   void place(string input);
   void calculatePointsScored(char color, int shape, int xPos, int yPos);
   int  pointsScored(int xPos, int yPos, string side);
   bool endGameChecker();
   bool inputValidation(string input);
   int  spaceCount(string input);
   bool playerHandValidation(string inputType, char color, int shape);
   bool boardPosValidation(char color, int shape, int xPos, int yPos);
   bool withinBoardSize(int xPos, int yPos);
   bool placingOnEmptyTile(int xPos, int yPos);
   bool validPlacing(char color, int shape, int xPos, int yPos);
   bool nearSameColorOrShape(char color, int shape, int xPos, int yPos, int newX, int newY);
   bool checkSaveGame(string input);
   void saveGame(string input);
   void loadGame(string fileName);
   void loadBoardTiles(string boardString, int xSize);
   
};