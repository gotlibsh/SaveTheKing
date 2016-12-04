#include "Controller.h"
#include "Utilities.h"
#include <iostream>

int main()
{
	string levelsFilePath = "levels.txt";
	string levelTerminator = "$$$";
	string openingMsgPath = "opening.txt";
	string endingMsgPath = "ending.txt";

	Controller gameController(levelsFilePath, levelTerminator);

	if (gameController.isFileOpen())
	{
		printMsg(openingMsgPath);
		gameController.runGame();
		printMsg(endingMsgPath);
	}
	else
	{
		std::cout << "Couldn't find or open the file " << levelsFilePath << std::endl;
		std::cout << "Press any key to continue..." << std::endl;

		_getch();
	}

	return 0;
}