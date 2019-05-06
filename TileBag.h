#include <string>
#include <Tile>
#include <LinkedList>

class TileBag {
public:
   TileBag();
   
   //real methods
   int      getSize();
   Tile     drawTileFront();
   void     addBack(char color, int shape);
   
private:
//instance variables
   LinkedList tileBag;
   
//methods
   
};