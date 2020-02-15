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
		cout << "4 : Search item by ID" << endl;
		cout << "5 : Search item by Name" << endl;
		cout << "6 : Delete item" << endl;
		cout << "7 : Update item" << endl;
		cout << "8 : Get from file" << endl;
		cout << "9 : Put to file" << endl;
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
			searchById();
			break;
		case(5):
			searchByName();
			break;
		case(6):
			deleteItem();
			break;
		case(7):
			updateItem();
			break;
		case(8):
			getFromFile();
			break;
		case(9):
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
	if (!SL.IsFull()) {
		ItemType temp;
		temp.SetRecordFromKB();
		SL.Add(temp);
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
	if (!SL.IsEmpty()) {
		while(SL.GetNextItem(temp) == 1){
			temp.DisplayRecordOnScreen();
			cout << endl;
		}
	}
	else {
		cerr << "List is empty!" << endl;
	}

	cout << endl;
}

void Cmd::makeEmptyList()
{
	SL.makeEmpty();
}

void Cmd::searchById()
{
	ItemType temp;
	int input;
	cout << "Enter the ID to search data: ";
	cin >> input;
	SL.ResetList();

	while (true) {
		if (SL.GetNextItem(temp) == 1) {
			if (input == temp.GetId()) {
				temp.DisplayRecordOnScreen();
				break;
			}
		}
		else {
			cerr << "Fail to search file by ID!" << endl;
			break;
		}
	}
}

void Cmd::searchByName()
{
	ItemType temp;
	string input;
	cout << "Enter the NAME to search data: ";
	cin >> input;
	SL.ResetList();

	while (true) {
		if (SL.GetNextItem(temp) == 1) {
			if (input == temp.GetName()) {
				temp.DisplayRecordOnScreen();
				break;
			}
		}
		else {
			cerr << "Fail to search file by NAME!" << endl;
			break;
		}
	}
}

void Cmd::deleteItem() 
{
	ItemType temp;
	int key;
	cout << "Enter the ID to delete data: ";
	cin >> key;

	while (true) {
		if (SL.GetNextItem(temp) == 1) {
			if (key == temp.GetId()) {
				SL.Delete(temp);
				break;
			}
		}
		else {
			cerr << "Fail to find and delete by NAME!" << endl;
			break;
		}
	}
}

void Cmd::updateItem()
{
	ItemType temp;
	temp.SetRecordFromKB();
	SL.Add(temp);
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
			SL.Add(temp);
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
		while (SL.GetNextItem(temp) == 1) {
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