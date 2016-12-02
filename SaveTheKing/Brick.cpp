#include "Brick.h"

//+---------------------------------------------------------+
//|						Constructors						|
//+---------------------------------------------------------+

Brick::Brick()
{}

//+---------------------------------------------------------+
//|					Public Member Functions					|
//+---------------------------------------------------------+

BrickState Brick::getState() const
{
	return m_state;
}

Point Brick::getPlace() const
{
	return m_place;
}

void Brick::setPlace(int x, int y)
{
	m_place.m_x = x;
	m_place.m_y = y;
}

void Brick::setState(BrickState state)
{
	m_state = state;
}

char Brick::print() const
{
	return (char)m_state;
}
