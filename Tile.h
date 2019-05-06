
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:
   Tile(Color color, Shape shape);
   
   Color  getColor();
   Shape  getShape();

private:
   Colour colour;
   Shape  shape;
};

#endif // ASSIGN2_TILE_H