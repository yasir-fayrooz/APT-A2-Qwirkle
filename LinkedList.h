
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();                                                  //constructor
   ~LinkedList();                                                 //deconstructor

   int    getSize();
   Tile*  get(int i);
   void   addBack(Tile* tile);
   void   deleteTileFront();
   void   deleteTileHand(char color, int shape);
   bool   tileExists(char color, int shape);
   void   shuffleTiles(int index, int randomNumber);

private:
   Node* head;
   int   size;
};

#endif // ASSIGN2_LINKEDLIST_H
