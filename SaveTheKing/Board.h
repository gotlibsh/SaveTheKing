#pragma once

#include "Utilities.h"
#include "Brick.h"

class Board
{
public:
	//	Constructors
	Board();
	Board(const vector<string> & level);

	//	Public Member Functions 
	vector<vector<Brick>> getBricks() const;
	Brick getNeighbor(const Point & place, KeyPress direction) const;
	Brick getBrick(const Point & place) const;
	void setNewState(const Point & place, BrickState state);
	void print() const;
private:
	//	Private Member Functions 
	Brick brickMaker(const char & single) const;
	void setBricks(const vector<string> & vec);
	
	//	Private Member Data
	vector<vector<Brick>> m_bricks;
};

