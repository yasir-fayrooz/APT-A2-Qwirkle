#include Renderer.h

#include <iostream>

//MISC METHODS

void Renderer::clearConsole()
{
	
}

String Renderer::getInput()
{
	return "";
}

bool Renderer::getQuit()
{
	return quit;
}

//MAIN MENU METHODS

void Renderer::mainMenu()
{
	
}

void Renderer::playerName(string player)
{
	
}

void Renderer::loadGame()
{
	
}

void Renderer::showStudentInfo()
{
	
}

//GameEngine METHODS

void Renderer::playerTurn(bool player1Turn, string player1Name, string player2Name)
{
	
}

void Renderer::playerScore(Player player)
{
	
}

void Renderer::board(Board board)
{
	//this will be a bit difficult to render but not too difficult.
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