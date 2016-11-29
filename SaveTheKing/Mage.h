#pragma once

#include "Board.h"
#include "Point.h"
#include "Brick.h"
#include "Utilities.h"

class Mage
{
public:
	Mage();
	Mage(const Point & place);
	bool stepTo(Board & board, KeyPress direction);
private:
	bool isStepable(const Brick & brick) const;

	Point m_place;
	bool m_isAboveKey;
};