#pragma once

#include "Utilities.h"
#include "Brick.h"

class Board
{
public:
	Board();
	Board(const vector<string> & vec);
	vector<vector<Brick>> getBricks() const;
	Brick getNeighbor(const Point & place, KeyPress direction) const;
	Brick getBrick(const Point & place) const;
	void setNewState(const Point & place, BrickState state);
	void print() const;
private:
	Brick brickMaker(const char & single) const;
	void setBricks(const vector<string> & vec);
	vector<vector<Brick>> m_bricks;
};

