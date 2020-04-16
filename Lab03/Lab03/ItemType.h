#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_
//--------------------------------------------------------------------
//		Item information class.
//--------------------------------------------------------------------
class ItemType
{
private:
	int m_ContainerID;				///<  �����̳��� ��ȣ.
	int m_Serial;					///<  ������ ������ȣ.
	string m_Name;					///<  ������ �̸�.
	int m_Num;						///<  ������ ����.
	string m_Usage;					///<  ������ �뵵.
	int m_Date;						///<  ���� ������


public:
	ItemType()
		//--------------------------------------------------------------------
		//		Default Constructor.
		//--------------------------------------------------------------------
	{
		m_ContainerID = -1;
		m_Serial = -1;
		m_Name = "";
		m_Num = -1;
		m_Usage = "";
		m_Date = -1;
	}


	~ItemType() {}
	//--------------------------------------------------------------------
	//		Destructor.
	//--------------------------------------------------------------------


	int GetContainerID();
	//--------------------------------------------------------------------
	//	Brief:	Get Container ID.
	//	Pre:	container id is set.
	//	Post:	none.
	//	Return: container id.
	//--------------------------------------------------------------------


	int GetSerial();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity serial.
	//	Pre:	commodity serial is set.
	//	Post:	none.
	//	Return: commodity serial.
	//--------------------------------------------------------------------


	string GetName();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity name.
	//	Pre:	commodity name is set.
	//	Post:	none.
	//	Return: commodity name.
	//--------------------------------------------------------------------


	int GetNum();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity number.
	//	Pre:	commodity number is set.
	//	Post:	none.
	//	Return: commodity number.
	//--------------------------------------------------------------------


	string GetUsage();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity usage.
	//	Pre:	commodity usage is set.
	//	Post:	none.
	//	Return: commodity usage.
	//--------------------------------------------------------------------


	int GetDate();
	//--------------------------------------------------------------------
	//	Brief:	Get commodity date.
	//	Pre:	commodity date is set.
	//	Post:	none.
	//	Return: commodity date.
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


	void SetNum(int inNum);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity number.
	//	Pre:	none.
	//	Post:	commodity number is set.
	//	Param:	inNum		commodity number.
	//--------------------------------------------------------------------


	void SetUsage(string inUsage);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity usage.
	//	Pre:	none.
	//	Post:	commodity usage is set.
	//	Param:	inUsage		commodity usage.
	//--------------------------------------------------------------------


	void SetDate(int inDate);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity date.
	//	Pre:	none.
	//	Post:	commodity date is set.
	//	Param:	inDate		commodity date.
	//--------------------------------------------------------------------


	void SetRecord(int inContainerID, int inSerial, string inName, int inNum, string inUsage, int inDate);
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record.
	//	Pre:	none.
	//	Post:	commodity record is set.
	//	Param:	inContainerID	container id.
	//	Param:	inSerial		commodity serial.
	//	Param:	inName			commodity name.
	//	Param:	inNum			commodity number.
	//	Param:	inUsage			commodity usage.
	//	Param	inDate			commodity date.
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


	void DisplayNumOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity number on screen.
	//	Pre:	commodity number is set.
	//	Post:	commodity number is on screen.
	//--------------------------------------------------------------------


	void DisplayUsageOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity usage on screen.
	//	Pre:	commodity usage is set.
	//	Post:	commodity usage is on screen.
	//--------------------------------------------------------------------


	void DisplayDateOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity date on screen.
	//	Pre:	commodity date is set.
	//	Post:	commodity date is on screen.
	//--------------------------------------------------------------------


	void DisplayRecordOnScreen();
	//--------------------------------------------------------------------
	//	Brief:	Display commodity record on screen.
	//	Pre:	commodity record is set.
	//	Post:	commodity record is on screen.
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


	void SetNumFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity number from keyboard.
	//	Pre:	none.
	//	Post:	commodity number is set.
	//--------------------------------------------------------------------


	void SetUsageFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity usage from keyboard.
	//	Pre:	none.
	//	Post:	commodity usage is set.
	//--------------------------------------------------------------------


	void SetDateFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity date from keyboard
	//	Pre:	none.
	//	Post:	commodity date is set.
	//--------------------------------------------------------------------


	void SetRecordFromKB();
	//--------------------------------------------------------------------
	//	Brief:	Set commodity record from keyboard.
	//	Pre:	none.
	//	Post:	commodity record is set.
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


	RelationType Compare(const ItemType& data);
	//--------------------------------------------------------------------
	//	Brief:	Compare two itemtypes by item serial number.
	//	Pre:	two items should be initialized.
	//	Post:	the target file includes the new item record.
	//	Param:	data		target item for comparing.
	//	Return:	return LESS if this.Serial < data.Serial,
	//				   EQUAL if this.Serial == data.Serial,
	//				   GREATER if this.Serial > data.Serial.
	//--------------------------------------------------------------------	
};
#endif _ITEMTYPE_H_