#ifndef _CONTAINERTYPE_H_
#define _CONTAINERTYPE_H_
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
	//		
	//--------------------------------------------------------------------

	//=================================================================================================


	int GetContainerID();
	//--------------------------------------------------------------------
	//	Brief:	Get Container ID.
	//	Pre:	container id is set.
	//	Post:	none.
	//	Return: container id.
	//--------------------------------------------------------------------


	string GetContainerLocation();
	//--------------------------------------------------------------------
	//	Brief:	Get Container location.
	//	Pre:	container location is set.
	//	Post:	none.
	//	Return: container location.


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


	RelationType Compare(const ContainerType& data);
	//--------------------------------------------------------------------
	//	Brief:	Compare two ContainerType by container id.
	//	Pre:	two Containers should be initialized.
	//	Post:	none.
	//	Param:	data		target container for comparing.
	//	Return:	return LESS if this.c_Id < data.c_Id,
	//				   EQUAL if this.c_Id == data.c_Id,
	//				   GREATER if this.c_Id > data.c_Id.
	//--------------------------------------------------------------------	


	//=================================================================================================



	int AddItem(ItemType data);
	//--------------------------------------------------------------------
	//	
	//--------------------------------------------------------------------


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

#endif _CONTAINERTYPE_H_