#include "Giant.h"

//+---------------------------------------------------------+
//|						Constructors						|
//+---------------------------------------------------------+

/*
*	Default constructor.
*/
Giant::Giant()
{}

/*
*	Assigns the place and other variables of the giant.
*/
Giant::Giant(const Point & place)
	:m_place(place), m_isAboveKey(false)
{}


//+---------------------------------------------------------+
//|					Public Member Functions					|
//+---------------------------------------------------------+

/*
*	Returns whether the giant succeed to step his wanted step.
*/
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

//+---------------------------------------------------------+
//|					Private Member Functions				|
//+---------------------------------------------------------+

/*
*	Returns whether the giant is allowed to step on the given brick.
*/
bool Giant::isStepable(const Brick & brick) const
{
	return (brick.getState() == MIDGET ||
		brick.getState() == EMPTY ||
		brick.getState() == KEY);
}

/*
*	Returns the index of the midget with given place.
*/
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
