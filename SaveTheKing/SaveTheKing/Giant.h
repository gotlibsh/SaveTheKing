#pragma once

#include "Midget.h"
#include "Board.h"
#include "Point.h"
#include "Brick.h"
#include "Utilities.h"

class Giant
{
public:
	Giant();
	Giant(const Point & place);
	bool stepTo(Board & board, KeyPress direction, vector<Midget> & midgets);
private:
	bool isStepable(const Brick & brick) const;
	int findMidget(const vector<Midget> midgets, const Point & place) const;
	Point m_place;
	bool m_isAboveKey;
};

