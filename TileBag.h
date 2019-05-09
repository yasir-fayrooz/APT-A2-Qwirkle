#include "Tile.h"

#include <string>
#include <list>

class TileBag {
public:
   TileBag();

   //real methods
   int      getSize();
   Tile     drawTileFront();
   void     addBack(char color, int shape);
   string   toString();

private:
//instance variables
   LinkedList tileBag;
   
   void       shuffleBag();
   void       initialiseTiles();

//methods

};
