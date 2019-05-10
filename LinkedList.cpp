
#include "LinkedList.h"

//constructor
LinkedList::LinkedList(Node* head_) : head(head_), size(0) {}				//size?

//deconstructor
LinkedList::~LinkedList() {}

int LinkedList::getSize(){
	return size;
}

// Tile LinkedList::get(int i)
// {
// 	//gets the tile at i position and returns it
// 	//does NOT increment or decrement size
// 	return nullptr;
// }

//adds tile to the back of the list
void LinkedList::addBack(Tile* tile){
	Node* newNode = new Node(tile,nullptr);
	if(head == nullptr){
		head = newNode;
	}else if(size == 1){
		head->next = newNode;
	}else{
		Node* tempNode = head;
		while(tempNode != nullptr){
			tempNode = tempNode->next;
		}
		tempNode = newNode;
	}
	size++;
}

void LinkedList::deleteTileFront(){
	Node* toDelete = head;
	if(size == 1){
		head = nullptr;
	}else if(size > 1){
		head = head->next;
		delete toDelete;
	}
	size--;
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
