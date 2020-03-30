#include "Application.h"


// Program driver
void Application::Run()
{
	while (1) {
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1:			// read a record and add to list.
			AddItem();
			break;
		case 2:			// display all the records on screen.
			DisplayAllItem();
			break;
		case 3:			// make empty list.
			m_List.MakeEmpty();
			break;
		case 4:			// load list data from a file.
			ReadDataFromFile();
			break;
		case 5:			// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}	
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << '\n' << '\n';
	cout << "\t	1 : Add item" << '\n';
	cout << "\t	2 : Print all on screen" << '\n';
	cout << "\t	3 : Make empty list" << '\n';
	cout << "\t	4 : Get from file" << '\n';
	cout << "\t	5 : Put to file" << '\n';
	cout << "\t	0 : Quit" << '\n';

	cout << '\n' << "\t Choose a Command--> ";
	cin >> command;
	cout << '\n';

	return command;
}


// Add new record into list.
int Application::AddItem()
{

}


// Display all record in the list on screen.
void Application::DisplayAllItem()
{

}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName)
{

}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName)
{

}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{

}


// Open a file as a write mode, and write all data into the file.
int Application::WriteDataToFile()
{

}


// Search student's record by student's id from KB.
int Application::RetrieveStudent()
{

}


// Delete student's record by student's id from KB.
int Application::DeleteStudent()
{

}


// Replace studnet's record by finding based on student's id, and input information.
int Application::Replace()
{

}