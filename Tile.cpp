
#include "Tile.h"

Tile::Tile(Color color, Shape shape)
{
   this.color = color;
   this.shape = shape;
}


Color Tile::getColor()
{
	return color;
}

Shape Tile::getShape()
{
	return shape;
}