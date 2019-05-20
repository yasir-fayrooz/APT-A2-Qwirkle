#include "Tile.h"

Tile::Tile(Color color, Shape shape)
{
   this->color = color;
   this->shape = shape;
}
Tile::Tile(const Tile &oldTile)
{
	this->color = oldTile.color;
	this->shape = oldTile.shape;
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
	string colorStr;
	colorStr = color;
	return colorStr + std::to_string(shape);	
}
