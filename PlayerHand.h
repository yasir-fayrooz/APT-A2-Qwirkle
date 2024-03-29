#ifndef ASSIGN2_PLAYERHAND_H
#define ASSIGN2_PLAYERHAND_H

#include "LinkedList.h"

#include "TileBag.h"

#include <string>
using std::string;

class PlayerHand {
public:
   PlayerHand(TileBag* tileBag);
   PlayerHand(string playerHandString);
   ~PlayerHand();

   void     drawTile(TileBag* tileBag);
   void     deleteTileHand(char color, int shape);
   void     replaceTile(char color, int shape, TileBag* tileBag);
   bool     checkIfTileInHand(char color, int shape);
   string   toString();
   int      getSize();


private:
//instance variables
   LinkedList* playerHand;

//methods

};

#endif //ASSIGN2_PLAYERHAND_H
