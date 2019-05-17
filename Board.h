#include "Tile.h"
#include <string>

using std::string;

#define MAX_BOARD_X  26
#define MAX_BOARD_Y  26


class Board {
public:
   Board();
   Board(int xSize, int ySize);

   void placeTile(char color, int shape, int xPos, int yPos);
   Tile getTile(int xPos, int yPos);
   bool isEmptyTile(int xPos, int yPos);
   int  getTilesPlaced();

   int  getXSize();
   int  getYSize();

   string toString();

private:
   Tile tile[6][6];
   int  tilesPlaced;
   int  xSize;
   int  ySize;

   void checkAndExpandBoard(xPos, yPos);
};

#endif // ASSIGN2_TILE_H
