
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

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
   void   deleteNode(Node* node);

private:
   Node* head;
   int   size;
};

#endif // ASSIGN2_LINKEDLIST_H
