
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
	/*

	int boardX = board->getXSize();
	int boardY = board->getYSize();
	while (int i = 0; i < boardX; i++)
	{
		if (i == 0) 
		{
			std::cout << ("\n   ");
		}
		std::cout << (i + "  ");
	}
	while (int z = 0; z < boardX; z++)
	{
		if (z == 0)
		{
			std::cout << ("\n  ----");
		}
		std::cout << ("---");
	}
	while (int y = 0; y < boardY; y++)
	{
		std::cout << ("\n" + letters[y] + " |");
		while (int x = 0; x < boardX; x++)
		{
			if (board->isEmptyTile(x, y) == true)
			{
				std::cout << ("  |");
			}
			else
			{
				std::cout << (board->getTile(x, y) + "|");
			}
		}
	}

	*/
	return board;
}

/* INSTANCE VARIABLES
   
   Tile tile[6][6];
   int  tilesPlaced;
   int  xSize;
   int  ySize;

*/