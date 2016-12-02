#pragma once

#include "Point.h"
#include "Utilities.h"

class Brick
{
public:
	//	Constructors
	Brick();

	//	Public Member Functions
	BrickState getState() const;
	Point getPlace() const;
	void setPlace(int x, int y);
	void setState(BrickState state);
	char print() const;
private:
	//	Private Member Data
	BrickState m_state;
	Point m_place;
};

