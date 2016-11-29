#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <thread>
#include <conio.h>

using std::vector;
using std::string;
using std::ifstream;

const int SPECIAL_KEY = 224;
const int KB_ESCAPE = 27;
const int KB_SPACE = 32;
const int KB_P = 80;
const int KB_UP = 72;
const int KB_DOWN = 80;
const int KB_LEFT = 75;
const int KB_RIGHT = 77;

enum BrickState
{
	EMPTY = ' ',
	FIRE = '*',
	WALL = '=',
	KEY = 'F',
	GATE = '#',
	THRONE = '@',
	MIDGET = '^',
	KING = 'K',
	THIEF = 'T',
	GIANT = 'G',
	MAGE = 'M'
};

enum ActiveChar
{
	P_KING = 0,
	P_GIANT,
	P_THIEF,
	P_MAGE
};

enum KeyPress
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	CHANGE_CHAR,
	SPACE,
	ESCAPE,
	OTHER
};

vector<string> readLevel(ifstream & file, const string & terminator);
KeyPress keyboardKey();
KeyPress randomDirection();