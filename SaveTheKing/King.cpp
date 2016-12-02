#include "King.h"

//+---------------------------------------------------------+
//|						Constructors						|
//+---------------------------------------------------------+

/*
*	Default constructor.
*/
King::King()
{}

/*
*	Assigns the place and other variables of the king.
*/
King::King(const Point & place)
	:m_place(place), m_isAboveKey(false), m_cameToThrone(false)
{}

//+---------------------------------------------------------+
//|					Public Member Functions					|
//+---------------------------------------------------------+

/*
*	Returns whether the king succeed to step his wanted step.
*/
bool King::stepTo(Board & board, KeyPress direction)
{
	Brick neighbor = board.getNeighbor(m_place, direction);

	if (!isStepable(neighbor))
	{
		return false;		// Can't move.
	}

	if (m_isAboveKey)
	{	//	The king was above a key.
		board.setNewState(m_place, KEY);
		m_isAboveKey = false;
	}
	else
	{
		board.setNewState(m_place, EMPTY);
	}

	//	Updates the new place of the king and draws it down.
	m_place = neighbor.getPlace();
	board.setNewState(m_place, KING);
	
	//	Updates whether the king came to his throne, and whether his stepped on a key.
	m_cameToThrone = (neighbor.getState() == THRONE);
	m_isAboveKey = (neighbor.getState() == KEY);

	return true;
}


/*
*	Returns whether the king came to the throne or not.
*/
bool King::cameToThrone() const
{
	return m_cameToThrone;
}


//+---------------------------------------------------------+
//|					Private Member Functions				|
//+---------------------------------------------------------+

/*
*	Returns whether the king is allowed to step on the given brick.
*/
bool King::isStepable(const Brick & brick) const
{
	return (brick.getState() == THRONE ||
		brick.getState() == EMPTY ||
		brick.getState() == KEY);
}
