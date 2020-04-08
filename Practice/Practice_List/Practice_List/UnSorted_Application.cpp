#include "UnSorted_Application.h"

// Command 와 Run 작성 숙지해야한다.
void UnSorted_Application::Run()
{
	bool quit = false;
	while (!quit)
	{
		int Cmd = GetCommand();
		switch (Cmd)
		{
		case 1:
			AddItem();
			break;
		case 2:
			DisplayAllItem();
			break;
		case 3:
			MakeEmpty();
			break;
		case 4:
			ReadDataFromFile();
			break;
		case 5:
			WriteDataToFile();
			break;
		case 0:
			quit = true;
			break;
		default:
			cout << "\t-----------------------------------" << '\n';
			cout << "\t=====| ERROR: Wrong Command |======" << '\n';
			cout << "\t-----------------------------------" << '\n';
			break;
		}
	}
}


int UnSorted_Application::GetCommand()
{
	cout << '\n';
	cout << "\t--- ID -- Command -----" << '\n';
	cout << "\t    1: Add item" << '\n';
	cout << "\t    2: Print all on screen" << '\n';
	cout << "\t    3: Make empty list" << '\n';
	cout << "\t    4: Get from file" << '\n';
	cout << "\t    5: Put to file" << '\n';
	cout << "\t    0: Quit" << '\n';
	cout << '\n';
	cout << '\n';
	cout << "\tChoose a Command --> ";
	cin >> m_Command;

	return m_Command;
}


int UnSorted_Application::AddItem()
{
	if (m_List.IsFull()) {
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR: List is Full |======" << '\n';
		cout << "\t=====| ERROR: ADD  FAIL    |======" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}

	ItemType item, curItem;
	bool found = false;
	cout << '\n';
	item.SetRecordFromKB();
	m_List.ResetList();
	int iPos = m_List.GetNextItem(curItem);
	for (iPos; iPos > 0; iPos = m_List.GetNextItem(curItem)) {
		if (item.CompareByID(curItem) == EQUAL) {
			found = true;
			break;
		}
	}

	if (found) {
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR:DUPLICATED KEY|======" << '\n';
		cout << "\t=====| ERROR: ADD  FAIL    |======" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}
	m_List.Add(item);
	cout << '\n';
	cout << "\t---------------------------------" << '\n';
	cout << "\t=====|  ADD ITEM SUCCESS  |======" << '\n';
	cout << "\t---------------------------------" << '\n';
	return 1;
	
}


void UnSorted_Application::DisplayAllItem()
{
	if (m_List.IsEmpty()) {
		cout << "\t-----------------------------------" << '\n';
		cout << "\t=====| ERROR :   EMPTY LIST |======" << '\n';
		cout << "\t-----------------------------------" << '\n';
	}
	ItemType item;
	m_List.ResetList();
	int iPos = m_List.GetNextItem(item);
	for (iPos; iPos > 0; iPos = m_List.GetNextItem(item)) {
		cout << '\n';
		cout << "========|   STORAGE   |=========" << '\n';
		item.DisplayRecordOnScreen();
		cout << "========| =========== |=========" << '\n';
	}
}


void UnSorted_Application::MakeEmpty()
{
	m_List.MakeEmpty();
	cout << '\n';
	cout << "\t---------------------------------" << '\n';
	cout << "\t=====| EMPTY LIST SUCCESS |======" << '\n';
	cout << "\t---------------------------------" << '\n';

}


int UnSorted_Application::OpenInFile(char* inFilename)
{
	m_InFile.open(inFilename);
	if (m_InFile.is_open()) {
		return 1;
	}
	return 0;
}


int UnSorted_Application::OpenOutFile(char* inFilename)
{
	m_OutFile.open(inFilename);
	if (m_OutFile.is_open()) {
		return 1;
	}
	return 0;
}


int UnSorted_Application::ReadDataFromFile()
{
	char filename[CHARMAXSIZE];
	cout << "\t[File name] : ";
	cin >> filename;
	if (OpenInFile(filename)) {
		cout << "\t=====| FILE OPEN SUCCESS |======" << '\n';
		ItemType item;
		while (!m_InFile.eof()) {
			item.ReadDataFromFile(m_InFile);
			if (m_List.Add(item)) {
				cout << "\t=====| READING   SUCCESS |======" << '\n';
			}
			else {
				cout << "\t=====| ERROR:  FULL LIST |======" << '\n';
				return 0;
			}
		}
		return 1;
	}
	cout << "\t=====| ERROR: Fail to open file |======" << '\n';
	return 0;
}


int UnSorted_Application::WriteDataToFile()
{
	char filename[CHARMAXSIZE];
	cout << "\t[File name] : ";
	cin >> filename;
	if (OpenOutFile(filename)) {
		cout << "\t=====| FILE OPEN SUCCESS |======" << '\n';
		if (m_List.IsEmpty()) {
			cout << "\t=====| ERROR: EMPTY LIST |======" << '\n';
			return 0;
		}
		ItemType item;
		m_List.ResetList();
		int iPos = m_List.GetNextItem(item);
		for (iPos; iPos > 0; iPos = m_List.GetNextItem(item)) {
			item.WriteDataToFile(m_OutFile);
			cout << "\t=====| WRITING   SUCCESS |======" << '\n';
		}
		return 1;
	}
	cout << "\t=====| ERROR: Fail to open file |======" << '\n';
	return 0;
	
}