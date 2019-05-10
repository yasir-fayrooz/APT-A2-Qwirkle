#include "Renderer.h"

#include <iostream>
#include <string>
#include <stdexcept>

using std::string;

#define EXIT_SUCCESS    0

// Functions
void newGame();
void loadGame();
void showStudentInfo();
bool quit();
bool playerValidation(std::string name);
void fileValidation(std::string fileName);

int main(void) {

  Renderer* render = new Renderer(); // instance
  bool quitGame = false;

	while(bool quitGame = false)
	{
	render->clearConsole();
	render->mainMenu();
	
				
				//This method will render the main menu

	string input = render->getInput();
					//This method will get input and return the string.
    	if (input.compare("1"))
    	{
    		newGame();
    	}
    	else if (input.compare("2"))
    	{
    		loadGame();
    	}
    	else if (input.compare("3"))
    	{
    		showStudentInfo();
    	}
    	else if (input.compare("4"))
    	{
    		quit();
    	}
    	else
    	{
    		throw std::runtime_error("Not valid Entry");
    	}

    std::cout << "Welcome to Qwirkle!" << "\n" << "-------------------" << "\n";
  }
   return EXIT_SUCCESS;
}

void newGame(Renderer* render, GameEngine* gameEngine)
{
    render->clearConsole();
    string player1 = 0;
    string player2 = 0;
    
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
    	gameEngine = new GameEngine(player1, player2);
    	gameEngine->startGame(render);
    }
}

bool playerValidation(std::string name)
{
	//validates player name to specification after getting input...
	return false;
}

void loadGame(Renderer* render, GameEngine* gameEngine)
{
   render->clearConsole();
   String fileName = 0;
    
   while(fileValidation(fileName) == false && render->getQuit() == false)
   {
     render->loadGame();
			//This will render line to enter file name to load
     fileName = render->getInput();
   }
    
   if(render->getQuit() == false)
   {
     gameEngine = new GameEngine(fileName);
     gameEngine.startGame(render);
   }
}

void showStudentInfo(Renderer* render)
{
  render->clearConsole(); 
  // clear console
  
  std::cout << "------------------------------" << "\n";
  std::cout << "Name: Raph McCarthy" << "\n" << "Student ID: s3544758" << "\n" << "Email: s3544758@student.rmit.edu.au" << "\n \n";
  std::cout << "Name: Yasir Fayrooz Ali" << "\n" << "Student ID: s3742162" << "\n" << "Email: s3742162@student.rmit.edu.au" << "\n \n"; 
  std::cout << "Name: Jeremy Richards" << "\n" << "Student ID: s3721762" << "\n" << "Email: s3721762@student.rmit.edu.au" << "\n \n"; 
  std::cout << "Name: Ido Yaron" << "\n" << "Student ID: s3708691" << "\n" << "Email: s3708691@student.rmit.edu.au" << "\n";
  std::cout << "------------------------------" << "\n";
  //print names and info
  
  string input = render->getInput();
    	while(!input.compare(""))
    	{
    	    main();
    	}
    	// return to main menu
}

void fileValidation(std::string fileName)
{
	//checks if relative file path name exists
	return false;
}

bool quit()
{
	bool quitGame = true;
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