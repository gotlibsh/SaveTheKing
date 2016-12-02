#include "Controller.h"
#include <iostream>
#include <Windows.h>

//+---------------------------------------------------------+
//|						Constructors						|
//+---------------------------------------------------------+

/*
*	Assigns the variables of the controller.
*/
Controller::Controller(string levelFilePath, string terminator)
	: m_terminator(terminator), m_sumOfSteps(0), m_activeChar(P_KING)
{
	srand((unsigned)time(NULL));	// Resets for random midgets moves.
	m_file.open(levelFilePath);
}

/*
*	Closes the ifstream m_file when the controller is out of use.
*/
Controller::~Controller()
{
	if (m_file.is_open())
		m_file.close();
}

//+---------------------------------------------------------+
//|					Public Member Functions					|
//+---------------------------------------------------------+

/*
*	Runs the whole game until the user ends all levels, or until the escape key is pressed.
*/
void Controller::runGame()
{
	KeyPress key = OTHER;

	while (!m_file.eof())
	{
		setNewLevel();
		printScreen();

		key = keyboardKey();

		do
		{
			switch (key)
			{
			case UP:
			case DOWN:
			case LEFT:
			case RIGHT:
				if (moveCharacter(key))
				{
					moveMidgets();
					m_sumOfSteps++;
					printScreen();
				}
				break;
			case CHANGE_CHAR:
				m_activeChar = nextChar();
				printScreen();
				break;
			case SPACE:
				moveMidgets();
				printScreen();
				break;
			case ESCAPE:
				return;
			case OTHER:
				break;
			default:
				break;
			}
			if (m_king.cameToThrone())
			{
				break;
			}

			key = keyboardKey();
		} while (!m_king.cameToThrone());
	}
}

/*
*	Returns whether the file stream is open or not.
*/
bool Controller::isFileOpen() const
{
	return m_file.is_open();
}

//+---------------------------------------------------------+
//|					Private Member Functions				|
//+---------------------------------------------------------+

/*
*	Resets all variables needed to start a new level.
*/
void Controller::setNewLevel()
{
	std::system("cls");
	vector<string> textLevel = readLevel(m_file, m_terminator);
	m_board = Board(textLevel);
	vector<vector<Brick>> boardBricks = m_board.getBricks();
	
	setNewCharacters(boardBricks);
	m_activeChar = P_KING;
	m_sumOfSteps = 0;
}

/*
*	Resets the characters to the new state according to the new level.
*/
void Controller::setNewCharacters(const vector<vector<Brick>> & boardBricks)
{
	m_midgets.clear();

	for (auto line : boardBricks)
	{
		for (auto brick : line)
		{
			switch (brick.getState())
			{
			case KING:
				m_king = King(brick.getPlace());
				break;
			case MAGE:
				m_mage = Mage(brick.getPlace());
				break;
			case GIANT:
				m_giant = Giant(brick.getPlace());
				break;
			case THIEF:
				m_thief = Thief(brick.getPlace());
				break;
			case MIDGET:
			{
				Midget midget = Midget(brick.getPlace());
				m_midgets.push_back(midget);
			}
			default:
				break;
			}
		}
	}
}

/*
*	Moves the given character to his next step.
*/
bool Controller::moveCharacter(KeyPress key)
{
	switch (m_activeChar)
	{
	case P_KING:
		return m_king.stepTo(m_board, key);
	case P_GIANT:
		return m_giant.stepTo(m_board, key, m_midgets);
	case P_THIEF:
		return m_thief.stepTo(m_board, key);
	case P_MAGE:
		return m_mage.stepTo(m_board, key);
	}
	return false;
}

/*
*	Moves all the midgets one step each.
*/
void Controller::moveMidgets()
{
	for (auto & midget : m_midgets)
	{
		midget.stepTo(m_board, randomDirection());
	}
}

/*
*	Prints the board and all of the additional details.
*/
void Controller::printScreen() const
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	m_board.print();

	std::cout << "Character in control: ";
	switch (m_activeChar)
	{
	case P_KING:
		std::cout << "King " << std::endl;
		break;
	case P_GIANT:
		std::cout << "Giant" << std::endl;
		break;
	case P_THIEF:
		std::cout << "Thief" << std::endl;
		break;
	case P_MAGE:
		std::cout << "Mage " << std::endl;
		break;
	}

	std::cout << "Sum of moves: " << m_sumOfSteps << std::endl;
	std::cout << "Thief has a key: " << ((m_thief.hasAKey()) ? "Yes" : "No ") << std::endl;
}

/*
*	Returns the next character in line.
*/
ActiveChar Controller::nextChar() const
{
	return (ActiveChar)((m_activeChar + 1) % 4);
}
