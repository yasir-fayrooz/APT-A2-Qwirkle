#include <string>
#include <TileBag>
#include <LinkedList>

class PlayerHand {
public:
   PlayerHand(TileBag* tileBag);
      
   void     drawTile(TileBag* tileBag);
   void     deleteTileHand(char color, int shape);
   string   toString();
   int      getSize();
   
   
private:
//instance variables
   LinkedList playerHand;
   
//methods
   
};