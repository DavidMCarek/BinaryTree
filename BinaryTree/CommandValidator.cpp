
#include "stdafx.h"
#include "CommandValidator.h"
#include <string>

CommandValidator::CommandValidator()
{
}


CommandValidator::~CommandValidator()
{
}

// sets the command enum based on the input command 
void CommandValidator::SetCommand(std::string command)
{
	command = ToLower(command);

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

// takes in a string and makes all letters lowercase
std::string CommandValidator::ToLower(std::string input)
{
	std::string lowerInput = "";

	// iterate through the characters of the input and if the character is uppercase
	// subtract the the difference between upper and lower case letters from the letter
	// then append the now lower letter to the new output
	for (int i = 0; i < input.length(); i++)
	{
		std::string lowerChar = std::string(1, input[i]);
		if (input[i] <= 'Z' && input[i] >= 'A')
			lowerChar = std::string(1, input[i] - ('A' - 'a'));
			
		lowerInput.append(lowerChar);
	}

	return lowerInput;
}