#include "Board.h"
#include <iostream>

Board::Board()
{
}

Board::Board(const vector<string> vec)
{
	setBricks(vec);
}

vector<vector<Brick>> Board::getBricks() const
{
	return m_bricks;
}

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

Brick Board::getBrick(const Point & place) const
{
	return m_bricks[place.m_y][place.m_x];
}

void Board::setNewState(Point place, BrickState state)
{
	m_bricks[place.m_y][place.m_x].setState(state);
}

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

void Board::setBricks(const vector<string> & vec)
{
	int size = vec[0].size();

	for (int i = 0; i < vec.size(); i++)
	{
		vector<Brick> line;
		for (int j = 0; j < size; j++)
		{
			Brick temp = brickMaker(vec[i][j]);
			temp.setPlace(j, i);
			line.push_back(temp);
		}

		m_bricks.push_back(line);
	}
}

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

