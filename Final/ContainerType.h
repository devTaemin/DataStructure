#pragma once
//--------------------------------------------------------------------
//		Container type class.
//--------------------------------------------------------------------
class ContainerType
{
private:
	int m_ContainerID;									///< container id.
	string m_ContainerLocation;							///< location of container.
	AVLTree<SimpleItemType> m_SimpleItemTree;			///< structure for storing items.
	DoublySortedLinkedList<PhotoType> m_PhotoList;		///< structure for photos.

public:
	ContainerType();
	//--------------------------------------------------------------------
	//		Default Constructor.
	//--------------------------------------------------------------------


	~ContainerType();
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	int GetContainerID() const;
	//--------------------------------------------------------------------
	//	Brief:	Get Container ID.
	//	Pre:	container id is set.
	//	Post:	none.
	//	Return: container id.
	//--------------------------------------------------------------------


	string GetContainerLocation() const;
	//--------------------------------------------------------------------
	//	Brief:	Get Container location.
	//	Pre:	container location is set.
	//	Post:	none.
	//	Return: container location.
	//--------------------------------------------------------------------


	void SetContainerID(int inContainerID);
	//--------------------------------------------------------------------
	//	Brief:	Set container id.
	//	Pre:	none.
	//	Post:	container id is set.
	//	Param:	inContainerID		container id.
	//--------------------------------------------------------------------


	void SetContainerLocation(string inContainerLocation);
	//--------------------------------------------------------------------
	//	Brief:	Set container location.
	//	Pre:	none.
	//	Post:	container location is set.
	//	Param:	inContainerLocation		container location.
	//--------------------------------------------------------------------


	void SetRecord(int inContainerID, string inContainerLocation);
	//--------------------------------------------------------------------
	//	Brief:	Set container record.
	//	Pre:	none.
	//	Post:	contianer record is set.
	//	Param:	inContainerID			container id.
	//	Param:	inContainerLocation		container location.
	//--------------------------------------------------------------------


	void SetContainerIDFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set container id from keyboard.
	//	Pre:	none.
	//	Post:	container id is set.
	//--------------------------------------------------------------------


	void SetContainerLocationFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set container location from keyboard.
	//	Pre:	none.
	//	Post:	container location is set.
	//--------------------------------------------------------------------


	void SetContainerRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set container record from keyboard.
	//	Pre:	none.
	//	Post:	container record is set.
	//--------------------------------------------------------------------


	void DisplayContainerIDOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display container id on screen.
	//	Pre:	container id is set.
	//	Post:	container id is on screen.
	//--------------------------------------------------------------------


	void DisplayContainerLocationOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display container location on screen.
	//	Pre:	container location is set.
	//	Post:	container location is on screen.
	//--------------------------------------------------------------------


	void DisplayContainerRecordOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display container record on screen.
	//	Pre:	container record is set.
	//	Post:	container record is on screen.
	//--------------------------------------------------------------------



	bool operator==(const ContainerType& _con) {
		if (m_ContainerID == _con.GetContainerID())
			return true;
		return false;
	}


	bool operator>(const ContainerType& _con) {
		if (m_ContainerID > _con.GetContainerID())
			return true;
		return false;
	}


	bool operator<(const ContainerType& _con) {
		if (m_ContainerID < _con.GetContainerID())
			return true;
		return false;
	}


	void operator=(const ContainerType& _con) {
		m_ContainerID = _con.m_ContainerID;
		m_ContainerLocation = _con.m_ContainerLocation;
	}


	// Overload operator<<
	friend ostream& operator<<(ostream& _out, ContainerType& _con)
	{
		_out << "\t+--------------------------+" << endl;
		_out << "\t[ContainerID]: " << _con.m_ContainerID << endl;
		_out << "\t[Location]   : " << _con.m_ContainerLocation << endl;
		_out << "\t+--------------------------+" << endl;
		

		return _out;
	}


	
	void AddItem(ItemType& _data)
	//--------------------------------------------------------------------
	//	Brief:	SimpleItemType의 자료를 Container에 추가한다.
	//  Pre:	ContainerType이 선언되어 있어야한다.
	//  Post:	SimpleItemType자료가 Container에 추가된다.
	//  Param:	data		target data for convert and save in list.
	//--------------------------------------------------------------------
	{
		SimpleItemType s_Item;
		s_Item.GetRecordFromItemType(_data);
		m_SimpleItemTree.Add(s_Item);
	}


	void DeleteItem(ItemType& _data)
	//--------------------------------------------------------------------
	//	Brief:	SimpleItemType의 자료를 Container에서 삭제한다.
	//  Pre:	ContainerType이 선언되어 있어야한다.
	//  Post:	SimpleItemType자료가 Container으로부터 삭제된다.
	//  Param:	data		target data for convert and delete from list.
	//--------------------------------------------------------------------
	{
		SimpleItemType s_Item;
		s_Item.GetRecordFromItemType(_data);
		m_SimpleItemTree.Delete(s_Item);
	}


	void UpdateItem(ItemType& _data)
	//--------------------------------------------------------------------
	//	Brief:	SimpleItemType의 자료를 Container에서 교체한다.
	//  Pre:	ContainerType이 선언되어 있어야한다.
	//  Post:	SimpleItemType자료가 Container에서 교체된다.
	//  Param:	data		target data for convert and replace from list.
	//--------------------------------------------------------------------
	{
		SimpleItemType s_Item;
		s_Item.GetRecordFromItemType(_data);
		m_SimpleItemTree.Replace(s_Item);
	}


	void DisplayAllItem()
	//--------------------------------------------------------------------
	//	Brief:	Container가 저장한 모든 SimpleItemType 자료를 출력한다.
	//	pre:	Container is initialized.
	//	Post:	None.
	//--------------------------------------------------------------------
	{
		m_SimpleItemTree.PrintTree(cout);
	}


	void AddPhoto()
	//--------------------------------------------------------------------
	//		UnSortedList<string> c_Photo_list;
	//		Opencv 4.3.0 을 이용한 코드 작성, 수정 필요
	//--------------------------------------------------------------------
	{
		PhotoType photo;
		photo.AddPhoto();
		if (m_PhotoList.Add(photo) == 1){
			cout << "\t[SUCCESS: ADD PHOTO]" << endl;
		}
		else {
			cout << "\t[ERROR: ADD PHOTO]" << endl;
		}
	}


	void DeletePhoto()
	//--------------------------------------------------------------------
	//		UnSortedList<string> c_Photo_list;
	//		Opencv 4.3.0 을 이용한 코드 작성, 수정 필요
	//--------------------------------------------------------------------
	{
		PhotoType photo;
		photo.SetPhotoIDFromKB();
		if (m_PhotoList.Delete(photo) == 1) {
			cout << "\t[SUCCESS: DELETE PHOTO]" << endl;
		}
		else {
			cout << "\t[ERROR: DELETE PHOTO]" << endl;
		}
	}


	void UpdatePhoto()
	//--------------------------------------------------------------------
	//		UnSortedList<string> c_Photo_list;
	//		Opencv 4.3.0 을 이용한 코드 작성, 수정 필요
	//--------------------------------------------------------------------
	{
		PhotoType photo;
		photo.SetPhotoRecordFromKB();
		if (m_PhotoList.Replace(photo) == 1) {
			cout << "\t[SUCCESS: UPDATE PHOTO]" << endl;
		}
		else {
			cout << "\t[ERROR: UPDATE PHOTO]" << endl;
		}
	}


	void DisplayAllPhoto()
	//--------------------------------------------------------------------
	//		UnSortedList<string> c_Photo_list;
	//		Opencv 4.3.0 을 이용한 코드 작성, 수정 필요
	//--------------------------------------------------------------------
	{
		if (!m_PhotoList.IsEmpty())
		{
			DoublyIterator<PhotoType> itor(m_PhotoList);
			PhotoType tempPhoto;
			itor.Next();

			while (itor.NextNotNull()) {
				itor.Now(tempPhoto);
				cout << tempPhoto << endl;

			}
		}
	}
};
