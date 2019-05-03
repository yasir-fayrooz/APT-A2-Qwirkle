

class Renderer {
public:
	void clearConsole();
	void mainMenu();
	void playerName(String player);
	void loadGame();
	void showStudentInfo();
	
	String getInput();
	
	bool getQuit();

private:

   bool quit = false;
   
};