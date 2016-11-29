#include "King.h"

King::King()
{
}

King::King(const Point & place)
	:m_place(place), m_isAboveKey(false), m_cameToThrone(false)
{}

bool King::stepTo(Board & board, KeyPress direction)
{
	Brick neighbor = board.getNeighbor(m_place, direction);

	if (!isStepable(neighbor))
	{
		return false;		// Can't move.
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
	board.setNewState(m_place, KING);
	
	m_cameToThrone = (neighbor.getState() == THRONE);
	m_isAboveKey = (neighbor.getState() == KEY);

	return true;
}

bool King::isStepable(const Brick & brick) const
{
	return (brick.getState() == THRONE ||
		brick.getState() == EMPTY ||
		brick.getState() == KEY);
}

bool King::cameToThrone() const
{
	return m_cameToThrone;
}
