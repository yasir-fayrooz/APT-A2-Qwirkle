
#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "Tile.h"

class Node {

public:
   Node(Tile* tile, Node* next);            //constructor
   ~Node();                                 //deconstructor

   Tile*    tile;
   Node*    next;
};

#endif // ASSIGN2_NODE_H
