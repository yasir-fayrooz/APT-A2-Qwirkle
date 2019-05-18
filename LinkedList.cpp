
#include "LinkedList.h"

//constructor
LinkedList::LinkedList() : head(nullptr), size(0) {}

//deconstructor
LinkedList::~LinkedList() {
	/*
	FOR each Node
		GET  next
		DELETE node
	*/
}

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
		while(tempNode->next != nullptr){
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;
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

//iterates through the list and finds the first Tile with the same color and shape and deletes it.
void LinkedList::deleteTileHand(char color, int shape){
	Node* tempNode = head;
	if(head->tile->getColor() == color && head->tile->getShape() == shape){
		deleteTileFront();
		size--;
	}else{
		while((tempNode->next->tile->getColor() != color || tempNode->next->tile->getShape() != shape) && tempNode != nullptr){
			tempNode = tempNode->next;
		}
		if(tempNode->next != nullptr){
			Node* toDelete = tempNode->next;
			tempNode->next = toDelete->next;
			delete toDelete;
			size--;
		}
	}
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

//switch tiles
void LinkedList::shuffleTiles(int index, int randomNumber)
{
	char tile1Color = get(index)->getColor();
	int tile1Shape = get(index)->getShape();
	
	get(index)->setColor(get(randomNumber)->getColor());
	get(index)->setShape(get(randomNumber)->getShape());
	
	get(randomNumber)->setColor(tile1Color);
	get(randomNumber)->setShape(tile1Shape);

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
