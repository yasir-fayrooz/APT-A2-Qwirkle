
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <string>

using std::string;

// Define a Colour type
typedef char Color;

// Define a Shape type
typedef int Shape;

class Tile {
public:
   Tile(Color color, Shape shape);

   Color  getColor();
   Shape  getShape();
   string toString();

private:
   Color color;
   Shape  shape;
};

#endif // ASSIGN2_TILE_H
