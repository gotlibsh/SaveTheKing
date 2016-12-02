#include "Midget.h"

//+---------------------------------------------------------+
//|						Constructors						|
//+---------------------------------------------------------+

/*
*	Default constructor.
*/
Midget::Midget()
{}

/*
*	Assigns the place and variables of the midget.
*/
Midget::Midget(const Point & place)
	:m_basePlace(place), m_currentPlace(place), m_isAboveKey(false)
{}

//+---------------------------------------------------------+
//|					Public Member Functions					|
//+---------------------------------------------------------+

/*
*	Returns the current place of the midget.
*/
Point Midget::getCurrentPlace() const
{
	return m_currentPlace;
}

/*
*	Returns whether the midget succeed to step his wanted step.
*/
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

/*
*	Returns whether the midget is above a key.
*/
bool Midget::isAboveKey() const
{
	return m_isAboveKey;
}

/*
*	Sets the 'aboveKey' variable to the given state.
*/
void Midget::setAboveKey(bool state)
{
	m_isAboveKey = state;
}

/*
*	Moves the midget to his base place.
*/
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

//+---------------------------------------------------------+
//|					Private Member Functions				|
//+---------------------------------------------------------+

/*
*	Returns whether the midget is allowed to step on the given brick.
*/
bool Midget::isStepable(const Brick & brick) const
{
	return (brick.getState() == EMPTY ||
		brick.getState() == KEY);
}
