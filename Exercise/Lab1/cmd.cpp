#include "cmd.hpp"

cmd::cmd() {}
cmd::~cmd() {}

void cmd::run()
{
	bool run = false;
	while (!run)
	{
		int input;
		cout << setw(7) << "-- ID - Command -----" << endl;
		cout << setw(10) << "1: Add item" << endl;
		cout << setw(10) << "2: Print all on screen" << endl;
		cout << setw(10) << "3: Make empty list" << endl;
		cout << setw(10) << "4: Get from file" << endl;
		cout << setw(10) << "5: Put to file" << endl;
		cout << setw(10) << "0: Quit" << endl;
		cout << endl;
		cout << endl;
		cout << setw(7) << "Choose a Command --> ";
		cin >> input;
		
		switch (input)
		{
		case(1):
			addItem();
			cout << endl;
			break;
		case(2):
			printAll();
			cout << endl;
			break;
		case(3):
			makeEmpty();
			cout << endl;
			break;
		/*
		case(4):
			getFromFile();
			break;
		case(5):
			putToFile();
			break;
		*/
		case(0):
			run = quit();
			break;
		default:
			cout << "Wrong Input!" << endl;
			cout << endl;
		}
	}
}

void cmd::addItem()
{
	if (!AL.IsFull()) {
		ItemType temp;
		temp.SetRecordFromKB();
		AL.Add(temp);
	}
	else {
		cout << "ArrayList is Full" << endl;
	}
}

void cmd::printAll()
{
	ItemType temp;
	for (int i = 0; i < AL.GetLength(); i++) {
		AL.GetNextItem(temp);
		cout << endl;
	}
}

void cmd::makeEmpty()
{
	AL.MakeEmpty();
	AL.ResetList();
}

/*
void cmd::getFromFile()
{

}

void cmd::putToFile()
{

}
*/
bool cmd::quit()
{
	return true;
}