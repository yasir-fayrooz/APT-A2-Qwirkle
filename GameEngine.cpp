#include GameEngine.h


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
}

void GameEngine::renderGame()
{
	
}

bool GameEngine::validation(string input)
{
	
}

void GameEngine::replace(string input)
{
	
}

void GameEngine::place(string input)
{
	
}

void GameEngine::calculatePointsScored()
{
	
}

bool GameEngine::endGameChecker()
{
	return false;
}

bool GameEngine::inputValidation(string input)
{
	
}

bool GameEngine::playerHandValidation(string inputType, string input)
{
	
}

bool GameEngine::boardPosValidation(string inputType, string input)
{
	
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
	bool inputValidation = validation(input);
	
	WHILE(inputValidation == false && render.getQuit() == false)
		renderGame();
		render.inputValidationError();
		input = render.getInput();
		inputValidation = validation(input);
	ENDWHILE
	
	string inputType = //FIRST WORD OF THE input STRING (will be either "place" or "replace")
	
	IF(inputType EQUALS "replace" && render.getQuit() == false)
		replace(input);
	ELSE IF(inputType EQUALS "place" && render.getQuit() == false)
		place(input);
		calculatePointsScored();
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
bool validatedBoardPos = boardPosValidation(inputType, input);

IF(validatedInput == true && validatedPlayerHand == true)
	validatedMove = true;
ENDIF
ELSE IF(validatedInput == true && validatedPlayerHand == true && validatedBoardPos == true)
	validatedMove = true;
ENDELSEIF

return validatedMove;

*/