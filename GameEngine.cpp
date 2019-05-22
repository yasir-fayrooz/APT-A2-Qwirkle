#include "GameEngine.h"
#include <fstream>
#include <sstream>

#include <iostream> // del later

using std::stoi;

GameEngine::GameEngine(string player1name, string player2name, bool AIGame)
{
	//Method overloaded to start a new game
	board = new Board();
	tileBag = new TileBag();
	players[0] = new Player(player1name, tileBag);
	players[1] = new Player(player2name, tileBag);
	this->AIGame = AIGame;
}

GameEngine::GameEngine(string fileName)
{
	//Method overloaded to load a game
	//loads from file and stores into instance variables in .h file
	GameEngine::loadGame(fileName);
}

GameEngine::~GameEngine()
{
	delete board;
	delete tileBag;
	delete players[0];
	delete players[1];
}


/*
This method is our main game loop that runs when starting or loading a game.
*/
void GameEngine::startGame(Renderer* render)
{
	bool saveGame = false; //if a player saves a game, this will be true
	while(endGame == false && render->getQuit() == false) //Game loop conditions
	{
    	renderGame(render);

    	if(qwirkle == true)
    	{
      		render->qwirkle();
      		qwirkle = false; //qwirkle is an instance variable
    	}

		if(saveGame == true)
		{
			render->saveGame();
			saveGame = false;
		}

    	bool validation = false;
		string input = ""; //each time a player types something, it gets stored in input
		
		if(AIGame == true && player1Turn == false) //If its the AI turn
		{
			input = AIInput(); //AI calculates input and sets it to the input in the game loop
			render->AIInput(input); //AI renders the input to the screen
			validation = true; //AI input is always correct
		}
		else
		{
			while(validation == false && render->getQuit() == false && saveGame == false) //loop for validating players input
			{
				input = render->getInput();
				saveGame = checkSaveGame(input);
				validation = this->validation(input);
			
				if(validation == false && saveGame == false)
				{
					renderGame(render);
					render->inputValidationError();
				}
			
				if(saveGame == true)
				{
					this->saveGame(input);
				}
			}	
		}
		
		if(validation == true && render->getQuit() == false && saveGame == false) //Places or replaces once input is validated
		{
			string inputType = input.substr(0, input.find(" "));
			
			if(inputType.compare("replace") == 0)
			{
				replace(input);
				player1Turn = !player1Turn;
			}
			else if(inputType.compare("place") == 0)
			{
				place(input);
				player1Turn = !player1Turn;
				endGame = endGameChecker(); //checks game ending conditions
			}
		}
  	}
	
	if(endGame == true)
	{
		render->clearConsole();
		render->gameOver(players[0], players[1]);
		render->getInput();
	}
}

/*
This method renders the game to console
*/
void GameEngine::renderGame(Renderer* render)
{
	render->clearConsole();
	render->playerTurn(player1Turn, players[0]->getName(), players[1]->getName());
	render->playerScore(players[0]);
	render->playerScore(players[1]);
	render->tileBagCount(tileBag);
	render->board(board);
	render->playerHand(player1Turn, players[0], players[1]);
}

/*
This method is the main method that validates every part of input validation in sub-methods
*/
bool GameEngine::validation(string input)
{
	bool validatedMove = false;

	bool validatedInput = inputValidation(input); //inputValidation() validates the string length and contents.

	if(validatedInput == true)
	{
		string inputType = input.substr(0, input.find(" "));
		int firstSpace = input.find_first_of(" ") + 1;
		int secondSpace = input.find(" ", firstSpace + 1) + 1;
		int thirdSpace = input.find(" ", secondSpace + 1) + 1;
		
		string tile = input.substr(firstSpace, 2);
		string position = input.substr(thirdSpace, (input.length() - 12));

		char color = tile[0];
		int shape = stoi(tile.substr(1, 1));

		int xPos = position[0] % 65; //ASCII VALUE = 0 FOR 'A', 1 FOR 'B'...etc.. stoi(position.substr(1, position.length() - 1)); //convert str to int
		int yPos = stoi(position.substr(1, position.length() - 1)); //convert str to int

		bool validatedPlayerHand = playerHandValidation(inputType, color, shape); //validates the player hand and ensuring its a valid tile.
		bool validatedBoardPos = boardPosValidation(color, shape, xPos, yPos); //validates the board position string and ensuring its within limits

		if(validatedPlayerHand == true && inputType.compare("replace") == 0)
		{
			validatedMove = true;
		}
		else if(validatedPlayerHand == true && validatedBoardPos == true)
		{
			validatedMove = true;
		}
	}

	return validatedMove;
}

/*
This method replaces a tile in the players hand
*/
void GameEngine::replace(string input)
{
	int firstSpace = input.find_first_of(" ") + 1;
	string tile = input.substr(firstSpace, 2);

	char color = tile[0];
	int shape = stoi(tile.substr(1,1));

	if(player1Turn == true)
	{
		players[0]->deleteTileHand(color, shape);
		players[0]->replaceTile(color, shape, tileBag);
	}
	else if(player1Turn == false)
	{
		players[1]->deleteTileHand(color, shape);
		players[1]->replaceTile(color, shape, tileBag);
	}
}

/*
This method places a tile in the players hand to the board position
*/
void GameEngine::place(string input)
{
	int firstSpace = input.find_first_of(" ") + 1;
	int secondSpace = input.find(" ", firstSpace) + 1;
	int thirdSpace = input.find(" ", secondSpace) + 1;
	
	string tile = input.substr(firstSpace, 2);
	string position = input.substr(thirdSpace, (input.length() - 12));

	char color = tile[0];
	int shape = stoi(tile.substr(1, 1));

	int xPos = position[0] % 65; //ASCII VALUE = 0 FOR 'A', 1 FOR 'B'...etc..
	int yPos = stoi(position.substr(1, position.length() - 1)); //convert str to int

	board->placeTile(color, shape, xPos, yPos); //places tile

	if(player1Turn == true)
	{
		players[0]->deleteTileHand(color, shape);
		players[0]->drawTile(tileBag);
	}
	else if(player1Turn == false)
	{
		players[1]->deleteTileHand(color, shape);
		players[1]->drawTile(tileBag);
	}
	calculatePointsScored(color, shape, xPos, yPos); //adds points to the players score after placing
}

/*
This method returns the AI's string input and is calculated by:
1. Iterating through the whole board and finding a tile,
   1.1 Finding the empty spaces around the tile
   1.2 Checking the AI's hand and validating tile input
   1.3 If there is a tile than can be placed, return the place command with the tile and the position
2. If there arent any tiles in the hand that can be placed, return the replace command with the first tile in the hand.
*/
string GameEngine::AIInput()
{
	string input = "";
	
	for(int xPos = 0; xPos < board->getXSize(); xPos++)
	{
		for(int yPos = 0; yPos < board->getYSize(); yPos++)
		{
			if(board->getTile(xPos, yPos) != nullptr)
			{
				if(withinBoardSize(xPos + 1, yPos) == true &&
				   board->isEmptyTile(xPos + 1, yPos) == true)
			    {
					input = AIValidation(xPos + 1, yPos);
					if(input.compare("") != 0)
					{
						return input;
					}
			    }
				if(withinBoardSize(xPos - 1, yPos) == true &&
				   board->isEmptyTile(xPos - 1, yPos) == true)
			    {
					input = AIValidation(xPos - 1, yPos);
					if(input.compare("") != 0)
					{
						return input;
					}
			    }
				if(withinBoardSize(xPos, yPos + 1) == true &&
				   board->isEmptyTile(xPos, yPos + 1) == true)
				{
					input = AIValidation(xPos, yPos + 1);
					if(input.compare("") != 0)
					{
						return input;
					}
				}
				if(withinBoardSize(xPos, yPos - 1) == true &&
				   board->isEmptyTile(xPos, yPos - 1) == true)
				{
					input = AIValidation(xPos, yPos - 1);
					if(input.compare("") != 0)
					{
						return input;
					}
				}
			}
		}
	}
	
	return "replace " + players[1]->getPlayerHandString().substr(0, 2);
}

/*
This method returns the AI's string input and is calculated by:
1. Iterating through the AI players hand
2. If the tile in the hand can be placed on the empty xPos and yPos position
3. return the place command with the tile and xPos, yPos position
*/
string GameEngine::AIValidation(int xPos, int yPos)
{
	string input = "";
	string AIHand = players[1]->getPlayerHandString();
	
	int iterator = 0;
	for(unsigned int i = 0; i <= (AIHand.length() / 3); i++)
	{
		string tile;
		if(i == 0)
		{
			tile = AIHand.substr(iterator, 2);
		}
		else
		{
			iterator = AIHand.find(",", iterator) + 1;
			tile = AIHand.substr(iterator, 2);
		}
		
		char color = tile[0];
		int shape = stoi(tile.substr(1, 1));
		
		bool validatedBoardPos = boardPosValidation(color, shape, xPos, yPos); //validates the board position string and ensuring its within limits
		
		if(validatedBoardPos == true)
		{
			string validInput = "place ";
			validInput = validInput + color;
			validInput.append(std::to_string(shape));
			validInput.append(" at ");
			char xChar = 65 + xPos;
			validInput = validInput + xChar;
			validInput.append(std::to_string(yPos));
			return validInput;
		}
	}
	
	return "";
}

/*
This method checks the board tiles and adds the points scored once a player places a tile.
*/
void GameEngine::calculatePointsScored(char color, int shape, int xPos, int yPos)
{
	int pointsScored = 0;
	
	if(board->getTilesPlaced() == 1)
	{
		pointsScored++;
	}
	if(board->isEmptyTile((xPos + 1), yPos) == false)
	{
		pointsScored = pointsScored + this->pointsScored(xPos, yPos, "down"); //its going down because there is a tile under the one you placed	
	}
	if(board->isEmptyTile((xPos - 1), yPos) == false)
	{
		pointsScored = pointsScored + this->pointsScored(xPos, yPos, "up"); //its going up because there is a tile above the one you placed
	}
	if(board->isEmptyTile(xPos, (yPos + 1)) == false)
	{
		pointsScored = pointsScored + this->pointsScored(xPos, yPos, "right"); //its going right because there is a tile to the right where you placed	
	}
	if(board->isEmptyTile(xPos, (yPos - 1)) == false)
	{
		pointsScored = pointsScored + this->pointsScored(xPos, yPos, "left"); //its going left because there is a tile to the left where you placed	
	}

	if(player1Turn == true)
	{
		players[0]->setScore(players[0]->getScore() + pointsScored);
	}
	else if(player1Turn == false)
	{
		players[1]->setScore(players[1]->getScore() + pointsScored);
	}
}

/*
This method loops checking if there is tiles on the side specified in the parameter and adds points.
*/
int GameEngine::pointsScored(int xPos, int yPos, string side)
{
	int pointsScored = 0;
	pointsScored++;
	int qwirkleCheck = 1; //it also counts how many there are on the sides and if its 6, qwirkle is set to true

	int newX = xPos;
	int newY = yPos;

	while(board->getTile(newX, newY) != nullptr) //while there are more tiles on the side specified..
	{
		pointsScored++;
		qwirkleCheck++;

		if(side.compare("down") == 0)
		{
			newX = xPos + qwirkleCheck;
		}
		else if(side.compare("up") == 0)
		{
			newX = xPos - qwirkleCheck;
		}
		else if(side.compare("left") == 0)
		{
			newY = yPos - qwirkleCheck;
		}
		else if(side.compare("right") == 0)
		{
			newY = yPos + qwirkleCheck;
		}
	}

	if(qwirkleCheck == 6)
	{
		pointsScored = pointsScored + 6;
		qwirkle = true;
	}

	return pointsScored;
}

/*
This condition of ending a game specified in our assignment specification
*/
bool GameEngine::endGameChecker()
{
	bool endGame = false;

	if(tileBag->getSize() == 0)
	{
		if(players[0]->getPlayerHand()->getSize() == 0 ||
		   players[1]->getPlayerHand()->getSize() == 0)
		{
			endGame = true;
		}
	}

	return endGame;
}

/*
This checks 3 things, 
the inputs length matches the length of a command, 
the input has the words 'place' & 'at' OR 'replace' 
the words are in appropriate places and there are sufficient spaces in the input
*/
bool GameEngine::inputValidation(string input)
{
	bool validated = false;

	const int placeCommandLength = 14; //to check if board is small and position is G2 (1 digit)
	const int placeCommandLength2x = 15; //to check if board is big and position is G27 (2 digits)
	const int replaceCommandLength = 10;
	
	if(input.length() == placeCommandLength || input.length() == placeCommandLength2x)
	{
		if(input.substr(0,5).compare("place") == 0 && spaceCount(input) == 3 && input.substr(9,2).compare("at") == 0)
		{
			validated = true;
		}
	}
	else if(input.length() == replaceCommandLength)
	{
		if(input.substr(0,7).compare("replace") == 0 && spaceCount(input) == 1)
		{
			validated = true;
		}
	}

	return validated;
}

/*
This gets a string and counts how many spaces there are and returns the count
*/
int GameEngine::spaceCount(string input)
{
	int spaceCount = 0;

	for(unsigned int i = 0; i < input.length(); i++)
	{
		if(input[i] == 32) //32 = space ASCII
		{
			spaceCount++;
		}
	}

	return spaceCount;
}

/*
This method validates the players hand input by checking:
1. the color and shape is within limits according to the specification
2. The color and shape exists in the players hand
3. The player is not replacing a tile with no tile bags left
*/
bool GameEngine::playerHandValidation(string inputType, char color, int shape)
{
	bool validated = false;
	
	if(color == 82 || //RED ascii code
	   color == 79 || //ORANGE ascii code
	   color == 89 || //YELLOW ascii code
	   color == 71 || //GREEN ascii code
	   color == 66 || //BLUE ascii code
	   color == 80  ) //PURPLE ascii code
	{
		if(shape >= 1 && shape <= 6) //within shape limits
		{
			if(player1Turn == true && players[0]->checkIfTileInHand(color, shape))
			{
				validated = true;
			}
			else if(player1Turn == false && players[1]->checkIfTileInHand(color, shape))
			{
				validated = true;
			}
		}
	}

	if(tileBag->getSize() == 0 && inputType.compare("replace") == 0)
	{
		validated = false;
	}

	return validated;
}

/*
This method validates the board input by checking:
1. the board positions entered are within limits
2. the player is placing on an empty tile
3. the player is placing in a legal spot according to qwirkle rules
*/
bool GameEngine::boardPosValidation(char color, int shape, int xPos, int yPos)
{
	bool validated = false;

	bool isWithinBoardSize = withinBoardSize(xPos, yPos); //Checks in the positions are within board limits
	bool isPlacingOnEmptyTile = false;
	bool isValidPlacing = false;

	if(isWithinBoardSize == true)
	{
		isPlacingOnEmptyTile = placingOnEmptyTile(xPos, yPos);
		
		if(isPlacingOnEmptyTile == true)
		{
			isValidPlacing = validPlacing(color, shape , xPos, yPos); //checks qwirkle rules
		}
	}

	if(isWithinBoardSize == true && isPlacingOnEmptyTile == true && isValidPlacing == true)
	{
		validated = true;
	}

	return validated;
}

/*
This method validates the board input by checking:
1. the inputs board positions are within the boards size limits
*/
bool GameEngine::withinBoardSize(int xPos, int yPos)
{
	bool validated = false;

	if(xPos < board->getXSize() && xPos >= 0)
	{
		if(yPos < board->getYSize() && yPos >= 0)
		{
			validated = true;
		}
	}

	return validated;
}

/*
This method validates the board input by checking:
1. the position in the board is empty and not already occupied with a tile
*/
bool GameEngine::placingOnEmptyTile(int xPos, int yPos)
{
	bool validated = false;

	if(board->isEmptyTile(xPos, yPos))
	{
		validated = true;
	}

	return validated;
}

/*
This method validates the board input by checking:
1. the input position is not in an illegal spot by checking:
   1.1 the tile being placed must be on the same sides as either a color OR shape
   1.2 the tile being placed must not be on the same sides as a tile with the same color AND shape
2. The tile must not be placed in a spot where no other tiles are on its sides unless there are no tiles placed
*/
bool GameEngine::validPlacing(char color, int shape, int xPos, int yPos)
{
	bool validated = false;

	bool nearIllegalPiece = false;

	if(board->getTilesPlaced() == 0)
	{
		validated = true;
	}

	if(board->getTile(xPos + 1, yPos) != nullptr)
	{
		if(nearSameColorOrShape(color, shape, xPos, yPos, xPos + 1, yPos) == false)
		{
			nearIllegalPiece = true;
		}
		if(nearSameColorAndShape(color, shape, xPos, yPos, "down") == true)
		{
			nearIllegalPiece = true;
		}
	}
	if(board->getTile(xPos - 1, yPos) != nullptr)
	{
		if(nearSameColorOrShape(color, shape, xPos, yPos, xPos - 1, yPos) == false)
		{
			nearIllegalPiece = true;
		}
		if(nearSameColorAndShape(color, shape, xPos, yPos, "up") == true)
		{
			nearIllegalPiece = true;
		}
	}
	if(board->getTile(xPos, yPos + 1) != nullptr)
	{
		if(nearSameColorOrShape(color, shape, xPos, yPos, xPos, yPos + 1) == false)
		{
			nearIllegalPiece = true;
		}
		if(nearSameColorAndShape(color, shape, xPos, yPos, "right") == true)
		{
			nearIllegalPiece = true;
		}
	}
	if(board->getTile(xPos, yPos - 1) != nullptr)
	{
		if(nearSameColorOrShape(color, shape, xPos, yPos, xPos, yPos - 1) == false)
		{
			nearIllegalPiece = true;
		}
		if(nearSameColorAndShape(color, shape, xPos, yPos, "left") == true)
		{
			nearIllegalPiece = true;
		}
	}

	if(nearIllegalPiece == false)
	{
		//Checks to see it must be placed near a piece
		if(board->getTile(xPos + 1, yPos) == nullptr &&
		   board->getTile(xPos - 1, yPos) == nullptr &&
		   board->getTile(xPos, yPos + 1) == nullptr &&
		   board->getTile(xPos, yPos - 1) == nullptr && 
		   board->getTilesPlaced() > 0)
		{
			validated = false;
		}
		else
		{
			validated = true;
		}
	}

	return validated;
}

/*
This method validates the board input by checking:
1. in a loop, check the sides tiles and ensure they match the same color OR shape
*/
bool GameEngine::nearSameColorOrShape(char color, int shape, int xPos, int yPos, int newX, int newY)
{
	bool validated = false;

	int down = 0;
	int up = 0;
	int left = 0;
	int right = 0;

	if(newX == xPos + 1)
	{
		down++;
	}
	else if(newX == xPos - 1)
	{
		up--;
	}
	else if(newY == yPos + 1)
	{
		right++;
	}
	else if(newY == yPos - 1)
	{
		left--;
	}

	int checkXPos = xPos + up + down;
	int checkSecondX = xPos + (up + up) + (down + down);
	int checkYPos = yPos + left + right;
	int checkSecondY = yPos + (left + left) + (right + right);

	if(board->getTile(checkXPos, checkYPos)->getColor() == color)
	{
		if(board->getTile(checkSecondX, checkSecondY) == nullptr || 
		   board->getTile(checkSecondX, checkSecondY)->getColor() == color)
		{
			validated = true;
		}
	}
	else if(board->getTile(checkXPos, checkYPos)->getShape() == shape)
	{
		if(board->getTile(checkSecondX, checkSecondY) == nullptr || 
		   board->getTile(checkSecondX, checkSecondY)->getShape() == shape)
		{
			validated = true;
		}
	}

	return validated;
}

/*
This method validates the board input by checking:
1. in a loop, check the sides tiles and return true if a tile on the side matchs the same color AND shape
*/
bool GameEngine::nearSameColorAndShape(char color, int shape, int xPos, int yPos, string side)
{
	bool isNearSameColorAndShape = false;
	int check = 1;

	if(side.compare("down") == 0)
	{
		while(board->getTile(xPos + check, yPos) != nullptr)
		{
			if(board->getTile(xPos + check, yPos)->getColor() == color &&
			   board->getTile(xPos + check, yPos)->getShape() == shape)
			{
				isNearSameColorAndShape = true;
			}
			check++;
		}
	}
	else if(side.compare("up") == 0)
	{
		while(board->getTile(xPos - check, yPos) != nullptr)
		{
			if(board->getTile(xPos - check, yPos)->getColor() == color &&
			   board->getTile(xPos - check, yPos)->getShape() == shape)
			{
				isNearSameColorAndShape = true;
			}
			check++;
		}
	}
	else if(side.compare("left") == 0)
	{
		while(board->getTile(xPos, yPos - check) != nullptr)
		{
			if(board->getTile(xPos, yPos - check)->getColor() == color &&
			   board->getTile(xPos, yPos - check)->getShape() == shape)
			{
				isNearSameColorAndShape = true;
			}
			check++;
		}
	}
	else if(side.compare("right") == 0)
	{
		while(board->getTile(xPos, yPos + check) != nullptr)
		{
			if(board->getTile(xPos, yPos + check)->getColor() == color &&
			   board->getTile(xPos, yPos + check)->getShape() == shape)
			{
				isNearSameColorAndShape = true;
			}
			check++;
		}
	}

	return isNearSameColorAndShape;
}

/*
This method validates the input of saving a game by checking:
1. If the first word is EQUAL to "save"
2. if there is a space after save
3. if there are more characters after the space
*/
bool GameEngine::checkSaveGame(string input)
{
	bool save = false;

	if(input.substr(0, 4).compare("save") == 0)
	{
		if(input.substr(4, 1).compare(" ") == 0 && spaceCount(input) == 1)
		{
			if(input.length() > 5)
			{
				save = true;
			}
		}
	}

	return save;
}

/*
This saves the game by:
1. creating a file by the file name inputted and adding .txt extension
2. opens the file and adds each piece of data required as per assignment specification.
*/
void GameEngine::saveGame(string input)
{
	string fileName = input.substr((input.find_first_of(" ") + 1), input.length());

	fileName = fileName + ".txt";

	std::ofstream outFile;
	outFile.open(fileName);

	outFile << players[0]->getName() << std::endl;
	outFile << players[0]->getScore() << std::endl;
	outFile << players[0]->getPlayerHandString() << std::endl;
	outFile << players[1]->getName() << std::endl;
	outFile << players[1]->getScore() << std::endl;
	outFile << players[1]->getPlayerHandString() << std::endl;

	outFile << board->toString() << std::endl;

	outFile << " " << std::endl;

	outFile << tileBag->toString() << std::endl;

	if(player1Turn == true)
	{
		outFile << players[0]->getName() << std::endl;
	}
	else if(player1Turn == false)
	{
		outFile << players[1]->getName() << std::endl;
	}

	outFile.close();
}

/*
This loads the game by:
1. opening the file name after its validated it exists in the qwirkle.cpp main menu class
2. getting each piece of information and storing it in required instance variables for the game.
3. loading the boards x size and y size
4. loading the boards tiles
5. loading the tile bag and player hands from string
*/
void GameEngine::loadGame(string fileName)
{
	string file = fileName + ".txt";

	std::ifstream inFile;
	
	inFile.open(file);

	string player1Name;
	std::getline(inFile, player1Name);

	string player1ScoreStr;
	std::getline(inFile, player1ScoreStr);
	int player1Score = stoi(player1ScoreStr);

	string player1Hand;
	std::getline(inFile, player1Hand);

	string player2Name;
	std::getline(inFile, player2Name);
	
	if(player2Name.compare("AI") == 0)
	{
		AIGame = true;
	}

	string player2ScoreStr;
	std::getline(inFile, player2ScoreStr);
	int player2Score = stoi(player2ScoreStr);

	string player2Hand;
	std::getline(inFile, player2Hand);


	string boardString;
	std::getline(inFile, boardString);
	boardString = boardString + "\n";
	
	int ySize = 0;
	int xSize = 0;
	
	//loop to claculate how many columns there are
	for(unsigned int i = 0; i < boardString.length(); i++)
	{
		if(boardString[i] != 32 && boardString[i - 1] == 32)
		{
			ySize++;
		}
	}

	bool endBoard = false;
	
	//loop to calculate how many rows there are
	while(endBoard == false)
	{
		string tempString;
		std::getline(inFile, tempString);
		
		if(tempString.compare(" ") == 0)
		{
			endBoard = true;
			xSize--;
		}
		else
		{
			boardString = boardString + tempString + "\n";
			xSize++;
		}
	}

	board = new Board(xSize, ySize); //create an empty board with the calculated rows and columns
	loadBoardTiles(boardString, xSize); //loads the board tiles
	
	string tileBagString;
	std::getline(inFile, tileBagString);

	tileBag = new TileBag(tileBagString); //creates the tile bag with the tilebag string

	players[0] = new Player(player1Name, player1Score, player1Hand); //creates the first player with the loaded information

	players[1] = new Player(player2Name, player2Score, player2Hand); //creates the second player with the loaded information

	inFile.close();
}

/*
This loads the game by:
1. getting the boards string and
2. in a loop, while we have more rows to loop through the board string
3. within the boundries of each '|' in the strings
4. IF the boundries does not equal to '  '
5. Get the characters inside the boundry.
6. Add the tile to the appropriate x position and y position calculated by the loop
*/
void GameEngine::loadBoardTiles(string boardString, int xSize)
{
	std::istringstream iss(boardString);

	string line;
	std::getline(iss, line);
	std::getline(iss, line);

	unsigned int iterator = 0;
	int xPos = -1;
	int yPos = -1;
	
	for(int i = 0; i < xSize; i++)
	{
		std::getline(iss, line);
		xPos++;
		yPos = -1;
		iterator = 0;

		while(iterator < line.length() - 3)
		{
			int tileBoundry = line.find('|', iterator);
			yPos++;
			iterator = tileBoundry + 1;

			if(line.substr((tileBoundry + 1), 2).compare("  ") != 0)
			{
				string tile = line.substr((tileBoundry + 1), 2);
				char color = tile[0];
				int shape = stoi(tile.substr(1, 1));

				board->placeTile(color, shape, xPos, yPos);
			}
		}
	}
}

/* INSTANCE VARIABLES / FIELDS
Board board;
TileBag tileBag;
Player players[2];
bool player1Turn = true;
bool endGame = false;
*/

/* startGame(Renderer render) pseudocode implementation:
bool saveGame = false;
WHILE(endGame == false && render.getQuit() == false)
	renderGame();
	IF(qwirkle == true)
		render.quirkle();
		quirkle = false;
	ENDIF
	
	bool validation = false;
	
	WHILE(validation == false && render.getQuit() == false)
		string input = render.getInput();
		bool saveGame = checkSaveGame(input);
		validation = validation(input);
		
		IF(validation == false && saveGame == false)
			renderGame();
			render.validationError();
		ENDIF
		
		IF(saveGame == true)
			saveGame(input);
		ENDIF
		
	ENDWHILE
	
	string inputType = //FIRST WORD OF THE input STRING (will be either "place" or "replace")
	
	IF(inputType EQUALS "replace" && render.getQuit() == false)
		replace(input);
		player1Turn = !player1Turn;
	ELSE IF(inputType EQUALS "place" && render.getQuit() == false)
		place(input);
		player1Turn = !player1Turn;
		endGame = endGameChecker();
	ENDIF
ENDWHILE
*/

/* renderGame() method pseudocode
	render.clearConsole();
	render.playerTurn(player1Turn, players[0].getName(), players[1].getName());
	render.playerScore(players[0]);
	render.playerScore(players[1]);
	render.board(board);
	render.playerHand(player1Turn, players[0], players[1]);
*/

/* validation(string input) method pseudocode
bool validatedMove = false;
string inputType = "";
bool validatedInput = inputValidation(input);
IF(validatedInput == true)
	inputType = //THE FIRST WORD OF THE STRING input (will either be "place" or "replace")
ENDIF
bool validatedPlayerHand = playerHandValidation(inputType, input);
bool validatedBoardPos = boardPosValidation(input);
IF(validatedInput == true && validatedPlayerHand == true)
	validatedMove = true;
ENDIF
ELSE IF(validatedInput == true && validatedPlayerHand == true && validatedBoardPos == true)
	validatedMove = true;
ENDELSEIF
return validatedMove;
*/

/* replace(string input) method pseudocode
char color = //Second word FIRST LETTER of string input
int shape = //Second word SECOND LETTER of string input converted to int
IF(player1Turn == true)
	players[0].replaceTile(color, shape, tileBag);
ELSE IF(player1Turn == false)
	players[1].replaceTile(color, shape, tileBag);
ENDIF
*/

/* place(string input) method pseudocode
char color = //Second word FIRST LETTER of string input
int shape = //Second word SECOND LETTER of string input converted to int
int xPos = //FOURTH word of string input, FIRST LETTER converted to int (i.e. input = "place G5 at C4" = C4 = C = 2)
int yPos = //FOURTH word of string input, SECOND LETTER converted to int (i.e. input = "place G5 at C4" = C4 = 4 = 4)
board.placeTile(color, shape, xPos, yPos);
IF(player1Turn == true)
	players[0].deleteTileHand(color, shape);
	players[0].drawTile(tileBag);
ELSEIF(player1Turn == false)
	players[1].deleteTileHand(color, shape);
	players[1].drawTile(tileBag);
ENDIF
calculatePointsScored(color, shape, xPos, yPos);
*/

/* calculatePointsScored(char color, int shape, int xPos, int yPos) method pseudocode
int pointsScored = 0;
pointsScored = pointsScored + pointsScored(xPos, yPos, "up");
pointsScored = pointsScored + pointsScored(xPos, yPos, "left");
pointsScored = pointsScored + pointsScored(xPos, yPos, "right");
IF(board.getTile(xPos + 1, yPos) != null)
	pointsScored = pointsScored + pointsScored(xPos, yPos, "down");
ENDIF
IF(board.getTile(xPos - 1, yPos) != null)
	pointsScored = pointsScored + pointsScored(xPos, yPos, "up");
ENDIF
IF(board.getTile(xPos, yPos + 1) != null)
	pointsScored = pointsScored + pointsScored(xPos, yPos, "right");
ENDIF
IF(board.getTile(xPos, yPos - 1) != null)
	pointsScored = pointsScored + pointsScored(xPos, yPos, "left");
ENDIF
IF(player1Turn == true)
	players[0].setScore(players[0].getScore() + pointsScored);
ELSEIF(player1Turn == false)
	players[1].setScore(players[1].getScore() + pointsScored);
ENDIF
*/

/* pointsScored(int xPos, int yPos, string side) method pseudocode
int pointsScored = 0;
pointsScored++;
int qwirkleCheck = 1;
int newX = xPos;
int newY = yPos;
IF(side EQUALS down)
	newX = xPos + qwirkleCheck;
ELSEIF(side EQUALS up)
	newX = xPos - qwirkleCheck;
ELSEIF(side EQUALS left)
	newY = yPos - qwirkleCheck;
ELSEIF(side EQUALS right)
	newY = yPos + qwirkleCheck;
ENDIF
while(board.getTile(newX, newY) != null)
	pointsScored++;
	qwirkleCheck++;
	
	IF(side EQUALS down)
		newX = xPos + qwirkleCheck;
	ELSEIF(side EQUALS up)
		newX = xPos - qwirkleCheck;
	ELSEIF(side EQUALS left)
		newY = yPos - qwirkleCheck;
	ELSEIF(side EQUALS right)
		newY = yPos + qwirkleCheck;
	ENDIF
ENDWHILE
IF(qwirkleCheck == 6)
{
	pointsScored = pointsScored + 6;
	qwirkle = true;
}
return pointsScored;
*/

/* endGameChecker() method pseudocode
bool endGame = false;
IF(tileBag.getSize() == 0)
	IF(players[0].getPlayerHand().getSize() == 0)
		endGame = true;
	ELSEIF(players[1].getPlayerHand().getSize() == 0)
		endGame = true;
	ENDIF
ENDIF
return endGame;
*/

/* inputValidation(string input) method pseudocode 
bool validated = false;
const int placeCommandLength = 14;
const int replaceCommandLength = 10;
IF(input LENGTH EQUALS placeCommandLength && input has 3 spaces)
	IF(first word EQUALS "place")
		IF(third word EQUALS "at")
			validated = true;
		ENDIF
	ENDIF
ELSE IF(input LENGTH EQUALS replaceCommandLength && input has 1 space)
	IF(first word EQUALS "replace")
		validated = true;
	ENDIF
ENDIF
return validated;
*/

/* playerHandValidation(string inputType, string input) method pseudocode
bool validated = false
IF(input second word FIRST LETTER EQUALS RED OR ORANGE OR YELLOW OR GREEN OR BLUE OR PURPLE)
	IF(input second word SECOND LETTER CONVERTED TO INT EQUALS CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6 OR CLOVER)
		IF(player1Turn == true && players[0].checkIfTileInHand(second word FIRST CHAR, second word SECOND LETTER CONVERTED TO INT) == true)
			validated = true;
		ELSE IF(player1Turn == false && players[1].checkIfTileInHand(second word FIRST CHAR, second word SECOND LETTER CONVERTED TO INT) == true)
			validated = true;
		ENDIF
	ENDIF
ENDIF
IF(inputType EQUALS "replace" && tileBag.getSize() == 0)
	validated = false;
ENDIF
return validated;
*/

/* boardPosValidation(string input) method pseudocode
bool validated = false;
bool isWithinBoardSize = false;
bool isPlacingOnEmptyTile = false;
bool isValidPlacing = false;
int xPos = //FOURTH word of string input, FIRST LETTER converted to int (i.e. input = "place G5 at C4" = C4 = C = 2)
int yPos = //FOURTH word of string input, SECOND LETTER converted to int (i.e. input = "place G5 at C4" = C4 = 4 = 4)
isWithinBoardSize = withinBoardSize(xPos, yPos);
IF(isWithinBoardSize == true)
	isPlacingOnEmptyTile = placingOnEmptyTile(xPos, yPos);
ENDIF
IF(isWithinBoardSize == true && isPlacingOnEmptyTile == true)
	isValidPlacing = validPlacing(string input, xPos, yPos);
ENDIF
IF(isWithinBoardSize == true && isPlacingOnEmptyTile == true && isValidPlacing == true)
	validated = true;
ENDIF
return validated;
*/

/* withinBoardSize(int xPos, int yPos) method pseudocode
bool validated = false;
IF(xPos < board.getXSize() && xPos >= 0)
	IF(yPos < board.getYSize() && yPos >= 0)
		validated = true;
	ENDIF
ENDIF
return validated
*/

/* placingOnEmptyTile(int xPos, int yPos) method pseudocode
bool validated = false;
IF(board.isEmptyTile(xPos, yPos) == true)
	validated = true;
ENDIF
return validated
*/

/* validPlacing(string input, int xPos, int yPos) method pseudocode
bool validated = false;
char color = //Second word FIRST LETTER of string input
int shape = //Second word SECOND LETTER of string input converted to int
bool nearIllegalPiece = false;
IF(board.getTilesPlaced() == 0)
	validated == true;
ENDIF
IF(board.getTile(xPos + 1, yPos) != null)
	IF(nearSameColorOrShape(color, shape, xPos, yPos, xPos + 1, yPos) == false)
		nearIllegalPiece = true;
	ENDIF
ENDIF
IF(board.getTile(xPos - 1, yPos) != null)
	IF(nearSameColorOrShape(color, shape, xPos, yPos, xPos - 1, yPos) == false)
		nearIllegalPiece = true;
	ENDIF
ENDIF
	
IF(board.getTile(xPos, yPos + 1) != null)
	IF(nearSameColorOrShape(color, shape, xPos, yPos, xPos, yPos + 1) == false)
		nearIllegalPiece = true;
	ENDIF
ENDIF
	
IF(board.getTile(xPos, yPos - 1) != null)
	IF(nearSameColorOrShape(color, shape, xPos, yPos, xPos, yPos - 1) == false)
		nearIllegalPiece = true;
	ENDIF
ENDIF
IF(nearIllegalPiece == false)
	validated = true;
ENDIF
return validated;
*/

/* nearSameColorOrShape(char color, int shape, int xPos, int yPos, int newX, int newY) method pseudocode
bool validated = false;
int down = 0;
int up = 0;
int left = 0;
int right = 0;
IF(newX == xPos + 1)
	down++;
ELSEIF(newX == xPos - 1)
	down--;
ELSEIF(newY == yPos + 1)
	right++;
ELSEIF(newY == yPos - 1)
	left++;
ENDIF
int checkXPos = xPos + up + down;
int checkSecondX = xPos + (up + up) + (down + down);
int checkYPos = yPos + left + right;
int checkSecondY = yPos + (left + left) + (right + right);
IF(board.getTile(checkXPos, checkYPos).getColor() == color)
	IF(board.getTile(checkSecondX, checkSecondY) == null || board.getTile(checkSecondX, checkSecondY).getColor() == color)
		validated = true;
	ENDIF
ELSEIF(board.getTile(checkXPos, checkYPos).getShape() == shape)
	IF(board.getTile(checkSecondX, checkSecondY) == null || board.getTile(checkSecondX, checkSecondY).getShape() == shape)
		validated = true;
	ENDIF
ENDIF
return validated
*/

/* checkSaveGame(string input) method pseudocode
bool save = false;
IF first word of input EQUALS "save"
	IF(THERE IS A SPACE after "save")
		IF(input.length > 5)
			save = true;
		ENDIF
	ENDIF
ENDIF
return save;
*/

/* saveGame(string input) method pseudocode
string fileName = SECOND word from input string
//CREATE NEW FILE WITH FILE NAME
//IN FILE, PRINT players[0].getName();
//IN FILE, PRINT players[0].getScore();
//IN FILE, PRINT players[0].getPlayerHandString();
//IN FILE, PRINT players[1].getName();
//IN FILE, PRINT players[1].getScore();
//IN FILE, PRINT players[1].getPlayerHandString();
//IN FILE, PRINT whole board maybe use render.board() if possible?
//IN FILE, PRINT tileBag.toString();
IF(player1Turn == true)
	//IN FILE, PRINT players[0].getName();
ELSE IF (player1Turn == false)
	//IN FILE, PRINT players[1].getName();
*/

/* loadGame(string fileName) method pseudocode
//OPEN FILE
//FIRST LINE string user1 = players[0].setName(user1);
//SECOND LINE string score1 CONVERT TO INT = players[0].setScore(score1);
//THIRD LINE string hand1 = players[0].setHand(hand1);
//FOURTH LINE string user2 = players[1].setName(user2);
//FIFTH LINE string score2 CONVERT TO INT = players[1].setScore(score2);
//SIXTH LINE string hand2 = players[1].setHand(hand2);
//SEVENTH LINE IS THE BOARD WHICH IS COMPLEX WORK IN PROGRESS
*/