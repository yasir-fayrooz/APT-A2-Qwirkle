#include "TileBag.h"

TileBag::TileBag()
{
	//tileBag = new LinkedList();
	//drawTile(tileBag); //draw 6 tiles into your hand, maybe do this in a for loop. im just too lazy
	//drawTile(tileBag);
	//drawTile(tileBag);
	//drawTile(tileBag);
	//drawTile(tileBag);
	//drawTile(tileBag);
}

int TileBag::getSize()
{
	return tileBag.size();
}

Tile TileBag::drawTileFront()
{
	//pseudocode done
	return null;
}

void TileBag::addBack(char color, int shape)
{
	//pseudocode done
}

/* INSTANCE VARIABLES / FIELDS
 
 LinkedList tileBag;

*/

/* TileBag::drawTileFront() method pseudocode

Tile tile = new Tile(tileBag.get(0).getColor(), tileBag.get(0).getShape());

tileBag.deleteTileFront();

return tile;

*/

/* TileBag::addBack(char color, int shape) method pseudocode

Tile tile = new Tile(color, shape);

tileBag.addBack(tile);

*/