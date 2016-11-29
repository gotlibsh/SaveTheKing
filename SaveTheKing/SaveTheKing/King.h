#pragma once
#include "Point.h"
#include "Brick.h"
#include "Board.h"
#include "Utilities.h"

class King
{
public:
	King();
	King(const Point & place);

	bool stepTo(Board & board, KeyPress direction);
	bool cameToThrone() const;
private:
	bool isStepable(const Brick & brick) const;
	Point m_place;
	bool m_cameToThrone;
	bool m_isAboveKey;
};

