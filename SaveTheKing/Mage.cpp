#include "Mage.h"

Mage::Mage()
{
}

Mage::Mage(const Point & place)
	:m_place(place), m_isAboveKey(false)
{}

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

bool Mage::isStepable(const Brick & brick) const
{
	return (brick.getState() == FIRE ||
		brick.getState() == EMPTY ||
		brick.getState() == KEY);
}