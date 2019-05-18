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

void Tile::setColor(Color color)
{
	this->color = color;
}

void Tile::setShape(Shape shape)
{
	this->shape = shape;
}
string Tile::toString()
{
	string color;
	color = this->color;
	return color + std::to_string(shape);
}
