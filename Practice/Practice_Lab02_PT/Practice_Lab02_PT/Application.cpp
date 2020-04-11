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
			AddMusic();
			break;
		case 2:
			DeleteMusic();
			break;
		case 3:
			SearchByID_SequenS();
			break;
		case 4:
			SearchByID_BinaryS();
			break;
		case 5:
			SearchByName();
			break;
		case 6:
			ReplaceMusic();
			break;
		case 7:
			DisplayAllMusic();
			break;
		case 8:
			MakeEmpty();
			break;
		case 9:
			ReadDataFromFile();
			break;
		case 10:
			WriteDataToFile();
			break;
		case 0:
			quit = true;
			break;
		default:
			cout << '\n';
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
	cout << "\t    1: Add music" << '\n';
	cout << "\t    2: Delete music by serial number" << '\n';
	cout << "\t    3: Search music by serial number" << '\n';
	cout << "\t    4: Binary search music by serial number" << '\n';
	cout << "\t    5: Search music by name" << '\n';
	cout << "\t    6: Replace music record from keyborad" << '\n';
	cout << "\t    7: Print all music on screen" << '\n';
	cout << "\t    8: Make empty list" << '\n';
	cout << "\t    9: Get from file" << '\n';
	cout << "\t   10: Put to file" << '\n';
	cout << "\t    0: Quit" << '\n';

	cout << '\n';
	cout << '\n';
	cout << "\tChoose a Command --> ";
	cin >> m_Command;

	return m_Command;
}


int Application::AddMusic()
{
	ItemType item;
	item.SetRecordFromKB();
	if (m_List.Add(item) == 1) {
		cout << '\n';
		cout << "\t---------------------------------" << '\n';
		cout << "\t=====|  ADD ITEM SUCCESS  |======" << '\n';
		cout << "\t---------------------------------" << '\n';
		return 1;
	}
	else if (m_List.Add(item) == -1) {
		cout << '\n';
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR:DUPLICATED KEY|======" << '\n';
		cout << "\t=====| ERROR: ADD  FAIL    |======" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}
	else {
		cout << '\n';
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR: List is Full |======" << '\n';
		cout << "\t=====| ERROR: ADD  FAIL    |======" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}
}


int Application::DeleteMusic()
{
	ItemType item;
	item.SetSerialFromKB();
	if (m_List.Delete(item) == 1) {
		cout << '\n';
		cout << "\t---------------------------------" << '\n';
		cout << "\t=====| DELETE ITEM SUCCESS |=====" << '\n';
		cout << "\t---------------------------------" << '\n';
		return 1;
	}
	else if (m_List.Delete(item) == -1) {
		cout << '\n';
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR: SERIAL NOT FOUND|===" << '\n';
		cout << "\t=====| ERROR: DELETE  FAIL |======" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}
	else {
		cout << '\n';
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR: List is EMPTY|======" << '\n';
		cout << "\t=====| ERROR: DELETE  FAIL |======" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}
}


int Application::ReplaceMusic()
{
	ItemType item;
	item.SetRecordFromKB();
	if (m_List.Replace(item) == 1) {
		cout << '\n';
		cout << "\t-------------------------------" << '\n';
		cout << "\t=====| REPLACE  SUCCESS |======" << '\n';
		cout << "\t-------------------------------" << '\n';
		return 1;
	}
	else if (m_List.Replace(item) == -1) {
		cout << '\n';
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR: SERIAL NOT FOUND|===" << '\n';
		cout << "\t=====| ERROR: REPLACE  FAIL   |===" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}
	else {
		cout << '\n';
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR: List is EMPTY|======" << '\n';
		cout << "\t=====| ERROR: REPLACE  FAIL|======" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}
}


int Application::RetrieveMusic()
{
	ItemType item;
	item.SetSerialFromKB();
	if (m_List.Get(item) == 1) {
		cout << '\n';
		cout << "\t--------------------------------" << '\n';
		cout << "\t=====| RETRIEVE  SUCCESS |======" << '\n';
		cout << "\t--------------------------------" << '\n';
		item.DisplayRecordOnScreen();
		return 1;
	}
	else if (m_List.Get(item) == -1) {
		cout << '\n';
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR: SERIAL NOT FOUND|===" << '\n';
		cout << "\t=====| ERROR: RETRIEVE  FAIL  |===" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}
	else {
		cout << '\n';
		cout << "\t----------------------------------" << '\n';
		cout << "\t=====| ERROR: List is EMPTY|======" << '\n';
		cout << "\t=====| ERROR: DELETE  FAIL |======" << '\n';
		cout << "\t----------------------------------" << '\n';
		return 0;
	}
}


void Application::DisplayAllMusic()
{
	if (m_List.IsEmpty()) {
		cout << '\n';
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
		//m_List.ResetList(); Write하고 Read할때 오류 방지하기 위해
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

		if (add) {
			cout << "\t=====| READ DATA [FINISH]|======" << '\n';
			return 1;
		}
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
		cout << "\t=====| WRITE DATA [FINISH]|=====" << '\n';
		return 1;
	}
	cout << "\t=====| ERROR: Fail to open file |======" << '\n';
	return 0;

}


int Application::SearchByID_SequenS()
{

}


int Application::SearchByID_BinaryS()
{

}


int Application:: SearchByName()
{

}