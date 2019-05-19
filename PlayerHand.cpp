#include "PlayerHand.h"

PlayerHand::PlayerHand(TileBag* tileBag)
{
	playerHand = new LinkedList();
	for(int i = 0; i < 6; i++)
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
	playerHand = new LinkedList();
	
	int iterator = 0;
	for(unsigned int i = 0; i < playerHandString.length(); i++)
	{
		string tile;
		if(i == 0)
		{
			tile = playerHandString.substr(iterator, 2);
		}
		else
		{
			iterator = playerHandString.find(",", iterator) + 1;
			tile = playerHandString.substr(iterator, 2);
		}
		
		char color = tile[0];
		int shape = stoi(tile.substr(1, 1));
	
		Tile* loadTile = new Tile(color, shape);
	
		playerHand->addBack(loadTile);
	}
}

PlayerHand::~PlayerHand()
{
	delete playerHand;
}


void PlayerHand::drawTile(TileBag* tileBag)
{
	playerHand->addBack(tileBag->drawTileFront());
}

void PlayerHand::replaceTile(char color, int shape, TileBag* tileBag)
{
	tileBag->addBack(color, shape);
	drawTile(tileBag);

	//tileBag.addBack(color, shape);
	//PlayerHand::deleteTileHand(color, shape);
	//PlayerHand::drawTile(tileBag);
}

bool PlayerHand::checkIfTileInHand(char color, int shape)
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
	for(int i = 0; i < playerHand->getSize(); i++)
	{
		if (i == 0)
		{
			hand.append(playerHand->get(i)->toString());
		}
		else
		{
			hand.append(", " + playerHand->get(i)->toString());
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
