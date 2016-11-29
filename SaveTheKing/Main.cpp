#include "Controller.h"
#include <iostream>

int main()
{
	string path = "level.txt";
	string levelTerminator = "$$$";

	Controller gameController(path, levelTerminator);

	if (gameController.isFileOpen())
		gameController.startGame();
	else
	{
		std::cout << "Couldn't find or open the file " << path << std::endl;
		std::cout << "Press any key to continue..." << std::endl;

		_getch();
	}

	return 0;
}