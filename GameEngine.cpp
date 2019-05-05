#include GameEngine.h
#include TileCodes.h

GameEngine::GameEngine(string player1name, string player2name)
{
	//creates 2 new players in the player array, initialises new things such as board etc.
}

GameEngine::GameEngine(string fileName)
{
	//loads from file and stores into instance variables in .h file
}

void GameEngine::startGame(Renderer render)
{
	//This will be our game loop
	//pseudocode done
}

void GameEngine::renderGame()
{
	//pseudocode done
}

bool GameEngine::validation(string input)
{
	//pseudocode done
	return false;
}

void GameEngine::replace(string input)
{
	//pseudocode done
}

void GameEngine::place(string input)
{
	//pseudocode done
}

void GameEngine::calculatePointsScored(char color, int shape, int xPos, int yPos)
{
	//pseudocode done
}

int GameEngine::pointsScored(int xPos, int yPos, string side)
{
	//pseudocode done
	return 0;
}

bool GameEngine::endGameChecker()
{
	//pseudocode done
	return false;
}

bool GameEngine::inputValidation(string input)
{
	//pseudocode done
	return false;
}

bool GameEngine::playerHandValidation(string inputType, string input)
{
	//pseudocode done
	return false;
}

bool GameEngine::boardPosValidation(string input)
{
	//pseudocode done
	return false;
}

bool GameEngine::withinBoardSize(int xPos, int yPos)
{
	//pseudocode done
	return false;
}

bool GameEngine::placingOnEmptyTile(int xPos, int yPos)
{
	//pseudocode done
	return false;
}

bool GameEngine::validPlacing(string input, int xPos, int yPos)
{
	//pseudocode done
	return false;
}

bool GameEngine::nearSameColorOrShape(char color, int shape, int xPos, int yPos, int newX, int newY)
{
	//pseudocode done
	return false;
}

/* INSTANCE VARIABLES / FIELDS

Board board;
TileBag tileBag;

Player players[2];
bool player1Turn = true;

bool endGame = false;

*/

/* startGame(Renderer render) pseudocode implementation:

WHILE(endGame == false && render.getQuit() == false)
	renderGame();
	
	string input = render.getInput();
	bool validation = validation(input);
	
	WHILE(validation == false && render.getQuit() == false)
		renderGame();
		render.validationError();
		input = render.getInput();
		validation = validation(input);
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