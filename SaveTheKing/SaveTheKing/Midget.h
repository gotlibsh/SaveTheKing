#pragma once

#include "Board.h"
#include "Point.h"
#include "Utilities.h"

class Midget
{
public:
	Midget();
	Midget(Point place);
	Point getCurrentPlace() const;
	bool stepTo(Board & board, KeyPress direction);
	bool isAboveKey() const;
	void setAboveKey(bool state);
	void moveToBase(Board & board);
private:
	bool isStepable(const Brick & brick) const;
	Point m_basePlace;
	Point m_currentPlace;
	bool m_isAboveKey;
};

