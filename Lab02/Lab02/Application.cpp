#include "Application.h"

// Program driver.
void Application::Run()
{
	//------------------------------------------------------------------------
	// case 1:  Add new record into list.
	// case 2:  Delete student's record by student's id from KB.
	// case 3:  Replace.
	// case 4:  리스트에서 해당 Type를 가진 item을 찾아 출력한다.
	// case 5:	리스트에서 해당 Name를 가진 item을 찾아 출력한다.
	// case 6:	리스트에서 해당 id를 가진 item을 이진검색하여 출력한다.
	// case 7:	리스트에서 해당 id를 가진 item을 이진검색, record를 바꾼다.
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
	// (1) 현재 list의 capacity를 확인한다. full이면 실패(0)을 return.
	// (2) 추가하고자 하는 item을 입력받는다.
	// (3) Add 함수를 이용하여 입력한다.
	//	   - add 성공시 성공(1) 1 return, 실패(0)시 0 return.
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
	// (1) List가 비워져있는지 확인한다. 비었을 시, 실패(0) return.
	// (2) 지우고자 하는 데이터를 입력받는다.
	// (2) 삭제에 성공(1)하면 성공 메세지를 출력한다. 성공(1) return.
	// (3) 삭제에 실패(0)하면 실패 메세지를 출력한다. 실패(0) return.
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



//해당 Serial의 item을 변경한다.
int Application::ReplaceItem()
{
	//----------------------------------------------------------------
	// (1) 변경하고자 하는 아이템의 serial number을 받는다.
	// (2) 검색에 성공한 경우,
	//     - 변경에 성공(1)하면 성공 메세지를 출력한다. 성공(1) return.
	//     - 변경에 실패(0)하면 실패 메세지를 출력한다. 실패(0) return.
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



//Type로 item을 찾아 출력한다.
int Application::SearchByType_SequenS()
{
	//----------------------------------------------------------------
	// (1) 찾고자 하는 item의 Type를 입력한다.
	// (2) 선형탐색 함수를 이용하여 검색한다.
	//     - 검색 성공(1)시, message, display and 1 return.
	//     - 검색 실패(0)시, message and 0 return. 
	// ---------------------------------------------------------------
	ItemType item;												// (1).
	item.SetTypeFromKB();

	if (SearchAllItemByType(item)){							// (2).
		return 1;
	}
	return 0;
}


//Type으로 모든 item을 찾아서 출력한다.
int Application::SearchAllItemByType(ItemType& inData)
{
	//----------------------------------------------------------------
	// (1) 리스트의 item을 받기 위해서 변수 temp를 선언한다.
	// (2) 탐색을 위해 iterator을 초기화한다.
	// (3) 리스트의 마지막에 갈때까지 탐색 loop를 시작한다.
	//     - 만약 같은 type을 찾았다면, found = true로 하며 검색을 계속
	//     - 찾을때마다, 출력을 해준다.
	// (4) 검색 실패(0)시, result(0) return.
	// (5) 검색 성공(1)시, result(1) return.
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


//Name로 item을 찾아 출력한다.
int Application::SearchByName_SequenS()
{
	//----------------------------------------------------------------
	// (1) 찾고자 하는 item의 name를 입력한다.
	// (2) 선형탐색 함수를 이용하여 검색한다.
	//     - 검색 성공(1)시, message, display and 1 return.
	//     - 검색 실패(0)시, message and 0 return. 
	// ---------------------------------------------------------------
	ItemType item;												// (1).
	item.SetNameFromKB(); 

	if (SearchAllItemByName(item)) {
		return 1;
	}
	return 0;	
}


//이름으로 item을 찾아서 출력한다.
int Application::SearchAllItemByName(ItemType& inData)
{
	//----------------------------------------------------------------
	// (1) 리스트의 item을 받기 위해서 변수 temp를 선언한다.
	// (2) 탐색을 위해 iterator을 초기화한다.
	// (3) 리스트의 마지막에 갈때까지 탐색 loop를 시작한다.
	//     - 만약 같은 name을 찾았다면, found = true로 하며 검색을 계속
	//     - 찾을때마다, 출력을 해준다.
	// (4) 검색 실패(0)시, result(0) return.
	// (5) 검색 성공(1)시, result(1) return.
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


// 리스트에서 해당 Serial를 가진 item을 찾아 출력한다.
int Application::SearchBySerial_BinaryS()
{
	//----------------------------------------------------------------
	// (1) 찾고자 하는 item의 Serial을 입력한다.
	// (2) 이진탐색 함수를 이용하여 검색한다.
	//     - 검색 성공(1)시, message, display and 1 return.
	//     - 검색 실패(0)시, message and 0 return. 
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


// 리스트에서 해당 Serial를 가진 item을 찾아 출력한다.
int Application::ReplaceFromKB_BinaryS()
{
	//----------------------------------------------------------------
	// (1) 찾고자 하는 item의 Record를 입력한다.
	// (2) 이진탐색 함수를 이용하여 검색하고, 내용을 교체한다.
	//     - 수행 성공(1)시, message, display and 1 return.
	//     - 수행 실패(0)시, message and 0 return. 
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
	// (1) 리스트의 포인터 초기화, 리스트의 item을 받아옴.
	// (2) List가 비어있는지 확인, 비어있을 경우 message를 남긴다.
	// (3) 포인터가 끝까지 갈 때 까지 item을 출력.
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
	// (1) file명을 입력받는다.
	// (2) 파일이 성공적으로 열리지 않았으면, 실패(0)을 return.
	// (3) 파일 읽어오기
	//	   - 아이템을 저장할 temp 선언, 포인터 초기화.
	//	   - 파일의 끝에 도달할때까지 loop [!m_InFile.eof()] 시작
	//	   - 읽어오기 -> 읽어온 부분이 끝인지 확인(정지판단) -> 리스트 삽입.
	// (4) 파일 종료
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
	// (1) file명을 입력받는다.
	// (2) 파일이 성공적으로 열리지 않았으면, 실패(0)을 return.
	// (3) 리스트가 비어있는지 확인. 비어있으면 실패(0)을 return.
	// (4) 파일 읽어오기
	//	   - 아이템을 저장할 temp 선언, 포인터 초기화.
	//	   - 리스트의 마지막 item까지 순차적 접근.
	//	   - 접근한 item을 파일에 작성.
	// (5) 파일 종료
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

