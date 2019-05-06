
#include "LinkedList.h"


LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
}

int LinkedList::size()
{
	return size;
	//size is an instance variable in LinkedList.h file
}

Tile LinkedList::get(int i)
{
	//gets the tile at i position and returns it
	//does NOT increment or decrement size
	return null;
}

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