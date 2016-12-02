#pragma once

#include "Board.h"
#include "Point.h"
#include "Utilities.h"

class Midget
{
public:
	//	Constructors
	Midget();
	Midget(const Point & place);

	//	Public Member Functions
	Point getCurrentPlace() const;
	bool stepTo(Board & board, KeyPress direction);
	bool isAboveKey() const;
	void setAboveKey(bool state);
	void moveToBase(Board & board);

private:
	//	Private Member Functions
	bool isStepable(const Brick & brick) const;

	//	Private Member Data
	Point m_basePlace;
	Point m_currentPlace;
	bool m_isAboveKey;
};

