
#include "Node.h"

//constructor
Node::Node(Tile* tile, Node* next) : tile(tile), next(next){}       //this?

//copy constructor
Node::Node(Node& other) : tile(other.tile), next(other.next){}
