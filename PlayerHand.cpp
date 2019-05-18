#include "PlayerHand.h"

PlayerHand::PlayerHand(TileBag* tileBag)
{
	playerHand = new LinkedList();
	while (int i = 0; i < 6; i++)
	{
		drawTile(tileBag);
	}
	//drawTile(tileBag); //draw 6 tiles into your hand, maybe do this in a for loop. im just too lazy
	//drawTile(tileBag);
	//drawTile(tileBag);
	//drawTile(tileBag);
	//drawTile(tileBag);
	//drawTile(tileBag);
}

PlayerHand::PlayerHand(string playerHandString)
{
	//iterate through playerhandstring and add tiles to playerHand linkedlist
}


void PlayerHand::drawTile(TileBag* tileBag)
{
	playerHand->addback(tileBag.drawTileFront());
	//playerHand.addback(tileBag.drawTileFront());
}

void PlayerHand::replaceTile(char color, int shape, TileBag* tileBag)
{
	tileBag->addBack(color, shape);
	playerHand->deletTileHand(color, shape);
	playerHand->drawTile(tileBag);

	//tileBag.addBack(color, shape);
	//PlayerHand::deleteTileHand(color, shape);
	//PlayerHand::drawTile(tileBag);
}

bool checkIfTileInHand(char color, int shape)
{
	return playerHand->tileExists(color, shape);
}

void PlayerHand::deleteTileHand(char color, int shape)
{
	playerHand->deleteTileHand(color, shape);
	//iterate through linked list, find same color and shape and remove from list
}

string PlayerHand::toString()
{
	string hand = "";
	//returns a string version of the playerHand
	//loops through all the playerHand LinkedList and gets the Tile info and stores in string with commas
	//i.e. Y4,G2,B6 etc....
	while(unsigned int i = 0; i < playerHand->getSize(); i++)
	{
		if (i == 0)
		{
			hand = playerHand->get(i);
		}
		else
		{
			hand = (hand + ", " + playerHand->get(i);
		}
	}
	return hand;
}

int PlayerHand::getSize()
{
	//returns the size of the LinkedList instance variable "playerHand"
	return playerHand->getSize();
}

/* INSTANCE VARIABLES / FIELDS
 
 LinkedList playerHand;

*/
