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
	Controller(string levelFilePath, string terminator);
	~Controller();
	void startGame();
	bool isFileOpen() const;
private:
	void setNewLevel();
	void setNewCharacters(const vector<vector<Brick>> & boardBricks);
	bool moveCharacter(KeyPress key);
	void moveMidgets();
	void printScreen() const;
	ActiveChar nextChar();
	std::ifstream m_file;
	string m_terminator;
	King m_king;
	Mage m_mage;
	Giant m_giant;
	Thief m_thief;
	vector<Midget> m_midgets;
	Board m_board;
	ActiveChar m_activeChar;
	int m_sumOfSteps;
};

