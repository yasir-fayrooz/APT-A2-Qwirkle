
#include "Board.h"

Board::Board()
{
	tilesPlaced = 0;
	xSize = 6;
	ySize = 6;
}

Board::Board(int xSize, int ySize)
{
	this->xSize = xSize;
	this->ySize = ySize;
}

Board::~Board()
{
	for(int x = 0; x < xSize; x++)
	{
		for(int y = 0; y < ySize; y++)
		{
			if(isEmptyTile(x, y) == false)
			{
				delete tile[x][y];	
			}
		}
	}
}

void Board::placeTile(char color, int shape, int xPos, int yPos)
{
	tile[xPos][yPos] = new Tile(color, shape);
	Board::checkAndExpandBoard(xPos, yPos);
	
	tilesPlaced++;
}

void Board::checkAndExpandBoard(int xPos, int yPos)
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

Tile* Board::getTile(int xPos, int yPos)
{
	return tile[xPos][yPos];
}

bool Board::isEmptyTile(int xPos, int yPos)
{
	bool empty = false;
	
	if(tile[xPos][yPos] == nullptr)
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

string Board::toString()
{
	string board = "";
	
	for(int i = 0; i < xSize; i++)
	{
		if(i == 0)
		{
			board.append("   ");
		}
		board.append(std::to_string(i) + "  ");
	}
	
	board.append("\n");
	
	for(int i = 0; i < xSize; i++)
	{
		if(i == 0)
		{
			board.append("  ");
		}
		board.append("---");
	}
	
	board.append("\n");
	
	for(int x = 0; x < xSize; x++)
	{
		string row;
		char rowChar = 65 + x;
		row = rowChar;
		
		board.append(row + " |");
		
		for(int y = 0; y < ySize; y++)
		{
			if(isEmptyTile(x, y) == true)
			{
				board.append("  |");
			}
			else
			{
				board.append(getTile(x, y)->toString() + "|");
			}
		}
		
		board.append("\n");
	}
	
	return board;
}

/* INSTANCE VARIABLES
   
   Tile tile[6][6];
   int  tilesPlaced;
   int  xSize;
   int  ySize;

*/