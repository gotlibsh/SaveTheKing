#pragma once

#include "Board.h"
#include "Giant.h"
#include "King.h"
#include "Thief.h"
#include "Midget.h"
#include "Mage.h"
#include "Brick.h"
#include "Utilities.h"

class Controller
{
public:
	//	Constructor/Destructor
	Controller(string levelFilePath, string terminator);
	~Controller();

	//	Public Member Functions
	void runGame();
	bool isFileOpen() const;
	bool exitSucceed() const;
private:
	//	Private Member Functions
	void setNewLevel();
	void setNewCharacters(const vector<vector<Brick>> & boardBricks);
	bool moveCharacter(KeyPress key);
	void moveMidgets();
	void printScreen() const;
	void finishedLevelMsg() const;
	ActiveChar nextChar() const;

	//	Private Member Data
	ifstream m_file;
	string m_terminator;
	King m_king;
	Mage m_mage;
	Giant m_giant;
	Thief m_thief;
	vector<Midget> m_midgets;
	Board m_board;
	ActiveChar m_activeChar;
	bool m_exitSuccess;
	int m_sumOfSteps;
	int m_level;
};

