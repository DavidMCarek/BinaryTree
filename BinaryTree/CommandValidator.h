#pragma once
#include <string>

class CommandValidator
{
public:
	CommandValidator();
	~CommandValidator();
	void SetCommand(std::string command);
	bool IsValidCommand();
	enum Command { Insert, Delete, Search, Min, Max, Next, Previous, List, Help, Exit, Invalid };
	Command GetCurrentCommand();
private:
	Command currentCommand;
};

