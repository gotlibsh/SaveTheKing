#include "Midget.h"

Midget::Midget()
{
}

Midget::Midget(Point place)
	:m_basePlace(place), m_currentPlace(place), m_isAboveKey(false)
{}

Point Midget::getCurrentPlace() const
{
	return m_currentPlace;
}

bool Midget::stepTo(Board & board, KeyPress direction)
{
	Brick neighbor = board.getNeighbor(m_currentPlace, direction);

	if (!isStepable(neighbor))
	{
		return false;
	}

	if (m_isAboveKey)
	{
		board.setNewState(m_currentPlace, KEY);
		m_isAboveKey = false;
	}
	else if(board.getBrick(m_currentPlace).getState() == MIDGET) // checks if nobody else is there (maybe he came back when someone was there.)
	{
		board.setNewState(m_currentPlace, EMPTY);
	}

	m_currentPlace = neighbor.getPlace();
	board.setNewState(m_currentPlace, MIDGET);

	m_isAboveKey = (neighbor.getState() == KEY);

	return true;
}

bool Midget::isAboveKey() const
{
	return m_isAboveKey;
}

void Midget::setAboveKey(bool state)
{
	m_isAboveKey = state;
}

void Midget::moveToBase(Board & board)
{
	Brick basePlaceBrick = board.getBrick(m_basePlace);

	if (m_isAboveKey)
	{
		board.setNewState(m_currentPlace, KEY);
		m_isAboveKey = false;
	}
	else
	{
		board.setNewState(m_currentPlace, EMPTY);
	}
	m_currentPlace = m_basePlace;

	if (basePlaceBrick.getState() == EMPTY)
	{
		board.setNewState(m_basePlace, MIDGET);
	}
}

bool Midget::isStepable(const Brick & brick) const
{
	return (brick.getState() == EMPTY ||
		brick.getState() == KEY);
}
