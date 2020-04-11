#include "Application.h"


void Application::Run()
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
		case 6:
			RetrieveStudent();
			break;
		case 7:
			DeleteStudent();
			break;
		case 8:
			Replace();
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


int Application::GetCommand()
{
	cout << '\n';
	cout << "\t--- ID -- Command -----" << '\n';
	cout << "\t    1: Add item" << '\n';
	cout << "\t    2: Print all on screen" << '\n';
	cout << "\t    3: Make empty list" << '\n';
	cout << "\t    4: Get from file" << '\n';
	cout << "\t    5: Put to file" << '\n';
	cout << "\t    6: Retrieve student by ID" << '\n';
	cout << "\t    7: Delete student by ID" << '\n';
	cout << "\t    8: Replace record of student" << '\n';
	cout << "\t    0: Quit" << '\n';
	cout << '\n';
	cout << '\n';
	cout << "\tChoose a Command --> ";
	cin >> m_Command;

	return m_Command;
}


int Application::AddItem()
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


void Application::DisplayAllItem()
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


void Application::MakeEmpty()
{
	m_List.MakeEmpty();
	cout << '\n';
	cout << "\t---------------------------------" << '\n';
	cout << "\t=====| EMPTY LIST SUCCESS |======" << '\n';
	cout << "\t---------------------------------" << '\n';

}


int Application::OpenInFile(char* inFilename)
{
	m_InFile.open(inFilename);
	if (m_InFile.is_open()) {
		return 1;
	}
	return 0;
}


int Application::OpenOutFile(char* inFilename)
{
	m_OutFile.open(inFilename);
	if (m_OutFile.is_open()) {
		return 1;
	}
	return 0;
}


int Application::ReadDataFromFile()
{
	char filename[FILENAMESIZE];
	cout << "\t[File name] : ";
	cin >> filename;
	if (OpenInFile(filename)) {
		cout << "\t=====| FILE OPEN SUCCESS |======" << '\n';
		ItemType item;
		bool add = false;
		m_List.ResetList(); // Write�ϰ� Read�Ҷ� ���� �����ϱ� ����
		while (!m_InFile.eof()) {
			item.ReadDataFromFile(m_InFile);
			if (m_List.Add(item) == 1) {
				cout << "\t=====| READING   SUCCESS |======" << '\n';
				add = true;
			}
			else if (m_List.Add(item) == -1) {
				cout << "\t=====| ERROR:  DUPLICATED KEY |======" << '\n';
			}
			else {
				cout << "\t=====| ERROR:  FULL LIST |======" << '\n';
				m_InFile.close();
				return 0;
			}
		}
		m_InFile.close();

		if (add) { return 1; }
		else {
			cout << "\t=====| ERROR:  ADDING FAIL |======" << '\n';
			cout << "\t=====| SUSPICOUS:  ALL ELEMENTS ARE  DUPLICATED! |======" << '\n';
			return 0;
		}
	}
	cout << "\t=====| ERROR: Fail to open file |======" << '\n';
	return 0;
}


int Application::WriteDataToFile()
{
	char filename[FILENAMESIZE];
	cout << "\t[File name] : ";
	cin >> filename;
	if (OpenOutFile(filename)) {
		cout << "\t=====| FILE OPEN SUCCESS |======" << '\n';
		if (m_List.IsEmpty()) {
			cout << "\t=====| ERROR: EMPTY LIST |======" << '\n';
			m_OutFile.close();
			return 0;
		}
		ItemType item;
		m_List.ResetList();
		int iPos = m_List.GetNextItem(item);
		for (iPos; iPos > 0; iPos = m_List.GetNextItem(item)) {
			item.WriteDataToFile(m_OutFile);
			cout << "\t=====| WRITING   SUCCESS |======" << '\n';
		}
		m_OutFile.close();
		return 1;
	}
	cout << "\t=====| ERROR: Fail to open file |======" << '\n';
	return 0;

}


int Application::RetrieveStudent()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_List.Get(item)) {
		cout << '\n';
		cout << "\t=====| RETRIEVE  SUCCESS |======" << '\n';
		item.DisplayRecordOnScreen();
		return 1;
	}
	cout << '\n';
	cout << "\t=====| ERROR: RETRIEVE FAIL |======" << '\n';
	return 0;
}


int Application::DeleteStudent()
{
	ItemType item;
	item.SetIdFromKB();
	if (m_List.Delete(item)) {
		cout << '\n';
		cout << "\t=====| DELETE  SUCCESS |======" << '\n';
		return 1;
	}
	cout << '\n';
	cout << "\t=====| ERROR: DELETE FAIL |======" << '\n';
	return 0;
}


int Application::Replace()
{
	ItemType item;
	item.SetRecordFromKB();
	if (m_List.Replace(item)) {
		cout << '\n';
		cout << "\t=====| REPLACE  SUCCESS |======" << '\n';
		return 1;
	}
	cout << '\n';
	cout << "\t=====| ERROR: REPLACE FAIL |======" << '\n';
	return 0;
}