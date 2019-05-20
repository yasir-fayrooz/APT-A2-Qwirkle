
#include "Node.h"

//constructor
Node::Node(Tile* tile_, Node* next_) : tile(tile_), next(next_){}       //this?

//deconstructor
Node::~Node(){  delete tile; }
