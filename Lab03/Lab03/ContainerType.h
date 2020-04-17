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
		return (c_Id == _item.GetContainerID());
	}


	bool operator>(const ContainerType& _item) {
		return (c_Id > _item.GetContainerID());
	}


	bool operator<(const ContainerType& _item) {
		return (c_Id < _item.GetContainerID());
	}


	void operator=(const ContainerType& _item) {
		c_Id = _item.c_Id;
		c_Location = _item.c_Location;
		c_Photo_list = _item.c_Photo_list;
		c_itemList = _item.c_itemList;
	}


	int AddItem(ItemType data)
	//--------------------------------------------------------------------
	//	
	//--------------------------------------------------------------------
	{

	}


	int DeleteItem(ItemType& data);
	//--------------------------------------------------------------------
	//		
	//--------------------------------------------------------------------


	int UpdateItem(ItemType data);
	//--------------------------------------------------------------------
	//		
	//--------------------------------------------------------------------


	int AddPhoto(string data);
	//--------------------------------------------------------------------
	//		
	//--------------------------------------------------------------------


	int DeletePhoto(string& data);
	//--------------------------------------------------------------------
	//		
	//--------------------------------------------------------------------


	int UpdatePhoto(string data);
	//--------------------------------------------------------------------
	//		
	//--------------------------------------------------------------------


	int DisplayAllItem();
	//--------------------------------------------------------------------
	//		
	//--------------------------------------------------------------------


	int DisplayAllPhoto();
	//--------------------------------------------------------------------
	//		
	//--------------------------------------------------------------------


	int FindByName();
	//--------------------------------------------------------------------
	//		
	//--------------------------------------------------------------------


	int FindByUsage();
	//--------------------------------------------------------------------
	//		
	//--------------------------------------------------------------------

};