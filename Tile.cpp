#include "Tile.h"

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
	string color;
	color = this->color;
	return color + std::to_string(shape);
}
