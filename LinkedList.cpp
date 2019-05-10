
#include "LinkedList.h"

//constructor
LinkedList::LinkedList(Node* head_) : head(head_), size(0) {}				//size?

//deconstructor
LinkedList::~LinkedList() {}

int LinkedList::getSize(){
	return size;
}

//gets the tile at i position and returns it
Tile* LinkedList::get(int i){
	Node* node = head;
	for(int k=1;k<i;k++){
		node = node->next;
	}
	return node->tile;
}

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
	if(size == 1){
		head = nullptr;
	}else if(size > 1){
		deleteNode(head);
		// head = head->next;
		// delete toDelete;
	}
	size--;
}

//iterates through the list and finds the first Tile with the same color and shape and deletes it.
void LinkedList::deleteTileHand(char color, int shape){
	Node* tempNode = head;
	while((tempNode->tile->getColor() != color || tempNode->tile->getShape() != shape) && tempNode != nullptr){
		tempNode = tempNode->next;
	}
	if(tempNode != nullptr){
		deleteNode(tempNode);
	}
	size--;
}

//iterate through list, if same color and shape set exists to true and return valid
bool LinkedList::tileExists(char color, int shape){
	bool exists = false;
	Node* tempNode = head;
	while(tempNode != nullptr){
		if(tempNode->tile->getColor() == color && tempNode->tile->getShape() == shape){
			exists = true;
		}
		tempNode = tempNode->next;
	}
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

void LinkedList::deleteNode(Node* node){
	Node* toDelete = node;
	node = node->next;
	delete toDelete;
}
