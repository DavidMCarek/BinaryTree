// EECS 2510 : Binary Tree
// David Carek

#include "stdafx.h"
#include <iostream>
#include <string>
#include "CommandValidator.h"
#include "BinaryTree.h"

using namespace std;

void help();
bool executeCommand(CommandValidator::Command command, BinaryTree& binaryTree);

int main()
{
	// when first starting the program display the information on what the program does
	// and the commands associated with it
	help();

	string command;
	string userInput;
	bool exitProgram = false;
	CommandValidator commandValidator;
	BinaryTree binaryTree;

	// while the user still wants to run the the program keep asking for input
	do
	{
		userInput = "";
		command = "";
		// prompt
		cout << "Please enter a command or \"help\" to list commands : ";

		// get command and potential string
		cin >> command;

		// we need to set the command that will be validated
		commandValidator.setCommand(command);

		// if the command is valid execute it else let user know input is invalid 
		// and continue through the loop
		if (commandValidator.isValidCommand())
		{
			// execute command will also set the exit program variable by returning true 
			// if the command is exit
			exitProgram = executeCommand(commandValidator.getCurrentCommand(), binaryTree);
		}
		else
		{
			cout << endl
				<< "The command entered is invalid."
				<< endl;
		}
		
		cout << endl;
			
	} while (!exitProgram);

    return 0;
}

// executes a particular function for a given command
bool executeCommand(CommandValidator::Command command, BinaryTree& binaryTree)
{
	
	// now we need to execute the correct piece of code for the command entered
	switch (command)
	{
		case CommandValidator::Command::Exit: 
		{
			return true;
		} break;
		
		case CommandValidator::Command::Help:
		{
			help();
		} break;
		
		case CommandValidator::Command::Insert:
		{
			string userInput;
			cin >> userInput;
			cout << endl;
			binaryTree.insert(userInput);
		} break;

		case CommandValidator::Command::List:
		{
			cout << endl;
			binaryTree.list();
		} break;

		case CommandValidator::Command::Min:
		{
			cout << endl;
			binaryTree.min();
		} break;

		case CommandValidator::Command::Max:
		{
			cout << endl;
			binaryTree.max();
		} break;

		case CommandValidator::Command::Search:
		{
			string userInput;
			cin >> userInput;
			cout << endl;
			binaryTree.search(userInput);
		} break;

		case CommandValidator::Command::Next:
		{
			string userInput;
			cin >> userInput;
			cout << endl;
			binaryTree.next(userInput);
		} break;

		case CommandValidator::Command::Previous:
		{
			string userInput;
			cin >> userInput;
			cout << endl;
			binaryTree.previous(userInput);
		} break;
		
		case CommandValidator::Command::Delete:
		{
			string userInput;
			cin >> userInput;
			cout << endl;
			binaryTree.deleteInput(userInput);
		} break;
	}
	
	return false;
}

// outputs information pertaining to the user and how the program works
void help() 
{
	// output the help menu
	cout << "This program creates a binary search tree where the user can perform several operations." << endl
		<< "Commands List :" << endl << endl

		<< "insert <string>" << endl
		<< "adds the text after insert to the tree then displays the input text and count for number of times input" << endl << endl

		<< "delete <string>" << endl
		<< "decrements the count of the word if found and then outputs the word and the new count. If not found count will be -1" << endl << endl

		<< "search <string>" << endl
		<< "if the text is found, it is displayed with the count of occurrences" << endl << endl

		<< "min" << endl
		<< "outputs the minimum value of the tree or a blank line if set is empty" << endl << endl

		<< "max" << endl
		<< "outputs the maximum value of the tree or a blank line if set is empty" << endl << endl

		<< "next <string>" << endl
		<< "outputs the successor of the text or an empty line if not found" << endl << endl

		<< "prev <string>" << endl
		<< "outputs the predecessor of the text or an empty line if not not found" << endl << endl

		<< "list" << endl
		<< "displays all entries in the tree with their counts in ascending order" << endl << endl

		<< "help" << endl
		<< "outputs the help screen" << endl << endl

		<< "exit" << endl
		<< "quits the program" << endl << endl;
		
}