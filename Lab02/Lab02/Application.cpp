#include "Application.h"

// Program driver.
void Application::Run()
{
	//------------------------------------------------------------------------
	// case 1:  Add new record into list.
	// case 2:  Delete student's record by student's id from KB.
	// case 3:  Replace.
	// case 4:  ����Ʈ���� �ش� Type�� ���� item�� ã�� ����Ѵ�.
	// case 5:	����Ʈ���� �ش� Name�� ���� item�� ã�� ����Ѵ�.
	// case 6:	����Ʈ���� �ش� id�� ���� item�� �����˻��Ͽ� ����Ѵ�.
	// case 7:	����Ʈ���� �ش� id�� ���� item�� �����˻�, record�� �ٲ۴�.
	// case 8:  Display all record in the list on screen.
	// case 9:  Make list empty.
	// case 10: Open a file as a read mode, read all data on the file, 
	//		    and set list by the data.
	// case 11: Open a file as a write mode, and write all data into the file.
	// case 0:  Quit.
	//------------------------------------------------------------------------
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		
			AddItem();
			break;
		case 2:		
			DeleteItem();
			break;
		case 3:		
			ReplaceItem();
			break;
		case 4:		
			SearchByType_SequenS();
			break;
		case 5:
			SearchByName_SequenS();
			break;
		case 6:
			SearchBySerial_BinaryS();
			break;
		case 7:
			ReplaceFromKB_BinaryS();
			break;
		case 8:		
			DisplayAllItem();
			break;
		case 9:		
			m_List.MakeEmpty();
			break;
		case 10:		
			ReadDataFromFile();
			break;
		case 11:		
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
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1  : Add item" << endl;
	cout << "\t   2  : Delete item" << endl;
	cout << "\t   3  : Replace item" << endl;
	cout << "\t   4  : Search item by Type" << endl;
	cout << "\t   5  : Search item by Name" << endl;
	cout << "\t   6  : Binary Search item by Serial" << endl;
	cout << "\t   7  : Binary Search and Replace item from KB" << endl;
	cout << "\t   8  : Print all on screen" << endl;
	cout << "\t   9  : Make empty list" << endl;
	cout << "\t   10 : Get from file" << endl;
	cout << "\t   11 : Put to file " << endl;
	cout << "\t   0  : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	//----------------------------------------------------------------
	// (1) ���� list�� capacity�� Ȯ���Ѵ�. full�̸� ����(0)�� return.
	// (2) �߰��ϰ��� �ϴ� item�� �Է¹޴´�.
	// (3) Add �Լ��� �̿��Ͽ� �Է��Ѵ�.
	//	   - add ������ ����(1) 1 return, ����(0)�� 0 return.
	// ---------------------------------------------------------------
	if (m_List.IsFull())										// (1).
	{
		cout << "\t<==========| FULL LIST |==========>" << endl;
		return 0;
	}

	ItemType item;												// (2).
	item.SetRecordFromKB();				
	m_List.Add(item);											// (3).

	return 1;
}


// Delete commodity record by commodity serial from KB.
int Application::DeleteItem()
{
	//----------------------------------------------------------------
	// (1) List�� ������ִ��� Ȯ���Ѵ�. ����� ��, ����(0) return.
	// (2) ������� �ϴ� �����͸� �Է¹޴´�.
	// (2) ������ ����(1)�ϸ� ���� �޼����� ����Ѵ�. ����(1) return.
	// (3) ������ ����(0)�ϸ� ���� �޼����� ����Ѵ�. ����(0) return.
	// ---------------------------------------------------------------
	if (m_List.IsEmpty()) { return 0; }							// (1).
	ItemType item;												// (2).
	item.SetSerialFromKB();				

	if (m_List.Delete(item)) {									// (3).
		cout << "\t<==========| DELETE SUCCESS |==========>" << endl;
		return 1;
	}
	cout << "\t<==========| DELETE FAIL |==========>" << endl;	// (4).

	
	return 0;
}



//�ش� Serial�� item�� �����Ѵ�.
int Application::ReplaceItem()
{
	//----------------------------------------------------------------
	// (1) �����ϰ��� �ϴ� �������� serial number�� �޴´�.
	// (2) �˻��� ������ ���,
	//     - ���濡 ����(1)�ϸ� ���� �޼����� ����Ѵ�. ����(1) return.
	//     - ���濡 ����(0)�ϸ� ���� �޼����� ����Ѵ�. ����(0) return.
	//----------------------------------------------------------------
	ItemType item;												// (1).
	item.SetSerialFromKB();

	if (m_List.Retrieve_SeqS(item))								// (2).
	{
		cout << "\t<==========I NEW RECORD |==========>" << endl;
		item.SetRecordFromKB();
		cout << "\t<==========I ========== |==========>" << endl;
		m_List.Replace(item);
		return 1;
	}
	cout << "<\t==========I FAIL TO FIND |==========>" << endl;
	return 0;
}



//Type�� item�� ã�� ����Ѵ�.
int Application::SearchByType_SequenS()
{
	//----------------------------------------------------------------
	// (1) ã���� �ϴ� item�� Type�� �Է��Ѵ�.
	// (2) ����Ž�� �Լ��� �̿��Ͽ� �˻��Ѵ�.
	//     - �˻� ����(1)��, message, display and 1 return.
	//     - �˻� ����(0)��, message and 0 return. 
	// ---------------------------------------------------------------
	ItemType item;												// (1).
	item.SetTypeFromKB();

	if (SearchAllItemByType(item)){							// (2).
		return 1;
	}
	return 0;
}


//Type���� ��� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchAllItemByType(ItemType& inData)
{
	//----------------------------------------------------------------
	// (1) ����Ʈ�� item�� �ޱ� ���ؼ� ���� temp�� �����Ѵ�.
	// (2) Ž���� ���� iterator�� �ʱ�ȭ�Ѵ�.
	// (3) ����Ʈ�� �������� �������� Ž�� loop�� �����Ѵ�.
	//     - ���� ���� type�� ã�Ҵٸ�, found = true�� �ϸ� �˻��� ���
	//     - ã��������, ����� ���ش�.
	// (4) �˻� ����(0)��, result(0) return.
	// (5) �˻� ����(1)��, result(1) return.
	// ---------------------------------------------------------------
	ItemType temp;												// (1).
	bool found = false;

	m_List.ResetList();											// (2).
	int iPos = m_List.GetNextItem(temp);

	
	for (iPos; iPos > -1; iPos = m_List.GetNextItem(temp))		// (3).
	{
		if (temp.GetType() == inData.GetType()) {
			cout << "<=======I  STORAGE  |=======>" << endl;
			temp.DisplayRecordOnScreen();
			cout << "<=======I  -------  |=======>" << endl;
			cout << '\n';
			found = true;
		}
	}

	if (!found) {												// (4).
		cout << "<==========I CAN'T FIND ITEM |==========>" << endl;
		return 0;
	}
	return 1;													// (5).
}


//Name�� item�� ã�� ����Ѵ�.
int Application::SearchByName_SequenS()
{
	//----------------------------------------------------------------
	// (1) ã���� �ϴ� item�� name�� �Է��Ѵ�.
	// (2) ����Ž�� �Լ��� �̿��Ͽ� �˻��Ѵ�.
	//     - �˻� ����(1)��, message, display and 1 return.
	//     - �˻� ����(0)��, message and 0 return. 
	// ---------------------------------------------------------------
	ItemType item;												// (1).
	item.SetNameFromKB(); 

	if (SearchAllItemByName(item)) {
		return 1;
	}
	return 0;	
}


//�̸����� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchAllItemByName(ItemType& inData)
{
	//----------------------------------------------------------------
	// (1) ����Ʈ�� item�� �ޱ� ���ؼ� ���� temp�� �����Ѵ�.
	// (2) Ž���� ���� iterator�� �ʱ�ȭ�Ѵ�.
	// (3) ����Ʈ�� �������� �������� Ž�� loop�� �����Ѵ�.
	//     - ���� ���� name�� ã�Ҵٸ�, found = true�� �ϸ� �˻��� ���
	//     - ã��������, ����� ���ش�.
	// (4) �˻� ����(0)��, result(0) return.
	// (5) �˻� ����(1)��, result(1) return.
	// ---------------------------------------------------------------
	ItemType temp;												// (1).
	bool found = false;

	m_List.ResetList();											// (2).
	int iPos = m_List.GetNextItem(temp);


	for (iPos; iPos > -1; iPos = m_List.GetNextItem(temp))		// (3).
	{
		if (temp.GetName() == inData.GetName()) {
			cout << "<=======I  STORAGE  |=======>" << endl;
			temp.DisplayRecordOnScreen();
			cout << "<=======I  -------  |=======>" << endl;
			cout << '\n';
			found = true;
		}
	}

	if (!found) {												// (4).
		cout << "<==========I CAN'T FIND ITEM |==========>" << endl;
		return 0;
	}
	return 1;													// (5).
}


// ����Ʈ���� �ش� Serial�� ���� item�� ã�� ����Ѵ�.
int Application::SearchBySerial_BinaryS()
{
	//----------------------------------------------------------------
	// (1) ã���� �ϴ� item�� Serial�� �Է��Ѵ�.
	// (2) ����Ž�� �Լ��� �̿��Ͽ� �˻��Ѵ�.
	//     - �˻� ����(1)��, message, display and 1 return.
	//     - �˻� ����(0)��, message and 0 return. 
	// ---------------------------------------------------------------
	ItemType item;												// (1).
	item.SetSerialFromKB();
	if (m_List.RetrieveByBS(item))								// (2).
	{
		cout << "<=======I  STORAGE  |=======>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<=======I  =======  |=======>" << endl;
		return 1;
	}
	cout << "<==========I CAN'T FIND ITEM !==========>" << endl;

	return 0;

}


// ����Ʈ���� �ش� Serial�� ���� item�� ã�� ����Ѵ�.
int Application::ReplaceFromKB_BinaryS()
{
	//----------------------------------------------------------------
	// (1) ã���� �ϴ� item�� Record�� �Է��Ѵ�.
	// (2) ����Ž�� �Լ��� �̿��Ͽ� �˻��ϰ�, ������ ��ü�Ѵ�.
	//     - ���� ����(1)��, message, display and 1 return.
	//     - ���� ����(0)��, message and 0 return. 
	// ---------------------------------------------------------------

	ItemType item;												// (1).
	item.SetRecordFromKB();
	if (m_List.Replace(item)) {									// (2).
		cout << "\t<==========I NEW RECORD |==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "\t<==========I ========== |==========>" << endl;
		return 1;
	}
	return 0;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	//----------------------------------------------------------------
	// (1) ����Ʈ�� ������ �ʱ�ȭ, ����Ʈ�� item�� �޾ƿ�.
	// (2) List�� ����ִ��� Ȯ��, ������� ��� message�� �����.
	// (3) �����Ͱ� ������ �� �� ���� item�� ���.
	// ---------------------------------------------------------------
	
	ItemType data;												// (1).
	m_List.ResetList();
	int iPos = m_List.GetNextItem(data);

	if (m_List.IsEmpty()) {										// (2).
		cout << "\t<==========I NO ITEM |==========>" << endl;
		cout << '\n';
	}
	else {
		cout << "-------| Current list |-------" << endl;
		cout << "------------------------------" << endl;
		for (iPos; iPos > -1; iPos = m_List.GetNextItem(data)) {// (3).
			cout << "<=======I  STORAGE  |=======>" << endl;
			data.DisplayRecordOnScreen();
			cout << "<=======I  =======  |=======>" << endl;
			cout << endl;
		}
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName)
{
	//----------------------------------------------------------------
	// (1) return 1 if the file is opened successfully, 
	//	   otherwise return 0.
	// ---------------------------------------------------------------
	m_InFile.open(fileName);									// (1).
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName)
{
	//----------------------------------------------------------------
	// (1) return 1 if the file is opened successfully, 
	//	   otherwise return 0.
	// ---------------------------------------------------------------
	m_OutFile.open(fileName);									// (1).
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	//----------------------------------------------------------------
	// (1) file���� �Է¹޴´�.
	// (2) ������ ���������� ������ �ʾ�����, ����(0)�� return.
	// (3) ���� �о����
	//	   - �������� ������ temp ����, ������ �ʱ�ȭ.
	//	   - ������ ���� �����Ҷ����� loop [!m_InFile.eof()] ����
	//	   - �о���� -> �о�� �κ��� ������ Ȯ��(�����Ǵ�) -> ����Ʈ ����.
	// (4) ���� ����
	// ---------------------------------------------------------------
	char filename[FILENAMESIZE];								// (1).
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	
	if (!OpenInFile(filename))									// (2).
		return 0;

	ItemType temp;												// (3).
	while (!m_InFile.eof())										
	{
		temp.ReadDataFromFile(m_InFile);
		m_List.Add(temp);
	}


	m_InFile.close();											// (4).
	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	//----------------------------------------------------------------
	// (1) file���� �Է¹޴´�.
	// (2) ������ ���������� ������ �ʾ�����, ����(0)�� return.
	// (3) ����Ʈ�� ����ִ��� Ȯ��. ��������� ����(0)�� return.
	// (4) ���� �о����
	//	   - �������� ������ temp ����, ������ �ʱ�ȭ.
	//	   - ����Ʈ�� ������ item���� ������ ����.
	//	   - ������ item�� ���Ͽ� �ۼ�.
	// (5) ���� ����
	// ---------------------------------------------------------------
	char filename[FILENAMESIZE];								// (1).
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))									// (2).
		return 0;

	if (m_List.IsEmpty()) { return 0; }							// (3).

	ItemType temp;												// (4).
	m_List.ResetList();
	int iPos = m_List.GetNextItem(temp);
	for (iPos; iPos > -1; iPos = m_List.GetNextItem(temp)) {
		temp.WriteDataToFile(m_OutFile);
	}

	m_OutFile.close();											// (5).
	return 1;
}

