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
		if (MasterList.IsFull()) { // MasterList �뷮 üũ	
			cout << "[ERROR: MASTERLIST IS FULL!]" << endl;
			return 0;
		}
		if (TempList.IsFull()) { // TempList �뷮 üũ
			cout << "[ERROR: TEMPLIST IS FULL!]" << endl;
			return 0;
		}

		ItemType _item;	// ��ǰ ����, �Է¹ޱ�
		_item.SetRecordFromKB();
		if (_item.GetContainerID() < 0) { // 1. ��ǰ�� ��� �����̳� ����
			if (MasterList.Add(_item) == 1) { // �ߺ�Ȯ�θ���
				TempList.Enqueue(_item);
				cout << "[SUCCESS: MASTERLIST, TEMPLIST]1" << endl;
				return 1;
			}
			else {
				cout << "[ERROR: DUPLICATED ITEM!]" << endl;
				return 0;
			}
			
		}

		ContainerType curContainer; // 2. �����̳ʰ� �����ϴ� ���
		curContainer.SetContainerID(_item.GetContainerID());
		if (ContainerList.RetrieveByBS(curContainer)) {
			if (MasterList.Add(_item) == 1) { // �ߺ�Ȯ�θ���
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
			if (ContainerList.IsFull()) { // 3. �����̳ʰ� ���µ� �����̳� ������ �� ���� ����(0)
				cout << "[ERROR: CONTAINERLIST IS FULL!]3" << endl;
				return 0;
			} // 4. �����̳ʸ� �����ؼ� ������ �Է��ϰ� �� �ȿ� ��������
			ContainerType _container; // ��ǰ�� ��� �����̳� ����.
			_container.SetContainerID(_item.GetContainerID());
			_container.DisplayContainerIDOnScreen();
			_container.SetContainerLocationFromKB();
			_container.AddItem(_item);
			if (MasterList.Add(_item) == 1) { // �ߺ�Ȯ�θ���
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
		if (MasterList.IsEmpty()) { // MasterList �뷮 üũ	
			cout << "[ERROR: MASTERLIST IS EMPTY!]" << endl;
			return 0;
		}

		ItemType _item;	// ���� item�� �����̳� ��ȣ�� �Ϸù�ȣ �ޱ�
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

		if (MasterList.Delete(_item)) { // MasterList���� ���������� Ȯ��
			ContainerType curContainer; // _item�� ����� �����̳ʸ� ã������ �����̳� ������
			curContainer.SetContainerID(_item.GetContainerID());
			ContainerList.RetrieveByBS(curContainer);
			curContainer.DeleteItem(_item);
			cout << "[SUCCESS: MASTERLIST, CONTAINERLIST]" << endl;
			return 1;
		}
		cout << "[ERROR: MASTERLIST, CONTAINERLIST]" << endl;
		return 0;
	}


	int UpdateCommodityMaster() // �����ؾ���. update�Ҷ�, �����̳ʰ� �ٲ�� ����� �ٽ� �־���ϴµ� ����ó�� �ȵ�
								// �׸��� Replace�� �ȵǼ� Ȯ���ʿ�.
	{
		if (MasterList.IsEmpty()) { // MasterList �뷮 üũ	
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
			ContainerType curContainer; // _item�� ����� �����̳ʸ� ã������ �����̳� ������
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
	// (1) file���� �Է¹޴´�.
	// (2) ������ ���������� ������ �ʾ�����, ����(0)�� return.
	// (3) ���� �о����
	//	   - �������� ������ temp ����, ������ �ʱ�ȭ.
	//	   - ������ ���� �����Ҷ����� loop [!m_InFile.eof()] ����
	//	   - �о���� -> �о�� �κ��� ������ Ȯ��(�����Ǵ�) -> ����Ʈ ����.
	// (4) ���� ����
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
	// (1) file���� �Է¹޴´�.
	// (2) ������ ���������� ������ �ʾ�����, ����(0)�� return.
	// (3) ����Ʈ�� ����ִ��� Ȯ��. ��������� ����(0)�� return.
	// (4) ���� �о����
	//	   - �������� ������ temp ����, ������ �ʱ�ȭ.
	//	   - ����Ʈ�� ������ item���� ������ ����.
	//	   - ������ item�� ���Ͽ� �ۼ�.
	// (5) ���� ����
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
		ContainerType curContainer; // 2. �����̳ʰ� �����ϴ� ���
		curContainer.SetContainerID(_item.GetContainerID());
		if (ContainerList.RetrieveByBS(curContainer)) {
			if (MasterList.Add(_item) == 1) { // �ߺ�Ȯ�θ���
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
			if (ContainerList.IsFull()) { // 3. �����̳ʰ� ���µ� �����̳� ������ �� ���� ����(0)
				cout << "[ERROR: CONTAINERLIST IS FULL!]3" << endl;
				return 0;
			} // 4. �����̳ʸ� �����ؼ� ������ �Է��ϰ� �� �ȿ� ��������
			ContainerType _container; // ��ǰ�� ��� �����̳� ����.
			_container.SetContainerID(_item.GetContainerID());
			_container.DisplayContainerIDOnScreen();
			_container.SetContainerLocationFromKB();
			_container.AddItem(_item);
			if (MasterList.Add(_item) == 1) { // �ߺ�Ȯ�θ���
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


	// Opencv 4.3.0 �� �̿��Ͽ� ���� ����.
	int AddPhotoContainer()
	{
		cout << "������������ ����Դϴ�." << endl;
		return 0;
	}


	// Opencv 4.3.0 �� �̿��Ͽ� ���� ����.
	int DeletePhotoContainer()
	{
		cout << "������������ ����Դϴ�." << endl;
		return 0;
	}


	// Opencv 4.3.0 �� �̿��Ͽ� ���� ����.
	void DisplayAllPhotoContainer()
	{
		cout << "������������ ����Դϴ�." << endl;
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
			// ContainerType ���ο��� GetNextItem() �� photo�� tItemList���� ��� �ʿ��ϴ�
			// id�� �ް�
			// MasterList���� �ش��ϴ� id�� record�� binarysearch�� �˻��Ѵ�.
		}
	}

};