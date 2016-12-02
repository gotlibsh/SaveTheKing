#include "Board.h"
#include <iostream>

//+---------------------------------------------------------+
//|						Constructors						|
//+---------------------------------------------------------+

/*
*	Default constructor.
*/
Board::Board()
{}

/*
*	Constructor gets:vector of strings - sets:vector of bricks.
*/
Board::Board(const vector<string> & vec)
{
	setBricks(vec);
}

//+---------------------------------------------------------+
//|					Public Member Functions					|
//+---------------------------------------------------------+

/*
*	Returns a vector of vectors of bricks.
*/
vector<vector<Brick>> Board::getBricks() const
{
	return m_bricks;
}

/*
*	Returns the neighbor of a character according to requested direction
*/
Brick Board::getNeighbor(const Point & place, KeyPress direction) const
{
	switch (direction)
	{
	case UP:
		return m_bricks[place.m_y - 1][place.m_x];
	case DOWN:
		return m_bricks[place.m_y + 1][place.m_x];
	case LEFT:
		return m_bricks[place.m_y][place.m_x - 1];
	case RIGHT:
		return m_bricks[place.m_y][place.m_x + 1];
	}
	return Brick();
}

/*
*	Returns a brick in a place requested by controller.
*/
Brick Board::getBrick(const Point & place) const
{
	return m_bricks[place.m_y][place.m_x];
}

/*
*	Sets the state of a brick
*/
void Board::setNewState(const Point & place, BrickState state)
{
	m_bricks[place.m_y][place.m_x].setState(state);
}

/*
*	Prints the board.
*/
void Board::print() const
{
	for (auto line : m_bricks)
	{
		for (auto singleBrick : line)
		{
			std::cout << singleBrick.print();
		}
		std::cout << std::endl;
	}
}

//+---------------------------------------------------------+
//|					Private Member Functions				|
//+---------------------------------------------------------+

/*
*	Returns a brick according to the char appearing on the board.
*/
Brick Board::brickMaker(const char & single) const
{
	Brick temp;
	switch (single)
	{
	case EMPTY:
		temp.setState(EMPTY);
		break;
	case MIDGET:
		temp.setState(MIDGET);
		break;
	case KING:
		temp.setState(KING);
		break;
	case MAGE:
		temp.setState(MAGE);
		break;
	case GIANT:
		temp.setState(GIANT);
		break;
	case THIEF:
		temp.setState(THIEF);
		break;
	case WALL:
		temp.setState(WALL);
		break;
	case KEY:
		temp.setState(KEY);
		break;
	case THRONE:
		temp.setState(THRONE);
		break;
	case FIRE:
		temp.setState(FIRE);
		break;
	case GATE:
		temp.setState(GATE);
		break;
	}

	return temp;
}

/*
*	Assigns a 2D vector of bricks, that is set from a vector of strings.  
*/
void Board::setBricks(const vector<string> & vec)
{
	for (int row = 0; row < vec.size(); row++)
	{
		int rowSize = (int)(vec[row].size());
		vector<Brick> line;
		
		for (int col = 0; col < rowSize; col++)
		{
			//temp gets a new brick and sets a place for it
			Brick temp = brickMaker(vec[row][col]);
			temp.setPlace(col, row);
			//brick is pushed into line
			line.push_back(temp);
		}
		//line is pushed into m_bricks vector
		m_bricks.push_back(line);
	}
}