#pragma once
//--------------------------------------------------------------------
//		Storage type class.
//--------------------------------------------------------------------
class StorageType
{
private:
	int m_StorageID;									///< storage id.
	string m_StorageLocation;							///< location of storage.

	AVLTree<ContainerType> m_ContainerTree;				///< structure for container.
	DoublySortedLinkedList<int> m_ContainerIDs;			///< container IDs.

public:
	StorageType();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	~StorageType();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	int GetID() const; 
	//--------------------------------------------------------------------
	//	Brief:	Get Storage ID.
	//	Pre:	storage id is set.
	//	Post:	none.
	//	Return: storage id.
	//--------------------------------------------------------------------


	string GetStorageLocation() const;
	//--------------------------------------------------------------------
	//	Brief:	Get Storage location.
	//	Pre:	storage location is set.
	//	Post:	none.
	//	Return: storage location.
	//--------------------------------------------------------------------


	int GetContainerNumbers() const;
	//--------------------------------------------------------------------
	//	Brief:	Get container numbers.
	//	Pre:	container numbers is set.
	//	Post:	none.
	//	Return: container numbers.
	//--------------------------------------------------------------------


	void SetStorageID(int inStorageID);
	//--------------------------------------------------------------------
	//	Brief:	Set storage id.
	//	Pre:	none.
	//	Post:	storage id is set.
	//	Param:	inStorageID			storage id.
	//--------------------------------------------------------------------


	void SetStorageLocation(string inStorageLocation);
	//--------------------------------------------------------------------
	//	Brief:	Set storage location.
	//	Pre:	none.
	//	Post:	storage location is set.
	//	Param:	inStorageLocation		storage location.
	//--------------------------------------------------------------------


	void SetRecord(int inStorageID, string inStorageLocation);
	//--------------------------------------------------------------------
	//	Brief:	Set storage record.
	//	Pre:	none.
	//	Post:	storage record is set.
	//	Param:	inStorageID				storage id.
	//	Param:	inStorageLocation		storage location.
	//--------------------------------------------------------------------


	void SetStorageIDFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set storage id from keyboard.
	//	Pre:	none.
	//	Post:	storage id is set.
	//--------------------------------------------------------------------


	void SetStorageLocationFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set storage location from keyboard.
	//	Pre:	none.
	//	Post:	storage location is set.
	//--------------------------------------------------------------------


	void SetStorageRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set storage record from keyboard.
	//	Pre:	none.
	//	Post:	storage record is set.
	//--------------------------------------------------------------------


	void DisplayStorageIDOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display storage id on screen.
	//	Pre:	storage id is set.
	//	Post:	storage id is on screen.
	//--------------------------------------------------------------------


	void DisplayStorageLocationOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display storage location on screen.
	//	Pre:	storage location is set.
	//	Post:	storage location is on screen.
	//--------------------------------------------------------------------


	void DisplayStorageRecordOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display storage record on screen.
	//	Pre:	storage record is set.
	//	Post:	storage record is on screen.
	//--------------------------------------------------------------------



	bool operator==(const StorageType& _storage) {
		if (m_StorageID == _storage.GetID())
			return true;
		return false;
	}


	bool operator>(const StorageType& _storage) {
		if (m_StorageID > _storage.GetID())
			return true;
		return false;
	}


	bool operator<(const StorageType& _storage) {
		if (m_StorageID < _storage.GetID())
			return true;
		return false;
	}


	void operator=(const StorageType& _storage) {
		m_StorageID = _storage.m_StorageID;
		m_StorageLocation = _storage.m_StorageLocation;
		m_ContainerTree = _storage.m_ContainerTree;
		m_ContainerIDs = _storage.m_ContainerIDs;
	}


	// Overload operator<<
	friend ostream& operator<<(ostream& _out, StorageType& _storage)
	{
		_out << "\t----------------------------" << endl;
		_out << "\t[StorageID]  : " << _storage.m_StorageID << endl;
		_out << "\t[Location]   : " << _storage.m_StorageLocation << endl;
		_out << "\t[Con-Numbers]: " << _storage.GetContainerNumbers() << endl;
		_out << "\t----------------------------" << endl;

		return _out;
	}


	bool IsContainerEmpty()
	//--------------------------------------------------------------------
	//	Brief:	Check Whether stored container is empty.
	//  Pre:	StorageType이 선언되어 있어야한다.
	//  Post:	none.
	//	Return:	Return true if container is empty, otherwise false.
	//--------------------------------------------------------------------
	{
		return m_ContainerTree.IsEmpty();
	}


	void RetrieveContainer(ContainerType& _con, bool& _found)
	//--------------------------------------------------------------------
	//	Brief:	Container 자료를 Storage에서 찾는다.
	//  Pre:	StorageType이 선언되어 있어야한다.
	//  Post:	일치하는 Container를 참조하고, 여부를 found에 참조.
	//  Param:	_con		target data for saving.
	//	Param:	_fount		boolean varialbe.
	//--------------------------------------------------------------------
	{
		m_ContainerTree.Retrieve(_con, _found);
	}



	void AddContainer(ContainerType& _con, bool& _func)
	//--------------------------------------------------------------------
	//	Brief:	Container 자료를 Storage에 추가한다.
	//  Pre:	StorageType이 선언되어 있어야한다.
	//  Post:	Container 자료가 Storage에 추가된다.
	//  Param:	_con		target data for saving.
	//--------------------------------------------------------------------
	{
		m_ContainerTree.Add(_con, _func);
		if (_func)								// 추가 동작이 성공한 경우
		{
			int inID = _con.GetID();
			m_ContainerIDs.Add(inID);
		}
	}


	void DeleteContainer(ContainerType& _con, bool& _func)
	//--------------------------------------------------------------------
	//	Brief:	Container 자료를 Storage로부터 삭제한다.
	//  Pre:	StorageType이 선언되어 있어야한다.
	//  Post:	Container 자료가 Storage에 추가된다.
	//  Param:	_con		target data for deleting.
	//--------------------------------------------------------------------
	{
		m_ContainerTree.Delete(_con, _func);
		if (_func)								// 삭제 동작이 성공한 경우
		{
			int deleteID = _con.GetID();
			m_ContainerIDs.Delete(deleteID);
		}
	}


	void UpdateContainer(ContainerType& _con, bool& _found)
	//--------------------------------------------------------------------
	//	Brief:	Container 자료를 Storage에서 교체한다.
	//  Pre:	StorageType이 선언되어 있어야한다.
	//  Post:	Container 자료가 Storage에서 교체된다.
	//  Param:	_con		target data for updating.
	//--------------------------------------------------------------------
	{
		m_ContainerTree.Replace(_con, _found);
	}


	void DisplayAllContainer()
	//--------------------------------------------------------------------
	//	Brief:	Storage가 저장한 모든 Container 자료를 출력한다.
	//	pre:	Storage is initialized.
	//	Post:	None.
	//--------------------------------------------------------------------
	{
		m_ContainerTree.PrintTree(cout);
	}


	void DisplayAllDetailsStorage(const AVLTree<ItemType*>& _master)
	//--------------------------------------------------------------------
	//	Brief:	Storage가 저장한 모든 자료를 출력한다.
	//	pre:	Storage is initialized.
	//	Post:	None.
	//--------------------------------------------------------------------
	{
		bool func;
		ContainerType curContainer;
		DoublyIterator<int> itor(m_ContainerIDs);
		itor.Next();
		while (itor.NextNotNull())
		{
			int data;
			itor.Now(data);
			curContainer.SetContainerID(data);
			m_ContainerTree.Retrieve(curContainer, func);
			cout << curContainer << endl;
			curContainer.DisplayAllDetailsContainer(_master);
			itor.Next();
		}
	}
};
