#pragma once

#include "Midget.h"
#include "Board.h"
#include "Point.h"
#include "Brick.h"
#include "Utilities.h"

class Giant
{
public:
	//	Constructors
	Giant();
	Giant(const Point & place);

	//	Public Member Functions
	bool stepTo(Board & board, KeyPress direction, vector<Midget> & midgets);
private:
	//	Private Member Functions
	bool isStepable(const Brick & brick) const;
	int findMidget(const vector<Midget> midgets, const Point & place) const;

	//	Private Member Data
	Point m_place;
	bool m_isAboveKey;
};

