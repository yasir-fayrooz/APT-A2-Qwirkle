
#include "LinkedList.h"


LinkedList::LinkedList(Node* head) : head(head) {}

LinkedList::~LinkedList() {
}

int LinkedList::getSize()
{
	return size;
	//size is an instance variable in LinkedList.h file
}

// Tile LinkedList::get(int i)
// {
// 	//gets the tile at i position and returns it
// 	//does NOT increment or decrement size
// 	return nullptr;
// }

void LinkedList::addBack(Tile tile)
{
	//adds tile to the back of the list
	//size++;
}

void LinkedList::deleteTileFront()
{
	//deletes tile at the front of list
	//size--;
}

void LinkedList::deleteTileHand(char color, int shape)
{
	//iterate through list and find Tile with same color and shape and delete it.
	//size--;
}

bool LinkedList::tileExists(char color, int shape)
{
	//iterate through list, if same color and shape set exists to true and return valid
	bool exists = false;

	return exists;
}

void LinkedList::shuffleTiles(int index, int randomNumber)
{
	/*

	Tile* tile1 = get(index);
	Tile* tile2 = get(randomNumber);    //We are getting pointers NOT COPYING TILES

	Tile* tempPointer = &tile2;

	tile2 = &tile1;
	tile1 = &tempPointer;

		//SWAP THE TILES POSITIONS IN THE LINKED LIST
		//I THINK THATS HOW ITS DONE DOUBLE CHECK WHEN YOU WRITE IT
	*/
}
