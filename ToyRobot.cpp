// ToyRobot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Robot.h"
#include "CmdProc.h"

CRobot g_Robot;
CCmdProc g_Cmd(&g_Robot);


int main(int argc, char* argv[])
{
	if(argc == 2)
	{
		std::ifstream file(argv[1]);

		if(!file.is_open())
			std::cout<<"Failed to open "<<argv[1]<<".\n";
		
		std::string data = "";
		//process each line of the input text file
		while(getline(file, data, '\n'))
		{
			std::vector<std::string> args;
			std::cout << data << "\n";
			g_Cmd.SplitCmdLine(data, args); //split each line into arguments
			g_Cmd.ProcessCmd(args);
		}
		file.close();
	}
	else
		std::cout<<"Input file missing.\n";

	return 0;
}

