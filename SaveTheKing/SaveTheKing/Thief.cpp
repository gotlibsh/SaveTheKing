#include "Thief.h"

Thief::Thief()
{
}

Thief::Thief(Point place)
	:m_place(place), m_hasAKey(false), m_isAboveAKey(false)
{}

bool Thief::stepTo(Board & board, KeyPress direction)
{
	Brick neighbor = board.getNeighbor(m_place, direction);

	if (!isStepable(neighbor) || ((neighbor.getState() == GATE) && !m_hasAKey))
	{
		return false;
	}

	if (m_isAboveAKey)
	{
		board.setNewState(m_place, KEY);
		m_isAboveAKey = false;
	}
	else
	{
		board.setNewState(m_place, EMPTY);
	}

	m_place = neighbor.getPlace();
	board.setNewState(m_place, THIEF);

	switch (neighbor.getState())
	{
	case GATE:
		m_hasAKey = false;
		break;
	case KEY:
		m_isAboveAKey = m_hasAKey;
		m_hasAKey = true;
		break;
	}

	return true;
}

bool Thief::hasAKey() const
{
	return m_hasAKey;
}

bool Thief::isStepable(const Brick & brick) const
{
	return (brick.getState() == GATE ||
		brick.getState() == EMPTY ||
		brick.getState() == KEY);
}