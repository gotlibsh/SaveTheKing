#pragma once

#include "Board.h"
#include "Point.h"
#include "Utilities.h"

class Thief
{
public:
	//	Constructors
	Thief();
	Thief(const Point & place);

	//	Public Member Functions
	bool stepTo(Board & board, KeyPress direction);
	bool hasAKey() const;
private:
	//	Private Member Functions
	bool isStepable(const Brick & brick) const;

	//	Private Member Data
	Point m_place;
	bool m_hasAKey;
	bool m_isAboveAKey;
};

