#pragma once


class CCmdProc
{
protected:
	CRobot *m_pRobot; //pointer to the CRobot object

	bool GetDirectionFromStr(const char *Str, Direction *pOut); //convert direction string into enum type
	bool ProcessPlaceCmd(std::vector<std::string> &args); //process PLACE command

public:
	CCmdProc(CRobot *_pRobot);
	~CCmdProc(void);
	void ProcessCmd(std::vector<std::string> &args);
	bool SplitCmdLine(std::string &cmd, std::vector<std::string> &args);
};

