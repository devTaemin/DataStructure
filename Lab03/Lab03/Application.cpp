#include "pch.h"
#include "Application.h"




Application::Application()
{
	m_Command = -1;
}


Application::~Application(){}


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:
			AddCommodityMaster();
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			DisplayAllMaster();
			break;
		case 6:
			
			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			break;
		case 11:

			break;
		case 12:

			break;
		case 13:

			break;
		case 14:

			break;
		case 15:

			break;
		case 16:

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
	cout << endl << endl;
	cout << "\t---ID----- Command -----------" << '\n';
	cout << "\t======= [ MasterList ] =======" << '\n';
	cout << "\t   1  : Add commodity" << '\n';
	cout << "\t   2  : Delete commodity" << '\n';
	cout << "\t   3  : Update commodity" << '\n';
	cout << "\t   4  : Binary Search commodity by id" << '\n';
	cout << "\t   5  : Display all on screen" << '\n';
	cout << "\t   6  : Make empty list" << '\n';
	cout << "\t   7  : Get from file" << '\n';
	cout << "\t   8  : Put to file" << '\n';
	cout << "\t==============================" << '\n';
	cout << "\t======= [ TempList ] =========" << '\n';
	cout << "\t   9  : Add commodity" << '\n';
	cout << "\t   10 : Dequeue commodity" << '\n';
	cout << "\t   11 : Display all on screen" << '\n';
	cout << "\t==============================" << '\n';
	cout << "\t======= [ ContainerList ] ====" << '\n';
	cout << "\t   12  : Add photo" << '\n';
	cout << "\t   13  : Delete photo" << '\n';
	cout << "\t   14  : Display all photo in container" << '\n';
	cout << "\t   15  : Display all commodity in container" << '\n';
	cout << "\t   16  : Display details of all commodity in container" << '\n';
	cout << "\t==============================" << '\n';
	cout << "\t   0  : Quit" << '\n';
	cout << "\t==============================" << '\n';
	cout << '\n';

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

