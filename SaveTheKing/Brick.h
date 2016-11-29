#pragma once

#include "Point.h"
#include "Utilities.h"

class Brick
{
public:
	BrickState getState() const;
	Point getPlace() const;
	void setPlace(int x, int y);
	void setState(BrickState state);
	char print() const;
private:
	BrickState m_state;
	Point m_place;
};

