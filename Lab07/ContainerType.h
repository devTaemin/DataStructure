/*
#pragma once
//--------------------------------------------------------------------
//		Container type class.
//--------------------------------------------------------------------

class ContainerType
{
private:
	int m_ContainerID;									///< container id.
	string m_ContainerLocation;							///< location of container. 


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
	//	Post:	commodity record is set.
	//	Param:	inContainerID			container id.
	//	Param:	inContainerLocation		commodity location.
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



	bool operator==(const ContainerType& _item) {
		if (m_ContainerID == _item.GetContainerID())
			return true;
		return false;
	}


	bool operator>(const ContainerType& _item) {
		if (m_ContainerID > _item.GetContainerID())
			return true;
		return false;
	}


	bool operator<(const ContainerType& _item) {
		if (m_ContainerID < _item.GetContainerID())
			return true;
		return false;
	}


	void operator=(const ContainerType& _item) {
		if (m_ContainerID != _item.m_ContainerID) {
			m_ContainerID = _item.m_ContainerID;
			m_ContainerLocation = _item.m_ContainerLocation;
		}
	}


	int AddItem(ItemType data)
		//--------------------------------------------------------------------
		//	Brief:	SimpleItemType의 자료를 Container에 추가한다.
		//  Pre:	ContainerType이 선언되어 있어야한다.
		//  Post:	SimpleItemType자료가 Container에 추가된다.
		//  Param:	data		target data for convert and save in list.
		//	return: return 1 if function works well, otherwise 0.
		//--------------------------------------------------------------------
	{
		SimpleItemType s_Item;
		s_Item.GetRecordFromItemType(data);
		if (c_itemList.Add(s_Item)) { return 1; }
		return 0;
	}


	int DeleteItem(ItemType data)
		//--------------------------------------------------------------------
		//	Brief:	SimpleItemType의 자료를 Container에서 삭제한다.
		//  Pre:	ContainerType이 선언되어 있어야한다.
		//  Post:	SimpleItemType자료가 Container으로부터 삭제된다.
		//  Param:	data		target data for convert and delete from list.
		//	return: return 1 if function works well, otherwise 0.		
		//--------------------------------------------------------------------
	{
		SimpleItemType s_Item;
		s_Item.GetRecordFromItemType(data);
		if (c_itemList.Delete(s_Item)) { return 1; }
		return 0;
	}


	int UpdateItem(ItemType data)
		//--------------------------------------------------------------------
		//	Brief:	SimpleItemType의 자료를 Container에서 교체한다.
		//  Pre:	ContainerType이 선언되어 있어야한다.
		//  Post:	SimpleItemType자료가 Container에서 교체된다.
		//  Param:	data		target data for convert and replace from list.
		//	return: return 1 if function works well, otherwise 0.	
		//--------------------------------------------------------------------
	{
		SimpleItemType s_Item;
		s_Item.GetRecordFromItemType(data);
		if (c_itemList.Replace(s_Item)) { return 1; }
		return 0;
	}


	int AddPhoto(string data)
		//--------------------------------------------------------------------
		//		UnSortedList<string> c_Photo_list;	
		//		Opencv 4.3.0 을 이용한 코드 작성, 수정 필요
		//--------------------------------------------------------------------
	{
		if (c_Photo_list.Add(data)) { return 1; }
		return 0;
	}


	int DeletePhoto(string data)
		//--------------------------------------------------------------------
		//		UnSortedList<string> c_Photo_list;	
		//		Opencv 4.3.0 을 이용한 코드 작성, 수정 필요
		//--------------------------------------------------------------------
	{
		if (c_Photo_list.Delete(data)) { return 1; }
		return 0;
	}


	int UpdatePhoto(string data)
		//--------------------------------------------------------------------
		//		UnSortedList<string> c_Photo_list;	
		//		Opencv 4.3.0 을 이용한 코드 작성, 수정 필요
		//--------------------------------------------------------------------
	{
		if (c_Photo_list.Replace(data)) { return 1; }
		return 0;
	}


	void DisplayAllItem()
		//--------------------------------------------------------------------
		//		UnSortedList<SimpleItemType> c_itemList;
		//--------------------------------------------------------------------
	{
		SimpleItemType curItem;
		c_itemList.ResetList();
		int iPos = c_itemList.GetNextItem(curItem);
		for (iPos; iPos >= 0; iPos = c_itemList.GetNextItem(curItem)) {
			curItem.DisplayRecordOnScreen();
		}
	}


	void DisplayAllPhoto()
		//--------------------------------------------------------------------
		//		UnSortedList<string> c_Photo_list;
		//		Opencv 4.3.0 을 이용한 코드 작성, 수정 필요
		//--------------------------------------------------------------------
	{
		cout << "코드가 구현되지 않았습니다 :)" << '\n';
	}


	int FindByName()
		//--------------------------------------------------------------------
		//		UnSortedList<SimpleItemType> c_itemList;
		//--------------------------------------------------------------------
	{
		bool found = false;
		SimpleItemType findItem;
		findItem.GetName();
		SimpleItemType curItem;
		c_itemList.ResetList();
		int iPos = c_itemList.GetNextItem(curItem);
		for (iPos; iPos >= 0; iPos = c_itemList.GetNextItem(curItem)) {
			if (curItem.GetName() == findItem.GetName()) {
				curItem.DisplayRecordOnScreen();
				found = true;
			}
		}

		if (!found) { return 0; }
		return 1;
	}


	int FindByUsage(SortedList<ItemType>& list)
		//--------------------------------------------------------------------
		//		UnSortedList<SimpleItemType> c_itemList;
		//--------------------------------------------------------------------
	{
		bool found = false;
		ItemType findItem;
		ItemType curItem;
		SimpleItemType curSimpleItem;

		findItem.SetUsageFromKB();
		list.ResetList();
		int iPos = list.GetNextItem(curItem);
		for (iPos; iPos >= 0; iPos = list.GetNextItem(curItem)) {
			if (curItem.GetUsage() == findItem.GetUsage()) {
				int serial = curItem.GetSerial();
				c_itemList.ResetList();
				int sPos = c_itemList.GetNextItem(curSimpleItem);
				for (sPos; sPos >= 0; sPos = c_itemList.GetNextItem(curSimpleItem)) {
					if (curSimpleItem.GetSerial() == serial) {
						curSimpleItem.DisplayRecordOnScreen();
						found = true;
					}
				}
			}
		}
		if (!found) { return 0; }
		return 1;
	}
};
*/