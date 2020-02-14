#include "Cmd.hpp"

Cmd::Cmd() {}
Cmd::~Cmd() {}

void Cmd::run()
{
	int input;
	bool key = false;

	while (!key) {

		cout << "--- ID - Command -----" << endl;
		cout << "1 : Add item" << endl;
		cout << "2 : Print all on screen" << endl;
		cout << "3 : Make empty list" << endl;
		cout << "4 : Get from file" << endl;
		cout << "5 : Put to file" << endl;
		cout << "0 : Quit" << endl;
		cout << endl;
		cout << endl;
		cout << "Choosse a Command --> ";
		cin >> input;
		cout << endl;

		switch (input) {
		case(1):
			addItem();
			break;
		case(2):
			printAll();
			break;
		case(3):
			makeEmptyList();
			break;
		case(4):
			getFromFile();
			break;
		case(5):
			putToFile();
			break;
		case(0):
			key = quit();
			break;
		default:
			cout << "Wrong Input" << endl;
		}
	}
}

void Cmd::addItem()
{
	if (!AL.IsFull()) {
		ItemType temp;
		temp.SetRecordFromKB();
		AL.Add(temp);
		cout << endl;
	}
	else {
		cerr << "Array is Full!" << endl;
		cout << endl;
	}
}

void Cmd::printAll()
{
	ItemType temp;
	while (AL.GetNextItem(temp) != 0) {
		temp.DisplayRecordOnScreen();
		cout << endl;
	}
	cout << endl;
}

void Cmd::makeEmptyList()
{
	AL.MakeEmpty();
}

void Cmd::getFromFile()
{
	ItemType temp;
	ifstream fin;
	string filename;

	cout << "Enter the filename: ";
	cin >> filename;
	cout << endl;
	fin.open(filename);

	if (fin.is_open()) {
		while (!fin.eof()){
			temp.ReadDataFromFile(fin);
			AL.Add(temp);
		}
	}
	else {
		cerr << "Fail to open file \'" << filename << "\'!" << endl;
	}
}

void Cmd::putToFile()
{
	ItemType temp;
	ofstream fout;
	string filename;

	cout << "Enter the filename: ";
	cin >> filename;
	fout.open(filename);
	
	if (fout.is_open()) {
		while (AL.GetNextItem(temp) == 1) {
			temp.WriteDataToFile(fout);
		}
	}
	else {
		cerr << "Fail to open file \'" << filename << "\'!" << endl;
	}
}

bool Cmd::quit()
{
	return true;
}