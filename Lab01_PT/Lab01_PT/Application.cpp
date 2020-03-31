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
		case 4:			// retrieve record.
			RetrieveStudent();
			break;
		case 5:			// delete record.
			DeleteStudent();
			break;
		case 6:			// replace record.
			Replace();
			break;
		case 7:			// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:			// save list data into a file.
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
	cout << "\t---ID -- Command ----- " << '\n';
	cout << "\t	  1 : Add item" << '\n';
	cout << "\t	  2 : Print all on screen" << '\n';
	cout << "\t	  3 : Make empty list" << '\n';
	cout << "\t	  4 : Retrieve item" << '\n';
	cout << "\t	  5 : Delete item" << '\n';
	cout << "\t	  6 : Replace item" << '\n';
	cout << "\t	  7 : Get from file" << '\n';
	cout << "\t	  8 : Put to file" << '\n';
	cout << "\t	  0 : Quit" << '\n';

	cout << '\n' << "\t Choose a Command--> ";
	cin >> command;
	cout << '\n';

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	// Check whether array is full or not. if array is full, new record can't be saved.
	if (m_List.IsFull())
	{
		cout << "List is full!" << '\n';
		return -1;
	}

	// if array is not full, set record from keyboard input.
	ItemType inItem;
	inItem.SetRecordFromKB();
	
	// As student id is a primary key, it should not be duplicated.
	int list_size = m_List.GetLength();
	bool isDuplicated = false;
	if (!m_List.IsEmpty()) {
		ItemType temp;
		m_List.ResetList();
		for (int i = 0; i < list_size; i++) {
			m_List.GetNextItem(temp);
			if (temp == inItem) { isDuplicated = true; break; }
		}
		if (!isDuplicated) { m_List.Add(inItem); }	// if primary key is not duplicated, add in list.
		else {
			cout << "Error: ID is duplicated!" << '\n';
		}
	}
	else {
		m_List.Add(inItem);
	}

	// Display current items in list to checkout if funtion works well.
	DisplayAllItem();
	return 1;
}


// Display all record in the list on screen.
void Application::DisplayAllItem()
{	
	// Check if array is empty or not. if not, find the all item in array and display records.
	cout << "\n\tCurrent list" << '\n';
	if (!m_List.IsEmpty()) {
		ItemType item;
		m_List.ResetList();
		int list_size = m_List.GetLength();
		for (int i = 0; i < list_size; i++) {
			m_List.GetNextItem(item);
			item.DisplayRecordOnScreen();
			cout << '\n';
		}
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName)
{
	// return 1 if the file is opened successfully, otherwise return -1.
	m_InFile.open(fileName);
	if (m_InFile.is_open()) {
		return 1;
	}
	return -1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName)
{
	// return 1 if the file is opened successfully, otherwise return -1.
	m_OutFile.open(fileName);
	if (m_OutFile.is_open()) {
		return 1;
	}
	return -1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	// input filename from keyboard.
	char filename[FILENAMESIZE];
	cout << "\n\tEnter file name : ";
	cin >> filename;

	// check if file is opened successfully. if not, return -1.
	if (OpenInFile(filename) == -1)
		return -1;

	// Until file reaches the end of contents, read data from file to itemtype variable.
	ItemType temp;
	m_List.ResetList();
	while (!m_InFile.eof()) {
		// read id, name, address.
		temp.ReadDataFromFile(m_InFile);
		// check whether cursor reaches the end of contents.
		if (m_InFile.eof()) { break; }
		// if not, add on array.
		m_List.Add(temp);
	}

	// close file, and display to check if the function works well.
	m_InFile.close();
	DisplayAllItem();
	return 1;

}


// Open a file as a write mode, and write all data into the file.
int Application::WriteDataToFile()
{
	// input filename from keyboard.
	char filename[FILENAMESIZE];
	cout << "\n\tEnter file name : ";
	cin >> filename;

	// check if file is opened successfully. if not, return -1.
	if (OpenOutFile(filename) == -1)
		return -1;

	// use the length of array to loop items in array.
	ItemType temp;
	m_List.ResetList();
	int list_size = m_List.GetLength();
	for (int i = 0; i < list_size; i++) {
		// save the array's contents in itemtype variable.
		m_List.GetNextItem(temp);
		// write the record of item on the file.
		temp.WriteDataToFIle(m_OutFile);
	}

	// close file, and display to check if the function works well.
	m_OutFile.close();
	DisplayAllItem();
	return 1;
}


// Search student's record by student's id from KB.
int Application::RetrieveStudent()
{
	// set id on itemtype variable to find out record in the array based on id as a primary key.
	ItemType Item;
	Item.SetIdFromKB();
	// display record and return 1 if item is founded, otherwise return -1.
	if (m_List.Get(Item) == 1) {
		Item.DisplayRecordOnScreen();
		return 1;
	}
	else { 
		return -1; 
	}
}


// Delete student's record by student's id from KB.
int Application::DeleteStudent()
{
	// set id on itemtype variable to find out and delete the record in the array based on id as a primary key.
	ItemType Item;
	Item.SetIdFromKB();
	// return 1 if item is foudned and deleted successfully, otherwise -1.
	if (m_List.Delete(Item) == 1) {
		cout << "Success to delete!" << '\n';
		return 1;
	}
	else { 
		return -1; 
	}
}


// Replace studnet's record by finding based on student's id, and input information.
int Application::Replace()
{
	// set record on itemtype variable to findout and replace the record in the array based on id as a primary key.
	ItemType Item;
	Item.SetRecordFromKB();
	// return 1 if item is founded and replaced successfully, otherwise -1.
	if (m_List.Replace(Item) == 1) {
		cout << "Success to replace!" << '\n';
		return 1;
	}
	else { 
		return -1; 
	}
}