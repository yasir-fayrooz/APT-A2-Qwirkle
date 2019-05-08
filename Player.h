#include <string>
#include <PlayerHand>
#include <TileBag>

class Player {
public:
   Player(string player1name, string player2name);
   
   string       getName();
   int          getScore();
   void         setScore(int score);
   string       getPlayerHandString();
   void         replaceTile(char color, int shape, TileBag* tileBag)
   PlayerHand   getPlayerHand();
   bool         checkIfTileInHand(char color, int shape);
   void         drawTile(TileBag* tileBag);
   void         deleteTileHand(char color, int shape);
   
private:
//instance variables
   string       name;
   int          score;
   PlayerHand   playerHand;
   
//methods
};