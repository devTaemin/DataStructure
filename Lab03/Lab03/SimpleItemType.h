#pragma once
//--------------------------------------------------------------------
//		Simple Item information class.
//--------------------------------------------------------------------
class SimpleItemType
{
private:
	int s_ContainerID;				///<  컨테이너의 번호.
	int s_Serial;					///<  물건의 고유 번호.
	string s_Name;					///<  물건의 이름.

public:
	SimpleItemType()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		s_ContainerID = -1;
		s_Serial = -1;
		s_Name = "";
	}


	~SimpleItemType() {}
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


	int GetSerial() const;
	//--------------------------------------------------------------------
	//	Brief:	Get commodity serial.
	//	Pre:	commodity serial is set.
	//	Post:	none.
	//	Return: commodity serial.
	//--------------------------------------------------------------------


	string GetName() const;
	//--------------------------------------------------------------------
	//	Brief:	Get commodity name.
	//	Pre:	commodity name is set.
	//	Post:	none.
	//	Return: commodity name.
	//--------------------------------------------------------------------


	void SetContainerID(int inContainerID);
	//--------------------------------------------------------------------
	//	Brief:	Set container id.
	//	Pre:	none.
	//	Post:	container id is set.
	//	Param:	inContainerID		container id.
	//--------------------------------------------------------------------


	void SetSerial(int inSerial);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity serial.
	//	Pre:	none.
	//	Post:	commodity serial is set.
	//	Param:	inName		commodity name.
	//--------------------------------------------------------------------


	void SetName(string inName);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity name.
	//	Pre:	none.
	//	Post:	commodity name is set.
	//	Param:	inName		commodity name.
	//--------------------------------------------------------------------


	void SetRecord(int inContainerID, int inSerial, string inName);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//	Param:	inContainerID	container id.
	//	Param:	inSerial		commodity serial.
	//	Param:	inName			commodity name.
	//--------------------------------------------------------------------


	void SetContainerIDFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set container id from keyboard.
	//	Pre:	none.
	//	Post:	container id is set.
	//--------------------------------------------------------------------


	void SetSerialFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity serial from keyboard
	//	Pre:	none.
	//	Post:	commodity serial is set.
	//--------------------------------------------------------------------


	void SetNameFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity name from keyboard
	//	Pre:	none.
	//	Post:	commodity name is set.
	//--------------------------------------------------------------------


	void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record from keyboard.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//--------------------------------------------------------------------


	void DisplayContainerIDOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display container id on screen.
	//	Pre:	container id is set.
	//	Post:	container id is on screen.
	//--------------------------------------------------------------------


	void DisplaySerialOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity serial on screen.
	//	Pre:	commodity serial is set.
	//	Post:	commodity serial is on screen.
	//--------------------------------------------------------------------


	void DisplayNameOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity name on screen.
	//	Pre:	commodity name is set.
	//	Post:	commodity name is on screen.
	//--------------------------------------------------------------------


	void DisplayRecordOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity record on screen.
	//	Pre:	commodity record is set.
	//	Post:	commodity record is on screen.
	//--------------------------------------------------------------------


	int ReadDataFromFile(ifstream& fin);
	//--------------------------------------------------------------------
	//	Brief:	Read a record from a file.
	//	Pre:	the target file is opened.
	//	Post:	student record is set.
	//	Param:	fin		file descriptor.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------


	int WriteDataToFile(ofstream& fout);
	//--------------------------------------------------------------------
	//	Brief:	Write a record into file.
	//	Pre:	the target file is opened, and the list is initialized.
	//	Post:	the target file includes new record.
	//	Param:	fout		file descriptor.
	//	Return:	return 1 if this function works well, otherwise 0.
	//--------------------------------------------------------------------



	RelationType Compare(const SimpleItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Compare two Simpleitemtypes by item container id.
	//	Pre:	two items should be initialized.
	//	Post:	none.
	//	Param:	data		target item for comparing.
	//	Return:	return LESS if this.ContainerID < data.ContainerID,
	//				   EQUAL if this.ContainerID == data.ContainerID,
	//				   GREATER if this.ContainerID > data.ContainerID.
	//--------------------------------------------------------------------	


	void GetRecordFromItemType(ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Get the record from ItemType to SimpleItemType.
	//	Pre:	both datatype should be initialized.
	//	Post:	SimpleItemType's record is updated.
	//	Param:	data		target item for update 
	//--------------------------------------------------------------------	


	bool operator==(const SimpleItemType& _item) {
		if (s_Serial == _item.GetSerial())
			return true;
		return false;
	}


	bool operator>(const SimpleItemType& _item) {
		if (s_Serial > _item.GetSerial())
			return true;
		return false;
	}


	bool operator<(const SimpleItemType& _item) {
		if (s_Serial < _item.GetSerial())
			return true;
		return false;
	}


	void operator=(const SimpleItemType& _item) {
		s_ContainerID = _item.GetContainerID();
		s_Serial = _item.GetSerial();
		s_Name = _item.GetName();
	}
};