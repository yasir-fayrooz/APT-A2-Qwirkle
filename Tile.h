
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
   Tile(const Tile &oldTile);

   Color  getColor();
   Shape  getShape();
   void   setColor(Color color);
   void   setShape(Shape shape);
   
   string toString();

private:
   Color color;
   Shape  shape;
};

#endif // ASSIGN2_TILE_H
