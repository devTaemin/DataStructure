#include "Application.h"


// Program driver
void Application::Run()
{
	//------------------------------------------------------------------------
	// case 1:  Add new record into list.
	// case 2:  Delete student's record by student's id from KB.
	// case 3:  Replace.
	// case 4:  Search by id.
	// case 5:	Searchy by binary search.
	// case 6:	Search by name.
	// case 7:  Display all record in the list on screen.
	// case 8:  Make list empty.
	// case 9:  Open a file as a read mode, read all data on the file, 
	//		    and set list by the data.
	// case 10: Open a file as a write mode, and write all data into the file.
	// case 0:  Quit.
	//------------------------------------------------------------------------
	while (1) {
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
			SearchByID_SequenS();
			break;
		case 5:
			SearchByID_BinarayS();
			break;
		case 6:
			SearchByName();
			break;
		case 7:
			DisplayAllItem();
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
	cout << "\t	  2 : Delete item" << '\n';
	cout << "\t	  3 : Replace item" << '\n';
	cout << "\t	  4 : Search item by ID" << '\n';
	cout << "\t	  5 : Search item by Binary Search" << '\n';
	cout << "\t	  6 : Search item by name" << '\n';
	cout << "\t	  7 : Print all on screen" << '\n';
	cout << "\t	  8 : Make empty list" << '\n';
	cout << "\t	  9 : Get from file" << '\n';
	cout << "\t	  10: Put to file" << '\n';
	cout << "\t	  0 : Quit" << '\n';

	cout << '\n' << "\t Choose a Command--> ";
	cin >> command;
	cout << '\n';

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
		cout << "<======== FULL LIST! ========>" << '\n';
		return 0;
	}
	else {
		ItemType inItem;											// (2).
		inItem.SetRecordFromKB();									// (3).
		if (m_List.Add(inItem) == 1) {
			cout << "<======== ADD SUCCESS! ========>";
			return 1;
		}
		else {
			cout << "<======== ADD FAIL! ========>";
			return 0;
		}
	}

}

// Delete student's record by student's id from KB.
int Application::DeleteItem()
{
	//----------------------------------------------------------------
	// (1) ������� �ϴ� �����͸� �Է��Ѵ�.
	// (2) ������ ����(1)�ϸ� ���� �޼����� ����Ѵ�. ����(1) return.
	// (3) ������ ����(0)�ϸ� ���� �޼����� ����Ѵ�. ����(0) return.
	// ---------------------------------------------------------------
	ItemType Item;												// (1).
	Item.SetIdFromKB();


	if (m_List.Delete(Item) == 1) {								// (2).
		cout << "<======== DELETE SUCCESS! ========>" << '\n';
		return 1;
	}
	else {														// (3).
		cout << "<======== DELETE FAIL! ========>" << '\n';
		return 0;
	}
}


//�ش� id�� item�� �����Ѵ�.
int Application::ReplaceItem()
{
	//----------------------------------------------------------------
	// (1) �����ϰ��� �ϴ� �������� �Է¹޴´�.
	// (2) ���濡 ����(1)�ϸ� ���� �޼����� ����Ѵ�. ����(1) return.
	// (3) ���濡 ����(0)�ϸ� ���� �޼����� ����Ѵ�. ����(0) return.
	//---------------------------------------------------------------
	ItemType Item;												// (1).
	Item.SetRecordFromKB(); //Ű����κ��� ������ �Է¹���

	if (m_List.Replace(Item) == 1) {							// (2).
		cout << "<======== REPLACE SUCCESS! ========>" << '\n';
		return 1;
	}
	else {														// (3).
		cout << "<======== REPLACE FAIL! ========>" << '\n';
		return 0;
	}
}


// ����Ʈ���� �ش� id�� ���� item�� ã�� ����Ѵ�.
int Application::SearchByID_SequenS()
{
	//----------------------------------------------------------------
	// (1) ã���� �ϴ� item�� id�� �Է��Ѵ�.
	// (2) ����Ž�� �Լ��� �̿��Ͽ� �˻��Ѵ�.
	//     - �˻� ����(1)��, message, display and 1 return.
	//     - �˻� ����(0)��, message and 0 return. 
	// ---------------------------------------------------------------

	ItemType item;												// (1).
	item.SetIdFromKB();
	if (m_List.Retrieve_SeqS(item) == 1)							// (2).
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ
}


// ����Ʈ���� �ش� id�� ���� item�� ã�� ����Ѵ�.
int Application::SearchByID_BinarayS()
{
	//----------------------------------------------------------------
	// (1) ã���� �ϴ� item�� id�� �Է��Ѵ�.
	// (2) ����Ž�� �Լ��� �̿��Ͽ� �˻��Ѵ�.
	//     - �˻� ����(1)��, message, display and 1 return.
	//     - �˻� ����(0)��, message and 0 return. 
	// ---------------------------------------------------------------

	ItemType item;												// (1).
	item.SetIdFromKB();
	if (m_List.RetrieveByBS(item) == 1)						// (2).
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ
}

// ����Ʈ���� �ش� name�� ���� item�� ã�� ����Ѵ�.
int Application::SearchByName()
{
	//----------------------------------------------------------------
	// (1) ã���� �ϴ� item�� name�� �Է��Ѵ�.
	// (2) Ž�� �Լ��� �̿��Ͽ� �˻��Ѵ�.
	//     - �˻� ����(1)��, message, display and 1 return.
	//     - �˻� ����(0)��, message and 0 return. 
	// ---------------------------------------------------------------
	ItemType item;
	item.SetNameFromKB();

	if (SearchAllItemByName(item) != 0)
		return 1;
	return 0;
}


// �̸����� Item�� ã�´�.
int Application::SearchAllItemByName(ItemType& inData)
{
	//----------------------------------------------------------------
	// (1) ����Ʈ�� item�� �ޱ� ���ؼ� ���� temp�� �����Ѵ�.
	// (2) Ž���� ���� iterator�� �ʱ�ȭ�Ѵ�.
	// (3) ����Ʈ�� �������� �������� Ž�� loop�� �����Ѵ�.
	//     - ���� ���� name�� ã�Ҵٸ�, result = 1�� �ϸ� �˻��� ���
	//     - ã��������, ����� ���ش�.
	// (4) �˻� ����(1)��, result(1) return.
	// (5) �˻� ����(0)��, result(0) return.
	// ---------------------------------------------------------------
	ItemType temp;												// (1).
	int result = 0;

	m_List.ResetList();											// (2).
	while (m_List.GetNextItem(temp) != -1)						// (3).
	{
		if (temp.GetName() == inData.GetName())
		{
			if (result == 0) // ó�� ã���� ��, ��¿�.
				cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();
			cout << '\n';
			result = 1;
		}
	}
	if (result == 1)											// (4).
		cout << "<====================================>" << endl;
	else                                                        // (5).
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}


// Display all record in the list on screen.
void Application::DisplayAllItem()
{
	//----------------------------------------------------------------
	// (1) List�� ����ִ��� Ȯ�� ��, ���
	// (2) List�� ������� ��� message.
	// ---------------------------------------------------------------
	cout << "\n\tCurrent list" << '\n';							// (1).
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
	else {
		cout << "<============I EMPTY !==========>" << endl;	// (2).
	}
}


// Make list empty;
void Application::MakeEmpty()
{
	m_List.MakeEmpty();
	m_List.ResetList();
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName)
{
	//----------------------------------------------------------------
	// (1) return 1 if the file is opened successfully, 
	//	   otherwise return 0.
	// ---------------------------------------------------------------

	m_InFile.open(fileName);
	if (m_InFile.is_open()) {
		return 1;
	}
	return 0;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char* fileName)
{
	//----------------------------------------------------------------
	// (1) return 1 if the file is opened successfully, 
	//	   otherwise return 0.
	// ---------------------------------------------------------------
	m_OutFile.open(fileName);
	if (m_OutFile.is_open()) {
		return 1;
	}
	return 0;
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
	// (5) ���� ���� display
	// ---------------------------------------------------------------

	char filename[FILENAMESIZE];								// (1).
	cout << "\n\tEnter file name : ";
	cin >> filename;

	if (OpenInFile(filename) == 0)								// (2).
		return 0;

	ItemType temp;												// (3).
	m_List.MakeEmpty();
	while (!m_InFile.eof()) {
		// read id, name, address.
		temp.ReadDataFromFile(m_InFile);
		if (m_InFile.eof()) { break; }
		m_List.Add(temp);
	}

	m_InFile.close();											// (4).
	DisplayAllItem();											// (5).
	return 1;

}


// Open a file as a write mode, and write all data into the file.
int Application::WriteDataToFile()
{
	//----------------------------------------------------------------
	// (1) file���� �Է¹޴´�.
	// (2) ������ ���������� ������ �ʾ�����, ����(0)�� return.
	// (3) ���� �о����
	//	   - �������� ������ temp ����, ������ �ʱ�ȭ.
	//	   - ����Ʈ�� ���̸� �̿��Ͽ�, item�� ����.
	//	   - ������ item�� ���Ͽ� �ۼ�.
	// (4) ���� ����
	// (5) ���� ���� display
	// ---------------------------------------------------------------

	char filename[FILENAMESIZE];								// (1).
	cout << "\n\tEnter file name : ";
	cin >> filename;

	if (OpenOutFile(filename) == 0)								// (2).
		return 0;

	ItemType temp;												// (3).
	m_List.ResetList();
	int list_size = m_List.GetLength();
	for (int i = 0; i < list_size; i++) {
		// save the array's contents in itemtype variable.
		m_List.GetNextItem(temp);
		// write the record of item on the file.
		temp.WriteDataToFile(m_OutFile);
	}

	m_OutFile.close();											// (4).
	DisplayAllItem();											// (5).
	return 1;
}