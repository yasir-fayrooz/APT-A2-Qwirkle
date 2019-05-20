#include "Board.h"

Board::Board()
{
	xSize = 6;
	ySize = 6;
	//create the board
	tile = new Tile**[ySize];
	for(int y = 0; y < ySize; y++)
	{
		tile[y] = new Tile*[xSize];
	}
	//initialise to nullptr
	for(int y = 0; y < ySize; y++)
	{
		for(int x = 0; x < xSize; x++)
		{
			tile[y][x] = nullptr;
		}
	}
	//initialise tilesPlaced
	tilesPlaced = 0;
}

Board::Board(int xSize, int ySize)
{
	//initialise xSize, ySize
	this->xSize = xSize;
	this->ySize = ySize;
	//initialise Board size
	tile = new Tile**[ySize];
	for(int y = 0; y < ySize; y++)
	{
		tile[y] = new Tile*[xSize];
	}
	//initialise tiles to nullptr
	for(int y = 0; y < ySize; y++)
	{
		for(int x = 0; x < xSize; x++)
		{
			tile[y][x] = nullptr;
		}
	}
}

Board::~Board()
{
	for(int y = 0; y < ySize; y++)
	{
		for(int x = 0; x < xSize; x++)
		{
			delete tile[y][x];
		}
		delete[] tile[y];
	}
	delete[] tile;
	tile = nullptr;
}

void Board::placeTile(char color, int shape, int xPos, int yPos)
{
	tile[yPos][xPos] = new Tile(color, shape);
	checkAndExpandBoard(xPos, yPos); 

	tilesPlaced++;
}

void Board::checkAndExpandBoard(int xPos, int yPos)
{
	if(xPos == (xSize - 1) && xSize < MAX_BOARD_X)
	{
		//CREATE NEW TEMP ARRAY START
		Tile*** newTile = new Tile**[ySize];
		for(int y = 0; y < ySize; y++)
		{
			newTile[y] = new Tile*[xSize + 1];   //creates new 2d array of array xSize + 1
		}
		//CREATE NEW TEMP ARRAY END	
		
		//COPY ARRAY VALUES TO NEW ARRAY START
		for(int x = 0; x < xSize + 1; x++)
		{
			for(int y = 0; y < ySize; y++)
			{
				if(x != xSize && tile[y][x] != nullptr)
				{
					newTile[y][x] = new Tile(tile[y][x]->getColor(), tile[y][x]->getShape());  //copies all old values		
				}
				else
				{
					newTile[y][x] = nullptr;
				}
			}
		}
		//COPY ARRAY VALUES TO NEW ARRAY END
		
		//DELETE OLD ARRAY START
		for(int y = 0; y < ySize; y++)
		{
			for(int x = 0; x < xSize; x++)
			{
				delete tile[y][x];
			}
			delete[] tile[y];
		}
		delete[] tile;
		tile = nullptr;
		//DELETE OLD ARRAY END
		
		//ASSIGN DELETED TO NEW TEMP ARRAY START
		tile = newTile;
		*tile = *newTile;
		**tile = **newTile;
		***tile = ***newTile;
		xSize++;
		//ASSIGN DELETED TO NEW TEMP ARRAY END
	}
	if(yPos == ySize - 1 && ySize < MAX_BOARD_Y)
	{
		//CREATE NEW TEMP ARRAY START
		Tile*** newTile = new Tile**[ySize + 1];
		for(int y = 0; y < ySize + 1; y++)
		{
			newTile[y] = new Tile*[xSize];   //creates new 2d array of array xSize
		}
		//CREATE NEW TEMP ARRAY END	
		
		//COPY ARRAY VALUES TO NEW ARRAY START
		for(int x = 0; x < xSize; x++)
		{
			for(int y = 0; y < ySize + 1; y++)
			{
				if(y != ySize && tile[y][x] != nullptr)
				{
					newTile[y][x] = new Tile(tile[y][x]->getColor(), tile[y][x]->getShape());  //copies all old values		
				}
				else
				{
					newTile[y][x] = nullptr;
				}
			}
		}
		//COPY ARRAY VALUES TO NEW ARRAY END
		
		//DELETE OLD ARRAY START
		for(int y = 0; y < ySize; y++)
		{
			for(int x = 0; x < xSize; x++)
			{
				delete tile[y][x];
			}
			delete[] tile[y];
		}
		delete[] tile;
		tile = nullptr;
		//DELETE OLD ARRAY END
		
		//ASSIGN DELETED TO NEW TEMP ARRAY START
		tile = newTile;
		*tile = *newTile;
		**tile = **newTile;
		***tile = ***newTile;
		ySize++;
		//ASSIGN DELETED TO NEW TEMP ARRAY END
	}
}

Tile* Board::getTile(int xPos, int yPos)
{
	if((xPos >= xSize - 1 || xPos < 0) ||
	   (yPos >= ySize - 1 || yPos < 0))
	{
		return nullptr;
	}

	return tile[yPos][xPos];
}

bool Board::isEmptyTile(int xPos, int yPos)
{
	if((xPos >= xSize - 1 || xPos < 0) ||
	   (yPos >= ySize - 1 || yPos < 0))
	{
		return true;
	}
	
	bool empty = false;
	
	if(tile[yPos][xPos] == nullptr)
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
	
	for(int i = 0; i < ySize; i++)
	{
		if(i == 0)
		{
			board.append("   ");
		}
		board.append(std::to_string(i) + "  ");
	}
	
	board.append("\n");
	
	for(int i = 0; i < ySize; i++)
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
			if(tile[y][x] == nullptr)
			{
				board.append("  |");
			}
			else
			{
				board.append(tile[y][x]->toString() + "|");
			}
		}
		if(x != xSize - 1)
		{
			board.append("\n");	
		}
	}
	
	return board;
}

/* INSTANCE VARIABLES
   
   Tile tile[6][6];
   int  tilesPlaced;
   int  xSize;
   int  ySize;

*/