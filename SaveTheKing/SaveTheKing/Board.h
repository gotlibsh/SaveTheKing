#pragma once

#include "Utilities.h"
#include "Brick.h"

class Board
{
public:
	Board();
	Board(vector<string> level);
	vector<vector<Brick>> getBricks() const;
	Brick getNeighbor(const Point & place, KeyPress direction) const;
	Brick getBrick(const Point & place) const;
	void setNewState(Point place, BrickState state);
	void print() const;
private:
	vector<vector<Brick>> m_bricks;
	Brick brickMaker(const char & single) const;
	void setBricks(const vector<string> & vec);
};

