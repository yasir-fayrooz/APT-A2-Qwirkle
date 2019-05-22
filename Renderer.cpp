#include "Renderer.h"

#include <iostream>

#ifdef _WIN32
    #include <windows.h>

    void Renderer::sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    void Renderer::sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif

void Renderer::clearConsole()
{
	system("clear");
}

string Renderer::getInput()
{
	string input;
	std::cout << "> ";
	std::getline(std::cin, input);
	if (input.compare("quit") == 0)
	{
		quit = true;
	}
	return input;
}

bool Renderer::getQuit()
{
	return quit;
}

//MAIN MENU METHODS

void Renderer::mainMenu()
{
	quit = false;
	std::cout << "--------------------------------\n";
    std::cout << "|      Welcome to Qwirkle!     |" << "\n--------------------------------\n";
	std::cout << "|             Menu             |";
	std::cout << "\n--------------------------------\n";
	std::cout << "|       1. 2 Player Game       |\n";
	std::cout << "|      2. You VS AI (CPU)      |\n";
	std::cout << "|         3. Load Game         |\n";	
	std::cout << "| 4. Show student information  |\n";
	std::cout << "|           5. Quit            |\n";
	std::cout << "--------------------------------\n";
}

void Renderer::playerName(string player)
{
	std::cout << "Enter a name for " << player << "(or 'quit')\n";
	std::cout << "Requirements: must be all capital letters only minimum length of 3\n";
}

void Renderer::loadGame()
{
	std::cout << "Enter the filename from which load a game (or 'quit')\n";
}

void Renderer::showStudentInfo()
{
	std::cout << "----------------------------------\n";
	std::cout << "Name: Yasir Fayrooz Ali\n";
	std::cout << "Student ID: s3742162\n";
	std::cout << "Email: s3742162@student.rmit.edu.au\n";
	std::cout << "\n";
	std::cout << "Name: Raphael McCarthy\n";
	std::cout << "Student ID: s3544758\n";
	std::cout << "Email: s3544758@student.rmit.edu.au\n";
	std::cout << "\n";
	std::cout << "Name: Jeremy Richards\n";
	std::cout << "Student ID: s3721762\n";
	std::cout << "Email: s3721762@student.rmit.edu.au\n";
	std::cout << "\n";
	std::cout << "Name: Ido Yaron\n";
	std::cout << "Student ID: s3708691\n";
	std::cout << "Email: s3708691@student.rmit.edu.au\n";
	std::cout << "----------------------------------\n";
}

//GameEngine METHODS

void Renderer::playerTurn(bool player1Turn, string player1Name, string player2Name)
{
	if (player1Turn == true)
	{
		std::cout << player1Name << " it's your turn\n";
	}
	else
	{
		std::cout << player2Name << " it's your turn\n";
	}
}

void Renderer::playerScore(Player* player)
{
	std::cout << "Score for " << player->getName() << ": " << player->getScore() << "\n";
}

void Renderer::tileBagCount(TileBag* tileBag)
{
	std::cout << "Tile Bag count: " << tileBag->getSize() << std::endl;
}

void Renderer::board(Board* board)
{
	std::cout << board->toString() << std::endl;
}

void Renderer::playerHand(bool player1Turn, Player* player1, Player* player2)
{
	std::cout << "Your hand is: " << std::endl;
	if (player1Turn == true)
	{
		std::cout << player1->getPlayerHandString() << "\n";
	}
	else
	{
		std::cout << player2->getPlayerHandString() << "\n";
	}
	
	std::cout << "" << std::endl;
}

void Renderer::saveGame()
{
	std::cout << "Game saved successfully..\n";
}

void Renderer::inputValidationError()
{
	std::cout << "Input error! Ensure these conditions are met:\n";
	std::cout << "1. Case sensitive command: 'place [tile] at [position]' or 'replace [tile]'\n";
	std::cout << "2. The game follows standard qwirkle rules\n";
	std::cout << "3. The tile is in your hand and there are enough tiles in bag to replace\n";
	std::cout << "4. Alternatively, you can save the game using the 'save [filename]' or quit using the 'quit' command\n";
}

void Renderer::qwirkle()
{
	std::cout << "QWIRKLE!!" << std::endl;
}

void Renderer::renderMenuError()
{
	std::cout << "Error: please select a valid option (1-5)" << std::endl;
}

void Renderer::gameOver(Player* player1, Player* player2)
{
	std::cout << "Game Over" << std::endl;
	std::cout << "Score for " << player1->getName() << ":" << player1->getScore() << std::endl;
	std::cout << "Score for " << player2->getName() << ":" << player2->getScore() << std::endl;
	
	if(player1->getScore() > player2->getScore())
	{
		std::cout << "Player " << player1->getName() << " won!" << std::endl;
	}
	else if(player2->getScore() > player1->getScore())
	{
		std::cout << "Player " << player2->getName() << " won!" << std::endl;
	}
	else
	{
		std::cout << "The Game is a draw!" << std::endl;
	}
	
	std::cout << "\nGoodbye" << std::endl;
}

void Renderer::AIInput(string input)
{
	std::cout << "> " << std::flush;
	for(unsigned int i = 0; i < input.length(); i++)
	{
		std::cout << input[i] << std::flush;
		sleep(200);
	}
	sleep(300);
	std::cout << "\n";
}

/* INSTANCE VARIABLES / FIELDS

boolean quit = false;

*/

/* clearConsole() method pseudocode

	Manually implement how to clear a console

*/

/* mainMenu() method pseudocode

	std::cout all the main menu as per assignment spec

*/

/* playerName(String player) method pseudocode

	the passed in string from the qwirkle.cpp class will be either "Player 1" or "Player 2"
	
	std::cout ("Enter a name for " + player);

*/

/* loadGame() method pseudocode

	std::cout "Enter the filename from which load a game";

*/

/* showStudentInfo() method pseudocode

	std::cout all of our student info...

*/

/* getInput() method pseudocode

	std::cout "> "; 
	//as per assignment spec
	
	then store the std::in as a local method string variable named input.
	
	check IF the input string is EQUAL to "quit", then set renderer's quit boolean to true;
	
	return input;

*/

/* playerTurn(bool player1Turn, string player1Name, string player2Name) method pseudocode

	check IF player1Turn == true
	std::cout player1Name + ", it's your turn" std::endl;
	ELSE
		std::cout player2Name + ", it's your turn" std::endl;

*/

/* playerScore(Player player) method pseudocode

	std::cout "Score for " + player.getName() + ": " + player.getScore() std::endl;

*/

/* board(Board board) method pseudocode

	//i will implement a pseudocode later as it is a bit lengthy

*/

/* playerHand(bool player1Turn, Player player1, Player player2) method pseudocode
	std::cout "Your hands is" std::endl;
	
	check IF player1Turn == true
	std::cout player1.getPlayerHandString() std::endl;
	ELSE
	std::cout player2.getPlayerHandString() std::endl;
*/
