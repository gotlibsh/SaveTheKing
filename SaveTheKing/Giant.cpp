#include "Giant.h"

Giant::Giant()
{
}

Giant::Giant(const Point & place)
	:m_place(place), m_isAboveKey(false)
{}


bool Giant::stepTo(Board & board, KeyPress direction, vector<Midget> & midgets)
{
	Brick neighbor = board.getNeighbor(m_place, direction);
	bool isMidgetAboveKey = false;

	if (!isStepable(neighbor))
	{
		return false;
	}

	if (neighbor.getState() == MIDGET)
	{
		int curMidget = findMidget(midgets, neighbor.getPlace());
		isMidgetAboveKey = midgets[curMidget].isAboveKey();
		midgets[curMidget].moveToBase(board);
		midgets[curMidget].setAboveKey(false);
	}
	
	if (m_isAboveKey)
	{
		board.setNewState(m_place, KEY);
		m_isAboveKey = false;
	}
	else
	{
		board.setNewState(m_place, EMPTY);
	}

	m_place = neighbor.getPlace();
	board.setNewState(m_place, GIANT);

	m_isAboveKey = (neighbor.getState() == KEY || isMidgetAboveKey);

	return true;
}

bool Giant::isStepable(const Brick & brick) const
{
	return (brick.getState() == MIDGET ||
		brick.getState() == EMPTY ||
		brick.getState() == KEY);
}

int Giant::findMidget(const vector<Midget> midgets, const Point & place) const
{
	for (int i = 0; i < midgets.size(); i++)
	{
		if (midgets[i].getCurrentPlace().m_x == place.m_x &&
			midgets[i].getCurrentPlace().m_y == place.m_y)
		{
			return i;
		}
	}

	return -1;
}
