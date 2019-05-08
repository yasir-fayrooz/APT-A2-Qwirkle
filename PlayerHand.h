#include "TileBag.h"

#include <string>
#include <list>

class PlayerHand {
public:
   PlayerHand(TileBag* tileBag);

   void     drawTile(TileBag* tileBag);
   void     deleteTileHand(char color, int shape);
   void     replaceTile(char color, int shape, TileBag* tileBag);
   bool     checkIfTileInHand(char color, int shape);
   string   toString();
   int      getSize();


private:
//instance variables
   LinkedList playerHand;

//methods

};
