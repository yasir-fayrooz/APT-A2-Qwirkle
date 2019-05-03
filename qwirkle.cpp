
#include "LinkedList.h"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "TODO: Implement Qwirkle!" << std::endl;

   return EXIT_SUCCESS;
}


/* INSTANCE VARIABLES / FIELDS

GameEngine gameEngine;
Renderer render = new Renderer() instance

private boolean quitGame = false;

*/

/* main() method implementation pseudo code:

WHILE (quitGame == false)
	
	render.clearConsole();
	render.mainMenu();
			//This method will render the main menu

	String input = render.getInput();
					//This method will get input and return the string.

	IF input == 1
		newGame();
		//This method will be in the qwirkle class for further explanation.
	ELSE IF input == 2
		loadGame();
		//This method will be in the qwirkle class for further explanation.
	ELSE IF input == 3
		showStudentInfo();
		//This method will be in the qwirkle class for further explanation.
	ELSE IF input == 4
		quit();
		//This method will be in the qwirkle class for further explanation.
	ELSE
		print error blah blah...
	
ENDWHILE

*/

/* newGame() method implementation pseudo code:

render.clearConsole();

String player1 = null;
String player2 = null;

WHILE (playerValidation(player1) == false && render.getQuit == false)
	render.playerName("Player 1"); //This will render player 1 to enter his name
	player1 = render.getInput(); 
ENDWHILE

WHILE (playerValidation(player2) == false && render.getQuit == false)
	render.playerName("Player 2"); //This will render player 2 to enter his name
	player2 = render.getInput();
ENDWHILE

IF(render.getQuit == false)
	gameEngine = new GameEngine(player1, player2);
	gameEngine.startGame(render);
ENDIF

*/

/* loadGame() method implementation pseudo code:
render.clearConsole();

String fileName = null;

WHILE (fileValidation(fileName) == false && render.getQuit == false)
	render.loadGame();
			//This will render line to enter file name to load
	fileName = render.getInput();
ENDWHILE

IF(render.getQuit == false)
	gameEngine = new GameEngine(fileName);
	gameEngine.startGame(render);
ENDIF

*/

/* showStudentInfo() method implementation pseudo code:
	
This should be fairly straight forward to do. All you have to do
is clear the console, print out our student names and the next 
input given returns us to the main menu.

*/

/* quit() method implementation pseudo code:
	
quitGame = true;
//sets quitGame variable to true to exit out of our main loop and quit
	
*/