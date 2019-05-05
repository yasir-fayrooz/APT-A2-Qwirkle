#include "Player.h"

Player::Player(string name, TileBag* tileBag)
{
	//sets name to this.name;
	//sets score to 0
	//sets playerHand to new PlayerHand(tileBag);
}

string Player::getName()
{
	//finished
	return name;
}

int Player::getScore()
{
	//finished
	return score;
}

void Player::setScore(int score)
{
	//finished
	this.score = score;
}

string Player::getPlayerHandString()
{
	//pseudocode done
	return "";
}

void Player::replaceTile(char color, int shape, TileBag* tileBag)
{
	//pseudocode done
}

PlayerHand Player::getPlayerHand()
{
	//finished
	return playerHand;
}

bool Player::checkIfTileInHand(char color, int shape)
{
	//pseudocode done
	return false;
}

void Player::deleteTileHand(char color, int shape)
{
	playerHand.deleteTileHand(color, shape);
}

void Player::drawTile(TileBag* tileBag)
{
	playerHand.drawTile(tileBag);
}

/* INSTANCE VARIABLES / FIELDS

   string       name;
   int          score;
   PlayerHand   playerHand;

*/

/* getPlayerHandString() method pseudocode

return playerHand.toString();

*/

/* replaceTile(char color, int shape, TileBag* tileBag) method pseudocode

playerHand.replaceTile(color, shape, tileBag);

*/

/* checkIfTileInHand(char color, int shape) method pseudocode

return playerHand.checkIfTileInHand(color, shape);

*/