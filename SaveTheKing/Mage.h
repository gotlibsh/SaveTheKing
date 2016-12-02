#pragma once

#include "Board.h"
#include "Point.h"
#include "Brick.h"
#include "Utilities.h"

class Mage
{
public:
	//	Constructors
	Mage();
	Mage(const Point & place);

	//	Public Member Functions
	bool stepTo(Board & board, KeyPress direction);
private:
	//	Private Member Functions
	bool isStepable(const Brick & brick) const;

	//	Private Member Data
	Point m_place;
	bool m_isAboveKey;
};