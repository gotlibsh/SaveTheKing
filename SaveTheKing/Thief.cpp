#include "Thief.h"

//+---------------------------------------------------------+
//|						Constructors						|
//+---------------------------------------------------------+

/*
*	Default constructor.
*/
Thief::Thief()
{}

/*
*	Assigns the place and variables of the thief.
*/
Thief::Thief(const Point & place)
	:m_place(place), m_hasAKey(false), m_isAboveAKey(false)
{}

//+---------------------------------------------------------+
//|					Public Member Functions					|
//+---------------------------------------------------------+

/*
*	Returns whether the thief succeed to step his wanted step.
*/
bool Thief::stepTo(Board & board, KeyPress direction)
{
	Brick neighbor = board.getNeighbor(m_place, direction);

	if (!isStepable(neighbor) || ((neighbor.getState() == GATE) && !m_hasAKey))
	{
		return false;
	}

	if (m_isAboveAKey)
	{	//	The thief was above a key (apart from the key he holds in his packet).
		board.setNewState(m_place, KEY);
		m_isAboveAKey = false;
	}
	else
	{
		board.setNewState(m_place, EMPTY);
	}

	//	Updates the new place of the thief and draws it on the board.
	m_place = neighbor.getPlace();
	board.setNewState(m_place, THIEF);

	switch (neighbor.getState())
	{
	case GATE:	//	Key has been used.
		m_hasAKey = false;
		break;
	case KEY:	//	Handles both options: first key to grab and second key.
		m_isAboveAKey = m_hasAKey;
		m_hasAKey = true;
		break;
	}

	return true;
}

/*
*	Returns whether the thief has already a key or not.
*/
bool Thief::hasAKey() const
{
	return m_hasAKey;
}

//+---------------------------------------------------------+
//|					Private Member Functions				|
//+---------------------------------------------------------+

/*
*	Returns whether the thief is allowed to step on the given brick.
*/
bool Thief::isStepable(const Brick & brick) const
{
	return (brick.getState() == GATE ||
		brick.getState() == EMPTY ||
		brick.getState() == KEY);
}