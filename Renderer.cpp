#include "Renderer.h"

#include <iostream>
#include <stdlib.h>

void Renderer::clearConsole()
{
	system("cls");
}

String Renderer::getInput()
{
	string input;
	std::cout << "> ";
	std::cin >> input;
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
    std::cout << "Welcome to Qwirkle!" << "\n" << "-------------------" << "\n";
	std::cout << "Menu\n";
	std::cout << "----\n";
	std::cout << "1. New Game\n";
	std::cout << "2. Load Game\n";	
	std::cout << "3. Show student information\n";
	std::cout << "4. Quit\n";
}

void Renderer::playerName(string player)
{
	std::cout << ("Enter a name for " + player + "\n");
}

void Renderer::loadGame()
{
	std::cout << "Enter the filename from which load a game\n";
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
		std::cout << (player1Name + " it's your turn\n");
	}
	else
	{
		std::cout << (player2Name + " it's your turn\n");
	}
}

void Renderer::playerScore(Player* player)
{
	std::cout << ("Score for " + player->getName() + ": " + player->getScore() + "\n");
}

void Renderer::board(Board* board)
{
	std::cout << board->toString() << std::endl;
	/*
	   0  1  2  3  4  5
	  -------------------
	A |  |  |  |  |  |  |
	B |  |  |B4|B6|B5|  |
	C |  |  |R4|  |G5|  |
	D |  |Y1|Y4|Y2|  |  |
	E |  |  |P4|  |  |  |
	F |  |  |  |  |  |  |
	*/

}

void Renderer::playerHand(bool player1Turn, Player* player1, Player* player2)
{
	if (player1Turn == true)
	{
		std::cout << (player1->getPlayerHandString() + "\n");
	}
	else
	{
		std::cout << (player2->getPlayerHandString() + "\n");
	}
}

void Renderer::saveGame()
{
	std::cout << "Game saved successfully..\n";
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
