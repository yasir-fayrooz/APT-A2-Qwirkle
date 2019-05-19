#include "GameEngine.h"
#include "Renderer.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

using std::string;

#define EXIT_SUCCESS    0

// Functions
void newGame(Renderer* render);
void loadGame(Renderer* render);
void showStudentInfo(Renderer* render);
bool quit();
bool playerValidation(string name);
bool fileValidation(string fileName);

int main(void) {

  Renderer* render = new Renderer(); // instance
  bool quitGame = false;
  bool renderMenuError = false;

  while(quitGame == false)
  {
    render->clearConsole();
    render->mainMenu();
	
	if(renderMenuError == true)
	{
		render->renderMenuError();
		renderMenuError = false;
	}

    //This method will render the main menu

    string input = render->getInput();
    //This method will get input and return the string.
    if (input.compare("1") == 0)
    {
      newGame(render);
    }
    else if (input.compare("2") == 0)
    {
      loadGame(render);
    }
    else if (input.compare("3") == 0)
    {
      showStudentInfo(render);
    }
    else if (input.compare("4") == 0)
    {
      quitGame = quit();
    }
    else
    {
      renderMenuError = true;
    }
  }
  
  delete render;
  return EXIT_SUCCESS;
}

void newGame(Renderer* render)
{
	render->clearConsole();
	string player1 = "";
	string player2 = "";

	while (playerValidation(player1) == false && render->getQuit() == false)
	{
		render->playerName("Player 1"); //This will render player 1 to enter his name
		player1 = render->getInput();
	}

	while (playerValidation(player2) == false && render->getQuit() == false)
	{
		render->playerName("Player 2"); //This will render player 2 to enter his name
		player2 = render->getInput();
	}

	if(render->getQuit() == false)
	{
		GameEngine* gameEngine = new GameEngine(player1, player2);
		gameEngine->startGame(render);
		delete gameEngine;
	}
}

//validates player name to specification after getting input...
bool playerValidation(string name){
	bool isValid = true;
  
	if(name.length() < 2)
	{
	  isValid = false;
	}
  
	for(unsigned int i=0; i < name.size(); i++){
		if(name[i] < 65  || name[i] > 90){
		  isValid = false;
		}
  }
  return isValid;
}

void loadGame(Renderer* render)
{
  render->clearConsole();
  string fileName = "";

  while(fileValidation(fileName) == false && render->getQuit() == false)
  {
    render->loadGame();
    //This will render line to enter file name to load
    fileName = render->getInput();
  }

  if(render->getQuit() == false)
  {
    GameEngine* gameEngine = new GameEngine(fileName);
    gameEngine->startGame(render);
	delete gameEngine;
  }
}

void showStudentInfo(Renderer* render)
{
  render->clearConsole();
  // clear console

  render->showStudentInfo();
  //print names and info

  string input = render->getInput();
  // return to main menu
}

//checks if relative file path name exists
bool fileValidation(string fileName)
{
  bool isExist = true;
  string file = fileName + ".txt";
  std::ifstream input(file);
  if(input.fail()){
    isExist = false;
  }
  return isExist;
}

bool quit()
{
	return true;
}


/* INSTANCE VARIABLES / FIELDS
Renderer render = new Renderer() instance
private boolean quitGame = false;
*/

/* main() method implementation pseudo code:

WHILE (quitGame == false)

render->clearConsole();
render->mainMenu();

//This method will render the main menu

String input = render->getInput();
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
render->clearConsole();
String player1 = null;
String player2 = null;
WHILE (playerValidation(player1) == false && render->getQuit() == false)
render->playerName("Player 1"); //This will render player 1 to enter his name
player1 = render->getInput();
ENDWHILE
WHILE (playerValidation(player2) == false && render->getQuit() == false)
render->playerName("Player 2"); //This will render player 2 to enter his name
player2 = render->getInput();
ENDWHILE
IF(render->getQuit() == false)
GameEngine gameEngine = new GameEngine(player1, player2);
gameEngine.startGame(render);
ENDIF
*/

/* loadGame() method implementation pseudo code:
render->clearConsole();
String fileName = null;
WHILE (fileValidation(fileName) == false && render->getQuit() == false)
render->loadGame();
//This will render line to enter file name to load
fileName = render->getInput();
ENDWHILE
IF(render->getQuit() == false)
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
set the quitGame bool to equal quit() which returns true.
//sets quitGame variable to true to exit out of our main loop and quit
*/
