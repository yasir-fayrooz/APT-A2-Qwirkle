#include "TileBag.h"

#include <random>
//#include <iostream>

//using std::cout;
//using std::endl;

TileBag::TileBag(){
	tileBag = new LinkedList();
	initialiseTiles();
	shuffleBag();
}

TileBag::TileBag(string tileBagString)
{
	tileBag = new LinkedList();
	
	int iterator = 0;
	for(unsigned int i = 0; i < tileBagString.length(); i++)
	{
		string tile;
		if(i == 0)
		{
			tile = tileBagString.substr(iterator, 2);
		}
		else
		{
			iterator = tileBagString.find(",", iterator) + 1;
			tile = tileBagString.substr(iterator, 2);
		}
		
		char color = tile[0];
		int shape = stoi(tile.substr(1, 1));
	
		Tile* loadTile = new Tile(color, shape);
	
		tileBag->addBack(loadTile);
	}
}

TileBag::~TileBag(){
	delete tileBag;
}

int TileBag::getSize(){
	return tileBag->getSize();
}

//draws the first tile
Tile* TileBag::drawTileFront(){
	Tile* tile = tileBag->get(0);
	tileBag->deleteTileFront();
	return tile;
}

//adds a tile to the tileBag
void TileBag::addBack(char color, int shape){
	Tile* tile = new Tile(color,shape);
	tileBag->addBack(tile);
}

//RUNS LOOP AND ADDSBACK 2 OF EACH TILE TO THE TILE BAG LIST IN ORDER
void TileBag::initialiseTiles(){
	for(int shape=1;shape<7;shape++){
		for(int i=0;i<2;i++){
			Tile* r = new Tile('R',shape);
			tileBag->addBack(r);
			Tile* o = new Tile('O',shape);
			tileBag->addBack(o);
			Tile* y = new Tile('Y',shape);
			tileBag->addBack(y);
			Tile* g = new Tile('G',shape);
			tileBag->addBack(g);
			Tile* b = new Tile('B',shape);
			tileBag->addBack(b);
			Tile* p = new Tile('P',shape);
			tileBag->addBack(p);
		}
	}
}

void TileBag::shuffleBag(){
	int min = 0;
	int max = tileBag->getSize() - 1;

	std::random_device engine;
	std::uniform_int_distribution<int> uniform_dist(min, max);

	int randNum = -1;
	for (int i = 0; i != tileBag->getSize(); ++i) {
		randNum = uniform_dist(engine);
		tileBag->shuffleTiles(i,randNum);
	}
}

string TileBag::toString(){
	string str = "";
	for(int i=0;i<tileBag->getSize();i++){
		str = str + tileBag->get(i)->getColor() + std::to_string(tileBag->get(i)->getShape()) + ",";
	}
	return str;
}

/* INSTANCE VARIABLES / FIELDS

 LinkedList tileBag;

*/

/* TileBag::drawTileFront() method pseudocode

Tile tile = new Tile(tileBag.get(0).getColor(), tileBag.get(0).getShape());

tileBag.deleteTileFront();

return tile;

*/

/* TileBag::addBack(char color, int shape) method pseudocode

Tile tile = new Tile(color, shape);

tileBag.addBack(tile);

*/

//to_string
//FOR(each tile in tileBag)
	//string = string + tile.toString();
	//string = string + ",";
//END FOR LOOP

/*
shuffleBag

FOR(int index = 0; index < tileBag.getSize(); index++)
	int randomNumber = //RANDOM NUMBER FROM 0 TO tileBag.getSize() - 1
	tileBag.shuffleTiles(index, randomNumber);

//RAPH CODE START
int min = 1;
			int max = tileBag.getSize();

			std::random_device engine;
			std::uniform_int_distribution<int> uniform_dist(min, max);

			int value = -1;
			for (int i = 0; i != tileBag.getSize(); ++i) {
			value = uniform_dist(engine);
//RAPH CODE END

*/
