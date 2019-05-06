
#include "Board.h"

Board::Board()
{
	tile = new Tile[6][6];
	tilesPlaced = 0;
	xSize = 6;
	ySize = 6;
}


void Board::placeTile(char color, int shape, int xPos, int yPos)
{
	tile[xPos][yPos] = new Tile(color, shape);
	Board::checkAndExpandBoard(xPos, yPos);
	
	tilesPlaced++;
}

void Board::checkAndExpandBoard(xPos, yPos)
{
	/*
		IF(xPos == xSize - 1 && xSize < MAX_BOARD_X)
			xSize++;
			CREATE NEW TEMPORARY TILE OF SIZE tileTemp[xSize][ySize];
			FILL IN ALL EXISTING TILES FROM tile[xSize - 1][ySize] into tileTemp[xSize][ySize]
			DELETE tile array
			SET tile array to tileTemp array
		ELSEIF(yPos == ySize - 1 && ySize < MAX_BOARD_Y)
			ySize++;
			CREATE NEW TEMPORARY TILE OF SIZE tileTemp[xSize][ySize];
			FILL IN ALL EXISTING TILES FROM tile[xSize][ySize - 1] into tileTemp[xSize][ySize]
			DELETE tile array
			SET tile array to tileTemp array
		ENDIF
	
	*/
	
}

Tile Board::getTile(int xPos, int yPos)
{
	return tile[xPos][yPos];
}

bool Board::isEmptyTile(int xPos, int yPos)
{
	bool empty = false;
	
	if(tile[xPos][yPos] == NULL)
	{
		empty = true;
	}
	
	return empty;
}

int Board::getTilesPlaced()
{
	return tilesPlaced;
}

int Board::getXSize()
{
	return xSize;
}

int Board::getYSize()
{
	return ySize;
}

/* INSTANCE VARIABLES
   
   Tile tile[6][6];
   int  tilesPlaced;
   int  xSize;
   int  ySize;

*/