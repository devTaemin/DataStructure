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
	// (1) 현재 list의 capacity를 확인한다. full이면 실패(0)을 return.
	// (2) 추가하고자 하는 item을 입력받는다.
	// (3) Add 함수를 이용하여 입력한다.
	//	   - add 성공시 성공(1) 1 return, 실패(0)시 0 return.
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
	// (1) 지우고자 하는 데이터를 입력한다.
	// (2) 삭제에 성공(1)하면 성공 메세지를 출력한다. 성공(1) return.
	// (3) 삭제에 실패(0)하면 실패 메세지를 출력한다. 실패(0) return.
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


//해당 id의 item을 변경한다.
int Application::ReplaceItem()
{
	//----------------------------------------------------------------
	// (1) 변경하고자 하는 아이템을 입력받는다.
	// (2) 변경에 성공(1)하면 성공 메세지를 출력한다. 성공(1) return.
	// (3) 변경에 실패(0)하면 실패 메세지를 출력한다. 실패(0) return.
	//---------------------------------------------------------------
	ItemType Item;												// (1).
	Item.SetRecordFromKB(); //키보드로부터 정보를 입력받음

	if (m_List.Replace(Item) == 1) {							// (2).
		cout << "<======== REPLACE SUCCESS! ========>" << '\n';
		return 1;
	}
	else {														// (3).
		cout << "<======== REPLACE FAIL! ========>" << '\n';
		return 0;
	}
}


// 리스트에서 해당 id를 가진 item을 찾아 출력한다.
int Application::SearchByID_SequenS()
{
	//----------------------------------------------------------------
	// (1) 찾고자 하는 item의 id를 입력한다.
	// (2) 선형탐색 함수를 이용하여 검색한다.
	//     - 검색 성공(1)시, message, display and 1 return.
	//     - 검색 실패(0)시, message and 0 return. 
	// ---------------------------------------------------------------

	ItemType item;												// (1).
	item.SetIdFromKB();
	if (m_List.Retrieve_SeqS(item) == 1)							// (2).
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 반환
}


// 리스트에서 해당 id를 가진 item을 찾아 출력한다.
int Application::SearchByID_BinarayS()
{
	//----------------------------------------------------------------
	// (1) 찾고자 하는 item의 id를 입력한다.
	// (2) 이진탐색 함수를 이용하여 검색한다.
	//     - 검색 성공(1)시, message, display and 1 return.
	//     - 검색 실패(0)시, message and 0 return. 
	// ---------------------------------------------------------------

	ItemType item;												// (1).
	item.SetIdFromKB();
	if (m_List.RetrieveByBS(item) == 1)						// (2).
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;	//성공(1)을 반환
	}
	//발견 못할시
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//실패(0)을 반환
}

// 리스트에서 해당 name을 가진 item을 찾아 출력한다.
int Application::SearchByName()
{
	//----------------------------------------------------------------
	// (1) 찾고자 하는 item의 name을 입력한다.
	// (2) 탐색 함수를 이용하여 검색한다.
	//     - 검색 성공(1)시, message, display and 1 return.
	//     - 검색 실패(0)시, message and 0 return. 
	// ---------------------------------------------------------------
	ItemType item;
	item.SetNameFromKB();

	if (SearchAllItemByName(item) != 0)
		return 1;
	return 0;
}


// 이름으로 Item을 찾는다.
int Application::SearchAllItemByName(ItemType& inData)
{
	//----------------------------------------------------------------
	// (1) 리스트의 item을 받기 위해서 변수 temp를 선언한다.
	// (2) 탐색을 위해 iterator을 초기화한다.
	// (3) 리스트의 마지막에 갈때까지 탐색 loop를 시작한다.
	//     - 만약 같은 name을 찾았다면, result = 1로 하며 검색을 계속
	//     - 찾을때마다, 출력을 해준다.
	// (4) 검색 성공(1)시, result(1) return.
	// (5) 검색 실패(0)시, result(0) return.
	// ---------------------------------------------------------------
	ItemType temp;												// (1).
	int result = 0;

	m_List.ResetList();											// (2).
	while (m_List.GetNextItem(temp) != -1)						// (3).
	{
		if (temp.GetName() == inData.GetName())
		{
			if (result == 0) // 처음 찾았을 시, 출력용.
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
	// (1) List가 비어있는지 확인 후, 출력
	// (2) List가 비어있을 경우 message.
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
	// (1) file명을 입력받는다.
	// (2) 파일이 성공적으로 열리지 않았으면, 실패(0)을 return.
	// (3) 파일 읽어오기
	//	   - 아이템을 저장할 temp 선언, 포인터 초기화.
	//	   - 파일의 끝에 도달할때까지 loop [!m_InFile.eof()] 시작
	//	   - 읽어오기 -> 읽어온 부분이 끝인지 확인(정지판단) -> 리스트 삽입.
	// (4) 파일 종료
	// (5) 저장 정보 display
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
	// (1) file명을 입력받는다.
	// (2) 파일이 성공적으로 열리지 않았으면, 실패(0)을 return.
	// (3) 파일 읽어오기
	//	   - 아이템을 저장할 temp 선언, 포인터 초기화.
	//	   - 리스트의 길이를 이용하여, item에 접근.
	//	   - 접근한 item을 파일에 작성.
	// (4) 파일 종료
	// (5) 저장 정보 display
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