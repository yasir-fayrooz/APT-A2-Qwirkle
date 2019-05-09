#include "TileBag.h"

TileBag::TileBag()
{
	//tileBag = new LinkedList();
	//tileBag.initialiseTiles();
	//tileBag.shuffleBag();
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

void TileBag::initialiseTiles()
{
	//RUNS LOOP AND ADDSBACK 2 OF EACH TILE TO THE TILE BAG LIST IN ORDER
}

void TileBag::shuffleBag()
{
	/*
	
	FOR(int index = 0; index < tileBag.getSize(); index++)
		int randomNumber = //RANDOM NUMBER FROM 0 TO tileBag.getSize() - 1
		tileBag.shuffleTiles(index, randomNumber);	
		
	*/
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