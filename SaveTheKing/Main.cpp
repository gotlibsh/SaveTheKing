#include "Controller.h"
#include "Utilities.h"
#include <iostream>

int main()
{
	string levelsFilePath = "levels.txt";
	string openingMsgPath = "opening.txt";
	string endingMsgPath = "ending.txt";
	string levelTerminator = "$$$";

	Controller gameController(levelsFilePath, levelTerminator);

	if (gameController.isFileOpen())
	{	//	File exits and it's open.
		printMsg(openingMsgPath);
		gameController.runGame();

		if (gameController.exitSucceed())
			printMsg(endingMsgPath);
	}
	else
	{	//	Couldn't find or open the file of the levels.
		std::cout << "Couldn't find or open the file " << levelsFilePath << std::endl;
		std::cout << "Press any key to continue..." << std::endl;

		_getch();
	}

	return 0;
}