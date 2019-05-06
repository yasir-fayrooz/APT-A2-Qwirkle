#include "PlayerHand.h"

PlayerHand::PlayerHand(TileBag* tileBag)
{
	//playerHand = new LinkedList();
	//drawTile(tileBag); //draw 6 tiles into your hand, maybe do this in a for loop. im just too lazy
	//drawTile(tileBag);
	//drawTile(tileBag);
	//drawTile(tileBag);
	//drawTile(tileBag);
	//drawTile(tileBag);
}

void PlayerHand::drawTile(TileBag* tileBag)
{
	//playerHand.addback(tileBag.drawTileFront());
}

void PlayerHand::replaceTile(char color, int shape, TileBag* tileBag)
{
	//tileBag.addBack(color, shape);
	//PlayerHand::deleteTileHand(color, shape);
	//PlayerHand::drawTile(tileBag);
}

bool checkIfTileInHand(char color, int shape)
{
	return playerHand.tileExists(color, shape);
}

void PlayerHand::deleteTileHand(char color, int shape)
{
	playerHand.deleteTileHand(char color, int shape);
	//iterate through linked list, find same color and shape and remove from list
}

string PlayerHand::toString()
{
	string hand = "";
	//returns a string version of the playerHand
	//loops through all the playerHand LinkedList and gets the Tile info and stores in string with commas
	//i.e. Y4,G2,B6 etc....
	return hand;
}

int PlayerHand::getSize()
{
	//returns the size of the LinkedList instance variable "playerHand"
	return playerHand.size();
}

/* INSTANCE VARIABLES / FIELDS
 
 LinkedList playerHand;

*/