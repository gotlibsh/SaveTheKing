#include "Brick.h"

//+---------------------------------------------------------+
//|						Constructors						|
//+---------------------------------------------------------+

Brick::Brick()
{}

//+---------------------------------------------------------+
//|					Public Member Functions					|
//+---------------------------------------------------------+

/*
*	Returns the point (x,y) of the brick.
*/
Point Brick::getPlace() const
{
	return m_place;
}

/*
*	Returns the state of the brick.
*/
BrickState Brick::getState() const
{
	return m_state;
}

/*
*	Sets the point (x,y) of the brick.
*/
void Brick::setPlace(int x, int y)
{
	m_place.m_x = x;
	m_place.m_y = y;
}

/*
*	Sets the state of the brick.
*/
void Brick::setState(BrickState state)
{
	m_state = state;
}

/*
*	Returns the character representing this brick.
*/
char Brick::print() const
{
	return (char)m_state;
}
