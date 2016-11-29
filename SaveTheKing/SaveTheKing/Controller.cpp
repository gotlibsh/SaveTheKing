#include "Controller.h"
#include <iostream>
#include <Windows.h>

Controller::Controller(string levelFilePath, string terminator)
{
	m_file.open(levelFilePath);
	m_terminator = terminator;
	m_sumOfSteps = 0;
	m_activeChar = P_KING;
}

Controller::~Controller()
{
	if (m_file.is_open())
		m_file.close();
}

void Controller::startGame()
{
	while (!m_file.eof())
	{
		setNewLevel();
		printScreen();

		KeyPress key = keyboardKey();

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
					printScreen();
					m_sumOfSteps++;
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
			case OTHER:
				break;
			default:
				break;
			}

			key = keyboardKey();
		} while (key != ESCAPE && !m_king.cameToThrone());
	}
}

bool Controller::isFileOpen() const
{
	return m_file.is_open();
}

void Controller::setNewLevel()
{
	vector<string> textLevel = readLevel(m_file, m_terminator);
	m_board = Board(textLevel);

	vector<vector<Brick>> boardBricks = m_board.getBricks();
	setNewCharacters(boardBricks);
	m_activeChar = P_KING;
	m_sumOfSteps = 0;
}

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

void Controller::moveMidgets()
{
	for (auto & midget : m_midgets)
	{
		midget.stepTo(m_board, randomDirection());
	}
}

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
	std::cout << "Thief has a key: " << ((m_thief.hasAKey()) ? "Yes" : "No ");
}

ActiveChar Controller::nextChar()
{
	return (ActiveChar)((m_activeChar + 1) % 4);
}
