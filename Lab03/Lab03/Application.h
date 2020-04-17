#pragma once
//--------------------------------------------------------------------
//		APPLICATION
//--------------------------------------------------------------------
class Application
{
private:
	SortedList<ItemType> MasterList;
	SortedList<ContainerType> ContainerList;
	TempType TempList;
	ifstream m_InFile;
	ofstream m_OutFile;
	int m_Command;

public:
	Application();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	~Application();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	void Run();
	//--------------------------------------------------------------------
	//	Brief:	Program driver.
	//	Pre:	program is started.
	//	Post:	program is finished.
	//--------------------------------------------------------------------


	int GetCommand();
	//--------------------------------------------------------------------
	//	Brief:	Display command on screen and get a input from keyboard.
	//	Pre:	none.
	//	Post:	none.
	//	Return:	user's commands.
	//--------------------------------------------------------------------


	int AddCommodityMaster()
	{
		if (MasterList.IsFull()) { // MasterList 용량 체크	
			cout << "[ERROR: MASTERLIST IS FULL!]" << endl;
			return 0;
		}
		if (TempList.IsFull()) { // TempList 용량 체크
			cout << "[ERROR: TEMPLIST IS FULL!]" << endl;
			return 0;
		}

		ItemType _item;	// 물품 생성, 입력받기
		_item.SetRecordFromKB();
		if (_item.GetContainerID() < 0) { // 1. 물품이 담길 컨테이너 미정
			if (MasterList.Add(_item) == 1) { // 중복확인먼저
				TempList.Enqueue(_item);
				cout << "[SUCCESS: MASTERLIST, TEMPLIST]1" << endl;
				return 1;
			}
			else {
				cout << "[ERROR: DUPLICATED ITEM!]" << endl;
				return 0;
			}
			
		}

		ContainerType curContainer; // 2. 컨테이너가 존재하는 경우
		curContainer.SetContainerID(_item.GetContainerID());
		if (ContainerList.RetrieveByBS(curContainer)) {
			if (MasterList.Add(_item) == 1) { // 중복확인먼저
				curContainer.AddItem(_item);
				cout << "[SUCCESS: MASTERLIST, CONTAINERLIST]2" << endl;
				return 1;
			}
			else {
				cout << "[ERROR: DUPLICATED ITEM!]" << endl;
				return 0;
			}	
		}
		else {
			if (ContainerList.IsFull()) { // 3. 컨테이너가 없는데 컨테이너 공간이 다 차면 실패(0)
				cout << "[ERROR: CONTAINERLIST IS FULL!]3" << endl;
				return 0;
			} // 4. 컨테이너를 생성해서 정보를 입력하고 그 안에 물건정리
			ContainerType _container; // 물품이 담길 컨테이너 생성.
			_container.SetContainerID(_item.GetContainerID());
			_container.DisplayContainerIDOnScreen();
			_container.SetContainerLocationFromKB();
			_container.AddItem(_item);
			if (MasterList.Add(_item) == 1) { // 중복확인먼저
				ContainerList.Add(_container);
				cout << "[SUCCESS: MASTERLIST, CONTAINERLIST]4" << endl;
				return 1;
			}
			else {
				cout << "[ERROR: DUPLICATED ITEM!]" << endl;
				return 0;
			}
		}
	}


	int DeleteCommodityMaster()
	{
		if (MasterList.IsEmpty()) { // MasterList 용량 체크	
			cout << "[ERROR: MASTERLIST IS EMPTY!]" << endl;
			return 0;
		}

		ItemType _item;	// 지울 item의 컨테이너 번호와 일련번호 받기
		_item.SetContainerIDFromKB();
		_item.SetSerialFromKB();
		if (_item.GetContainerID() < 0) {
			if (TempList.DeleteItem(_item) == 1) {
				MasterList.Delete(_item);
				cout << "[SUCCESS: MASTERLIST, TEMPLIST]" << endl;
				return 1;
			}
			cout << "[ERROR: MASTERLIST, TEMPLIST]" << endl;
			return 0;
		}

		if (MasterList.Delete(_item)) { // MasterList에서 지워지는지 확인
			ContainerType curContainer; // _item이 저장된 컨테이너를 찾기위한 컨테이너 포인터
			curContainer.SetContainerID(_item.GetContainerID());
			ContainerList.RetrieveByBS(curContainer);
			curContainer.DeleteItem(_item);
			cout << "[SUCCESS: MASTERLIST, CONTAINERLIST]" << endl;
			return 1;
		}
		cout << "[ERROR: MASTERLIST, CONTAINERLIST]" << endl;
		return 0;
	}


	int UpdateCommodityMaster() // 수정해야함. update할때, 컨테이너가 바뀌면 지우고 다시 넣어야하는데 예외처리 안됨
								// 그리고 Replace가 안되서 확인필요.
	{
		if (MasterList.IsEmpty()) { // MasterList 용량 체크	
			cout << "[ERROR: MASTERLIST IS FULL!]" << endl;
			return 0;
		}

		ItemType _item;
		_item.SetRecordFromKB();
		if (_item.GetContainerID() < 0) {
			if (TempList.ReplaceItem(_item) == 1) {
				TempList.DeleteItem(_item);
				MasterList.Replace(_item);
				cout << "[SUCCESS: MASTERLIST, TEMPLIST]1" << endl;
				return 1;
			}
			cout << "[ERROR: MASTERLIST, TEMPLIST]1" << endl;
			return 0;
		}

		if (MasterList.Replace(_item)) {
			ContainerType curContainer; // _item이 저장된 컨테이너를 찾기위한 컨테이너 포인터
			curContainer.SetContainerID(_item.GetContainerID());
			ContainerList.RetrieveByBS(curContainer);
			curContainer.UpdateItem(_item);
			cout << "[SUCCESS: MASTERLIST, CONTAINERLIST]2" << endl;
			return 1;
		}
		cout << "[ERROR: MASTERLIST, CONTAINERLIST]2" << endl;
		return 0;
	}


	int BinarySearchCommodityMaster()
	{
		ItemType curitem;
		curitem.SetSerialFromKB();
		MasterList.ResetList();
		if (MasterList.RetrieveByBS(curitem)) {
			curitem.DisplayRecordOnScreen();
			return 1;
		}
		cout << "[ERROR: FAIL TO BINARY SEARCH]!" << '\n';
		return 0;
	}


	void DisplayAllMaster()
	{
		ItemType curItem;
		MasterList.ResetList();
		int iPos = MasterList.GetNextItem(curItem);
		for (iPos; iPos >= 0; iPos = MasterList.GetNextItem(curItem)) {
			cout << '\n';
			curItem.DisplayRecordOnScreen();
		}
	}

	void MakeEmptyMaster()
	{
		MasterList.MakeEmpty();
	}


	// Open a file by file descriptor as an input file.
	int OpenInFile(char* filename)
	//----------------------------------------------------------------
	// (1) return 1 if the file is opened successfully, 
	//	   otherwise return 0.
	// ---------------------------------------------------------------
	{
		m_InFile.open(filename);									// (1).
		if (!m_InFile)	return 0;
		else	return 1;
	}


	// Open a file by file descriptor as an output file.
	int OpenOutFile(char* filename)
	//----------------------------------------------------------------
	// (1) return 1 if the file is opened successfully, 
	//	   otherwise return 0.
	//----------------------------------------------------------------
	{
		m_OutFile.open(filename);									// (1).
		if (!m_OutFile)	return 0;
		else	return 1;
	}


	// Open a file as a read mode, read all data on the file, and set list by the data.
	int ReadDataFromFile()
	//----------------------------------------------------------------
	// (1) file명을 입력받는다.
	// (2) 파일이 성공적으로 열리지 않았으면, 실패(0)을 return.
	// (3) 파일 읽어오기
	//	   - 아이템을 저장할 temp 선언, 포인터 초기화.
	//	   - 파일의 끝에 도달할때까지 loop [!m_InFile.eof()] 시작
	//	   - 읽어오기 -> 읽어온 부분이 끝인지 확인(정지판단) -> 리스트 삽입.
	// (4) 파일 종료
	//----------------------------------------------------------------
	{
		char filename[FILENAMESIZE];								// (1).
		cout << "\n\tEnter Input file Name : ";
		cin >> filename;


		if (!OpenInFile(filename))									// (2).
			return 0;

		ItemType temp;												// (3).
		while (!m_InFile.eof())
		{
			temp.ReadDataFromFile(m_InFile);
			MasterList.Add(temp);
		}


		m_InFile.close();											// (4).
		return 1;
	}

	// Open a file as a write mode, and write all data into the file
	int WriteDataToFile()
	//----------------------------------------------------------------
	// (1) file명을 입력받는다.
	// (2) 파일이 성공적으로 열리지 않았으면, 실패(0)을 return.
	// (3) 리스트가 비어있는지 확인. 비어있으면 실패(0)을 return.
	// (4) 파일 읽어오기
	//	   - 아이템을 저장할 temp 선언, 포인터 초기화.
	//	   - 리스트의 마지막 item까지 순차적 접근.
	//	   - 접근한 item을 파일에 작성.
	// (5) 파일 종료
	//----------------------------------------------------------------
	{
		char filename[FILENAMESIZE];								// (1).
		cout << "\n\tEnter Output file Name : ";
		cin >> filename;

		if (!OpenOutFile(filename))									// (2).
			return 0;

		if (MasterList.IsEmpty()) { return 0; }							// (3).

		ItemType temp;												// (4).
		MasterList.ResetList();
		int iPos = MasterList.GetNextItem(temp);
		for (iPos; iPos > -1; iPos = MasterList.GetNextItem(temp)) {
			temp.WriteDataToFile(m_OutFile);
		}

		m_OutFile.close();											// (5).
		return 1;
	}
	

	int AddCommodityTemp()
	{
		if (TempList.IsFull()) { return 0; }
		ItemType item;
		item.SetContainerID(-1);
		item.SetSerialFromKB();
		item.SetNameFromKB();
		item.SetNumFromKB();
		item.SetUsageFromKB();
		item.SetNumFromKB();
		if (TempList.Enqueue(item)) { return 1; }
		return 0;
	}

	int DequeueCommodityTemp()
	{
		ItemType _item;
		TempList.Dequeue(_item);
		_item.DisplayRecordOnScreen();
		MasterList.Delete(_item);
		_item.SetContainerIDFromKB();
		
		if (_item.GetContainerID() < 0) {
			MasterList.Add(_item);
			TempList.Enqueue(_item);
			cout << "[SUCCESS MASTERLIST TEMPLIST]" << '\n';
			return 1;
		}
		ContainerType curContainer; // 2. 컨테이너가 존재하는 경우
		curContainer.SetContainerID(_item.GetContainerID());
		if (ContainerList.RetrieveByBS(curContainer)) {
			if (MasterList.Add(_item) == 1) { // 중복확인먼저
				curContainer.AddItem(_item);
				cout << "[SUCCESS: MASTERLIST, CONTAINERLIST]2" << endl;
				return 1;
			}
			else {
				cout << "[ERROR: DUPLICATED ITEM!]" << endl;
				return 0;
			}
		}
		else {
			if (ContainerList.IsFull()) { // 3. 컨테이너가 없는데 컨테이너 공간이 다 차면 실패(0)
				cout << "[ERROR: CONTAINERLIST IS FULL!]3" << endl;
				return 0;
			} // 4. 컨테이너를 생성해서 정보를 입력하고 그 안에 물건정리
			ContainerType _container; // 물품이 담길 컨테이너 생성.
			_container.SetContainerID(_item.GetContainerID());
			_container.DisplayContainerIDOnScreen();
			_container.SetContainerLocationFromKB();
			_container.AddItem(_item);
			if (MasterList.Add(_item) == 1) { // 중복확인먼저
				ContainerList.Add(_container);
				cout << "[SUCCESS: MASTERLIST, CONTAINERLIST]4" << endl;
				return 1;
			}
			else {
				cout << "[ERROR: DUPLICATED ITEM!]" << endl;
				return 0;
			}
		}
	}

	void DisplayAllTemp()
	{
		TempList.DisplayAllItems();
	}


	// Opencv 4.3.0 을 이용하여 추후 구현.
	int AddPhotoContainer()
	{
		cout << "구현되지않은 기능입니다." << endl;
		return 0;
	}


	// Opencv 4.3.0 을 이용하여 추후 구현.
	int DeletePhotoContainer()
	{
		cout << "구현되지않은 기능입니다." << endl;
		return 0;
	}


	// Opencv 4.3.0 을 이용하여 추후 구현.
	void DisplayAllPhotoContainer()
	{
		cout << "구현되지않은 기능입니다." << endl;
	}



	void DisplayAllCommodityContainer()
	{
		ContainerType _container;
		_container.SetContainerIDFromKB();
		if (ContainerList.RetrieveByBS(_container)) {
			_container.DisplayContainerRecordOnScreen();
			SimpleItemType curItem;
			
		}
	}

	void DIsplayAllDetailContainer()
	{
		ContainerType _container;
		_container.SetContainerIDFromKB();
		ContainerList.ResetList();
		if (ContainerList.RetrieveByBS(_container)) {
			_container.DisplayContainerRecordOnScreen();
			SimpleItemType curItem;
			// ContainerType 내부에서 GetNextItem() 이 photo와 tItemList에서 모두 필요하다
			// id를 받고
			// MasterList에서 해당하는 id의 record를 binarysearch로 검색한다.
		}
	}

};