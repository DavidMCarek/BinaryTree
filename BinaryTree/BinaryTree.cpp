// EECS 2510 : Binary Tree
// David Carek


#include <iostream>
#include <string>

using namespace std;

void Help();
bool CommandRequiresString(string command);
bool IsValidCommand(string command);
bool IsValidInput(string input);
void ExecuteCommand(bool *exitProgram, string command);

int main()
{
	Help();

	string command;
	string userInput;
	bool exitProgram;

	// while the user still wants to run the the program keep asking for input
	do
	{
		// prompt
		cout << "Please enter a command or \"help\" to list commands : ";

		// get command
		cin >> command;

		// if the command is valid execute it else let user know input is invalid 
		// and continue through the loop
		if (IsValidCommand(command))
		{
			ExecuteCommand(&exitProgram, userInput);
		}
		else
		{
			cout << endl
				<< "The command entered is invalid."
				<< endl;
			continue;
		}
		


		cout << endl;
			
	} while (!exitProgram);

    return 0;
}

void ExecuteCommand(bool *exitProgram, string command) 
{
	*exitProgram = false;
	// break string into 2 separate strings and remmove spaces
}

bool IsValidInput(string input) 
{

}

void Help() 
{
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

		<< "previous <string>" << endl
		<< "outputs the predecessor of the text or an empty line if not not found" << endl << endl

		<< "list" << endl
		<< "displays all entries in the tree with their counts in ascending order" << endl << endl

		<< "help" << endl
		<< "outputs the help screen" << endl << endl

		<< "exit" << endl
		<< "quits the program" << endl;
		
}