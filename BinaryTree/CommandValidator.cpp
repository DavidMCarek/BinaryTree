
#include "stdafx.h"
#include "CommandValidator.h"
#include <string>

CommandValidator::CommandValidator()
{
}


CommandValidator::~CommandValidator()
{
}

void CommandValidator::SetCommand(std::string command)
{
	currentCommand = Invalid;
	if (command == "exit")
		currentCommand = Exit;
	else if (command == "insert")
		currentCommand = Insert;
	else if (command == "delete")
		currentCommand = Delete;
	else if (command == "search")
		currentCommand = Search;
	else if (command == "min")
		currentCommand = Min;
	else if (command == "max")
		currentCommand = Max;
	else if (command == "next")
		currentCommand = Next;
	else if (command == "prev")
		currentCommand = Previous;
	else if (command == "list")
		currentCommand = List;
	else if (command == "help")
		currentCommand = Help;

}

CommandValidator::Command CommandValidator::GetCurrentCommand() 
{
	return currentCommand;
}

bool CommandValidator::IsValidCommand()
{
	return currentCommand != Invalid;
}