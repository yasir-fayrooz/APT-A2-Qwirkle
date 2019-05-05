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
	//playerHand.addback(tileBag.drawTile(0));
}

void PlayerHand::deleteTileHand(char color, int shape)
{
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
	return 0;
}

/* INSTANCE VARIABLES / FIELDS
 
 LinkedList playerHand;

*/