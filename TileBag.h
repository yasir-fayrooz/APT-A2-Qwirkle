#ifndef COSC_ASS_TWO_TILEBAG
#define COSC_ASS_TWO_TILEBAG

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

#endif // COSC_ASS_TWO_TILEBAG
