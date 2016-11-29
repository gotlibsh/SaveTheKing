#pragma once

#include "Board.h"
#include "Point.h"
#include "Utilities.h"

class Thief
{
public:
	Thief();
	Thief(Point place);
	bool stepTo(Board & board, KeyPress direction);
	bool hasAKey() const;
private:
	bool isStepable(const Brick & brick) const;
	Point m_place;
	bool m_hasAKey;
	bool m_isAboveAKey;
};

