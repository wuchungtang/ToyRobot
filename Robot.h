#pragma once

struct Coord
{
	int x;
	int y;
};

enum Direction
{
	NORTH =0,
	EAST =1,
	SOUTH =2,
	WEST =3
};

const unsigned int DIRECTION_STR_LEN = 6;
const unsigned int NUM_DIRECTION =4;
const char DIRECTION_STRS[NUM_DIRECTION][DIRECTION_STR_LEN]=
{
	"NORTH",
	"EAST",
	"SOUTH",
	"WEST"
};

const std::string PLACE_CMD_STR= "PLACE";
const std::string MOVE_CMD_STR= "MOVE";
const std::string LEFT_CMD_STR= "LEFT";
const std::string RIGHT_CMD_STR= "RIGHT";
const std::string REPORT_CMD_STR= "REPORT";

const unsigned int MIN_POS=0;
const unsigned int MAX_POS=4;

class CRobot
{
protected:
	Coord m_Pos; //robot's current position
	Direction m_Facing;
	bool m_bPlaced;

	bool IsPosValid(int x, int y);
	bool Turn(bool bClockwise);


public:
	CRobot(void);
	~CRobot(void);

	bool Place(int x, int y, Direction f); //handle PLACE command
	bool Move();
	bool TurnLeft();
	bool TurnRight();
	bool Report();
};

