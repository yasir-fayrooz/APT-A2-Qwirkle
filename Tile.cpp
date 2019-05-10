
#include "Tile.h"

using std::string;

Tile::Tile(Color color, Shape shape)
{
   this->color = color;
   this->shape = shape;
}

Color Tile::getColor()
{
	return color;
}

Shape Tile::getShape()
{
	return shape;
}

string Tile::toString()
{
	//string s = color + shape;

	//return s;
}
