#include "Tile.h"
#include "LinkedList.h"

#include <string>

class TileBag {
public:
   TileBag();
   ~TileBag();

   //real methods
   int      getSize();
   Tile*    drawTileFront();
   void     addBack(char color, int shape);
   string   toString();

private:
//instance variables
   LinkedList* tileBag;

   void       shuffleBag();
   void       initialiseTiles();

//methods

};
