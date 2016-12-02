#pragma once
#include "Point.h"
#include "Brick.h"
#include "Board.h"
#include "Utilities.h"

class King
{
public:
	//	Constructors
	King();
	King(const Point & place);

	//	Public Member Functions
	bool stepTo(Board & board, KeyPress direction);
	bool cameToThrone() const;
private:
	//	Private Member Functions
	bool isStepable(const Brick & brick) const;

	//	Private Member Data
	Point m_place;
	bool m_cameToThrone;
	bool m_isAboveKey;
};

