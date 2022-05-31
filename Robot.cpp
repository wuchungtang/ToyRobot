#include "stdafx.h"
#include <iostream>
#include "Robot.h"



CRobot::CRobot(void)
{
	//initial status
	m_bPlaced = false;
	m_Pos.x = m_Pos.x = 0;
	m_Facing = NORTH;
}


CRobot::~CRobot(void)
{
}
///////////////////////////////////////////////////////////////////////////////////
bool CRobot::IsPosValid(int x, int y)
{
	if(x < MIN_POS ||  x > MAX_POS ||
	   y < MIN_POS ||  y > MAX_POS)
		return false;
	else
		return true;
}
///////////////////////////////////////////////////////////////////////////////////
bool CRobot::Place(int x, int y, Direction f)
{
	if(IsPosValid(x, y))
	{
		m_Pos.x = x;
		m_Pos.y = y;

		m_Facing = f;

		m_bPlaced = true;

		return true;
	}
	else
		return false;
}
//////////////////////////////////////////////////////////////////////////////////
bool CRobot::Move()
{
	if(!m_bPlaced)
		return false;

	Coord NextPos;
	NextPos = m_Pos; //initialized as the current pos

	switch(m_Facing)
	{
	case NORTH:
		NextPos.y++;
		break;

	case SOUTH:
		NextPos.y--;
		break;

	case EAST:
		NextPos.x++;
		break;

	case WEST:
		NextPos.x--;
		break;

	default:
		break;
	}

	if(IsPosValid(NextPos.x, NextPos.y))
	{
		m_Pos = NextPos;
		return true;
	}
	else
		return false;
}
////////////////////////////////////////////////////////////////////////////////////
bool CRobot::Turn(bool bClockwise)
{
	if(!m_bPlaced)
		return false;

	if(bClockwise)
		m_Facing = (Direction)(((unsigned int)m_Facing + 1 )  % NUM_DIRECTION);
	else
		m_Facing = (Direction)(((unsigned int)m_Facing - 1 + NUM_DIRECTION )  % NUM_DIRECTION);

	return true;
}
///////////////////////////////////////////////////////////////////////////////////
bool CRobot::TurnLeft()
{
	return Turn(false);
}
////////////////////////////////////////////////////////////////////////////////////
bool CRobot::TurnRight()
{
	return Turn(true);
}
////////////////////////////////////////////////////////////////////////////////////
bool CRobot::Report()
{
	if(!m_bPlaced)
		return false;

	std::cout<<"Output:"<<m_Pos.x<<","<<m_Pos.y<<","
		<<DIRECTION_STRS[ (unsigned char)m_Facing ]<<"\n";

	return true;
}