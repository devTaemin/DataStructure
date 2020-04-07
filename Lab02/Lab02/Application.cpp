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
	// case 10:  Open a file as a read mode, read all data on the file, 
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
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Search item by Type" << endl;
	cout << "\t   5 : Search item by Name" << endl;
	cout << "\t   6 : Binary Search item by Serial" << endl;
	cout << "\t   7 : Binary Search and Replace item from KB" << endl;
	cout << "\t   8 : Print all on screen" << endl;
	cout << "\t   9 : Make empty list" << endl;
	cout << "\t   10 : Get from file" << endl;
	cout << "\t   11 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;

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
		cout << "List is full" << endl;
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
	// (1) ������� �ϴ� �����͸� �Է��ϰ� �����Ѵ�.
	//	   - ���̸� �̿��Ͽ� ���� ���θ� Ȯ���Ѵ�.
	// (2) ������ ����(1)�ϸ� ���� �޼����� ����Ѵ�. ����(1) return.
	// (3) ������ ����(0)�ϸ� ���� �޼����� ����Ѵ�. ����(0) return.
	// ---------------------------------------------------------------
	int pre = m_List.GetLength();								// (1).
	ItemType item;
	item.SetTypeFromKB();

	m_List.Delete(item);

	if (pre > m_List.GetLength())								// (2).
	{
		cout << "<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;			// (3).
	return 0;
}



//�ش� Serial�� item�� �����Ѵ�.
int Application::ReplaceItem()
{
	//----------------------------------------------------------------
	// (1) �����ϰ��� �ϴ� �������� �Է¹޴´�.
	// (2) ���濡 ����(1)�ϸ� ���� �޼����� ����Ѵ�. ����(1) return.
	// (3) ���濡 ����(0)�ϸ� ���� �޼����� ����Ѵ�. ����(0) return.
	//---------------------------------------------------------------
	ItemType item;												// (1).
	item.SetRecordFromKB();

	m_List.Replace(item);									// (2),(3).
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

	if (m_List.Retrieve_SeqS_Type(item))								// (2).
	{
		cout << "<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;
	}
	cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;
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

	if (m_List.Retrieve_SeqS_Name(item))						// (2).
	{
		cout << "<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); 
		cout << "<====================================>" << endl;
		return 1;	
	}
	cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	
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
	ItemType item;

	item.SetSerialFromKB();
	if (m_List.RetrieveByBS(item))
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;
	}
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;

}


// ����Ʈ���� �ش� Serial�� ���� item�� ã�� ����Ѵ�.
int Application::ReplaceFromKB_BinaryS()
{
	//----------------------------------------------------------------
	// (1) ã���� �ϴ� item�� id�� �Է��Ѵ�.
	// (2) ����Ž�� �Լ��� �̿��Ͽ� �˻��ϰ�, ������ ��ü�Ѵ�.
	//     - ���� ����(1)��, message, display and 1 return.
	//     - ���� ����(0)��, message and 0 return. 
	// ---------------------------------------------------------------
	ItemType item;

	item.SetSerialFromKB();
	if (m_List.RetrieveByBS(item))
	{
		ReplaceItem();
		return 1;
	}
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;
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

	if (SearchAllItmeByName(item))
		return 1;	
	return 0;	
}


//�̸����� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchAllItmeByName(ItemType& inData)
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
	ItemType tmp;												// (1).
	int result = 0;						

	m_List.ResetList();											// (2).
	while (m_List.GetNextItem(tmp) != -1)						// (3).
	{
		if (tmp.GetName().find(inData.GetName()) != -1) 
		{
			if (result == 0)
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	
		}
	}
	if (result)	
		cout << "<====================================>" << endl;
	else	
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	//----------------------------------------------------------------
	// (1) List�� ����ִ��� Ȯ�� ��, ���
	// (2) List�� ������� ��� message.
	// ---------------------------------------------------------------
	ItemType data;

	cout << "\n\tCurrent list" << endl;
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName)
{
	//----------------------------------------------------------------
	// (1) return 1 if the file is opened successfully, 
	//	   otherwise return 0.
	// ---------------------------------------------------------------
	m_InFile.open(fileName);	

	
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
	m_OutFile.open(fileName);	

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
	// (5) ���� ���� display
	// ---------------------------------------------------------------
	int index = 0;
	ItemType data;	

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	
	if (!OpenInFile(filename))
		return 0;

	
	while (!m_InFile.eof())
	{
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}


	m_InFile.close();	
	return 1;
}


// Open a file as a write mode, and write all data into the file,
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
	ItemType data;	

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	m_List.ResetList();

	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();

	return 1;
}

