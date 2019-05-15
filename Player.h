#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "PlayerHand.h"
#include "TileBag.h"

#include <string>

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

#endif //ASSIGN2_PLAYER_H
