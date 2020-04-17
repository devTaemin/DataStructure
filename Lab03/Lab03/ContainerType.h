#pragma once
//--------------------------------------------------------------------
//		Container type class.
//--------------------------------------------------------------------

class ContainerType
{
private:
	int c_Id;									///< container id.
	string c_Location;							///< location of container. 
	UnSortedList<string> c_Photo_list;			///< photo of container.
	UnSortedList<SimpleItemType> c_itemList;	///< items in container.

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
		if (c_Id == _item.GetContainerID())
			return true;
		return false;
	}


	bool operator>(const ContainerType& _item) {
		if (c_Id > _item.GetContainerID())
			return true;
		return false;
	}


	bool operator<(const ContainerType& _item) {
		if (c_Id < _item.GetContainerID())
			return true;
		return false;
	}


	void operator=(const ContainerType& _item) {
		if (c_Id != _item.c_Id) {			// �������� �����ؾ��Ѵ�.
			c_Id = _item.c_Id;
			c_Location = _item.c_Location;
			c_Photo_list = _item.c_Photo_list;
			c_itemList = _item.c_itemList;
		}
	}


	int AddItem(ItemType data)
	//--------------------------------------------------------------------
	//	Brief:	SimpleItemType�� �ڷḦ Container�� �߰��Ѵ�.
	//  Pre:	ContainerType�� ����Ǿ� �־���Ѵ�.
	//  Post:	SimpleItemType�ڷᰡ Container�� �߰��ȴ�.
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
	//	Brief:	SimpleItemType�� �ڷḦ Container���� �����Ѵ�.
	//  Pre:	ContainerType�� ����Ǿ� �־���Ѵ�.
	//  Post:	SimpleItemType�ڷᰡ Container���κ��� �����ȴ�.
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
	//	Brief:	SimpleItemType�� �ڷḦ Container���� ��ü�Ѵ�.
	//  Pre:	ContainerType�� ����Ǿ� �־���Ѵ�.
	//  Post:	SimpleItemType�ڷᰡ Container���� ��ü�ȴ�.
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
	//		Opencv 4.3.0 �� �̿��� �ڵ� �ۼ�, ���� �ʿ�
	//--------------------------------------------------------------------
	{
		if (c_Photo_list.Add(data)) { return 1; }
		return 0;
	}


	int DeletePhoto(string data)
	//--------------------------------------------------------------------
	//		UnSortedList<string> c_Photo_list;	
	//		Opencv 4.3.0 �� �̿��� �ڵ� �ۼ�, ���� �ʿ�
	//--------------------------------------------------------------------
	{
		if (c_Photo_list.Delete(data)){ return 1; }
		return 0;
	}


	int UpdatePhoto(string data)
	//--------------------------------------------------------------------
	//		UnSortedList<string> c_Photo_list;	
	//		Opencv 4.3.0 �� �̿��� �ڵ� �ۼ�, ���� �ʿ�
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
	//		Opencv 4.3.0 �� �̿��� �ڵ� �ۼ�, ���� �ʿ�
	//--------------------------------------------------------------------
	{
		cout << "�ڵ尡 �������� �ʾҽ��ϴ� :)" << '\n';
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