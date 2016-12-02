#include "Mage.h"

//+---------------------------------------------------------+
//|						Constructors						|
//+---------------------------------------------------------+

/*
*	Default constructor.
*/
Mage::Mage()
{}

/*
*	Assigns the place and other variables of the king.
*/
Mage::Mage(const Point & place)
	:m_place(place), m_isAboveKey(false)
{}

//+---------------------------------------------------------+
//|					Public Member Functions					|
//+---------------------------------------------------------+

/*
*	Returns whether the mage succeed to step his wanted step.
*/
bool Mage::stepTo(Board & board, KeyPress direction)
{
	Brick neighbor = board.getNeighbor(m_place, direction);

	if (!isStepable(neighbor))
	{
		return false;
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
	board.setNewState(m_place, MAGE);

	m_isAboveKey = (neighbor.getState() == KEY);

	return true;
}

//+---------------------------------------------------------+
//|					Private Member Functions				|
//+---------------------------------------------------------+

/*
*	Returns whether the mage is allowed to step on the given brick.
*/
bool Mage::isStepable(const Brick & brick) const
{
	return (brick.getState() == FIRE ||
		brick.getState() == EMPTY ||
		brick.getState() == KEY);
}