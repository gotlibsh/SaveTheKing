#include "Utilities.h"

/*
*	Returns a vector of strings read from the given file stream.
*/
vector<string> readLevel(ifstream & file, const string & terminator)
{
	vector<string> vec;
	string line;

	while (std::getline(file, line))
	{
		if (line.compare(terminator) == 0)
			break;

		vec.push_back(line);
	}

	return vec;
}

/*
*	Returns the user's input key.
*/
KeyPress keyboardKey()
{
	while (!_kbhit())       // Wait for a key to be pressed.
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	int key = _getch();
	switch (key)
	{
	case 0:
	case SPECIAL_KEY:
	{
		key = _getch();

		switch (key)
		{
		case KB_UP:
			return UP;
		case KB_DOWN:
			return DOWN;
		case KB_LEFT:
			return LEFT;
		case KB_RIGHT:
			return RIGHT;
		default:
			return OTHER;
		}
	}
	break;
	case KB_P:
	case KB_p:
		return CHANGE_CHAR;
	case KB_SPACE:
		return SPACE;
	case KB_ESCAPE:
		return ESCAPE;
	default:
		return OTHER;
	}
}

/*
*	Returns a random direction for midgets up,down,left,right
*/
KeyPress randomDirection()
{
	return KeyPress(rand() % 4);
}
