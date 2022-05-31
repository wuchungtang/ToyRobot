#include "stdafx.h"
#include <vector>
#include <string>
#include "Robot.h"
#include "CmdProc.h"

//convert string into 10 based integer
bool StrToInt(const char *Str, int *pOut)
{
	char *ptr;
	int ret;
	ret = strtol(Str, &ptr, 10);

	if(Str == ptr)
		return false;
	else
	{
		*pOut = ret;
		return true;
	}
}

CCmdProc::CCmdProc(CRobot *_pRobot)
{
	m_pRobot = _pRobot;
}


CCmdProc::~CCmdProc(void)
{
}

bool CCmdProc::GetDirectionFromStr(const char *Str, Direction *pOut)
{
	unsigned int i;
	for(i=0;i<NUM_DIRECTION;i++)
	{
		if(strcmp(Str, DIRECTION_STRS[i])==0)
		{
			*pOut = (Direction)i;
			return true;
		}
	}

	return false;
}

bool CCmdProc::ProcessPlaceCmd(std::vector<std::string> &args)
{
	Direction dir;
	int x,y;

	if(args.size() != 4)
		return false;

	if(!StrToInt(args[1].c_str(), &x))
		return false;

	if(!StrToInt(args[2].c_str(), &y))
		return false;

	if(!GetDirectionFromStr(args[3].c_str(), &dir))
		return false;

	if(m_pRobot->Place(x, y, dir))
		return true;
	else
		return false;
}

void CCmdProc::ProcessCmd(std::vector<std::string> &args)
{
	if(args[0] == PLACE_CMD_STR)
		ProcessPlaceCmd(args);
	else if((args[0] == MOVE_CMD_STR) && (args.size()==1))
		m_pRobot->Move();
	else if((args[0] == LEFT_CMD_STR) && (args.size()==1))
		m_pRobot->TurnLeft();
	else if((args[0] == RIGHT_CMD_STR) && (args.size()==1))
		m_pRobot->TurnRight();
	else if((args[0] == REPORT_CMD_STR) && (args.size()==1))
		m_pRobot->Report();
}

bool CCmdProc::SplitCmdLine(std::string &cmd, std::vector<std::string> &args)
{
	size_t pos = 0;
    while ((pos = cmd.find(" ")) != std::string::npos ||
			((pos = cmd.find(",")) != std::string::npos) )
	{
		args.push_back(cmd.substr(0, pos));
        cmd.erase(0, pos + 1); 
    }

	args.push_back(cmd); //append the last element

	return true;
}
